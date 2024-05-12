divisiveis(X, Y):-
    X =< Y, ((Y mod X =:= 0, write(X), nl) ; X1 is X + 1, divisiveis(X1, Y)).