intervalo(X, Y):-
    X < Y - 1, X1 is X + 1, write(X1), nl, intervalo(X1, Y).