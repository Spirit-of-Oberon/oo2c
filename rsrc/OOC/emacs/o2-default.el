;; set load-path to incorporate directory with oberon2.el
;(setq load-path (cons "/usr/local/lib/oo2c" load-path))

;; auto load oberon2.el if oberon-2-mode is called; this assumes that 
;; oberon2.el is in the load-path
(autoload 'oberon-2-mode "oberon2" "The Oberon-2 major mode." t)

;; set oberon-2-mode as major mode for all files ending in ".Mod"
(setq auto-mode-alist (cons '("\\.Mod$" . oberon-2-mode) auto-mode-alist))

;; make Emacs file name completion ignore symbol files
(setq completion-ignored-extensions 
      (append (list ".Sym" ".Lib") completion-ignored-extensions))


;; turn on font-lock mode for Oberon-2 buffers
(add-hook 'oberon-2-mode-hook 
	  (lambda ()
	    ;(o2-font-lock-hilit-colors) ;; change some font-lock colors
	    (turn-on-font-lock)))
;; tell font-lock to use  maximum decorations:
(setq font-lock-maximum-decoration t)
;; enable font-lock mode for all buffers:
;(global-font-lock-mode t)


;; set Oberon-2 specific highlighting for hilit19; use of this mode is
;; deprecated, consider using font-lock mode instead
;(cond (window-system
;       (require 'hilit19)
;       (setq hilit-auto-highlight-maxout 200000)
;       (hilit-set-mode-patterns
;	'(o2-mode oberon-2-mode)
;	'(("(\\*" "\\*)" comment)
;	  ("<\\*" "\\*>" define)
;	  ("\"[^\n\"]*\"\\|\'[^\n\']*\'" 0 string)
;	  ("^[ \t]*PROCEDURE" nil defun)
;	  ("\\<\\(RECORD\\|ARRAY\\|OF\\|POINTER\\|TO\\|BEGIN\\|END\\|FOR\\|BY\\|IF\\|THEN\\|ELSE\\|ELSIF\\|CASE\\|WHILE\\|DO\\|MODULE\\|FROM\\|RETURN\\|IMPORT\\|VAR\\|LOOP\\|UNTIL\\|OR\\|DIV\\|MOD\\|EXIT\\|IN\\|IS\\|REPEAT\\|WITH\\|CONST\\|TYPE\\)\\>" nil keyword)))))


;; put compilation buffers in upper right corner of the display; note: this
;; does not work correctly under Emacs 20.2
;; (if window-system
;;     (let ((o2-frame-params '((height . 10)
;; 			     (unsplittable . t) (menu-bar-lines . 0)
;; 			     (left . (- 0)) (top . 0) (user-position . t)
;; 			     (font . "5x7") (width . 60) (auto-raise . t) 
;; 			     (vertical-scroll-bars . nil) (auto-lower . t)
;; 			     (name . "o2-compilation"))))
;;       (setq special-display-regexps
;; 	    `(("^\\*o2-compile.*\\*$" . ,o2-frame-params)
;; 	      ("^\\*o2-make.*\\*$" . ,o2-frame-params)))))


;; add menubar item with an index of the procedures, type-bound procedures,
;; and record declarations of the module; note: this does not work with
;; Emacs version 20.2, but has been fixed in 20.3
(add-hook 'oberon-2-mode-hook
	  (lambda ()
	    (imenu-add-to-menubar "Index")))


;; redefine some function keys for oberon-2 mode: put `next error' on F8, `find
;; def under cursor' on F9, and `redo last make' on F12
(add-hook 
 'oberon-2-mode-hook 
 (lambda ()
   (local-set-key [f8] 'next-error)
   (local-set-key [f9] 'o2-find-def-under-cursor)
   (local-set-key [f12] (lambda () (interactive) (o2-make o2-make-command)))))
