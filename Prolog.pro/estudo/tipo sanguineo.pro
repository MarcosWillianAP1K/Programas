doa(a, a).
doa(a, o).
doa(b, b).
doa(b, o).
doa(ab, a).
doa(ab, b).
doa(ab, ab).
doa(ab, o).
doa(o, o).

recebe(a, a).
recebe(a, ab).
recebe(b, b).
recebe(b, ab).
recebe(ab, ab).
recebe(o, o).
recebe(o, a).
recebe(o, b).
recebe(o, ab).

quais_recebe(X) :-
    recebe(X, Y),
    write("recebe: "),
    write(Y).

quais_doa(X) :-
    doa(X, Y),
    write("doa: "),
    write(Y).

quais_recebe_e_doa(X) :-
    quais_recebe(X); quais_doa(X).

tipo_pode_doar_para(X, Y) :-
    doa(X, Y).

tipo_pode_receber_de(X, Y) :-
    recebe(X, Y).