;; Legger alle ~filene i ~/.emacs.d/backups/
(setq backup-directory-alist
      `(("." . ,(concat user-emacs-directory "backups"))))

;; Legger alle #filene# i ~/.emacs.d/backups/
(setq auto-save-file-name-transforms
  `((".*" "~/.emacs.d/backups/" t)))

;; Hide splash-screen and startup-message
(setq inhibit-splash-screen t)
(setq inhibit-startup-message t)

