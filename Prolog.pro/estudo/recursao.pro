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

parente(X,Y):-
    (genitor(X,Y) ; (genitor(X, W), parente(W, Y))) ; (genitor(Y, X) ; (genitor(W, X), parente(W, Y))).

