nota(joao, 5.0).
nota(mariana, 9.0).
nota(joaquim, 4.5).
nota(maria, 6.0).
nota(cleuza, 8.5).
nota(mara, 4.0).
nota(joana, 8.0).
nota(jose, 6.5).
nota(mary, 10.0).

nota_do_aluno(X):-
    nota(X, Y), 
    (
        (Y >= 7.0, Y =< 10.0, write('Aprovado'));
        (Y >= 5.0, Y =< 6.9, write('Exame final'));
        (Y >= 0.0, Y =< 4.9, write('Reprovado'))
    ).