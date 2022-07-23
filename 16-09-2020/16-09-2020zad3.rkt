#lang scheme

(define l '(("Mozart" "The Marriage of Figaro Overture" 270) ("Gershwin"
"Summertime" 300) ("Queen" "Bohemian Rhapsody" 355) ("Gershwin" "Rhapsody in Blue" 1100)))

(define (avgDuration artist)  (/ (apply + (map (lambda (x) (car (reverse x))) (filter (lambda(x) (equal? (car x) artist)) l)))  (length (filter (lambda(x) (equal? (car x) artist)) l))))
