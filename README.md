Logic Project: Existential Graph Convertor

I coded a convertor from Existential Graphs to Propositional Logic/Boolean Algebra. I used C++ for this program.

If you take a horizontal cut of the existential graph, so that the ends of the circle are cut off, it can be presented in the following manner

Input: P  Output: P
Input: (P)  Output: ~P
Input: PQ   Output: P & Q
Input: (PQ)   Output: ~P | ~Q
Input: ((P)(Q))   Output: P | Q
Input: (P(Q))   Output: P->Q

This is to say that each () is a nested level.
The program works by asking the user to input a sentence with the input Format, and then performing DeMorgan’s on each individual nested level, working inside to out. It will reduce the sentence to it’s atomics.

It can also notice a pattern in sentences like [¬A ∨ B] and create an additional output [A ⟶  B]
It uses these “hard” brackets to notate an area that should have a property distributed across it
 A(A(B))=>
A ∧ [¬A ∨ B]
A ∧ [A ⟶  B]


Flaws:
As of right now, it only notices the patterns as shown above (shouldn’t be too challenging to find new patterns)
If you input a sentence like (A(A(B))) it will output [¬A ∨ A ∧ ¬B] instead of ¬A ∨ [A ∧ ¬B]
I am not acquainted with website making, and wasn’t able to make an easily accessible version of this. It is very much still in beta testing
This project was incredibly rushed due to poor time management, there are definitely bugs that I haven’t even thought of testing

Inputs to Try:
A
AB
(A)
(AB)
A(B)
(A(B))
A(A(B))
CDE
(ABCDE)
Try something fun? Might work?
