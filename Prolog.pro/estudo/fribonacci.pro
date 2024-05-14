fribonaci(0,1).



fribonaciaux(P1, P2):-
    write(P2),nl,
    P3 is (P1+ P2),
    fribonaciaux(P2, P3), !.

fribonaci(P1, P2):-
    write(P1),nl, write(P2),nl, 
    P3 is P1 + P2,
    fribonaciaux(P2,P3), !.