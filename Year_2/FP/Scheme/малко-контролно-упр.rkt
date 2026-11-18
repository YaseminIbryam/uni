#lang racket


(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a)
          (accumulate op nv (next a) b term next))))

(define (accumulate-i op nv a b term next)
  (if (> a b) nv
      (accumulate-i op (op nv (term a)) (next a) b term next)))

(define (path1 i)
  (cond [(= i 1) (cons -7 2)]
        [(= i 2) (cons 3 -3)]
        [(= i 3) (cons 1 5)]))

(define (++ x)
  (+ x 1))

(define (destination f n)
  (accumulate (lambda (x y) (cons (+(car x) (car y)) (+ (cdr x)  (cdr y))))
              (cons 0 0)
              1 n
              (lambda (i) (f i))
              ++))
(define (-- x)
  (- x 1))
(define (id i)
  i)
  

(define (square x)
  (* x x))
(define (path-length f n)
  (accumulate + 0
              1 n
              (lambda (i) (sqrt (+ (square (car (f i))) (square(cdr (f i))))))
              ++))
              
(define (clamp x b)
  (cond [(< x (- 0 b)) (- 0 b)]
        [(> x b) b]
        (else x)))

(lambda (x y) (cons (+(car x) (car y)) (+ (cdr x)  (cdr y))))

(define (destination* f n bounds)
  (accumulate-i (lambda (x y) (cons (clamp (+(car x) (car y)) (car bounds)) (clamp (+ (cdr x)  (cdr y)) (cdr bounds))))
              (cons 0 0)
              1 n
              (lambda (i) (f i))
              ++))
  
              
              