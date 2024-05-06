cantos(quadrado, sim).
cantos(rentangulo, sim).
cantos(circulo, nao).

lados(quadrado, sim).
lados(rentangulo, nao).
lados(circulo, sim).

qual_forma():-
    write('Sua forma possui cantos?\n'), 
    read(X),
    write('\nSua forma possui lados iguais?\n'), 
    read(Y),
    cantos(F, X), lados(F, Y), write(F).
