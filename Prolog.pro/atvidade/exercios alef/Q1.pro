
imparpar(X):-
    (0 is X mod 2, X =\= 0, write('Par'));
    (X mod 2 =\= 0, write('Impar'));
    (X == 0, write('Nulo')).