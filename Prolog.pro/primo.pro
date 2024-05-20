progenitor(u, w).
progenitor(u,z).
progenitor(z, x).
progenitor(w, y).


irmao(X, Y):-
    progenitor(U, X), progenitor(U, Y), Z \= W.

primo(X, Y):-
    progenitor(Z, X), progenitor(W,Y), irmao(Z, W).