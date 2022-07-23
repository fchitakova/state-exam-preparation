#lang racket

(define (addIfNew x l) (if (null? (member x l)) (cons x l) l))
(define (annotate db annotators)
(
(lambda (item-labels-pair)
(let ((item (car item-labels-pair)) (labels (cdr item-labels-pair)))
(cons item ( addIfNew labels
(
(lambda (annotator) ) annotators))))) db))