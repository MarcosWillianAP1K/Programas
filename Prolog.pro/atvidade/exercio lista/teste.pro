%1 questão 
%adicionar
adicionar(Elemento, Lista, NovaLista) :-
    append(Lista, [Elemento], NovaLista).

%remover
remover(X, [X | C], C).
remover(X, [Y | C], [Y | D]) :-
    remover(X, C, D).

%membro
membro(X, [X|_]).
membro(X, [_|Y]):-
    membro(X, Y).

%contatenar
conc([], L, L).
conc([X | L1], L2, [X | L3]) :-
    conc(L1, L2, L3).

%tamanho
tamanho([], 0).
tamanho([_|X], T):-
    tamanho(X, T1), T is T1 + 1.



% 2 questão
intersec([], _, []).
intersec([X|Rest1], L2, [X|Rest2]) :- 
    member(X, L2), intersec(Rest1, L2, Rest2).
    
intersec([_|Rest1], L2, Rest2) :- 
    intersec(Rest1, L2, Rest2).

% 3 questão
inverte([], []).
inverte([X|Rest], Invertida) :- 
    inverte(Rest, RestInvertida), append(RestInvertida, [X], Invertida).

% 4 questão
elementos_iguais([], _, []).
elementos_iguais([X|Rest1], L2, [X|Rest2]) :- 
    member(X, L2), elementos_iguais(Rest1, L2, Rest2).

elementos_iguais([_|Rest1], L2, Rest2) :- 
    elementos_iguais(Rest1, L2, Rest2).

% 5 questão
ordena_e_extremos(Lista, Ordenada, Menor, Maior) :-
    sort(Lista, Ordenada),
    [Menor|_] = Ordenada,
    reverse(Ordenada, [Maior|_]).