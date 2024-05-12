genitor(pam, bob).
genitor(tom, bob).
genitor(tom, liz).
genitor(bob, ann).
genitor(bob, pat).
genitor(pat, jim).


antecedentes(X):- 
    genitor(Y, X), write(Y), write('\n'), antecedentes(Y).

descendentes(X):-
    genitor(X,Y),  write(Y), write('\n'), descendentes(Y).

parenteaux(X,Y):-
    (genitor(Y, X) ; (genitor(W, X), parenteaux(W, Y))), !.

parente(X,Y):-
    (genitor(X,Y) ; (genitor(X, W), parente(W, Y))), !.

parente(X,Y):-
    (genitor(Y, X) ; (genitor(W, X), parenteaux(W, Y))).


fatorial(0, 1).

fatorial(N, F):-
    N > 0, 
    N1 is N - 1,
    fatorial(N1, F1),
    F is N * F1. 