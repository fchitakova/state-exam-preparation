#lang racket

(define products (list '(11 3.50) '(12 6.30) '(13 7.7) '(14 110) '(15 4.50) '(16 7.30) '(17 8.70) '(18 8.70)))
(define basket (list 11  12 13))

(define (bestFit code) (caar (filter (lambda(x) (equal? (cadr x) (+ (cadr (assoc code products)) 1.00))) products)))



(define (recommended basket bestFit products)
 (define (findPrice product) (cadr (assoc product products)))
 (define basketCost (apply + (map findPrice basket)))
  (filter 
   (lambda (product) (and (not (member product basket)) (<= (findPrice product) basketCost)))
   (map bestFit basket)))
  
         
    