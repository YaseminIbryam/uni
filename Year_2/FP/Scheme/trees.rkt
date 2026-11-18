#lang racket

(define empty-tree '())
(define (make-tree root left right) (list root left right))      ; не искаме просто (define make-tree list) - защо?
(define (make-leaf root) (make-tree root empty-tree empty-tree)) ; за удобство
(define root-tree car)
(define left-tree cadr)
(define right-tree caddr)
(define empty-tree? null?)
 
(define test-tree
  (make-tree 10
             (make-tree 7
                        (make-leaf 10)
                        (make-leaf 2))
             (make-tree 3
                        (make-tree 4
                                   (make-leaf 1)
                                   (make-leaf 2))
                        empty-tree)))
 
(define (height t)
  (if (empty-tree? t) 0
      (+ 1 (max (height (left-tree t)) (height  (right-tree t))))))
 
(define (get-level n t)
  (cond [(empty-tree? t) '()]
        [(= n 0) (list (root-tree t))]
      (append (get-level (- n 1) (left-tree t))
              (get-level (- n 1) (right-tree t)))))
 
 
 
 
(define (find-longest-path t)
  (if (empty-tree? t) empty-tree
      (if (> (height (left-tree t)) (height (right-tree t)))
             (cons (root-tree t) (find-longest-path (left-tree t)))
             (cons (root-tree t) (find-longest-path (right-tree t))))))
 
(define (sqr x)
  (* x x))
 
(define (tree-map f t)
  (if (empty-tree? t) empty-tree
      (make-tree (f (root-tree t)) (tree-map f (left-tree t)) (tree-map f (right-tree t)))))
 
 
(define (tree->list t)
  (if (empty-tree? t) empty-tree
      (append (tree->list (left-tree t)) (list (root-tree t)) (tree->list (right-tree t)))))
 
(define (bst-insert val t)
  (cond [(empty-tree? t) (make-leaf val)]
        [(> val (root-tree t)) (make-tree (root-tree t) (left-tree t) (bst-insert val (right-tree t)))]
        [else (make-tree (root-tree t) (bst-insert val (left-tree t)) (right-tree t))]))
 
(define (tree-srt lst)
  (tree->list (foldl bst-insert empty-tree lst)))

(define (leaf? t)
  (and (empty-tree? (left-tree t)) (empty-tree? (right-tree t))))

(define (prune t)
  (cond [(empty-tree? t) empty-tree]
        [(leaf? t) empty-tree]
        [else (make-tree (root-tree t) (prune (left-tree t)) (prune (right-tree t)))]))

(define (bloom t)
  (cond[(empty-tree? t) empty-tree]
       [(leaf? t) (make-tree (root-tree t) (make-leaf (root-tree t)) (make-leaf (root-tree t)))]
       [else (make-tree (root-tree t) (bloom (left-tree t)) (bloom (right-tree t)))]))

(define (max-min-average t)
  (/ (+ (apply max (tree->list t)) (apply min (tree->list t))) 2))

(define (avg t)
  (if (or (empty-tree? t) (leaf? t)) t
      (make-tree (max-min-average t) (avg (left-tree t)) (avg (right-tree t)))))

(define (avg* t)
  (if (or (empty-tree? t) (leaf? t)) t
      (make-tree (max-min-average t) (avg (left-tree t)) (avg (right-tree t)))))

(define (same-as-code t)
  (define (helper t code)
    (let ((left-code (* 2 code))
          (right-code (+ (* 2 code) 1)))
          (cond [(empty-tree? t) '()]
                [(= code (root-tree t)) (cons (root-tree t) (append (helper (left-tree t) left-code) (helper (right-tree t) right-code)))]
                [else (append (helper (left-tree t) left-code) (helper (right-tree t) right-code))])))
  (helper t 1))
  