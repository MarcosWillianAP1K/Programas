
ligacao(1, 2).
ligacao(1, 3).
ligacao(2, 4).
ligacao(3, 4).
ligacao(3,6).
ligacao(4, 6).
ligacao(5,6).


caminhoaux(X, Y):-
    (ligacao(X, Y), write(Y)), ! ; (ligacao(Y, X), write(Y)), !.

caminhoaux(X, Y):-
    ligacao(X, W),
    write(W), write(' -> '),
    caminhoaux(W, Y), !.


caminho(X, Y):-
    write(X), !, X \=Y,write(' -> '), caminhoaux(X, Y).