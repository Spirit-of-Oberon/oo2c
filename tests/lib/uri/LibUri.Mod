MODULE LibUri;

IMPORT
  URI:Authority:RegistryBased,
  URI:Authority:ServerBased,
  AuthorityUnparsed := URI:Authority:Unparsed,
  URI:CharClass,
  URIError := URI:Error,
  URIParser := URI:Parser,
  URI:String,
  FragmentUnparsed := URI:Fragment:Unparsed,
  QueryUnparsed := URI:Query:Unparsed,
  URI:Scheme:CurrentDoc,
  URI:Scheme:File,
  URI:Scheme:HTTP,
  URI:Scheme:Hierarchical,
  URI:Scheme:MailTo,
  URI:Scheme:Opaque,
  URI:Scheme:Memory,
  URI;

PROCEDURE Test* ();
  BEGIN
  END Test;

END LibUri.
