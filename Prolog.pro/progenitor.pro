progenitor(jose, maria).
progenitor(fernanda, maria).
progenitor(marcos, joao).
progenitor(giseli, joao).
progenitor(marcos, cleiton).
progenitor(giseli, cleiton).

masculino(marcos).
masculino(jose).
masculino(joao).
masculino(cleiton).

feminino(fernanda).
feminino(giseli).
feminino(maria).


pai(X, Y):-
    progenitor(Y, X), masculino(Y).