#!/usr/bin/perl -w
#-*-mode: cperl-*-

use strict;


# The first occurence of an unquoted mark character in the position
# pattern splits the pattern into a pre and a post part.  Quote
# character is backslash.  A backslash is quoted by doubling it.
my $mark = "%";

# only these strings are meta characters:
my @meta = ("\\$mark", '\\A', '\\Z', '\\n', '\\\\', '\\^', '^', '\\$', '$');
my $meta_re = "(".join("|", map {quotemeta($_)} @meta).")";


sub usage {
    die ("usage: $0 <error-text> <pos-pattern> <compiler-output>\n");
}

sub get_file {
  my ($file) = @_;
  
  local $/ = undef;
  open F, "< $file" or die "$0: failed to open `$file': $!\n";
  my $data = <F>;
  close F or die "$0: close failed: $!\n";

  #$data =~ s/\r\n?/\n/g;	# normalize CR+LF and CR to LF
  return $data;
}

sub make_re {
  my ($s) = @_;
  
  my @parts = split(m/$meta_re/, $s);
  for (my $i = 0; $i <= $#parts; $i+=2) { # quote everything not in @meta
    $parts[$i] = quotemeta($parts[$i]);
  }
  for (my $i = 1; $i <= $#parts; $i+=2) { # replace \% with %
    if ($parts[$i] eq "\\$mark") {
      $parts[$i] = "$mark";
    }
  }
  return join("", @parts);
}

sub transform_pattern {
  my ($pattern) = @_;
  
  my ($pre, $post);
  if ($pattern =~ /^$mark/) {
    $pre = ""; $post = substr($pattern, 1);
  } elsif ($pattern =~ /^(.*?[^\\])$mark(.*)$/) {
    ($pre, $post) = ($1, $2);
  } else {
    die "$0: pattern `$pattern' contains no position marker `$mark'\n";
  }

  return (make_re($pre).'\\z', '\\A'.make_re($post));
}

my ($current_file, $current_data) = ("", "");

sub position_matches {
  my ($file, $pos, $re_pre, $re_post) = @_;

  if ($file ne $current_file) {
    local $/ = undef;
    open G, "< $file" or die "$0: failed to open `$file': $!\n";
    $current_data = <G>;
    close G;
    $current_file = $file;
  }

  if ((0 <= $pos) and ($pos <= length($current_data))) {
    my $pre_data = substr($current_data, 0, $pos);
    $pre_data =~ s/\r\n?/\n/g;
    if ($pre_data =~ /$re_pre/) {
      my $post_data = substr($current_data, $pos);
      $post_data =~ s/\r\n?/\n/g;
      return ($post_data =~ /$re_post/);
    }
  }
  return 0;
}



if (@ARGV != 3) {
  usage();
}
my ($error_text, $pos_pattern, $output_file) = @ARGV;
my ($re_pre, $re_post) = transform_pattern($pos_pattern);
#print "re_pre=$re_pre\n";
#print "re_post=$re_post\n";

my $source_file;
open F, "< $output_file" or die "$0: faild to open `$output_file': $!\n";
while (1) {
  my $line = <F>;
  last if not defined $line;
  
  if ($line =~ m/^In file (.*):\s*$/) {  
    $source_file = $1;
  } elsif ($line =~ /^(\d+):(\d*) (.*)$/) {
    my ($pos, $text) = ($1, $3);
    if (defined $source_file) {
      if (position_matches($source_file, $pos, $re_pre, $re_post)) {
	if ($text eq $error_text) {
	  print "$0: found match\n";
	  exit(0);
	} else {
	  #print "$0: position matches, but got `$text' instead of `$error_text'\n";
	}
      }
    } else {
      die "$0: have not seen a reference to the source file\n";
    }
  }
  # ignore invalid lines in compiler output, they may be debug messages
}
close F;
print "$0: no match\n";
exit(1);
