#lang racket

;1
(define (subsets lst)
  (if (null? lst) (list '())
      (let ((rest (subsets (cdr lst))))
      (append rest (map (lambda(x) (cons (car lst) x)) rest)))))

;2

;(1) ((1))
;(1 2) ((1 2) (2 1))
;(2 3) ((2 3) (3 2)) -> (1 2 3) (2 3) (3 2) -> (1 2 3) (2 3 1) (3 2 1)
;(permutations '(1 2 3)) -> '((1 2 3) (1 3 2) (2 1 3) (2 3 1) (3 1 2) (3 2 1))
;(1 2 3) ((1 2 3) (2 3 1) (3 1 2))
;(2 3 4) ((2 3 4) (3 4 2) (4 2 3))
;(1 2 3 4) ((1 2 3 4) (2 3 4 1) (3 4 1 2) (4 1 2 3))
;

;(define (placeABeforeB a b lst)
  ;(if (
  ;(cond [(null? lst) '()]
        ;[(= (car lst) b) (append lst a)]
        ;[(cons (car lst) (placeBefore a b (cdr lst)))]))
      

  
;(define (rotations lst)
  ;(cond [(or (null? lst) '(()))]
        ;[(null? (cdr lst) '((car lst)))]
        ;[(append lst (map (placeBefore (car lst) (cadr lst) (rotations (cdr lst)))))]))
        
(define (rotations** lst)
  (define (helper k lst)
    (if (= k 0)
        '()
        (cons lst (helper (- k 1) (append (cdr lst) (list(car lst)))))))
  (helper (length lst) lst))

(define (rotations lst)
  (define (loop lst res)
    (if (member lst res)
        res
        (let ((rotated (append (cdr lst) (list (car lst)))))
        (loop rotated (append res (list lst))))))
  (loop lst '()))

    
(define (rotations* lst)
  (define (loop k lst res)
    (if (= k 0)
        (reverse res)
        (let ((rotated (append (cdr lst) (list (car lst)))))
        (loop (- k 1) rotated (cons lst res)))))
  (loop (length lst) lst '()))


(define (fact n)
  (if (or (= n 1) (= n 0))
      1
      (* n (fact (- n 1)))))
      

;(define (permutations lst)
;  (define (helper k lst)
;    (if (= k 0)
;        '()
 ;   (map (lambda(x) (cons (car lst) x)) (helper (fact (length (cdr lst)))(sort(cdr lst))))


(define (permutations lst)
  (define (helper lst result)
    (if (null? lst) '(())
        (apply append
               (map
                (lambda(x) (map (lambda(y) (cons (car x) y)) (permutations (cdr x))))
                (rotations lst)))))
  (helper lst '()))

(define (get-el-front el lst)
  (define (helper el lst beginning)
          (let ((first (car lst)))
            (if (= el first) (append (list first) (reverse beginning) (cdr lst))
              (helper el (cdr lst) (cons first beginning)))))
  (helper el lst '()))


(define (get-el-front* n lst)
  (define (helper k lst beginning)
          (let ((first (car lst)))
            (if (= k n) (append (list first) (reverse beginning) (cdr lst))
              (helper (+ k 1) (cdr lst) (cons first beginning)))))
  (helper 0 lst '()))

(get-el-front* 0 '(1 2 3 4))

;(define (permutations* lst)
;  (define (helper lst res)
;    (if (null? lst) '(())
;        (let ((head-lst (map (lambda (curr-num) (get-el-front curr-num lst)) lst)) (perms (permutations* (cdr lst))))
;          (map (lambda (perm) (cons (car head-lst) perm) perms) head-lst )
    
      
      
(define (permutations* lst)
  (define (helper lst curr-n res)
    (cond [(null? lst) '(())]
          [(= curr-n (length lst)) res]
          [else (let ((curr-lst (get-el-front* curr-n lst)))
                  (helper lst (+ 1 curr-n) (append res (map (lambda (x) (cons (car curr-lst) x)) (permutations* (cdr curr-lst))) )))]))
          
  (helper lst 0 '()))


(permutations* '(1 2 3 4))

(define (take n lst)
    (if (or (= n 0) (null? lst)) '()
        (cons (car lst)(take (- n 1) (cdr lst)))))
        
(take 3 '(4 5 2 6 5))

(define (sorted? lst)
  (cond [(or (null? lst) (null? (cdr lst))) #t]
        [(> (car lst) (cadr lst)) #f]
        [else (sorted? (cdr lst))]))

(sorted? '(4 6 8 9))
(sorted? '(3 4 6 5 8))
;3 (1 2 3 4) -> ((1 2 3) (1 2 4) (1 3 4) (2 3 4))
;(combinations 2 '(1 2 3 4 5)) -> '((1 2) (1 3) (1 4) (1 5) (2 3) (2 4) (2 5) (3 4) (3 5) (4 5))
(define (combinations k lst)
  (define (helper k lst len res)
    (cond [(= k 0) '(())]
          [(null? lst) '()]
          [(> k len) '(())]
          [(= k len) (list lst)]
          [else (helper k (cdr lst) (- len 1) (append (map (lambda(comb) (cons (car lst) comb)) (combinations (- k 1) (cdr lst))) res))]))
  (helper k lst (length lst) '()))
          
(combinations 2 '(1 2 3 4 5))
  