regiao(espirito_santo, sudeste).
regiao(minas_gerais, sudeste).
regiao(rio_de_janeiro, sudeste).
regiao(sao_paulo, sudeste).

capital(vitoria, espirito_santo).
capital(belo_horizonte, minas_gerais).
capital(rio_de_janeiro, rio_de_janeiro).
capital(sao_paulo, sao_paulo).

e_do_sudeste(X) :-
    regiao(X, sudeste).

qual_e_a_capital(X) :-
    capital(Y, X), e_do_sudeste(X),
    write(Y). 

regioes_do_sudeste(X) :-
    regiao(X, sudeste), write(X), regioes_do_sudeste(X  ).  