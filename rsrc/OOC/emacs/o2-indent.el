;;; Indentation support for OOC's oberon2.el
;; Copyright (C) 2004 Michael van Acken
;; Based on Karl Landström's oberon-2.el version 1.0
;; Licensed under the GPL v2

(defcustom ob2-indent-level 2
  "*Number of blanks for each indent step.")

(defconst ob2-indent-re-alist
  '(("|" . guard-sep)
    ("\\<BEGIN\\>" . begin)
    ("\\<CASE\\>" . case)
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
    ("\\<RECORD\\>" . record)
    ("\\<REPEAT\\>" . repeat)
    ("\\<UNTIL\\>" . until)
    ("\\<WHILE\\>" . while)
    ("\\<WITH\\>" . with)
    ("\\<PROCEDURE\\>[ \t]*\\(([^)]*)\\s-*\\)?\\(\\sw+\\)" . proc))
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
                               '(begin const-type-var else elsif end guard-sep
                                       import proc end-proc-or-module until)))
             "\\|")
"Regexp matching code that interrupt indentation of previous line.
Indentation relative to the previous line is either incremented
\(e.g. VAR after MODULE) or decremented (e.g. BEGIN after VAR). End of
procedure is *included* in the regexp \\<END\\>.")




;; ------
;; KEYMAP
;; ------

(defvar oberon-2-mode-map nil
  "Keymap used in Oberon-2 mode.")

(unless oberon-2-mode-map
  (setq oberon-2-mode-map (make-sparse-keymap)))


;; ------------------------
;; SYNTAX TABLE AND PARSING
;; ------------------------

(defvar oberon-2-mode-syntax-table
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?\' "\"" table)
    (modify-syntax-entry ?( "()1n" table)
    (modify-syntax-entry ?) ")(4n" table)
    (modify-syntax-entry ?* ". 23n" table)
;;     (modify-syntax-entry ?w "_" table)
    table)
  "Syntax table used in Oberon-2 mode.")


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
found B above point increment indentation with C steps.  One step
equals `ob2-indent-level' blanks.")

;; FIXME... pull out table from defvar so that it is easily changed
(setq ob2-indent-table
  (let ((table (make-hash-table :test 'equal)))
    ;; (puthash '(current . parent) delta table)
    (puthash '(begin . const-type-var) -1 table)
    (puthash '(begin . end) -2 table)
    (puthash '(begin . end-proc-or-module) -1 table)
    (puthash '(begin . import) 0 table)
    (puthash '(begin . module) 0 table)
    (puthash '(begin . proc) 0 table)
    (puthash '(const-type-var . const-type-var) 0 table)
    (puthash '(const-type-var . end) -1 table)
    (puthash '(const-type-var . import) 0 table)
    (puthash '(const-type-var . module) 1 table)
    (puthash '(const-type-var . proc) 1 table)
    (puthash '(else . case) 0 table)
    (puthash '(else . else) 0 table)
    (puthash '(else . elsif) 0 table)
    (puthash '(else . end) 0 table)
    (puthash '(else . guard-sep) 0 table)
    (puthash '(else . if) 0 table)
    (puthash '(else . with) 0 table)
    (puthash '(elsif . elsif) 0 table)
    (puthash '(elsif . end) -1 table)
    (puthash '(elsif . if) 0 table)
    (puthash '(end . begin) 0 table) ;nicer behaviour with abbrev expansion
    (puthash '(end . case) 0 table)
    (puthash '(end . else) 0 table)
    (puthash '(end . elsif) 0 table)
    (puthash '(end . end) -1 table)
    (puthash '(end . for) 0 table)
    (puthash '(end . guard-sep) 0 table)
    (puthash '(end . if) 0 table)
    (puthash '(end . loop) 0 table)
    (puthash '(end . proc) 0 table) ;nicer behaviour with abbrev expansion
    (puthash '(end . record) 0 table)
    (puthash '(end . until) -1 table)
    (puthash '(end . while) 0 table)
    (puthash '(end . with) 0 table)
    (puthash '(end-proc-or-module . begin) 0 table)
    (puthash '(end-proc-or-module . const-type-var) -1 table)
    (puthash '(end-proc-or-module . end) -1 table)
    (puthash '(end-proc-or-module . end-proc-or-module) -1 table)
    (puthash '(end-proc-or-module . proc) 0 table)
    (puthash '(end-proc-or-module . until) -1 table)
    (puthash '(guard-sep . guard-sep) 0 table)
    (puthash '(guard-sep . with) 0 table)
    (puthash '(guard-sep . case) 0 table)
    (puthash '(import . module) 0 table)
    (puthash '(other . begin) 1 table)
    (puthash '(other . case) 1 table)
    (puthash '(other . const-type-var) 1 table)
    (puthash '(other . else) 1 table)
    (puthash '(other . elsif) 1 table)
    (puthash '(other . end) 0 table)
    (puthash '(other . end-proc-or-module) 0 table)
    (puthash '(other . for) 1 table)
    (puthash '(other . if) 1 table)
    (puthash '(other . guard-sep) 1 table)
    (puthash '(other . import) 1 table)
    (puthash '(other . loop) 1 table)
    (puthash '(other . module) 1 table)
    (puthash '(other . record) 1 table)
    (puthash '(other . repeat) 1 table)
    (puthash '(other . proc) 1 table)
    (puthash '(other . until) 0 table)
    (puthash '(other . while) 1 table)
    (puthash '(other . with) 1 table)
    (puthash '(proc . const-type-var) 0 table)
    (puthash '(proc . end) -1 table)
    (puthash '(proc . end-proc-or-module) 0 table)
    (puthash '(proc . import) 0 table)
    (puthash '(proc . module) 1 table)
    (puthash '(proc . proc) 1 table)
    (puthash '(type . const-type-var) 0 table)
    (puthash '(type . end) -1 table)
    (puthash '(type . import) 0 table)
    (puthash '(type . module) 1 table)
    (puthash '(type . proc) 1 table)
    (puthash '(until . end) -1 table)
    (puthash '(until . repeat) 0 table)
    (puthash '(until . until) -1 table)
    (puthash '(var . const-type-var) 0 table)
    (puthash '(var . end) -1 table)
    (puthash '(var . import) 0 table)
    (puthash '(var . module) 1 table)
    (puthash '(var . proc) 1 table)
    table))


(defsubst ob2-get-indent-increment (current parent)
  "Return indentation increment from `ob2-indent-table'.

