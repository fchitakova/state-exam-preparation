#lang racket

(define (addDefault val l)
  (if (null? l) (list val) l))

(define (sumMinFix fl xl)
  (apply + (filter (lambda(f) (apply min (addDefault 0 (filter (lambda (x) (= (f x) x)) xl)))) fl)))

(define fl (list (lambda (x) (/ 1 x)) exp (lambda (x) (- (* 2 x) 3))))
(define xl '(-2 -1 1 3))

(sumMinFix fl '(-2 -1 1 3))