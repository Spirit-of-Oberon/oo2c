;;; Indentation support for OOC's oberon2.el
;; Copyright (C) 2004 Michael van Acken
;; Based on Karl Landström's oberon-2.el version 1.0
;; Licensed under the GPL v2

;; *pre-condition*: oberon2.el has been loaded

(defcustom ob2-indent-level 2
  "*Number of blanks for each indent step.")

(defconst ob2-indent-re-alist
  '(("|" . guard-sep)
    ("\\<BEGIN\\>" . begin)
    ("\\<CASE\\>" . case)
    ("\\<CATCH\\>" . catch)
    ("\\<\\(CONST\\|TYPE\\|VAR\\)\\>" . const-type-var)
    ("\\<ELSE\\>" . else)
    ("\\<ELSIF\\>" . elsif)

    ;; in ob2-indent-re, 'end-proc must come before 'end
    ("\\<END\\>[ \t]+\\sw" . end-proc-or-module)
    ("\\<END\\>[ \t]*\\(;\\|(\\*\\|$\\)" . end)

    ("\\<FOR\\>" . for)
    ("\\<IF\\>" . if)
    ("\\<IMPORT\\>" . import)
    ("\\<LOOP\\>" . loop)
    ("\\<MODULE\\>" . module)
    ("\\<RAISES\\>" . raises)
    ("\\<RECORD\\>" . record)
    ("\\<REPEAT\\>" . repeat)
    ("\\<TRY\\>" . try)
    ("\\<UNTIL\\>" . until)
    ("\\<WHILE\\>" . while)
    ("\\<WITH\\>" . with)
    ;; 'proc does not match procedure forward declarations or procedure types
    ("\\<PROCEDURE\\>[ \t]*\\(([^;]*)\\s-*\\)?\\(\\sw+\\)" . proc)
    ("\\<PROCEDURE\\>[ \t]*\\^" . proc-forward))
"Regexps matching code that affects indentation.
A symbolic name belongs to each regexp.")


(defsubst ob2-get-indent-re (symbol)
  "Return regexp from `ob2-indent-re-alist' matching SYMBOL, or nil."
  (car (rassoc symbol ob2-indent-re-alist)))


(defsubst ob2-get-indent-symbol (str)
"Return symbol from `ob2-indent-re-alist' matching STR, or nil.
The symbol corresponding to a to a regexp matching the string STR is
returned."
  (save-match-data
    (assoc-default str
                   ob2-indent-re-alist
                   (lambda (re key) (string-match re key)))))

(defconst ob2-indent-re
  (mapconcat (lambda (x) (car x)) ob2-indent-re-alist "\\|")
  "Regexp matching code that affects indentation.")

(defconst ob2-indent-interrupt-re
  (mapconcat 'identity
             (delq nil (mapcar (lambda (x) (ob2-get-indent-re x))
                               '(begin catch const-type-var else elsif end
				       guard-sep import proc raises
				       end-proc-or-module until proc-forward)))
             "\\|")
"Regexp matching code that interrupt indentation of previous line.
Indentation relative to the previous line is either incremented
\(e.g. VAR after MODULE) or decremented (e.g. BEGIN after VAR). End of
procedure is *included* in the regexp \\<END\\>.")

