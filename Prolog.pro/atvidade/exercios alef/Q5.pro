
nota(joao, 5.0).
nota(maria, 6.0).
nota(junior, 2.0).
nota(joana, 8.0).
nota(mariana, 9.0).
nota(joaquim, 4.5).
nota(cleuza, 8.5).
nota(mara, 4.0).
nota(jose, 6.5).
nota(mary, 10.0).
nota(lima, 3.5).


situacao:-
    nota(X, Y),
    (Y >= 7.0, write(X), write(' esta aprovado'), nl);
    (Y >= 4.0 , Y < 7.0, write(X), write(' esta de recuperacao'), nl);
    (Y < 4.0, write(X), write(' esta reprovado'), nl).