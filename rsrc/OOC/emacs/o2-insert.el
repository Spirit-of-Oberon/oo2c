(define-key o2-mode-map "\C-cm" 'o2-insert-module)
(define-key o2-mode-map "\C-cp" 'o2-insert-procedure)
(define-key o2-mode-map "\C-ct" 'o2-insert-typebound-procedure)
(define-key o2-mode-map "\C-c\C-t" 'o2-insert-typebound-redef)
(define-key o2-mode-map "\C-ci" 'o2-insert-if)
(define-key o2-mode-map "\C-cc" 'o2-insert-case)
(define-key o2-mode-map "\C-c\C-w" 'o2-insert-with)
(define-key o2-mode-map "\C-ce" 'o2-insert-else)
(define-key o2-mode-map "\C-c\C-e" 'o2-insert-elsif)
(define-key o2-mode-map "\C-cb" 'o2-insert-branch)
(define-key o2-mode-map "\C-cf" 'o2-insert-for)
(define-key o2-mode-map "\C-cw" 'o2-insert-while)
(define-key o2-mode-map "\C-cr" 'o2-insert-repeat)
(define-key o2-mode-map "\C-cl" 'o2-insert-loop)
(define-key o2-mode-map "\C-c\C-r" 'o2-insert-record)
(define-key o2-mode-map "\C-ch" 'o2-insert-header)

(let ((imap (make-sparse-keymap "Oberon-2 Insert")))
  (define-key imap [o2-insert-record] '("RECORD" . o2-insert-record))
  (define-key imap [o2-insert-loop] '("LOOP" . o2-insert-loop))
  (define-key imap [o2-insert-repeat] '("REPEAT..." . o2-insert-repeat))
  (define-key imap [o2-insert-while] '("WHILE..." . o2-insert-while))
  (define-key imap [o2-insert-for] '("FOR..." . o2-insert-for))
  (define-key imap [o2-insert-branch] '("|" . o2-insert-branch))
  (define-key imap [o2-insert-else] '("ELSE" . o2-insert-else))
  (define-key imap [o2-insert-with] '("WITH..." . o2-insert-with))
  (define-key imap [o2-insert-case] '("CASE..." . o2-insert-case))
  (define-key imap [o2-insert-elsif] '("ELSIF..." . o2-insert-elsif))
  (define-key imap [o2-insert-if] '("IF..." . o2-insert-if))
  (define-key imap [o2-insert-typebound-redef] 
    '("Type-bound Redef..." . o2-insert-typebound-redef))
  (define-key imap [o2-insert-typebound-procedure] 
    '("Type-bound Proc..." . o2-insert-typebound-procedure))
  (define-key imap [o2-insert-procedure]
  '("Procedure..." . o2-insert-procedure))
  (define-key imap [o2-insert-module] '("Module..." . o2-insert-module))

  (define-key o2-mode-map [menu-bar o2 o2-insert] (cons "Insert" imap)))


(defun o2-insert-block-suffix (label)
  (o2-newline)
  (o2-newline)
  (insert "END")
  (if o2-block-suffix
  (insert " (* " label " *)"))
  (insert ";")
  (end-of-line 0))

(defun o2-insert-case (expr)
  "Build skeleton CASE statment, prompting for the <expression>."
  (interactive "*sCase expression: ")
  (insert "CASE " expr " OF")
  (o2-insert-block-suffix "case")
  (insert "| "))

(defun o2-insert-else ()
  "Insert ELSE keyword and indent for next line."
  (interactive "*")
  (o2-newline)
  (backward-delete-char-untabify o2-indent nil)
  (insert "ELSE")
  (o2-newline)
  (o2-tab))

(defun o2-insert-branch ()
  "Indent for next line and insert '|'."
  (interactive "*")
  (o2-newline)
  (if (not 
       (save-excursion
	 (forward-line -1)
	 (looking-at "[ \t]*|")))
  (backward-delete-char-untabify o2-indent nil))
  (insert "| "))

(defun o2-insert-for (init end by)
  "Build skeleton FOR loop statment, prompting for the loop parameters."
  (interactive "*sInit: \nsend: \nsby: ")
  (insert "FOR " init " TO " end)
  (if (not (string-equal by ""))
  (insert " BY " by))
  (insert " DO")
  (o2-insert-block-suffix "for")
  (o2-tab))

(defun o2-insert-header (title)
  "Insert a comment block containing the module title, author, etc."
  (interactive "*sModule title: ")
  (insert "(*\n    Title: \t" title)
  (insert "\n    Created:\t")
  (insert (current-time-string))
  (insert "\n    Author: \t")
  (insert (user-full-name))
  (insert (concat "\n\t\t<" (user-login-name) "@" (system-name) ">\n"))
  (insert "*)\n\n"))

(defun o2-insert-elsif (guard)
  "Insert ELSIF part, prompting for the guard."
  (interactive "*sGuard: ")
  (o2-newline)
  (backward-delete-char-untabify o2-indent nil)
  (insert "ELSIF " guard " THEN")
  (o2-newline)
  (o2-tab))

(defun o2-insert-if (guard)
  "Insert skeleton IF statment, prompting for the guard."
  (interactive "*sGuard: ")
  (insert "IF " guard " THEN")
  (o2-insert-block-suffix "if")
  (o2-tab))

(defun o2-insert-loop ()
  "Build skeleton LOOP."
  (interactive "*")
  (insert "LOOP")
  (o2-insert-block-suffix "loop")
  (o2-tab))

(defun o2-insert-module (name)
  "Build skeleton MODULE, prompting for <module-name>."
  (interactive 
  (list (progn
	  (barf-if-buffer-read-only)
	  (read-from-minibuffer 
	   "Module name: "
	   (if (buffer-file-name)
	       (let ((file-name (file-name-nondirectory (buffer-file-name))))
		 (if (string-match "\\([a-zA-Z0-9]+\\)\\.Mod" file-name)
		     (substring file-name 0 (match-end 1)))))
	   nil nil 'o2-module-history))))
  (insert "MODULE " name ";\n\n\nBEGIN\n")
  (o2-tab)
  (insert "\nEND " name ".\n")
  (previous-line 4))

(defun o2-insert-typebound-procedure (name receiver args result)
  "Insert skeleton PROCEDURE, prompting for <name>, <receiver>, <parameters> 
and the <result-type>." 
  (interactive (o2-interactive-strings
		'(("Procedure name: " . o2-proc-history)
		  ("Receiver: " . o2-receiver-history)
		  ("Formal parameters: " . o2-fpar-history)
		  ("Result type: " . o2-result-history))
		'barf-if-read-only))
  (insert "PROCEDURE ")
  (if receiver
  (insert "(" receiver ") "))
  (insert name)
  (if (not (and (string-equal args "") (string-equal result "")))
  (insert " (" args ")"))
  (if (not (string-equal result ""))
  (insert ": " result))
  (insert ";")
  (o2-newline)
  (o2-tab)
  (insert "BEGIN")
  (o2-newline)
  (o2-newline)
					; remove export mark from procedure name
  (if (eq (aref name (1- (length name))) ?*)
  (setq name (substring name 0 (1- (length name)))))
  (insert "END " name ";")
  (o2-newline)
  (backward-delete-char-untabify o2-indent)
  (o2-newline)
  (end-of-line -2)
  (o2-tab))

(defun o2-insert-typebound-redef (name receiver)
  "Insert skeleton PROCEDURE, prompting for <name> and <receiver>.  The remaining
parameters (the formal parameter list including the result type, and the export
flag) will be copied from the exisiting definition of the procedure <name> for the receiver's base type."
  (interactive (o2-interactive-strings
		'(("Procedure name: " . o2-proc-history)
		  ("Receiver: " . o2-receiver-history))
		'barf-if-read-only))
  (let* ((rec-type (if (string-match ":[ \t\n]*\\(\\w+\\)[ \t\n]*" receiver)
		       (substring receiver (match-beginning 1) (match-end 1))
		     (error "Can't extract data type from receiver")))
	 (simple-name (if (string-match "[ \t\n*-]" name)
			  (substring name 0 (match-beginning 0))
			name))
	 (base (save-excursion
		 (o2-find-typebound-procedure-noselect rec-type simple-name)))
	 proc-attribs formal-pars result)
  (save-excursion 
    (set-buffer (car base))
    (goto-char (cdr base))
    (setq proc-attribs (o2-get-procedure))
    (setq formal-pars (nth 6 proc-attribs))
    (if (string-match "(\\(.*\\))[ \t\n]*\\(:[ \t\n]*\\(\\w+\\)[ \t\n]*\\)?"
		      formal-pars)
	(setq result (if (match-end 3)
			 (substring formal-pars 
				    (match-beginning 3) 
				    (match-end 3))
		       "")
	      formal-pars (substring formal-pars 
				     (match-beginning 1) 
				     (match-end 1)))
      (setq result ""
	    formal-pars "")))
  (o2-insert-typebound-procedure (concat simple-name (nth 5 proc-attribs))
				 receiver
				 formal-pars
				 result)))

(defun o2-insert-procedure (name args result)
  "Insert skeleton PROCEDURE, prompting for <name>, <parameters> and the
<result-type>." 
  (interactive (o2-interactive-strings
		'(("Procedure name: " . o2-proc-history)
		  ("Formal parameters: " . o2-fpar-history)
		  ("Result type: " . o2-result-history))
		'barf-if-read-only))
  (o2-insert-typebound-procedure name nil args result))

(defun o2-insert-with (guard)
  "Build skeleton WITH statement, prompting for the type guard."
  (interactive "*sType guard: ")
  (insert "WITH " guard " DO")
  (o2-insert-block-suffix "with")
  (o2-tab))

(defun o2-insert-record ()
  "Insert a RECORD outline."
  (interactive "*")
  (insert "RECORD")
  (o2-insert-block-suffix "record")
  (o2-tab))

(defun o2-insert-repeat (expr)
  "Build a REPEAT-UNTIL statement, prompting for the <expression>."
  (interactive "*sUntil expression: ")
  (insert "REPEAT")
  (o2-newline)
  (o2-newline)
  (insert "UNTIL " expr ";")
  (end-of-line 0)
  (o2-tab))

(defun o2-insert-while (guard)
  "Insert a WHILE statement, prompting for the <guard>."
  (interactive "*sWhile guard: ")
  (insert "WHILE " guard " DO")
  (o2-insert-block-suffix "while")
  (o2-tab))