(defconst ob2-statements-or-declarations-re
  (mapconcat (lambda (x) (ob2-get-indent-re x))
	     '(end-proc-or-module begin) "\\|")
  "Regexp matching code that is used to determine if point is in a
statement sequence or a list of declarations.")

(defconst ob2-record-re
  (mapconcat (lambda (x) (ob2-get-indent-re x))
	     '(record end) "\\|")
  "Regexp matching code that starts or ends a record definition.")

(defsubst ob2-get-match-symbol ()
  "Return the symbol representing the most recent match."
  (ob2-get-indent-symbol (match-string-no-properties 0)))

(defsubst ob2-inside-statement-sequence-p ()
  "Return non-nil if point is inside a statement sequence.
Else return nil."
  (save-match-data
    (save-excursion
      (if (ob2-re-search-backward-code ob2-statements-or-declarations-re)
	  (eq (ob2-get-match-symbol) 'begin)
	nil))))


;; ------
;; KEYMAP
;; ------

;; (defvar oberon-2-mode-map nil
;;   "Keymap used in Oberon-2 mode.")

;; (unless oberon-2-mode-map
;;   (setq oberon-2-mode-map (make-sparse-keymap))

  (define-key o2-mode-map "\t" 'ob2-indent-or-hippie)
  (define-key o2-mode-map [return] 'newline-and-indent)
  (define-key o2-mode-map "\C-c\C-i" 'indent-region)

(add-hook 'oberon-2-mode-hook 'ob2-enable-indent)




;; ------------------------
;; PARSING
;; ------------------------

(defsubst ob2-inside-string-p ()
  "Return non-nil if point is inside a string literal.
Else return nil."
  ;; No newlines are allowed in Oberon-2 string literals.
  (nth 3 (parse-partial-sexp (save-excursion (beginning-of-line) (point))
                             (point))))


(defsubst ob2-inside-comment-p ()
  "Return non-nil if point is inside a comment.
Else return nil."
  ;; (save-excursion (save-match-data (comment-beginning)))
  (nth 4 (parse-partial-sexp (point-min) (point))))


(defsubst ob2-inside-string-or-comment-p ()
  "Return non-nil if point is inside a string literal or comment.
Else return nil."
  (or (ob2-inside-string-p) (ob2-inside-comment-p)))


(defsubst ob2-re-search-forward-code (regexp)
  "Do `re-search-forward' but ignore strings and comments.
The function uses (`re-search-forward' REGEXP nil t)."
  (condition-case nil
      (progn (while (and (re-search-forward regexp)
                         (ob2-inside-string-or-comment-p)))
             (point))
    (error nil)))


(defsubst ob2-re-search-backward-code (regexp)
  "Do `re-search-backward' but ignore strings and comments.
The function uses (`re-search-backward' REGEXP nil t)."
  (condition-case nil
      (progn (while (and (re-search-backward regexp)
                         (ob2-inside-string-or-comment-p)))
             (point))
    (error nil)))


;; -----------
;; INDENTATION
;; -----------

(defvar ob2-indent-table nil
"Indentation table.

Key (A . B) and value C is interpreted as: If looking at A and have
found B above point increment indentation with C steps.  If a particular
pair is not in the hash, then C is assumed to be zero.  One step equals
`ob2-indent-level' blanks.")

;; FIXME... put table into defvar again
(setq ob2-indent-table
  (let ((table (make-hash-table :test 'equal)))
    ;; (puthash '(current . parent) delta table)
    (puthash '(begin . end-proc-or-module) -1 table)
    (puthash '(begin . proc) 1 table)
    (puthash '(begin . raises) 1 table)
    (puthash '(const-type-var . end) -1 table)
    (puthash '(const-type-var . proc) 1 table)
    (puthash '(const-type-var . raises) 1 table)
    (puthash '(else . end) -1 table)
    (puthash '(elsif . end) -1 table)
    (puthash '(end . end) -1 table)
    (puthash '(end . until) -1 table)
    (puthash '(end-proc-or-module . end) -1 table)
    (puthash '(end-proc-or-module . end-proc-or-module) -1 table)
    (puthash '(end-proc-or-module . proc) 1 table)
    (puthash '(end-proc-or-module . raises) 1 table)
    (puthash '(end-proc-or-module . until) -1 table)
    (puthash '(guard-sep . end) -1 table)
    (puthash '(other . begin) 1 table)
    (puthash '(other . case) 1 table)
    (puthash '(other . catch) 1 table)
    (puthash '(other . const-type-var) 1 table)
    (puthash '(other . else) 1 table)
    (puthash '(other . elsif) 1 table)
    (puthash '(other . for) 1 table)
    (puthash '(other . if) 1 table)
    (puthash '(other . guard-sep) 1 table)
    (puthash '(other . import) 1 table)
    (puthash '(other . loop) 1 table)
    (puthash '(other . record) 1 table)
    (puthash '(other . repeat) 1 table)
    (puthash '(other . proc) 1 table)
    (puthash '(other . raises) 1 table)
    (puthash '(other . try) 1 table)
    (puthash '(other . while) 1 table)
    (puthash '(other . with) 1 table)
    (puthash '(proc . end-proc-or-module) -1 table)
    (puthash '(proc . proc) 1 table)
    (puthash '(proc . raises) 1 table)
    (puthash '(proc-forward . proc) 1 table)
    (puthash '(proc-forward . raises) 1 table)
    (puthash '(until . end) -1 table)
    (puthash '(until . until) -1 table)
    table))


(defsubst ob2-get-indent-increment (current parent)
  "Return indentation increment from `ob2-indent-table'.

Gets the indentation increment from `ob2-indent-table' coresponding to
the key '(CURRENT PARENT).  See `ob2-indent-table'."
  (message "(ob2-get-indent-increment %s %s) --> %i" current parent
	   (gethash (cons current parent) ob2-indent-table 0))
  (gethash (cons current parent) ob2-indent-table 0))


(defun ob2-indent-line ()
  "Indent the current line as Oberon-2 code."
  (interactive)
  (let ((offset (- (current-column) (current-indentation))))

    (indent-line-to (ob2-calculate-indent))
    (when (> offset 0)
        (forward-char offset))))


(defun ob2-calculate-indent ()
  "Return the correct indentation for the current line."
  (save-excursion
    (back-to-indentation)
    
    (cond ((ob2-inside-comment-p)     ;comment row > 1
           (ob2-calc-indent-multi-line-comment))

          ((ob2-inside-param-list-p)
           (ob2-calc-indent-inside-multi-line-param-list))
          
          ((ob2-inside-multi-line-expr-p)
           (ob2-calc-indent-multi-line-expr))

          (t (ob2-calc-indent-normal)))))


(defun ob2-re-search-backward-code-2 (regexp)
  "Locate first preceeding word matching REGEXP that is not a reference
parameter or within an ended record definition.  Result is nil if there
is no match."
  (let ((foundp (ob2-re-search-backward-code regexp)))
    (cond ((not foundp)			;no match
	   nil)
	  ((ob2-looking-at-ref-param-p)	;skip reference parameter
	   (ob2-re-search-backward-code-2 regexp))
	  ((and (save-match-data	;skip record-end
		  (looking-at (ob2-get-indent-re 'end)))
		(not (ob2-inside-statement-sequence-p)))
	   (ob2-re-search-backward-code-2 ob2-record-re)
	   (ob2-re-search-backward-code-2 regexp))
	  (t				;default: return search result
	   foundp))))

(defun ob2-calc-indent-normal ()
  "Return correct indentation for current line (*normal* cases)."
  (let ((saved-word)
        (saved-column))
    (message "---> point=%s" (point))
    (save-excursion
      (when (ob2-re-search-backward-code-2 ob2-indent-re)
        (setq saved-word (ob2-get-match-symbol))
        (setq saved-column (current-indentation))))
    
    ;;(message "save-column=%s, saved-word=%s" saved-column saved-word)
    (if (null saved-word)
        0
      (let ((factor))
	(cond ((looking-at ob2-indent-interrupt-re)
	       (save-excursion		;place re in match-string
		 (ob2-re-search-forward-code ob2-indent-re)
		 (setq factor
		       (ob2-get-indent-increment (ob2-get-match-symbol)
						 saved-word))))
	      ((and (eq saved-word 'proc) ;comment after procedure
		    (looking-at "(\\*"))
	       (setq factor 0))
	      (t
	       (setq factor (ob2-get-indent-increment 'other saved-word))))
	(if (null factor)
	    0
	  (max 0 (+ saved-column (* factor ob2-indent-level))))))))


(defun ob2-inside-param-list-p ()
  "Return non-nil if point inside proc declaration or parameter list.
Else returns nil."
  (let ((saved-point
         (save-excursion (ob2-re-search-backward-code
                          (concat (ob2-get-indent-re 'proc)
                                  "\\|\\<MODULE\\>")))))
    (unless (null saved-point)
      (> (nth 0 (parse-partial-sexp saved-point (point))) 0))))


(defconst ob2-operator-re
 (concat "\\([=#+/&-]\\|<=\\|>=\\|[^<(]\\*\\|[^*]>\\|<[^*]\\|"
         (regexp-opt '("DIV" "IN" "IS" "MOD" "OR") 'words)
         "\\)")
 "Regular expression matching any Oberon-2 operator.")


(defconst ob2-indent-begin-inside-body-re
  (concat "\\(" (regexp-opt '("BEGIN" "CASE" "FOR" "IF" "LOOP" "REPEAT"
                                    "TRY" "WHILE" "WITH") 'words)
          "\\)")
  "Indentation inside body regexp.

Regular expression matching code inside a module/procedure body that
increments the indentation of the following lines.")


(defun ob2-inside-multi-line-expr-p ()
  "Determine if point is on multi line expression.

Non-nil is returned if point is on row n (n > 1) of an expression that
spans several lines.  Else nil is returned."
  (save-excursion
    (beginning-of-line)
    (or (looking-at (concat "[ \t]*" ob2-operator-re))
	(and (not (bobp))
	     (not (looking-at ob2-indent-begin-inside-body-re))
	     (save-excursion
	       (forward-line -1)
	       (beginning-of-line)
	       (looking-at (concat ".*" ob2-operator-re "[ \t]*$")))))))


(defun ob2-calc-indent-multi-line-expr ()
  "Calculate indentation for a multi line expression.

Returns the correct indentation for the current line when point is
inside a multiline expression."
  ;;(message "ob2-calc-indent-multi-line-expr point=%s" (point))
  (save-excursion
    (while (and (not (bobp)) (ob2-inside-multi-line-expr-p))
      (backward-to-indentation 1))
    ;;(message "ob2-calc-indent-multi-line-expr point2=%s" (point))
    
    (let ((sym (progn
		 (looking-at ob2-indent-re)
		 (ob2-get-match-symbol)))
	  (current-indent (current-indentation)))
      (cond ((eq sym 'if)
	     (+ current-indent 3))
	    ((memq sym '(while elsif))
	     (+ current-indent 6))
	    ((eq sym 'case)
	     (+ current-indent 5))
	    (t
	     (if (> (count-lines (point)
				 (or (ob2-re-search-forward-code
				      (concat ":=\\|" 
					      ob2-indent-begin-inside-body-re))
				     2))
		    1)
		 (error "Don't know how to indent line")
	       (if (save-match-data
		     (string-match ":?=" (match-string-no-properties 0)))
		   (progn (goto-char (match-end 0))
			  (current-column))
		 (+ current-indent (* ob2-indent-level 2)))))))))


(defun ob2-calc-indent-inside-multi-line-param-list ()
  "Calculate indentation when point is on multi line parameter list.

Returns the correct indentation of the current line when point is on
row n (n > 1) of a procedure parameter list spanning several lines."
  (save-excursion
    (goto-char
     (nth 1 (parse-partial-sexp
             (save-excursion (ob2-re-search-backward-code
                              (concat (ob2-get-indent-re 'proc)
                                      "\\|\\<MODULE\\>")))
             (point))))
    (1+ (current-column))))


(defun ob2-calc-indent-multi-line-comment ()
  "Calculate indentation when point is on a multi line comment.

Return the correct indentation of the current line when point is on
the n:th line of a multi-line comment, where n > 1."
  (save-excursion
    (comment-beginning)
    (current-column)))


(defun ob2-looking-at-ref-param-p ()
  "Return non-nil if looking at a reference parameter.
Else returns nil."
  (save-match-data 
    (let ((saved-point (save-excursion
			 (ob2-re-search-backward-code "\\<PROCEDURE\\>"))))
      (and saved-point
           (looking-at "\\<VAR\\>")
	   (> (nth 0 (parse-partial-sexp saved-point (point)))
              0)))))


;;;;

(defun ob2-indent-or-hippie (arg)
  (interactive "P")
  (if (<= (point) (save-excursion (back-to-indentation) (point)))
      (ob2-indent-line)
    (hippie-expand arg)))

(defun ob2-enable-indent ()
  ;; Indentation
  (set (make-local-variable 'indent-line-function) 'ob2-indent-line)
  (setq indent-tabs-mode nil)
  
  ;; Comments
  (require 'newcomment)
  (require 'cc-mode)			;for c-comment-indent
  (set (make-local-variable 'comment-start) "(* ")
  (set (make-local-variable 'comment-end) " *)")
  (comment-normalize-vars))

(defun ob2-indent-buffer-and-save (arg)
  (if (string-match "\\.Mod$" arg)
      (save-excursion
	(find-file arg)
	(oberon-2-mode)
	(indent-region (point-min) (point-max) nil)
	(write-file (concat (substring (file-name-nondirectory arg) 0 -4)
			    ".indent")))))

(defun ob2-indent-all-buffers ()
  (load-file "oberon2.el")
  (mapcar 'ob2-indent-buffer-and-save command-line-args))
