;;; oberon2.el --- major mode for Oberon-2 editing and compilation

;; Copyright (C) 1995-2003  Michael van Acken  <acken@informatik.uni-kl.de>
;; 
;; Version: 2.0, requires Emacs 21.2

;; This file is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.
       

;; Compatibility with 19.28 is not so important any more, and this breaks with
;; 21.3.1:
;; (if (or (> emacs-major-version 19) 
;; 	(and (= emacs-major-version 19) (> emacs-minor-version 32)))
;;     ;; workaround to avoid problems with 19.28
;;     (require 'c-mode))
;; (require 'compile)


(defvar o2-indent 2 
  "*The indentation per syntax level in Oberon-2-Mode")

(defvar o2-block-suffix t
  "*If not nil, then the commands that insert structured statements like IF, 
WHILE, etc. will add the initial keyword in a comment after the final END.")

(defvar o2-compilation-ask-about-save nil
  "*If not nil, \\[o2-compile] and \\[o2-make] ask which buffers to save before
compiling.  Otherwise all modified buffers are saved without asking.")

(defvar o2-cwd (expand-file-name command-line-default-directory)
  "*The working directory for programs (compiler, browser, make etc) run in a 
subshell.  If you want to set the default path regardless from the place where
emacs was started, please set an absolute path for o2-cwd in your .emacs file,
e.g. with (setq o2-cwd \"/users/home/my_home/oo2c/\")")

(defvar o2-concurrent-compilation nil
  "*Non-nil means that all compilation and make command run in separate
buffers.  This means that multiple commands can run concurrently.  With nil
only a single compilation \\[o2-compile] and a single make \\[o2-make] can be
active at the same time.")

(defvar o2-compile-command "oo2c -v -w "
  "*String passed to the shell to start the compilation of the current buffer.
Used by command \\[o2-compile].")

(defvar o2-make-command "oo2c --make -v "
  "*String passed to the shell to run the make programm.
Used by command \\[o2-make].")

(defvar o2-whereis-command "oowhereis "
  "*Command called with file name to retrieve the file's path.")

(defvar o2-browse-command "oob -x "
  "*Command called with module name to generate the module's exported definition
from its symbol file.")

(defvar o2-list-uses-command "oo2c --uses "
  "*Command called with declaration and module name to list all uses of the
declaration in all modules imported by the given module.")

(defvar o2-moddef-command "oob -x "
  "*Command called with module name to extract the module's exported definition
from its source code.")



;; various history lists
(defvar o2-compile-history nil)
(defvar o2-make-history nil)
(defvar o2-list-uses-history nil)
(defvar o2-module-history nil)
(defvar o2-identifier-history nil)
(defvar o2-proc-history nil)
(defvar o2-fpar-history nil)
(defvar o2-result-history nil)
(defvar o2-receiver-history nil)
(defvar o2-tbproc-history nil)
(defvar o2-receiver-type-history nil)

(defvar oberon-2-mode-hook nil
  "Function or functions to run on entry to Oberon-2 mode.")

(defvar o2-mode-syntax-table nil
  "Syntax table in use in Oberon-2-mode buffers.")

(if o2-mode-syntax-table
    ()
  (let ((table (make-syntax-table)))	
    (modify-syntax-entry ?\\ "\\" table)
    (modify-syntax-entry ?\( "()1n" table)
    (modify-syntax-entry ?\) ")(4n" table)
    (modify-syntax-entry ?* ". 23n" table)
    (modify-syntax-entry ?+ "." table)
    (modify-syntax-entry ?- "." table)
    (modify-syntax-entry ?= "." table)
    (modify-syntax-entry ?% "." table)
    (modify-syntax-entry ?< "." table)
    (modify-syntax-entry ?> "." table)
    (modify-syntax-entry ?$ "." table)
    (modify-syntax-entry ?& "." table)
    (modify-syntax-entry ?/ "." table)
    (modify-syntax-entry ?_ "." table)    
    (modify-syntax-entry ?| "." table)    
    (modify-syntax-entry ?_ "w" table)    
    (modify-syntax-entry ?\' "\"" table)
    (setq o2-mode-syntax-table table)))

(defvar o2-mode-map nil
  "Keymap used in Oberon-2 mode.")

(if o2-mode-map ()
  (let ((map (make-sparse-keymap))
	(imap (make-sparse-keymap "Oberon-2 Insert"))
	(hmap (make-sparse-keymap "Oberon-2 Hide/Show")))
    (define-key map "\t" 'o2-hippie-or-tab)
    (define-key map "\r" 'o2-newline)
    (define-key map "\177" 'backward-delete-char-untabify)
    (define-key map "\C-c\C-i" 'o2-indent-region)
    
    (define-key map "\C-c\C-c" 'o2-comment-region)
    (define-key map "\C-c\C-v" 'o2-uncomment-around-point)
    (define-key map "\C-cd" 'o2-edit-comment)
    
    (define-key map "\C-c\C-n" 'o2-next-visible-proc)
    (define-key map "\C-c\C-p" 'o2-previous-visible-proc)
    (define-key map "\C-c\C-u" 'o2-up-heading)
    (define-key map "\C-c\C-s" 'o2-show-subtree)
    (define-key map "\C-c\C-h" 'o2-hide-subtree)
    (define-key map "\C-c\C-l" 'o2-hide-leaves)
    
    (define-key map "\M-\C-h" 'o2-mark-defun)
    (define-key map "\C-c\C-f" 'o2-find-module)
    (define-key map "\C-c4\C-f" 'o2-find-module-other-window)
    (define-key map "\C-c5\C-f" 'o2-find-module-other-frame)
    (define-key map "\C-c4f" 'o2-find-module-other-window)
    (define-key map "\C-c5f" 'o2-find-module-other-frame)
    (define-key map "\C-c\C-d" 'o2-showdef-module)
    (define-key map "\C-c4\C-d" 'o2-showdef-module-other-window)
    (define-key map "\C-c5\C-d" 'o2-showdef-module-other-frame)
    (define-key map "\C-c4d" 'o2-showdef-module-other-window)
    (define-key map "\C-c5d" 'o2-showdef-module-other-frame)
    (define-key map "\C-c." 'o2-find-definition)
    (define-key map "\C-c4." 'o2-find-definition-other-window)
    (define-key map "\C-c5." 'o2-find-definition-other-frame)
    (define-key map "\C-c," 'o2-find-typebound-procedure)
    (define-key map "\C-c4," 'o2-find-typebound-procedure-other-window)
    (define-key map "\C-c5," 'o2-find-typebound-procedure-other-frame)
    (define-key map "\C-c-" 'o2-find-def-under-cursor)
    (define-key map "\C-c/" 'o2-find-def-under-cursor)
    (define-key map "\M-c" 'o2-compile)
    (define-key map "\M-\C-c" 'o2-make)
    (define-key map "\C-cu" 'o2-list-uses)
    (define-key map "\C-c`" 'next-error)
    (define-key map "\C-c'" 'next-error)
    (define-key map "\C-cg" 'o2-goto-error)

    (define-key hmap [o2-show-all] '("Show All" . o2-show-all))
    (define-key hmap [o2-hide-all] '("Hide All" . o2-hide-all))
    (define-key hmap [o2-hide-leaves] '("Hide Local Procs" . o2-hide-leaves))
    (define-key hmap [o2-show-subtree] '("Show Procedure" . o2-show-subtree))
    (define-key hmap [o2-hide-subtree] '("Hide Procedure" . o2-hide-subtree))

    (define-key map [menu-bar o2] 
      (cons "Oberon-2" (make-sparse-keymap "Oberon-2")))
    
    (define-key map [menu-bar o2 o2-hide-show] (cons "Hide / Show" hmap))
    (define-key map [menu-bar o2 o2-indent-region] 
      '("Indent Region..." . o2-indent-region))
    (define-key map [menu-bar o2 separator-eval2] '("--"))
    (define-key map [menu-bar o2 o2-goto-error] 
      '("Goto Error..." . o2-goto-error))
    (define-key map [menu-bar o2 next-error] 
      '("Next Error" . next-error))
    (define-key map [menu-bar o2 o2-make] '("Make..." . o2-make))
    (define-key map [menu-bar o2 o2-compile] '("Compile" . o2-compile))
    (define-key map [menu-bar o2 separator-eval1] '("--"))
    (define-key map [menu-bar o2 o2-find-typebound-procedure] 
      '("Find TB Proc..." . o2-find-typebound-procedure))
    (define-key map [menu-bar o2 o2-find-definition] 
      '("Find Definition..." . o2-find-definition))
    (define-key map [menu-bar o2 o2-showdef-module] 
      '("Show Module Def..." . o2-showdef-module))
    (define-key map [menu-bar o2 o2-find-module] 
      '("Find Module..." . o2-find-module))
    
    (define-key map [S-mouse-3] 'o2-find-def-under-mouse)
      
    (setq o2-mode-map map)))

(defun oberon-2-mode ()
"Major mode for editing Oberon-2 code.

Indentation:
\\[o2-newline]		make a newline, but indent like previous line
\\[o2-hippie-or-tab]		indent for o2-indent spaces; with numeric prefix indent region
\\[backward-delete-char-untabify]		convert tabs to spaces while moving backward
\\[o2-indent-region]		add/remove indentation level(s) to region [deprecated, use \\[o2-hippie-or-tab]]
The variable o2-ident determines how much spaces are inserted per indentation
level (default 2). 

Inserting Oberon-2 constructs:
\\[o2-comment-region]		comment region
\\[o2-uncomment-around-point]		uncomment text around point
\\[o2-edit-comment]		edit comment in other window

Move by procedure headings:
\\[o2-next-visible-proc]		move to next procedure
\\[o2-previous-visible-proc]		move to previous procedure
\\[o2-up-heading]		move to procedure, to which the present one is local
\\[o2-mark-defun]		put mark at end of procedure, point at the beginning

Functions to hide procedure bodies and declarations:
\\[o2-hide-subtree]		hide whole procedure
\\[o2-show-subtree]		show whole procedure again
\\[o2-hide-leaves]		hide bodies of all local procedures
\\[o2-hide-proc]	hide local declarations and the body
\\[o2-show-proc]	show local declarations and body again
\\[o2-hide-all]		hide all of buffer except procedure headings
\\[o2-show-all]		make all text in the buffer visible again

Managing source code:
\\[o2-find-module]		find file to a given module name
\\[o2-find-module-other-window]		like \\[o2-find-module], but display in another window
\\[o2-find-module-other-frame]		like \\[o2-find-module], but display in another frame
\\[o2-showdef-module]		generate and display the definition of a module
\\[o2-showdef-module-other-window]		like \\[o2-showdef-module], but display in another window
\\[o2-showdef-module-other-frame]		like \\[o2-showdef-module], but display in another frame
\\[o2-find-definition]		display (same window) the definition of an identifier
\\[o2-find-definition-other-window]		display (other window) the definition of an identifier
\\[o2-find-definition-other-frame]		display (other frame) the definition of an identifier
\\[o2-find-def-under-cursor]		display & blink to declaration of ident under cursor
\\[o2-find-typebound-procedure]		display (same window) a procedure bound to a given type
\\[o2-find-typebound-procedure-other-window]		display (other window) a procedure bound to a given type
\\[o2-find-typebound-procedure-other-frame]		display (other frame) a procedure bound to a given type
\\[o2-list-uses]		step through all uses of a declaration with \\[next-error]
All the above functions accept a module's alias name (as declared in the 
current buffers IMPORT list) instead of the real module name. For further
information on '\\[o2-find-definition]' or '\\[o2-find-typebound-procedure]' use \\[describe-key].
Any of the above functions that displays files in another window or frame won't
change the selected window if the `C-u' prefix is set.  Example: `C-u C-c 4 .'
will display the source of the definition of the given identifier in another
window, but the current window stays selected and point stays at the current
position.
`\\[o2-find-def-under-mouse]' (ie, shift with right mouse button) will, similar to `\\[o2-find-def-under-cursor]',
invoke `C-u \\[o2-find-definition-other-window]' with the qualified identifier under the mouse cursor as 
argument and blink to the found position.

Compiling:
\\[o2-compile]		compile current buffer
C-u \\[o2-compile]		prompt for compile command and compile current buffer
\\[o2-make]		run a make on a module
\\[next-error]		display the next error
\\[o2-goto-error]		prompt for module and error position, goto position

Searches will distinct cases. Delete converts tabs to spaces as it moves back. 
Emacs won't use tab characters. 
\\[indent-for-comment] will indent or create a comment on the current line at column 41 
(default).
The Oberon-2 menu can also be invoked with `C-mouse-3' (ie, control with right
mouse button) since GNU Emacs 19.29."
  (interactive)
  (kill-all-local-variables)
  (setq selective-display t)
  (setq indent-tabs-mode nil)
  (use-local-map o2-mode-map)
  (setq major-mode 'oberon-2-mode)
  (setq mode-name "Oberon-2")  
  (set (make-local-variable 'comment-column) 41)
  (set-syntax-table o2-mode-syntax-table)
  (set (make-local-variable 'paragraph-start) (concat "^$\\|" page-delimiter))
  (set (make-local-variable 'paragraph-separate) paragraph-start)
  (set (make-local-variable 'paragraph-ignore-fill-prefix) t)
  (set (make-local-variable 'require-final-newline) t)
  (set (make-local-variable 'comment-start) "(* ")
  (set (make-local-variable 'comment-end) " *)")
  (set (make-local-variable 'comment-start-skip) "(\\*+ *")
  (set (make-local-variable 'comment-indent-function) 'c-comment-indent)
  (set (make-local-variable 'parse-sexp-ignore-comments) nil)
  (set (make-local-variable 'hippie-expand-try-functions-list)
       '(try-expand-dabbrev 
         try-expand-dabbrev-all-buffers
         try-expand-dabbrev-from-kill))
  (setq case-fold-search nil)

  ; prepare compilation package to work with oo2c
  (add-hook 'compilation-mode-hook 'o2-compilation-mode-hook)

  ; add fontifying rules for font-lock-mode
  (make-local-variable 'font-lock-defaults)
  (setq font-lock-defaults
	'((nil
	   oberon-2-font-lock-keywords-1 
	   oberon-2-font-lock-keywords-2
	   oberon-2-font-lock-keywords-3)
	  nil nil nil 
	  nil  ; beginning-of-defun 
	  (font-lock-comment-start-regexp . "(\\*")))
  
  ; set hooks for imenu package; note: imenu is disabled by default
  (setq imenu-prev-index-position-function
        'o2-imenu-prev-index-position-function)
  (setq imenu-extract-index-name-function
        'o2-imenu-extract-index-name-function)
  (setq imenu-create-index-function 
        'o2-imenu-default-create-index-function)

  (run-hooks 'oberon-2-mode-hook))

(defun o2-compilation-mode-hook ()
;; This is called when compilation-mode-hook is run.  The mode-specific 
;; variables are only set if the variable o2-running-compile is not void, i.e.
;; if o2-compile or o2-make are running.
  (cond ((boundp 'o2-running-compile)
	 (set (make-local-variable 'compilation-finish-function)
	      (lambda (buffer exit) (o2-fit-to-window buffer))))))


(defun o2-interactive-strings (strings &optional barf-if-read-only)
;; STRINGS is a list of '(prompt . history) pairs, where prompt is a string
;; and history the history list for this prompt (or nil, if the default list
;; should be used).
  (if barf-if-read-only (barf-if-buffer-read-only))
  (mapcar (lambda (element)
	    (read-from-minibuffer (car element) nil nil nil (cdr element)))
	  strings))

(defun o2-newline ()
  "Insert a newline and indent following line like previous line."
  (interactive)
  (let ((prev-indent (current-indentation)))
    (newline)
    (if (looking-at "[ \t]+$")
	(delete-region (match-beginning 0) (match-end 0)))
    (let ((curr-indent (current-indentation)))
      (if (<= curr-indent prev-indent)
	  (indent-to-column (- prev-indent curr-indent)))
      (let* ((end (progn (end-of-line) (point)))
	     (start (progn (beginning-of-line) (point))))
	(untabify start end)
	(forward-char prev-indent)))))

(defun o2-tab ()
  "Indent to next tab stop."
  (interactive)
  (let* ((curr-indent (current-indentation))
	 (new-indent (* (1+ (/ curr-indent o2-indent)) o2-indent))
	 (diff (- new-indent curr-indent)))
    (if (> diff 0)
	(insert-char ?\040 diff))))

(defun o2-electric-tab (&optional level)
  "Ident current line one more level.  A numeric argument LEVEL means indent 
rigidly all the lines appearing in the current region by LEVEL.  A positive 
argument adds indentation, a negative argument removes it.  The relative 
indentation among the lines of the region is preserved."
  (interactive "P")
  (if (numberp level)
      ;; If numeric arg, then indent all lines beginning in current region
      (indent-code-rigidly (save-excursion
			     (goto-char (region-beginning))
			     (beginning-of-line)
			     (point))
			   (region-end) 
			   (* level o2-indent))
    ;; No arg supplied
    (o2-tab)))

(defun o2-hippie-or-tab (arg)
  "If point is before or on the first non-whitespace character of a line,
call o2-electrict-tab.  Otherwise try to expand the word before point."
  (interactive "P")
  (if (<= (point) (save-excursion (back-to-indentation) (point)))
      (o2-electric-tab arg)
    (hippie-expand arg)))

(defun o2-what-line ()
  (save-restriction
    (widen)
    (save-excursion
      (beginning-of-line)
      (1+ (count-lines 1 (point))))))

(defun o2-indent-region (start end arg)
  "Add/remove indentation to/from the region. Each line will be indented ARG more
levels respectively less levels if ARG negative."
  (interactive "*r\nnIndent: ")
  (let* ((start-line (progn (goto-char start) (o2-what-line)))
	 (end-line (progn (goto-char end) (backward-char 1) (o2-what-line)))
	 (spaces (* arg o2-indent))
	 (current-line start-line)
	 count)
    (untabify (progn (goto-line start-line) 
		     (point))
	      (progn (goto-line end-line)
		     (end-of-line)
		     (point)))
    (goto-line start-line)
    (while (<= current-line end-line)
      (setq count spaces)
      (cond ((> arg 0)
	     (insert-char ?\040 count))
	    ((< arg 0)
	     (while (and (< count 0)
			 (eq (following-char) ?\040))
	       (delete-char 1)
	       (setq count (1+ count)))))
      (next-line 1)
      (beginning-of-line)
      (setq current-line (1+ current-line)))
    (goto-line start-line)
    (push-mark (point) t)
    (goto-line (1+ end-line))))


;;; Here starts the code for the modified outline functions:

(defconst o2-proc-regexp "\\([ \t]*\\)PROCEDURE[ \t]*\\(\\([-*+]\\|([a-zA-Z0-9 \t:(,)]+)\\)[ \t]*\\)?\\(\\[[^\\]*\\][ \t]*\\)?"
;; Ugly. This should match any procedure header (including type-bound 
;; procedures) until just before the actual procedure name.  It won't
;; match a procedure forward declaration!
  "Regular expression to match the beginning of a procedure heading.")

(defun o2-indentation-level ()
;; Return the depth to which a procedures is nested.
;; Point must be at the beginning of a the heading, otherwise 0 is returned. 
;; The first \(...\) of o2-proc-regexp have to be put around the indentation.
  (save-excursion
    (beginning-of-line)
    (if (looking-at o2-proc-regexp)
	(/ (- (match-end 1) (match-beginning 1)) o2-indent)
      0)))

(defun o2-next-visible-proc (arg)
  "Move to the next visible procedure heading.
With argument, repeats or move backward if negative."
  (interactive "p")
  (let ((curr-point (point)))
    (if (< arg 0)
	(beginning-of-line)
      (end-of-line))
    (if (re-search-forward (concat "^\\(" o2-proc-regexp "\\w+\\)") nil 'move arg)
	(goto-char (match-end 2))
      (goto-char curr-point)		; restore cursor position
      (error "No further procedures."))))

(defun o2-previous-visible-proc (arg)
  "Move to the previous procedure heading.
With argument, repeats or move forward if negative."
  (interactive "p")
  (o2-next-visible-proc (- arg)))

(defun o2-next-proc ()
;;  Skip forward to just before the next (possibly invisible) procedure heading.
  (if (re-search-forward (concat "[\n\^M]\\(" o2-proc-regexp "\\w+\\)")
			 nil 'move)
      (goto-char (match-beginning 1))))

(defun o2-on-heading-p ()
;; Return T if point is on a header line.
  (save-excursion
    (if (re-search-backward "[\n]" nil 'move)
	(forward-char))
    (looking-at (concat "^" o2-proc-regexp "\\w+"))))

(defun o2-back-to-heading (&optional consider-nesting)
;; Move to previous procedure heading, or to beginning of this line if it is a
;; heading.
;; If consider-nesting is not nil local procedures before point will be skipped.
  (if (re-search-backward "[\n]" nil 'move)
      (forward-char))
  (or (o2-on-heading-p)
      (if consider-nesting	  
	  (let (exit result)
	    (while (and (not exit)
			(re-search-backward (concat "\\(END[ \t]+\\(\\w+\\)[ \t]*;\\|" o2-proc-regexp "\\w+\\)") nil 'move))
	      (if (match-beginning 2)
		  (let ((name (buffer-substring (match-beginning 2) (match-end 2))))
		    (if (re-search-backward (concat o2-proc-regexp name) nil 'move)
			t
		      (error "Can't find start of procedure %s." name)))
		(setq exit t)
		(beginning-of-line)
		(setq result (point))))
	    result)
	(re-search-backward (concat "^\\(" o2-proc-regexp "\\w+\\)") nil 'move))))

(defun o2-up-heading (arg)
  "Move to the procedure heading to which the present procedure is local.
With argument, move up ARG levels."
  (interactive "p")
  (o2-back-to-heading)
  (if (eq (o2-indentation-level) 0)
      (error "Uppermost level."))
    (while (and (> (o2-indentation-level) 0)
		(> arg 0)
		(not (bobp)))
      (let ((present-level (o2-indentation-level)))
	(while (>= (o2-indentation-level) present-level)
	  (o2-previous-visible-proc 1))
	(setq arg (1- arg)))))



(defun o2-search (pattern error-msg)
; Does a re-search-forward for pattern, signals error (with error-msg)
; if a occurence is found.
  (if (not (re-search-forward pattern nil t))
      (error error-msg)))

(defun o2-proc-end-delimiter (name)
  (concat "END[ \t]+" name "[ \t]*;"))

(defun o2-get-procedure ()
;; pre: point is inside a procedure (i.e. somewhere between the line of 
;;   procedure heading (inclusive) and the ';' following the procedure end 
;;   delimiter (inclusive).
;;   An error is signaled if point is outside any procedure.
;; post: result is a n-tuple with the elements
;;   name of the procedure
;;   end formal pars (pos directly following the final ;)
;;   end of CONST/TYPE/VAR declaration sequence (only if local procs exist, 
;;     nil otherwise) 
;;   end of local procedure declarations (only if local procs exist, nil 
;;     otherwise) 
;;   end of procedure (char following the final ;)
;;   export mark ("*" or "")
;;   formal parameters (string from initial parenthesis upto trailing ;)
  (save-excursion
    (let ((curr-point (point)))
      (if (o2-back-to-heading 'consider-nesting)
	  (let ((formal-pars "") (export-mark "")
		proc-name end-of-heading end-of-proc end-of-decl end-of-local)
	    (looking-at (concat o2-proc-regexp "\\(\\w+\\)[ \t\n]*\\(\\*[ \t\n]*\\)?"))
	    ; store export mark, if one exists
	    (if (match-beginning 6)
		(setq export-mark (buffer-substring (match-beginning 6)
						    (1+ (match-beginning 6)))))
	    (setq proc-name (buffer-substring (match-beginning 5) (match-end 5))) ; the name of the procedure
	    (goto-char (match-end 0))
	    (if (looking-at "(")
		(let ((start (point)))
		  (o2-search ")\\([ \t\n]*:[ \t\n]*[a-zA-Z0-9.]+\\)?[ \t\n]*;"
			     "no end of formal parameters") ; skip formal parameters and result
		  (setq formal-pars (buffer-substring start (1- (point)))))
	      (re-search-forward ";"))
	    (setq end-of-heading (point))	; this is the pos directly following the final ';' of the procedure heading
	    (o2-search (o2-proc-end-delimiter proc-name)
		       (concat "no end of procedure " proc-name))
	    (setq end-of-proc (point))
	    (if (> curr-point end-of-proc)
		(error "Point is not inside a procedure."))		
	    (goto-char end-of-heading)
	    (if (re-search-forward (concat "^" o2-proc-regexp "\\w+") end-of-proc t)
		(progn
		  (setq end-of-decl (- (match-beginning 0) 1))
		  (goto-char end-of-proc)
		  (re-search-backward (o2-proc-end-delimiter "\\w+") end-of-decl t 2)
		  (setq end-of-local (point))))
	    (list proc-name end-of-heading end-of-decl 
		  end-of-local end-of-proc export-mark formal-pars))
	(error "Point is not inside a procedure.")))))

(defun o2-flag-region (from to flag)
;; Hides or shows lines from FROM to TO, according to FLAG. If FLAG is `\\n' 
;; (newline character) then text is shown, while if FLAG is `\\^M' (control-M) 
;; the text is hidden.
  (let (buffer-read-only		; allow modification of buffer
	(modp (buffer-modified-p)))	; but keep the 'modified' flag
    (unwind-protect
        (subst-char-in-region from to
			      (if (= flag ?\n) ?\^M ?\n)
			      flag t)
     (set-buffer-modified-p modp))))	; restore flag

(defun o2-modify-proc (flag)
; Hides/shows procedure the point is in.
; Writes an error if point is not inside a procedure.
  (let ((proc-extent (o2-get-procedure)))
    (if (not (nth 2 proc-extent))	
	(o2-flag-region (nth 1 proc-extent) (nth 4 proc-extent) flag)
      (o2-flag-region (nth 1 proc-extent) (nth 2 proc-extent) flag)
      (o2-flag-region (nth 3 proc-extent) (nth 4 proc-extent) flag))))
	    
(defun o2-hide-proc ()
  "Hide the body directly following this heading."
  (interactive)
  (o2-modify-proc ?\^M))

(defun o2-show-proc ()
  "Show the body directly following this heading."
  (interactive)
  (o2-modify-proc ?\n))


(defun o2-hide-region-body (start end)
;; Hide all body lines in the region, but not headings.
  (save-excursion
    (save-restriction
      (narrow-to-region start end)
      (goto-char (point-min))
      (o2-next-proc)
      (while (not (eobp))
	(o2-modify-proc ?\^M)
	(o2-next-proc)))))

(defun o2-hide-all ()
  "Hide all of buffer except headings."
  (interactive)
  (o2-hide-region-body (point-min) (point-max)))

(defun o2-show-all ()
  "Show all of the text in the buffer."
  (interactive)
  (o2-flag-region (point-min) (point-max) ?\n))

(defun o2-hide-subtree ()
  "Hide everything after this heading at deeper levels."
  (interactive)
  (let ((proc-extent (o2-get-procedure)))
    (o2-flag-region (nth 1 proc-extent) (nth 4 proc-extent) ?\^M)))

(defun o2-show-subtree ()
  "Show everything after this heading at deeper levels."
  (interactive)
  (let ((proc-extent (o2-get-procedure)))
    (o2-flag-region (nth 1 proc-extent) (nth 4 proc-extent) ?\n)))

(defun o2-hide-leaves ()
  "Hide all bodies after this heading at deeper levels."
  (interactive)
  (let ((proc-extent (o2-get-procedure)))
    (o2-hide-region-body (nth 1 proc-extent) (nth 4 proc-extent))))

(defun o2-get-procedure-at-point ()
;; If point is inside a procedure declaration a list as in o2-get-procedure is 
;; returned with the starting point of the procedure declaration appended to 
;; it.  Otherwise result is nil.
  (save-excursion
    (let* (result
	   (pattern (concat "\\(" o2-proc-regexp "\\w+\\)\\|\\(" (o2-proc-end-delimiter "\\([a-zA-Z0-9]+\\)") "\\)")))
      (beginning-of-line)
      (if (o2-on-heading-p)
	  (append (o2-get-procedure) (list (point)))      
	(while (and (not result) (not (bobp)))
	  (if (re-search-backward pattern nil 'move)
	      (if (match-beginning 1)
					; found procedure heading
		  (let ((start (match-beginning 1)))
		    (setq result (append (o2-get-procedure) (list start))))
					; found end of procedure
		(let ((proc-name (buffer-substring (match-beginning 7) 
						   (match-end 7))))
		  (re-search-backward (concat "^" o2-proc-regexp proc-name 
					      "[ \t* ;(]") 
				      nil 'move)))))
	result))))

			 


(defun o2-read-import ()
;; If a module import is following, it's elements are returned in the form (alias-name true-name).
;; Otherwise the functions result is nil.
  (if (re-search-forward "\\(;\\)\\|\\(\\w+\\(:\\(\\w+\\)\\)*\\)\\([ \t\n]*:=[ \t\n]*\\(\\w+\\(:\\w+\\)*\\)[ \t\n]*\\)?[,;]" nil t)
      (prog1
	  (cond ((match-beginning 1)	; end of import list (';') reached
		 nil)
		((match-beginning 5)	; there exists an ':= xxx' branch
		 (cons
		  (buffer-substring (match-beginning 2) (match-end 2))
		  (buffer-substring (match-beginning 6) (match-end 6))))
		(t			; only the plain module name is imported
		 (cons
		  (if (match-beginning 4)
		      (buffer-substring (match-beginning 4) (match-end 4))
		    (buffer-substring (match-beginning 2) (match-end 2)))
		  (buffer-substring (match-beginning 2) (match-end 2)))))
	(backward-char 1))	
    nil))

(defun o2-import-list ()
;; Scans the complete IMPORT list and gives the imported modules in a list like
;; "((AliasA . ModuleA) (AliasB . ModuleB) ...)". If the keyword IMPORT
;; can not be found, nil is returned. If a module is not imported via an alias
;; name, the alias and the module name are identic.
  (save-excursion
    (let (import-list 
	  read-names
	  (data (match-data)))
      (unwind-protect
	  (progn
	    (goto-char (point-min))
	    (if (re-search-forward "[ \t\n]+IMPORT[ \t\n]+" nil t)
		(progn
		  (setq read-names (o2-read-import))
		  (while read-names		; not nice, but should work
		    (setq import-list (cons read-names import-list))
		    (setq read-names (o2-read-import)))))
	    import-list)
	(store-match-data data)))))

(defun o2-module-name (module-name)
;; If module-name is an alias of an imported module, the true module name is
;; returned, otherwise simply module-name. 
  (let ((alias (cdr (assoc module-name (o2-import-list)))))
    (if alias alias module-name)))

(defun o2-qualified-import (qualident)
;; Accepts a (possibly qualified) identifier (see Oberon Report), and separates
;; it into module and ident part. If the module name is given (qualident is 
;; something 'M.ident') the module name is extracted and possibly converted if
;; it is an alias from the IMPORT list. The result is (module-name . ident).
;; If no module is given (qualident is "ident") the function returns (nil . 
;; ident).  If the qualident contains illegal characters it will result to nil.
  (if (string-match "^\\(\\(\\w+\\) *\\. *\\)?\\(\\w+\\)$" qualident)
      (cons
       (if (match-end 1) (o2-module-name (substring qualident 
						    (match-beginning 2) 
						    (match-end 2))))
       (substring qualident (match-beginning 3) (match-end 3)))
    (error "Not legal qualified identifier.")))



(defun o2-switch-to (location &optional other save-mark)
; Note: This function accesses the variable current-prefix-arg to decide
; if to select another window or not.  This is not very `clean', I admit.
  (if (and save-mark
	   (not (memq other '(other-window other-frame)))
	   (eq (current-buffer) (car location)))
      (progn
	(push-mark nil t)
	(message "Mark saved where search started")))
  (let ((old-window (selected-window)))
    (if (eq other 'other-window)
	(switch-to-buffer-other-window (car location))
      (if (eq other 'other-frame)
	  (switch-to-buffer-other-frame (car location))
	(switch-to-buffer (car location))))
    (if (cdr location)
	(set-window-point (selected-window) (cdr location)))
    (if current-prefix-arg
	(select-window old-window))))

(defun o2-set-to (location)
;; location is a list (buffer position)
  (set-buffer (car location))
  (goto-char (cdr location)))


    
(defun o2-execute-command (command)
  (let ((shell shell-file-name)
	(default-directory o2-cwd))
    (call-process shell nil t t "-c" (concat "exec " command))))

(defun o2-locate-file (file-name &optional extension no-error)
;; Uses the command oowhereis to find the absolute path of files.
;; If extension is non nil and the name does not end with an extension,
;; the ending '.<extension>' is automatically appended. 
  (save-excursion
    (if (and extension
	     (not (string-match "\\.\\w+" file-name)))
	(setq file-name (concat file-name "." extension)))
    (set-buffer (get-buffer-create "*command execution*"))
    (erase-buffer)
    (o2-execute-command (concat o2-whereis-command file-name))
    (goto-char (point-min))
    (if (re-search-forward (concat "^.*" (o2-module-to-file file-name 'no-mod)
				   "$") 
			   nil t)
	(expand-file-name (buffer-substring (match-beginning 0) (match-end 0))
			  o2-cwd)
      (if no-error
	  nil
	(error "Cannot locate file %s." file-name)))))
  
(defun o2-module-to-file (module-name &optional no-mod)
  (save-match-data
    (let ((fn "")
	  (start 0))
      (while (string-match ":" module-name start)
	(setq fn (concat fn
			 (substring module-name start (match-beginning 0))
			 "/")
	      start (match-end 0)))
      (concat fn
	      (substring module-name start)
	      (if no-mod "" ".Mod")))))

(defun o2-find-module-noselect (module-name)
;; Calls the external command oowhereis with the parameter modulename.Mod and 
;; reads it (if necessary) into a buffer.  The buffer will be returned (but not
;; displayed).  If no such file exists, a error message will be printed.
  (find-file-noselect (o2-locate-file (o2-module-name module-name) "Mod")))

(defun o2-find-module (module-name)
"Call the external command oowhereis with the parameter 'MODULE-NAME.Mod' to 
find the associated file. If no such file exists, a error message will be
printed."
  (interactive (o2-read-qualident "Module name: " 'just-module 
				  'o2-module-history))
  (o2-switch-to (cons (o2-find-module-noselect module-name) nil)))

(defun o2-find-module-other-window (module-name)
"Like o2-find-module, but display the file in another window."
  (interactive (o2-read-qualident "Module name: " 'just-module
				  'o2-module-history))
  (o2-switch-to (cons (o2-find-module-noselect module-name) nil) 'other-window))

(defun o2-find-module-other-frame (module-name)
"Like o2-find-module, but display the file in another frame."
  (interactive (o2-read-qualident "Module name: " 'just-module
				  'o2-module-history))
  (o2-switch-to (cons (o2-find-module-noselect module-name) nil) 'other-frame))

(defun o2-showdef-module-noselect (module-name)
;; Call the external command o2-browse-command which extracts the interface of
;; a module out of a given symbol file.  The buffer gets the name 
;; *modulename.Def* and is not selected.
  (save-excursion
    (setq module-name (o2-module-name module-name))
    (let* ((defname (concat "*" module-name ".Def*"))
	   (buffer (get-buffer-create defname)))
      (set-buffer buffer)
      (oberon-2-mode)
      (let ((buffer-read-only nil))
	(erase-buffer)
	(if (/= 0
		(o2-execute-command (concat o2-moddef-command module-name)))
	    (o2-execute-command (concat o2-browse-command module-name)))
	(setq buffer-read-only t)
      (list buffer)))))

(defun o2-showdef-module (module-name)
"Call the external command o2-browse-command which extracts the interface of 
the module MODULE-NAME out of a given symbol file. The buffer gets the name
*MODULE-NAME.Def*."
  (interactive (o2-read-qualident "Module name: " 'just-module
				  'o2-module-history))
  (o2-switch-to (o2-showdef-module-noselect module-name))
  (oberon-2-mode))

(defun o2-showdef-module-other-window (module-name)
"Like o2-showdef-module, but display the file in another window."
  (interactive (o2-read-qualident "Module name: " 'just-module
				  'o2-module-history))
  (o2-switch-to (o2-showdef-module-noselect module-name) 'other-window))

(defun o2-showdef-module-other-frame (module-name)
"Like o2-showdef-module, but display the file in another frame."
  (interactive (o2-read-qualident "Module name: " 'just-module
				  'o2-module-history))
  (o2-switch-to (o2-showdef-module-noselect module-name) 'other-frame))



(defun o2-declarationp ()
;; Is t iff point is inside the declaration part of a module or procedure.
  (save-excursion
    (if (save-excursion (re-search-backward "[^\n]*DEFINITION " nil t))
	(not (re-search-backward "PROCEDURE[ \t\n]+\\w+" nil t))      
      (and (re-search-backward 
	    (concat "\\(PROCEDURE\\|MODULE\\|DEFINITION\\)\\|BEGIN\\|" (o2-proc-end-delimiter "\\w+"))
	    nil 'move)
	   (match-beginning 1)))))

(defun o2-no-recordp ()
;; Is t iff point is not inside a record type declaration.
  (save-excursion
    (let (terminate result (end-count 0))
      (while (and (not terminate)
		  (not result)
		  (re-search-backward 
		   "\\W\\(MODULE\\|PROCEDURE\\|CONST\\|TYPE\\|VAR\\)\\|RECORD\\|\\(END\\)\\W"
		   nil 'move))
	(cond 
	 ((match-beginning 1) (setq result t))
	 ((match-beginning 2) (setq end-count (1+ end-count)))
	 ((= end-count 0)     (setq terminate t))
	 (t                   (setq end-count (1- end-count)))))
      result)))

(defun o2-find-local-declaration (ident pos)
;; Searches the current buffer for the position of identifier's ident 
;; declaration valid at position pos. The result is the starting point of the 
;; declaration or nil if it cannot be found.  IDENT cannot be a qualified 
;; identifier.
;; This function will not merely do a backward search, but will scan only the 
;; relevant declaration scopes that may contain the declaration it is searching
;; for. It cannot find record fields or type-bound procedures. 
  (save-excursion
    (goto-char pos)
    (let* (terminate
	   (procpattern (concat "PROCEDURE[ \t-*+^]+" ident "[ \t* ;(]"))
	   (endpattern (o2-proc-end-delimiter "\\(\\w+\\)"))
	   (pattern (concat "\\W" 
			    "\\(\\(" procpattern "\\)"
			    "\\|\\(" "\\(\\w+[ \t\n*-]*,[ \t\n]*\\)*"
                                ident "\\([ \t\n*-]*,[ \t\n]*\\w+\\)*" 
                                "[ \t*-]*:[^=]\\)"
			    "\\|\\(" ident "[ \t*-]*=\\)"
			    "\\|\\(" endpattern "\\)\\)")))
      (while (not (or terminate (bobp)))
	(if (re-search-backward pattern nil 'move)
	    (cond
	     ((or (match-beginning 2)
		  (and (match-beginning 3) (o2-declarationp) (o2-no-recordp))
		  (and (match-beginning 6) (o2-declarationp)))
	      (setq terminate (1+ (point))))
	     ((match-beginning 7)
	      (goto-char (match-beginning 7))
	      (looking-at endpattern)	; include identifier parts beyond current point
	      (let ((proc-name (buffer-substring (match-beginning 1) (match-end 1))))		
		(if (and (re-search-backward (concat o2-proc-regexp proc-name "\\W") nil 'move)  
			 (string= proc-name ident)
			 (> 1 (- (match-end 1) (match-beginning 1))))
		    (setq terminate (match-end 1))))))))
      terminate)))

(defun o2-default-qualident (&optional just-module)
;; Scan the buffer at (and before) the current point for a qualified 
;; identifier.  Result is this qualified identifier (or the module if 
;; just-module isn't nil) or nil if none is found.
  (save-excursion
    (let (start-pos
	  (curr-point (point)))
      (beginning-of-line)
      (while (and (re-search-forward "[a-zA-Z]\\w*\\( *\\. *\\w+\\)*" nil t)
		  (<= (match-beginning 0) curr-point))
	(setq start-pos (match-beginning 0)))
      (if start-pos
	  (progn
	    (goto-char start-pos)
	    (if (and (not just-module) (looking-at "\\(\\w+\\) *\\. *\\w+"))
		(if (assoc (buffer-substring (match-beginning 1) (match-end 1)) 
			   (o2-import-list))
		    (buffer-substring (match-beginning 0) (match-end 0))
		  (buffer-substring (match-beginning 1) (match-end 1)))
	      (looking-at "\\w+")
	      (buffer-substring (match-beginning 0) (match-end 0))))))))
	      

(defun o2-read-qualident (string &optional just-module history)
;; Prompt for a qualident, offer the ident under point (or before) as default.
;; If history is non-nil, it is used as history list, otherwise the default
;; minibuffer-history is used.
  (let* ((default (o2-default-qualident just-module))
	 (spec (read-from-minibuffer
		(if default
		    (format "%s(default %s) " string default)
		  string)
		nil
		nil
		nil
		history))
	 (result (if (string= spec "")
		     default
		   spec)))
    ; update history manually
    (if (and history 
	     (not (string= (car (eval history)) result)))
	(set history (cons result (eval history))))
    (list result)))

(defun o2-limit-to-decl (pos limit-to-decl)
;; If limit-to-decl is non nil, return minimum of position of first procedure 
;; and pos, otherwise return pos.
  (if limit-to-decl
      (min
       (save-excursion
	 (goto-char (point-min))
	 (re-search-forward (concat o2-proc-regexp "\\w+") nil 'move)
	 (point))
       pos)
    pos))
	 
(defun o2-find-definition-noselect (qualident &optional limit-to-decl)
;; Find the definition of a given qualified identifier: result is (buffer . 
;; point).  If a buffer different from the current one has to be searched, it 
;; will not get selected.
;; There are three flavours:
;; 1. No module name is given. The function tries to locate the definition of
;;    the identifier in the current module.
;;    The search may fail on forward declared pointer base types. If the search
;;    at the current position fails, it is repeated with the position set to 
;;    the end of the local declaration block (if possible).
;; 2. A module name is given and the sources of the module are available.
;;    The module is loaded and the cursor jumps to the position of the 
;;    declaration.
;; 3. If nor 1. nor 2. holds, then the definition of the module is extracted 
;;    from it's symbol file and used instead.
;; 4. If you entered a module name and 2. and 3. failed, then you will get the 
;;    error message 'cannot find file xxx.Sym'.
;; limit-to-decl will bound the search for the declaration part (everything 
;; before the first normal procedure) of the module
  (let* 
      ((analyze     (o2-qualified-import qualident))
       (ident       (cdr analyze))
       (module-name (car analyze))
       (module-path (if module-name (o2-locate-file module-name "Mod" 'no-error)))
       (symbol-path (if (and module-name (not module-path)) (o2-locate-file module-name "Sym")))
       (buffer
	(cond
	 (symbol-path			; module name given, no module sources, symbol file exists
	  (car (o2-showdef-module-noselect module-name)))
	 (module-path			; module name given, module sources exist
	  (o2-find-module-noselect module-name))
	 (t
	  (current-buffer)))))
    (save-excursion
      (set-buffer buffer)
      (save-excursion
	(let ((location
	       (o2-find-local-declaration 
		ident 
		(o2-limit-to-decl (if (or symbol-path module-path) (point-max) (point)) limit-to-decl))))
	  ; second try, if nothing is found and search is local
	  (if (and (not location)
		   (not module-name)
		   (re-search-forward "^\\W*\\(BEGIN\\|END[ \t\n]+\\w+\\|PROCEDURE\\)\\W" nil 'move))
	      (setq location
		    (o2-find-local-declaration 
		     ident 
		     (o2-limit-to-decl (point) limit-to-decl))))
	  (if location 
	      (cons buffer location)
	    (error "Can't find declaration of %s" ident)))))))

(defun o2-find-definition (qualident &optional limit-to-decl)
"Find and display the definition of QUALIDENT.
If a module name is given (like 'M.ident') the module's source code (or the
definition, if the sources are not available) is loaded and searched for the
identifier in it's global scope. If just the identifier is given, the current
buffer will be searched for the definition of the identifier valid at the
current cursor position according to Oberon-2's scope rules.
If QUALIDENT is a null string, the identififier on or before the point (if 
there is any on the current line) will be used." 
;; limit-to-decl will bound the search for the declaration part (everything
;; before the first normal procedure) of the module.
  (interactive (o2-read-qualident "(qualified) Identifier: " nil
				  'o2-identifier-history))
  (o2-switch-to (o2-find-definition-noselect qualident limit-to-decl)
		nil 'save-mark))
	
(defun o2-find-definition-other-window (qualident &optional limit-to-decl)
  "Like o2-find-definition, but file will be displayed in another window."
;; limit-to-decl will bound the search for the declaration part (everything
;; before the first normal procedure) of the module.
  (interactive (o2-read-qualident "(qualified) Identifier: " nil
				  'o2-identifier-history))
  (o2-switch-to (o2-find-definition-noselect qualident limit-to-decl) 
		'other-window 'save-mark))
	
(defun o2-find-definition-other-frame (qualident &optional limit-to-decl)
  "Like o2-find-definition, but file will be displayed in another frame."
;; limit-to-decl will bound the search for the declaration part (everything
;; before the first normal procedure) of the module.
  (interactive (o2-read-qualident "(qualified) Identifier: " nil
				  'o2-identifier-history))
  (o2-switch-to (o2-find-definition-noselect qualident limit-to-decl) 
		'other-frame 'save-mark))

	
(defun o2-find-def-blink (new-window message)
  (let ((qualident (o2-default-qualident)))
    (if qualident
	(save-excursion
	  (o2-find-definition-other-window qualident)
	  (sit-for (if (boundp 'blink-matching-delay)
		       blink-matching-delay
		     1))
	  (select-window new-window))
      (error "%s not on qualified identifier." message))))

(defun o2-find-def-under-mouse (event)
  "Find definition of qualified identifier under the mouse and display it in
another window."
  (interactive "e")
  (let* ((start (event-start event))
	 (buffer (window-buffer (car start))))
    (set-buffer buffer)
    (goto-char (nth 1 start))
    (sit-for 0)
    (o2-find-def-blink (car start) "Mouse")))
	 
(defun o2-find-def-under-cursor ()
  "Find definition of qualified identifier under the cursor and display it in
another window."
  (interactive)
  (o2-find-def-blink (selected-window) "Cursor"))
	 
	 
  
(defun o2-get-pointer-to (record-name)
;; Finds the name of the first declared data type 'POINTER TO record-name' in 
;; the modules declaration block, or nil if the search fails.
  (save-excursion
    (goto-char (point-min))
    (if (re-search-forward (concat "\\W\\(\\w+\\)[ \t\n*-]*=\\s *POINTER\\s +TO\\s +" record-name "\\W") 
			   (o2-limit-to-decl (point-max) t) t)
	(buffer-substring (match-beginning 1) (match-end 1))
      (error "Can't find any declaration of type 'POINTER TO %s'." record-name))))

(defun o2-find-typebound-procedure-noselect (receiver proc-name &optional prev-path conv-to-pointer)
;; Takes a receiver data type (possibly qualified) and the name of a type-bound
;; procedure. It will find the procedure bound to the receiver. If the actual
;; procedure in use is inherited from a base type, this base type's procedure 
;; will be located. In the last line of the display the search path is printed.
;; The optional arguments mean: 
;;   prev-path is the search path until now
;;   conv-to-pointer controls if the receiver has to be modified from the passed record type 
;;                   to the corresponding pointer type.
;; The whole search process won't effect the display.
  (save-excursion
    (if (not prev-path) (setq prev-path ""))
    (goto-char (o2-limit-to-decl (point-max) t))
    (let* ((location (o2-find-definition-noselect receiver 'limit-to-decl))
	   (receiver (o2-qualified-import receiver))
	   (module (car receiver))
	   (ident (cdr receiver))
	   record 
	   base-type)
      (o2-set-to location)
      (save-excursion
        ; first we find the record type the procedure is bound to and generate the receiver type (if necessary)
	(if conv-to-pointer
	    (progn				; get the pointer type to the given record type
	      (setq record ident)
	      (setq ident (o2-get-pointer-to record)))
	  (if (looking-at (concat ident "[ \t\n*]*=\\s *POINTER\\s +TO\\s +\\(\\w+\\);"))
	      (progn (setq conv-to-pointer t) ; we have a pointer, now we extract the record type
		     (setq record (buffer-substring (match-beginning 1) (match-end 1)))
		     (let ((pos (o2-find-local-declaration record (o2-limit-to-decl (point-max) t))))
		       (if pos (goto-char pos) 
			 (error "Can't find record %s to pointer %s." record ident))))
	    (setq record ident)))
        ; second we try to extract the record's base type (if there is any)
	(if (not (looking-at (concat record "[ \t\n*\\-]*=\\s *RECORD\\W")))
	    (error "Receiver is not a (POINTER TO) RECORD data type.")
	  (setq base-type
		(if (and (re-search-forward 
			  "\\WEND\\W\\|(\\s *\\(\\w+\\s *\\(\\.\\w+\\s *\\)?\\))" nil t)
			 (match-end 1))
		    (buffer-substring (match-beginning 1) (match-end 1)))))
        ; third we try to locate the type-bound procedure to the current receiver type
	(goto-char (point-min))
	(if (re-search-forward 
	     (concat "\\WPROCEDURE\\s *(\\w+\\s *:\\s *" ident "\\s *)\\s *" proc-name "\\W") nil t)
	    (progn (message (concat prev-path ident)) ; yepp, we found it
		   (cons (current-buffer) (1+ (match-beginning 0))))
	  (if base-type			; we failed, so we try the same on the receiver's base type
	      (o2-find-typebound-procedure-noselect base-type 
						    proc-name 
						    (concat prev-path ident " ") 
						    conv-to-pointer)
	    (error "Can't find typebound procedure %s." proc-name)))))))

(defun o2-find-typebound-procedure-other-window (receiver proc-name)
  "Like o2-find-typebound-procedure, but file will be displayed in another window."
  (interactive (o2-interactive-strings
		'(("Receiver type: " . o2-receiver-type-history)
		  ("Procedure name: " . o2-proc-history))))
  (o2-switch-to (o2-find-typebound-procedure-noselect receiver proc-name) 
		'other-window 'save-mark))

(defun o2-find-typebound-procedure-other-frame (receiver proc-name)
  "Like o2-find-typebound-procedure, but file will be displayed in another frame."
  (interactive (o2-interactive-strings
		'(("Receiver type: " . o2-receiver-type-history)
		  ("Procedure name: " . o2-proc-history))))
  (o2-switch-to (o2-find-typebound-procedure-noselect receiver proc-name) 
		'other-frame 'save-mark))

(defun o2-find-typebound-procedure (receiver proc-name)
"Find to a data type RECEIVER the typebound procedure PROC-NAME bound to it. If
the procedure is inherited from the receiver's base type, the search is
automatically extended to this base type and so on. RECEIVER has to be a 
(possibly qualified) identifier.
The search may take a while."
  (interactive (o2-interactive-strings
		'(("Receiver type: " . o2-receiver-type-history)
		  ("Procedure name: " . o2-proc-history))))
  (o2-switch-to (o2-find-typebound-procedure-noselect receiver proc-name)
                nil 'save-mark))



(defun o2-fit-to-window (buffer)
; Reset the window-start of the buffer so that (point-max) is 
; displayed in the last line of window.
  (let* ((current (selected-window))
	 (window (get-buffer-window buffer t)))
    (if window
	(save-excursion
	  (select-window window)
	  (let ((old-point (window-point)))
	    (unwind-protect
		(progn
		  (forward-line (- 0 (- (window-height) 2 )))
		  (set-window-start window (point))
		  (while (not (pos-visible-in-window-p (point-max) window))
		    (forward-line 1)
		    (set-window-start window (point))))
	      (select-window current)
	      (set-window-point window old-point)))))))

(defun o2-goto-error (module err-pos)
  "Localize error as reported by a failed run time check.  Prompts for module name
and error position.  If the first string is a number, the point is placed at 
this position.  Otherwise the first string is assumed to be a module name. The
current buffer is set to this module, and point set to the second argument 
given."
  (interactive
   (let ((str (read-from-minibuffer "Module name or error position: ")))
     (if (string-match "^[0-9]" str)
	 (list nil (string-to-int str))
       (list str (string-to-int (read-from-minibuffer "Error position: "))))))
  (if (and module
	   (not (string-equal module "")))
      (o2-find-module module))
  (goto-char (1+ err-pos)))




(defun o2-compile-internal (command name)
;; Execute compile function with some specific settings.
  (let (o2-running-compile  ; set flag for compilation hook
	(default-directory o2-cwd)
	(compilation-ask-about-save o2-compilation-ask-about-save)
	(compilation-buffer-name-function
	 (lambda (name-of-mode) (concat "*" name "*"))))
    (compile command)))

(defun o2-curr-module-name ()
  (save-excursion
    (save-match-data
     (goto-char (point-min))
     (if (re-search-forward "MODULE\\s-+\\([a-zA-Z0-9_:]+\\)" nil t)
	 (match-string 1)
       (file-name-nondirectory (buffer-file-name))))))

(defun o2-compile (module &optional compile-command)
  "Compile MODULE (default: the current buffer's module name).  If C-u prefix
is set, read the compilation command from the minibuffer.
Runs the shell command 'o2-compile-command MODULE', in a separate process 
asynchronously with output going to the buffer *o2-compile:MODULE*.
Use the command \\[next-error] to get the next error message
and to move to the source code position that caused it."
  (interactive 
   (list (o2-curr-module-name)
	 (if current-prefix-arg
	     (read-from-minibuffer "Compile command: " o2-compile-command
				   nil nil 'o2-compile-history))))
  (if compile-command
      (setq o2-compile-command compile-command))
  (o2-compile-internal (concat o2-compile-command module) 
		       (if o2-concurrent-compilation
			   (concat "o2-compile:" module)
			 "o2-compile")))

(defun o2-make (command)
  "Make a given module respectively command.
Prompts for a command to be run in a separate process asynchronously with 
output going to the buffer *o2-make:COMMAND*.
You can then use the command \\[next-error] to get the next error message
and move to the source code position that caused it."
  (interactive (list (read-from-minibuffer "Make command: " o2-make-command
					   nil nil 'o2-make-history)))
  (setq o2-make-command command)
  (let ((make-command 
	 (if (string-match "^.*[ \t]\\([a-zA-Z0-9]+\\)[ \t]*$" command)
	     (substring command (match-beginning 1) (match-end 1))
	   "unknown")))
    (o2-compile-internal command (if o2-concurrent-compilation
				     (concat "o2-make:" make-command)
				   "o2-make"))))

(defun o2-list-uses (command)
  "List all uses of the given declaration in the specified module set.
Prompts for a command to be run in a separate process asynchronously with 
output going to the buffer *o2-search:COMMAND*.
You can then use the command \\[next-error] to get the use position
and move to the source code position that caused it."
  (interactive (list (read-from-minibuffer "Search command: " o2-list-uses-command
					   nil nil 'o2-list-uses-history)))
  (setq o2-list-uses-command command)
  (let ((search-command 
	 (if (string-match "^.*[ \t]\\([a-zA-Z0-9]+\\)[ \t]*$" command)
	     (substring command (match-beginning 1) (match-end 1))
	   "unknown")))
    (o2-compile-internal command (if o2-concurrent-compilation
				     (concat "o2-search:" search-command)
				   "o2-search"))))

;;;#########################################################################
;;; functions added Jan 02 1998:

;;; Note:
;;; Generally all functions that do a search for some syntactic construct
;;; ignore string constants and comments.  This means that they can be confused
;;; if accidentally a matching pattern appears inside a string or a comment.
;;; Chances that this happens are slim, though.

;;; regular expressions to recognize syntactic elements of an Oberon-2 program
(defconst o2-ident-re "\\<[a-zA-Z_][a-zA-Z_0-9]*\\>")
(defconst o2-identdef-re "\\<[a-zA-Z_][a-zA-Z_0-9]*\\s-*[-*+]?")
(defconst o2-system-flags-re "\\(\\[.*\\]\\)?")
(defconst o2-export-re "[-*+]?")
(defconst o2-record-decl-re
  (concat "\\(" o2-ident-re "\\)\\s-*" o2-export-re "\\s-*=\\s-*RECORD"))



;; Return a regular expression matching any declaration of procedure PROC-NAME.
;; If PROC-NAME is nil, then return a regexp matching any procedure.  The
;; expression will match normal procedures and type-bound procedures, but not a
;; forward declaration.  Subexpression 2 matches the receiver declaration (if
;; present), 3 the system flags (if present), and 4 the procedure name; the
;; expression contains 4 parenthesis pairs.  The regexp will fail if any
;; comments are placed between the keyword PROCEDURE and the procedure name.
(defun o2-beg-proc-re (&optional proc-name force-tb)
  (if proc-name
      (concat "\\<PROCEDURE\\s-*\\((\\([a-zA-Z0-9 \t:(,)]+\\))\\s-*\\)"
	      (if force-tb "" "?")
	      o2-system-flags-re "\\s-*\\(" proc-name "\\>\\)")
    (o2-beg-proc-re o2-ident-re force-tb)))

;; Return a regular expression matching the end of procedure PROC-NAME.  If
;; PROC-NAME is nil, then return a regexp matching any procedure.
;; Subexpression 1 matches the procedure name; the expression contains 1
;; parenthesis pair.  The regexp will fail if any comments or newlines are
;; placed between the keyword END and the final semicolon.  Note: If PROC-NAME
;; is nil it'll also match the (legal) sequence "END END;".
(defun o2-end-proc-re (&optional proc-name)
  (if proc-name
      (concat "\\<END[ \t]+\\(" proc-name "\\)[ \t]*;")
    (o2-end-proc-re o2-ident-re)))


(defun o2-beg-of-defun (&optional proc-name opoint no-error)
  "Move backward to the beginning of the current procedure.  Skip all nested
procedures in between.  Point is left at the start of the keyword
PROCEDURE.  Result is the position of point. 

If PROC-NAME is not nil, then search backwards for a declaration of a procedure
PROC-NAME.  An error is signalled if no such procedure exists."
  (interactive)
  (if opoint
      ()
    ;; make sure that we get a match even if we are at the beginning of the
    ;; procedure heading; but don't move past the end of the procedure
    (if (not (looking-at (concat ".*" (o2-end-proc-re))))
	(end-of-line)))
  ;; keep track of the initial position of point
  (setq opoint (or opoint (point)))
  
  (if (re-search-backward (concat (o2-beg-proc-re) "\\|" (o2-end-proc-re)) 
			  nil t)
      (if (match-end 4)
	  (if (or (not proc-name) 
		  (string= (match-string 4) proc-name))
	      ;; found the procedure we were looking for
	      (point)
	    (if no-error
		nil
	      (error "Can't find beginning of procedure %s" proc-name)))
	;; found the end of a procedure P: skip P and continue search
	(cond ((o2-beg-of-defun (match-string 5) opoint no-error)
	       (backward-char)
	       (o2-beg-of-defun nil opoint no-error))))
    (goto-char opoint)		; restore point
    (if no-error 
	nil
      (error "Point is not inside a procedure"))))

(defun o2-end-of-defun (&optional proc-name opoint no-error)
  "Move forward to the end of the current procedure.  Skip all nested
procedures in between.  Point is left after the final semicolon.  Result is the
position of point. 

If PROC-NAME is not nil, then search forward for the end a procedure PROC-NAME.
An error is signalled if no such procedure exists."
  (interactive)
  (if opoint
      ()
    ;; make sure that we get a match even if we are at the beginning of the
    ;; procedure heading; but don't move past the end of the procedure
    (if (looking-at (concat ".*" (o2-beg-proc-re)))
	(end-of-line)))
  ;; keep track of the initial position of point
  (setq opoint (or opoint (point)))
  
  (if (re-search-forward (concat (o2-beg-proc-re) "\\|" (o2-end-proc-re)) 
			 nil t)
      (if (match-end 5)
	  (if (or (not proc-name) 
		  (string= (match-string 5) proc-name))
	      ;; found the procedure we were looking for
	      (point)
	    (if no-error
		nil
	      (error "Can't find end of procedure %s" proc-name)))
	;; found the beginning of a procedure P: skip P and continue search
	(if (o2-end-of-defun (match-string 4) opoint no-error)
	    (o2-end-of-defun nil opoint no-error)))
    (goto-char opoint)		; restore point
    (if no-error
	nil
      (error "Point is not inside a procedure"))))

(defun o2-mark-defun ()
  "Mark the current Oberon-2 or procedure.
This puts the mark at the end, and point at the beginning.  The region starts 
resp. ends at the beginning of a line.  Whitespace following the end of the
procedure is part of the region."
  (interactive)
  (push-mark (point))
  (o2-end-of-defun)
  (push-mark (save-excursion
	       (re-search-forward "\\s-*")
	       (beginning-of-line)
	       (point)))
  (beginning-of-line)
  (o2-beg-of-defun)
  (beginning-of-line))


;; Return non-nil if point is in an Oberon-2 string, i.e. it's after the
;; starting delimiter but before (or on) the ending delimiter of the string.
;; In this case result is a cons list, with car being the first position in the
;; string, and cdr the first position behind it.
;;
;; Note: For an incomplete string, o2-in-stringp assumes that the string ends
;; with the current line.  This function won't distinguish between point being
;; inside comment/normal code.
(defun o2-in-stringp (&optional point)
  (save-excursion
    (save-match-data
      (let ((opoint (or point (point))))
	;; Oberon-2 strings can't stretch over multiple lines; it's enough to
	;; check that a string starts and ends on the current line, with point
	;; in between
	(goto-char opoint)
	(beginning-of-line)
	(catch 'exit
	  (while t
	    (if (re-search-forward "[\"']" opoint t)
		(let ((beg (point)))
		  (skip-chars-forward 
		   (concat "^\n" (char-to-string (preceding-char))))
		  (cond ((eolp)
                         (throw 'exit (cons beg (point))))
			((>= (point) opoint)
			 (throw 'exit (cons beg (1+ (point))))))
		  (forward-char))
	      (throw 'exit nil))))))))

;; Move behind next comment end sequence `*)', but skip nested comments in
;; between.  Result is the number of unmatched closing braces, i.e. 0 if the
;; current comment is terminated properly.  If point is initially inside a `(*'
;; character sequence, then this is counted as a nested comment.
;; pre: point is placed somewhere after an unmatched `(*'
(defun o2-end-of-comment (&optional point)
  (let ((cmt-count 1))
    (if point (goto-char point))
    (backward-char)		;find match even if point on right paren
    (while (and (> cmt-count 0)
		(re-search-forward "\\((\\*\\)\\|\\*)" nil 'move)
		(not (o2-in-stringp)))
      (setq cmt-count (if (match-end 1)
			  (1+ cmt-count)
			(1- cmt-count))))
    cmt-count))

;; Return non-nil if point is in an Oberon-2 comment, i.e. it's after the
;; second character of the starting delimiter, on the last character of the
;; ending delimiter, or in between.  In this case result is a cons list, with
;; car being the first position in the innermost comment around point, and cdr
;; the first position behind it.  If the comment isn't terminated, then cdr is
;; point-max.
(defun o2-in-commentp (&optional point)
  (save-excursion
    (save-match-data 
      (let ((opoint (or point (point)))
	    (cmt-stack nil))
	(goto-char (point-min))
	;; until point is reached: push position of comment start on stack, pop
        ;; a comment end
	(while (re-search-forward "\\((\\*\\)\\|\\*)" opoint 'move)
	  (if (or cmt-stack
		  (not (o2-in-stringp)))	;ignore delimiters in strings
	      (setq cmt-stack (if (match-end 1)
				  (cons (point) cmt-stack)
				(cdr cmt-stack)))))
	(if cmt-stack
	    (cons (car cmt-stack) 
		  (progn (o2-end-of-comment) (point))))))))

;; Return is non-nil if point is in a pragma, i.e. it's after the second
;; character of the starting delimiter, on the last character of the ending
;; delimiter, or in between.  In this case result is a cons list, with car
;; being the first position in the pragma, and cdr the first position behind
;; it.  If the pragma isn't terminated, then cdr is point-max.  A pragma inside
;; a comment doesn't count, and for a comment inside a pragma both
;; o2-in-commentp and o2-in-pragmap holds.
(defun o2-in-pragmap ()
  (save-excursion
    (save-match-data
      (let ((comment (o2-in-commentp)))
	(if comment			;in comment: move to beg of comment
	    (progn (goto-char (1- (car comment)))
		   (o2-in-pragmap))
	  (while 
	      (if (re-search-backward "\\(\\*)\\)\\|\\(<\\*\\)\\|\\*>" 
				      nil 'move)
		  (cond ((match-end 1)	;end of comment
			 (let ((comment (o2-in-commentp)))
			   (if comment
			       (goto-char (1- (car comment))) ;skip comment
			     t)))
			;; here holds: point is not inside comment
			((match-end 2)	;beginning of pragma
			 (o2-in-stringp))
			(t		;end of pragma, stop search
			 nil))))
	  ;; build cons cell with beginning and end of pragma
	  (if (looking-at "<\\*")
	      (cons (match-end 0)
		    (catch 'end-pragma
		      (while t
			(if (re-search-forward "\\((\\*\\)\\|\\*>" nil 'move)
			    (if (save-match-data (o2-in-stringp))
				()	;ignore if in string
			      (if (match-end 1) ;found beginning of comment
				  (o2-end-of-comment)
				(throw 'end-pragma (point))))
			  (throw 'end-pragma (point))))))))))))


(defun o2-comment-region (beg end &optional arg)
  "Comment the region by placing `(*' and `*)' around it."
  (interactive "r\nP")
  (save-excursion
    (goto-char end)
    (insert "*)")
    (goto-char beg)
    (insert "(*")))

(defun o2-uncomment-around-point (point)
  "Remove the innermost level of comment around point."
  (interactive "d")
  (save-excursion
    (let ((comment (o2-in-commentp point)))
      (if comment
	  (progn 
	    (goto-char (cdr comment))
	    (delete-backward-char 2)
	    (goto-char (car comment))
	    (delete-backward-char 2))
	(error "Point not inside comment")))))



;;;; added 1998/11/25: support for font lock mode
;;
;; To enable font-lock-mode for every buffer in oberon-2-mode, either add
;;   (add-hook 'oberon-2-mode-hook (function turn-on-font-lock))
;; or, to enable font-lock for all supported modes, add
;;   (global-font-lock-mode t)
;; to the initialization file.
;; 
;; Font Lock supports different levels of fontification: from boring but fast
;; colorizing to slower fontification with gaudy colors.  This mode supports
;; four levels:
;;   0: fontify strings and comments
;;   1: additionally fontify keywords and pragmas
;;   2: hilight names of procedure and module declarations, and the keywords
;;      PROCEDURE and MODULE
;;   3: set names of exported declarations in bold text
;; To get all supported markups you must do
;; (setq font-lock-maximum-decoration t).
;;
;; If you have a color display and do not like the default colors of Font Lock,
;; you may prefer the ones that are used with hilit19.  To replace the default
;; colors, evaluate (o2-font-lock-hilit-colors).  But this will change the 
;; coloring of all font-locked buffers.
;;
;; My personal entry in ~/.emacs looks like this:
;; (setq font-lock-maximum-decoration t)
;; (add-hook 'oberon-2-mode-hook 
;;           (lambda ()
;;             (o2-font-lock-hilit-colors)
;;             (turn-on-font-lock)))


(defvar oberon-2-font-lock-keywords-1 nil
  "Subdued level highlighting for Oberon-2 modes.")

(defvar oberon-2-font-lock-keywords-2 nil
  "Medium level highlighting for Oberon-2 modes.")

(defvar oberon-2-font-lock-keywords-3 nil
  "Gaudy level highlighting for Oberon-2 modes.")

(let 
    ((o2-keywords
      ;; keyword list before make-regexp: "RECORD\\|ARRAY\\|OF\\|POINTER\\|TO\\|BEGIN\\|END\\|FOR\\|BY\\|IF\\|THEN\\|ELSE\\|ELSIF\\|CASE\\|WHILE\\|DO\\|MODULE\\|FROM\\|RETURN\\|IMPORT\\|VAR\\|LOOP\\|UNTIL\\|OR\\|DIV\\|MOD\\|EXIT\\|IN\\|IS\\|REPEAT\\|WITH\\|TRY\\|CATCH\\|RAISES\\|CONST\\|TYPE\\|PROCEDURE"
      "ARRAY\\|B\\(EGIN\\|Y\\)\\|C\\(ASE\\|ONST\\|ATCH\\)\\|D\\(IV\\|O\\)\\|E\\(LS\\(E\\|IF\\)\\|ND\\|XIT\\)\\|F\\(OR\\|ROM\\)\\|I\\([FNS]\\|MPORT\\)\\|LOOP\\|MOD\\(\\|ULE\\)\\|O[FR]\\|P\\(OINTER\\|ROCEDURE\\)\\|R\\(AISES\\|E\\(CORD\\|PEAT\\|TURN\\)\\)\\|T\\(HEN\\|O\\|RY\\|YPE\\)\\|UNTIL\\|VAR\\|W\\(HILE\\|ITH\\)")
     (o2-proc-header
      "\\<\\(PROCEDURE\\)\\s-*\\((\\([a-zA-Z0-9 	:(,)]+\\))\\s-*\\)?\\(\\[.*\\]\\)?\\s-*\\(\\<[a-zA-Z_][a-zA-Z_0-9]*\\>\\>\\)")
     (o2-module-header
      "\\<\\(MODULE\\)\\s-+\\([a-zA-Z0-9_]+\\)\\>"))
  
  (setq
   oberon-2-font-lock-keywords-1
   (list
    ;; Fontify all builtin keywords
    (cons (concat "\\<\\(" o2-keywords "\\)\\>") 'font-lock-keyword-face)
    ;; Fontify pragmas
    (cons "<\\*.*\\*>" 'font-lock-reference-face))
   
   oberon-2-font-lock-keywords-2
   (append 
    oberon-2-font-lock-keywords-1
    ;; Fontify names of procedure declarations
    (list
     (list o2-module-header
	   '(1 o2-font-lock-scope-face prepend)
	   '(2 font-lock-function-name-face))
     ;; Change MODULE and PROCEDURE keywords to bold
     (list o2-proc-header
	   '(1 o2-font-lock-scope-face prepend)
	   '(5 font-lock-function-name-face))))
   
   oberon-2-font-lock-keywords-3
   (append 
    oberon-2-font-lock-keywords-2
    ;; Fontify exported identifiers as bold text
    (list
     '("\\(\\<[a-zA-Z_][a-zA-Z_0-9]*\\)\\s-*[-*]\\s-*[(=:,]"
       1 o2-font-lock-export-face prepend)
     '("PROCEDURE.*\\(\\<[a-zA-Z_][a-zA-Z_0-9]*\\)\\s-*\\*\\s-*[(;[]"
       1 o2-font-lock-export-face prepend)))))


(defun o2-font-lock-hilit-colors ()
;; Sets the face colors for font-lock-mode to value taken from hilit19.  Note
;; that this only works for color displays!  The net effect of this function
;; is, that buffers fontified with these colors look very similar to hilit19
;; enhanced buffers.
  (interactive)
  (require 'font-lock)
  (cond ((<= emacs-major-version 19)
	 (font-lock-make-face '(font-lock-comment-face "firebrick"))
	 (font-lock-make-face '(font-lock-string-face "grey40"))
	 (font-lock-make-face '(font-lock-keyword-face "RoyalBlue"))
	 (font-lock-make-face '(font-lock-function-name-face "Black"))
	 ;;(font-lock-make-face '(font-lock-variable-name-face "Black"))
	 ;;(font-lock-make-face '(font-lock-type-face "Black"))
	 (font-lock-make-face '(font-lock-reference-face "ForestGreen" nil t))
	 (font-lock-make-face '(o2-font-lock-export-face nil nil t))
	 (font-lock-make-face '(o2-font-lock-scope-face "blue" nil t)))
	(t
	 (custom-set-faces 
	  '(font-lock-comment-face ((t (:foreground "firebrick"))))
	  '(font-lock-string-face ((t (:foreground "grey40"))))
	  '(font-lock-keyword-face ((t (:foreground "RoyalBlue"))))
	  ;'(font-lock-builtin-face ((t (:foreground "Black"))))
	  '(font-lock-function-name-face ((t (:foreground "Black"))))
	  ;'(font-lock-variable-name-face ((t (:foreground "Black"))))
	  ;'(font-lock-type-face ((t (:foreground "Black"))))
	  '(font-lock-reference-face ((t (:foreground "ForestGreen"))))
	  ;'(font-lock-warning-face ((t (:foreground "Black"))))
	  '(o2-font-lock-export-face ((t (:bold t))))
	  '(o2-font-lock-scope-face ((t (:foreground "Blue" :bold t))))))))
	 
(add-hook 
;; This hook creates the additional faces used by the fontification
;; rules.
 'font-lock-mode-hook
 '(lambda () 
    (cond ((eq major-mode 'oberon-2-mode)
	   ;; create faces o2-font-lock-(export|scope)-face if they do not
	   ;; exist yet
	   (defvar o2-font-lock-export-face 'o2-font-lock-export-face)
	   (defvar o2-font-lock-scope-face 'o2-font-lock-scope-face)
	   (if (<= emacs-major-version 19)
	       (progn
		 (or (boundp 'o2-font-lock-export-face)
		     (font-lock-make-face '(o2-font-lock-export-face nil nil t)))
		 (or (boundp 'o2-font-lock-scope-face)
		     (font-lock-make-face '(o2-font-lock-scope-face nil nil t))))
	     ;; emacs version 20+
	     (or (facep 'o2-font-lock-export-face)
		 (custom-declare-face 'o2-font-lock-export-face 
				      '((t (:bold t)))
				      "Face prepended to style of exported identifiers."))
	     (or (facep 'o2-font-lock-scope-face)
		 (custom-declare-face 'o2-font-lock-scope-face 
				      '((t (:bold t)))
				      "Face prepended to style of keywords starting a scope")))))))




;;;; added 1998/11/28: support for imenu index
;;
;; With this you can have a menubar entry that holds an index of all the
;; procedures, type-bound procedures, and record declarations of the module.
;; To enable it, evaluate these lines:
;; 
;; (add-hook 'oberon-2-mode-hook
;;           (lambda ()
;;             (imenu-add-to-menubar "Index")))
;; 
;; Note: The imenu support has been tested successfully with Emacs version
;; 19.34 and 20.3.  It does not work with version 20.2 because of a bug in
;; imenu-add-to-menubar.

(defvar o2-imenu-proc-stack nil)
(defvar o2-imenu-proc-name nil)
(defvar o2-imenu-tb-procs nil)

(defmacro o2-imenu-close-sublist (nested-list curr-sublist curr-prefix)
  ;; Turns list in curr-sublist into a menu element and prepend it to the list
  ;; in nested-list.
  
  `(if ,curr-sublist
       (setq ,nested-list 
	     (cons (cons (if (eq (aref ,curr-prefix 0) ?#)
			     (concat "Class " (substring ,curr-prefix 1))
			   ,curr-prefix)
			 (o2-imenu-nest-list (reverse ,curr-sublist)))
		   ,nested-list)
	     ,curr-sublist
	     nil)))

(defun o2-imenu-nest-list (flat-list)
  ;; Converts a sorted flat list of menu entries into a nested list of menus.
  ;; Type-bound procedures are grouped into a "Class" entry, and procedures
  ;; with nested procedures in them get a submenu of their own.
  
  (let ((prefix-re (concat "\\(#?\\*?" o2-ident-re "\\*?\\)[/#]\\(.*\\)"))
	(nested-list nil)
	(curr-prefix nil)
	(curr-sublist nil)
	curr-name
	curr-pos)
    
    (save-match-data
      (while flat-list
	(setq curr-name (car (car flat-list)))
	(setq curr-pos (cdr (car flat-list)))
	(cond ((string-match prefix-re curr-name)
	       ;; close old sublist if the receiver type has changed
	       (if (and curr-sublist
			(not (string= (match-string 1 curr-name) curr-prefix)))
		   (o2-imenu-close-sublist nested-list curr-sublist curr-prefix))
	       
	       ;; create new sublist, or attach to existing sublist
	       (setq curr-sublist 
		     (cons (cons (match-string 2 curr-name) curr-pos)
			   curr-sublist)
		     curr-prefix
		     (match-string 1 curr-name)))
	      
	      (t
	       (if (and curr-sublist
			(string= curr-name curr-prefix))
		   ;; the current name is equal to the current prefix of the 
		   ;; sublist: move curr-name into the sublist
		   (setq curr-sublist 
			 (cons (cons (concat "--" curr-name "--") curr-pos) 
			       curr-sublist))
		 ;; attached (curr-name . curr-pos) to top-level list
		 (o2-imenu-close-sublist nested-list curr-sublist curr-prefix)
		 (setq nested-list (cons (car flat-list) nested-list)))))
	(setq flat-list (cdr flat-list))))
      
    (o2-imenu-close-sublist nested-list curr-sublist curr-prefix)
    nested-list))
    
(defun o2-match-string-no-properties (num)
  (buffer-substring-no-properties (match-beginning num) (match-end num)))

(defun o2-get-receiver-type (receiver)
  ;; extract the receiver type
  (if (string-match (concat "[ \t:]\\(" 
			    o2-ident-re "\\)[ \t]*$") 
		    receiver)
      (match-string 1 receiver)
    "invalidtype"))

(defun o2-imenu-prev-index-position-function ()
  ;; Searches backward for procedure or type declaration.
  (let ((re
	 (concat "\\(" (o2-end-proc-re) "\\)\\|"
		 "\\(" (o2-beg-proc-re) "\\)\\|" 
		 "\\(" o2-record-decl-re "\\)"))
	(re-search nil))
    
    ;; scan backwards for end of procedure, beginning of procedure, or 
    ;; declaration of a record type; for every end of procedure push the
    ;; procedure name, the other two kinds produce entries in the imenu index
    (while (and (setq re-search (re-search-backward re nil t))
		(match-beginning 1))
      (setq o2-imenu-proc-stack 
	    (cons 
	     (if (or (not o2-imenu-tb-procs)
		     (> (point) (nth 2 (car o2-imenu-tb-procs))))
		 (o2-match-string-no-properties 2)
	       ;; this END belongs to a type-bound procedure; use both
	       ;; receiver type and procedure name for the prefix
	       (let ((type-name (car (car o2-imenu-tb-procs))))
		 (setq o2-imenu-tb-procs (cdr o2-imenu-tb-procs))
		 (concat "#" type-name "#" (o2-match-string-no-properties 2))))
	     o2-imenu-proc-stack)))
    
    (setq
     o2-imenu-proc-name
     (cond ((not re-search)  ;; no match, the function eval must return nil
	    nil)
	   
	   ((and (match-end 3) (match-end 5))  ;; type-bound procedure
	    (let ((proc-name (o2-match-string-no-properties 7))
		  (receiver (o2-match-string-no-properties 5)))
	      (setq o2-imenu-proc-stack (cdr o2-imenu-proc-stack))
	      (concat "#" (o2-get-receiver-type receiver) "#" proc-name)))
	   
	   ((match-end 3) ;; normal procedure
	    (let* ((proc-name (o2-match-string-no-properties 7))
		   list)
	      (setq o2-imenu-proc-stack (cdr o2-imenu-proc-stack)
		    list o2-imenu-proc-stack)
	      (while list
		(setq proc-name (concat (car list) "/" proc-name)
		      list (cdr list)))
	      proc-name))
	   
	   (t ;; record declaration
	      (let ((type-name (o2-match-string-no-properties 9))
		    (proc-name "")
		    (list o2-imenu-proc-stack))
		(while list
		  (setq proc-name (concat (car list) "/" proc-name)
			list (cdr list)))
		(concat proc-name "*Records*/" type-name)))))))

(defun o2-imenu-extract-index-name-function ()
  o2-imenu-proc-name)

(defun o2-imenu-scan-tb-procs ()
  (interactive)
  (save-excursion
    (goto-char (point-max))
    (let ((tb-procs nil))
      (while (re-search-backward (o2-beg-proc-re nil 'force-tb) nil t)
	(setq tb-procs 
	      (cons (list
		     (o2-get-receiver-type (o2-match-string-no-properties 2))
		     (point)
		     (save-excursion (o2-end-of-defun nil nil t)))
		    tb-procs))
	(if (not (cdr (car tb-procs)))
	    (setq tb-procs (cdr tb-procs))))
      tb-procs)))

(defun o2-imenu-default-create-index-function ()
  (setq o2-imenu-proc-stack nil
	o2-imenu-tb-procs (reverse (o2-imenu-scan-tb-procs)))
  (o2-imenu-nest-list
   (reverse 
    (sort
     (imenu-default-create-index-function)
     (function imenu--sort-by-name)))))



;;;; added 2000/07/29: editing of texinfo comments
;;
;; These functions add the feature to edit Texinfo comments in another
;; window using the Texinfo mode, and inserting it back into the document 
;; at the place it came from.
;; The function is bound to C-c d, leaving the editor buffer is also done
;; with C-c d.

(make-variable-buffer-local 'o2-texinfo-start-marker)
(make-variable-buffer-local 'o2-texinfo-end-marker)
(make-variable-buffer-local 'o2-texinfo-comment-prefix)
(make-variable-buffer-local 'o2-texinfo-indent-column)

;; Like o2-in-commentp, with two exceptions: Report point on comment if the
;; point is on the "(*" that starts a comment, and the starting position is
;; the "(" character beginning the comment symbol.
(defun o2-on-commentp (&optional point)
  (save-excursion
    (if point (goto-char point))
    (let ((comment
	   (progn
	     (cond ((looking-at "(\\*")
		    (forward-char 2))
		   ((looking-at "\\*")
		    (forward-char 1)))
	     (o2-in-commentp))))
      (if comment (cons (- (car comment) 2) (cdr comment))))))

;; Returns buffer that is used for texinfo editing.
(defun o2-get-edit-buffer ()
  (let ((buffer (get-buffer "*o2-texinfo*")))
    (cond ((not buffer)
	   (setq buffer (generate-new-buffer "*o2-texinfo*"))
	   (save-excursion
	     (set-buffer buffer)
	     (texinfo-mode))))
    buffer))

;; Does fill-region, except that example blocks are skipped
(defun o2-fill-region (pmin pmax)
  (save-excursion
    (let ((end-marker (set-marker (make-marker) pmax))
	  (start (point)))
      (goto-char pmin)
      (while (< (point) end-marker)
	(setq start (point))
	(cond ((re-search-forward "^@example" end-marker t)
	       (fill-region start (point))
	       (re-search-forward "^@end example" end-marker 'move))
	      (t
	       (fill-region start end-marker)
	       (goto-char end-marker)))))))

(defun o2-edit-comment ()
  "Takes text from comment at or around point and displays it in another window
for editing.  If there is no comment at point, inserts an empty comment
followed by a newline and start editing with the empty text."
  (interactive)
  (barf-if-buffer-read-only)
  
  (let* ((comment 
	  (or (o2-on-commentp)
	      (progn 
		(save-excursion (insert "(***)") (o2-newline))
		(o2-on-commentp))))
	 (comment-prefix "")
	 (start-offset
	  (save-excursion
	    (goto-char (+ (car comment) 2))
	    (if (looking-at "[ *]") 
		(progn (setq comment-prefix (char-to-string (char-after))) 3)
	      2)))
	 (start-marker
	  (set-marker (make-marker) (car comment)))
	 (start-text
	  (+ (car comment) start-offset))
	 (end-marker
	  (set-marker (make-marker) (cdr comment)))
	 (end-text
	  (- (cdr comment) 2))
	 (start-column 
	  (save-excursion
	    (goto-char start-text)
	    (current-column)))
	 (text (buffer-substring-no-properties start-text end-text))
	 (point-offset (- (point) start-text))
	 (buffer (o2-get-edit-buffer)))
    ;; switch to texinfo buffer and insert text from comment
    (set-buffer buffer)
    (if (and (buffer-modified-p)
	     (not 
	      (yes-or-no-p "Texinfo buffer is modified.  Discard old text? ")))
	(error "Aborting"))
    (erase-buffer)
    (insert text)
    
    ;; display texinfo buffer in other window, and make sure point is ok
    (switch-to-buffer-other-window buffer)
    (set-window-point (selected-window) (1+ point-offset))
    (setq o2-texinfo-start-marker start-marker
	  o2-texinfo-end-marker end-marker
	  o2-texinfo-comment-prefix comment-prefix
	  o2-texinfo-indent-column start-column)

    ;; rewrite texinfo buffer: remove indentation, fix full column, fill the
    ;; whole buffer, and remove the modified flag
    (let ((left-margin 9999)) (delete-to-left-margin))
    (setq fill-column (- 79 start-column))
    (o2-fill-region (point-min) (point-max))
    (set-buffer-modified-p nil)

    (local-set-key "\C-cd" 'o2-reinsert-texinfo)
    (message "Press `C-c d' to return to source buffer")))

(defun o2-reinsert-texinfo ()
  "Takes the text from the Texinfo window, performs block fill on the whole 
buffer, and inserts it at the place where the text orginally was taken from."
  (interactive)
  (cond ((not (buffer-modified-p))
	 (delete-window)
	 (message "Text not modified"))
	 
	((and (boundp 'o2-texinfo-start-marker)
	      (boundp 'o2-texinfo-end-marker)
	      (boundp 'o2-texinfo-comment-prefix))
	 (let ((buffer (current-buffer))
	       (curr-point (point))
	       (start-marker o2-texinfo-start-marker)
	       (end-marker o2-texinfo-end-marker)
	       (comment-prefix o2-texinfo-comment-prefix)
	       (point-offet 0))
	   (save-excursion
	     (o2-fill-region (point-min) (point-max))
	     (goto-char (point-max))
	     (if (re-search-backward "[^ \n\t]" nil t)
		 (delete-region (1+ (point)) (point-max)))
	     (goto-char (point-min))
	     (forward-line)
	     (indent-region (point) (point-max) o2-texinfo-indent-column))
	   (setq point-offset (point))
	   (set-buffer (marker-buffer start-marker))
	   (goto-char start-marker)
	   (delete-region start-marker end-marker)
	   (insert (concat "(*" comment-prefix 
			   (save-excursion
			     (set-buffer buffer)
			     (buffer-substring-no-properties
			      (point-min)
			      (point-max)))
			   "  *)"))
	   (set-marker end-marker (point))
	   
	   (set-buffer buffer)
	   (set-buffer-modified-p nil)
	   (delete-window)
	   (forward-char (+ 1 (length comment-prefix) point-offset))))
	
	(t (error "Not in a o2-texinfo buffer"))))
