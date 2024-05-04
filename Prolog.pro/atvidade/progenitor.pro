progenitor(filo, joao).
progenitor(pedro, joao).
progenitor(maria, jose).
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).

%familia adcionada
progenitor(weudes, fernanda).
progenitor(weudes, marcos).
progenitor(eduarda, fernanda).
progenitor(eduarda, marcos).
progenitor(fernanda, julia).
progenitor(fernanda, iris).

%familia adcionada
sexo(weudes, masculino).
sexo(marcos, masculino).
sexo(eduarda, feminino).
sexo(fernanda, feminino).

sexo(filo, feminino).
sexo(pedro, masculino).
sexo(jose, masculino).
sexo(maria, feminino).
sexo(joao, masculino).
sexo(ana, feminino).
sexo(iris, feminino).
sexo(julia, feminino).
sexo(jorge, masculino).





pai_de(X, Y) :-
	progenitor(Y, X), 
	sexo(Y, masculino).

mae_de(X, Y) :-
	progenitor(Y, X), 
	sexo(Y, feminino).

filho_de(X, Y) :-
	progenitor(X, Y), 
	sexo(Y, masculino).

filha_de(X, Y) :-
	progenitor(X, Y), 
	sexo(Y, feminino).

irmao_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(Z, Y), 
	sexo(Y, masculino), X \= Y.

irma_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(Z, Y), 
	sexo(Y, feminino), X \= Y.

tio_de(X, Y) :-
	progenitor(Z, X), 
	irmao_de(Z, Y).


tia_de(X, Y) :-
	progenitor(Z, X), 
	irma_de(Z, Y).

avom_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(Y, Z), 
	sexo(Y, masculino).


avof_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(Y, Z), 
	sexo(Y, feminino).

bisavom_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(W, Z), 
	progenitor(Y, W), 
	sexo(Y, masculino).

bisavof_de(X, Y) :-
	progenitor(Z, X), 
	progenitor(W, Z), 
	progenitor(Y, W), 
	sexo(Y, feminino).

antepassado_de(X,Y) :-
	progenitor(Z,X),
	antepassado(Z,Y).

cunhado_de(X, Y):-
	progenitor(X, W), 
	progenitor(E, W), 
	irmao_de(E, Y), 
	X \= E.

cunhada_de(X, Y):-
	progenitor(X, W), 
	progenitor(E, W), 
	irma_de(E, Y), 
	X \= E.

sogro_de(X, Y):-
	progenitor(X, W),
	progenitor(E, W),
	pai_de(E, Y),
	X \= E.

sogra_de(X, Y):-
	progenitor(X, W),
	progenitor(E, W),
	mae_de(E, Y),
	X \= E.