Gets the indentation increment from `ob2-indent-table' coresponding to
the key '(CURRENT PARENT).  See `ob2-indent-table'."
  (message "(ob2-get-indent-increment %s %s)" current parent)
  (gethash (cons current parent) ob2-indent-table))


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

	  ((ob2-first-case-or-with-case-p)
	   (1- (ob2-calc-indent-normal)))

          ((ob2-comment-before-first-proc-p)
           (- (ob2-calc-indent-normal) ob2-indent-level))
          
          (t (ob2-calc-indent-normal)))))


(defun ob2-first-case-or-with-case-p ()
"Return non-nil if point is on the first CASE or WITH statement.
Non-nil is returned if the first line of the first case of a CASE or
WITH statement starts on a line.  Else returns nil."
  (and (save-excursion
	 (and (ob2-re-search-backward-code ob2-indent-re)
	      (looking-at "\\<\\(CASE\\|WITH\\)\\>")))
       (not (looking-at "|\\|\\(CASE\\|WITH\\)\\>"))
       (let ((saved-point (save-excursion (ob2-re-search-forward-code ":"))))
         (and saved-point
              (= (count-lines (point) saved-point)
                 1)))))


(defun ob2-calc-indent-normal ()
  "Return correct indentation for current line (*normal* cases)."
  (let ((foundp)
        (saved-word)
        (saved-column))

    (save-excursion
      ;; locate first preceeding word matching ob2-indent-re that is not
      ;; matching ob2-looking-at-ref-param-p
      (setq foundp (ob2-re-search-backward-code ob2-indent-re))
      (while (and foundp (ob2-looking-at-ref-param-p))
	(setq foundp (ob2-re-search-backward-code ob2-indent-re)))

      (when foundp
        (setq saved-word (ob2-get-indent-symbol
                          (match-string-no-properties 0)))

	;; special case with end of record
	(when (and (eq saved-word 'end)
		   (save-excursion (back-to-indentation)
				   (looking-at "\\(TYPE\\|VAR\\)\\>")))
	  (setq saved-word 'const-type-var))

        (setq saved-column (current-indentation))))
    
    (if (null saved-word)
        0
      (let ((factor))
        (if (looking-at ob2-indent-interrupt-re)
            (save-excursion               ;place re in match-string
              (ob2-re-search-forward-code ob2-indent-re)
              (setq factor
                    (ob2-get-indent-increment (ob2-get-indent-symbol
                                               (match-string-no-properties
                                                0))
                                              saved-word)))
          (setq factor (ob2-get-indent-increment 'other saved-word)))
        (if (null factor)
            0
          (+ saved-column (* factor ob2-indent-level)))))))


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
 (concat "\\([=#<>+*/&-]\\|<=\\|>=\\|"
         (regexp-opt '("DIV" "IN" "IS" "MOD" "OR") 'words)
         "\\)")
 "Regular expression matching any Oberon-2 operator.")


(defconst ob2-indent-begin-inside-body-re
  (concat "\\(" (regexp-opt '("BEGIN" "CASE" "FOR" "IF" "LOOP" "REPEAT"
                                    "WHILE" "WITH") 'words)
          "\\)")
  "Indentation inside body regexp.

Regular expression matching code inside a module/procedure body that
increments the indentation of the following lines.")


(defun ob2-inside-multi-line-expr-p ()
  "Determine if point is on multi line expression.

Non-nil is returned if point is on row n (n > 1) of an expression that
spans several lines.  Else nil is returned."
  (save-excursion
    (back-to-indentation)
    (or (looking-at ob2-operator-re)
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
  (save-excursion
    (while (and (not (bobp)) (ob2-inside-multi-line-expr-p))
      (backward-to-indentation 1))
    (if (> (count-lines (point)
                        (or (ob2-re-search-forward-code
			     (concat ":=\\|" ob2-indent-begin-inside-body-re))
                            2))
           1)
        (error "Don't know how to indent line")
      (if (save-match-data (string-match ":?=" (match-string-no-properties 0)))
          (progn (goto-char (match-end 0))
                 (current-column))
        (+ (current-indentation) (* ob2-indent-level 2))))))


(defun ob2-comment-before-first-proc-p ()
  "Determine if point is on comment before *first* procedure.

Returns non-nil if point is on the first row of a comment following an
IMPORT, CONST, TYPE or VAR declaration and preceding a procedure
declaration.  Else returns nil."
  (save-excursion
    (back-to-indentation)
    (and (looking-at "(\\*")
	 (save-excursion
	   (and (ob2-re-search-backward-code
		 (concat (ob2-get-indent-re 'import) "\\|"
			 (ob2-get-indent-re 'const-type-var) "\\|"
			 (ob2-get-indent-re 'end-proc-or-module)))
		(not (looking-at (ob2-get-indent-re 'end-proc-or-module)))))
	 (save-excursion
	   (and (ob2-re-search-forward-code ob2-indent-re)
		(string-match (ob2-get-indent-re 'proc)
			      (match-string-no-properties 0)))))))


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
  (let ((column (save-excursion
                  (comment-beginning)
                  (re-search-backward "(\\*")
                  (current-column))))
    (if (looking-at "\\*")
        (1+ column)
      (+ column 2))))


(defun ob2-looking-at-ref-param-p ()
  "Return non-nil if looking at a reference parameter.
Else returns nil."
  (let ((saved-point (save-excursion
                       (save-match-data(ob2-re-search-backward-code
                                        (ob2-get-indent-re 'proc))))))
      (and saved-point
           (looking-at "\\<VAR\\>")
           (> (nth 0 (parse-partial-sexp saved-point (point)))
              0))))


;;;;

;;;###autoload
(defun oberon-2-mode ()
  (interactive)
  (kill-all-local-variables)

  ;; Mode map
  (use-local-map oberon-2-mode-map)

  ;; Syntax table and parsing
  (set-syntax-table oberon-2-mode-syntax-table)
;;   (set (make-local-variable 'beginning-of-defun-function)
;;        'ob2-beginning-of-defun)
;;   (set (make-local-variable 'end-of-defun-function)
;;        'ob2-end-of-defun)

  ;; Indentation
  (set (make-local-variable 'indent-line-function) 'ob2-indent-line)
  
  (setq case-fold-search nil)
  (setq major-mode 'oberon-2-mode)
  (setq mode-name "Oberon-2")
  (run-hooks 'oberon-2-mode-hook))


(provide 'oberon-2-mode)

(defun ob2-indent-buffer-and-save (arg)
  (if (string-match "\\.Mod$" arg)
      (save-excursion
	(find-file arg)
	(oberon-2-mode)
	(indent-region (point-min) (point-max) nil)
	(write-file (concat (substring (file-name-nondirectory arg) 0 -4)
			    ".indent")))))

(defun ob2-indent-all-buffers ()
  (mapcar 'ob2-indent-buffer-and-save command-line-args))
