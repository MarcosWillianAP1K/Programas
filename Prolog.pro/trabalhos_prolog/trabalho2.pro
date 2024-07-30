:- dynamic paciente/2.

% paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, glicose], diabete)
paciente([maria, feminino, 37, nao, nao, passado, 30.5, 5.7, 100], nao).
paciente([gorete, feminino, 53, nao, nao, passado, 26.37, 4.5, 112], nao).
paciente([pedro, masculino, 54, nao, nao, nunca, 31.86, 6.6, 145], nao).
paciente([juliana, feminino, 37, nao, nao, passado, 21.25, 6.1, 200], nao).
paciente([catisvalda, feminino, 56, nao, nao, nunca, 30.95, 6.5, 145], nao).
paciente([ursulino, masculino, 79, nao, nao, passado, 31.19, 5.8, 155], nao).
paciente([jose, masculino, 67, nao, nao, sim, 27.32, 6.8, 220], sim).
paciente([marta, feminino, 74, nao, nao, sim, 29.51, 8.2, 240], sim).
paciente([jussara, feminino, 37, nao, nao, passado, 36.87, 8.8, 160], sim).
paciente([katia, feminino, 65, sim, sim, nunca, 33.55, 8.9, 202], sim).
paciente([marcelo, masculino, 55, nao, sim, passado, 30.42, 6.2, 300], sim).
paciente([ayla, feminino, 61, nao, nao, passado, 34.45, 6.5, 280], sim).
paciente([rafaela, feminino, 58, sim, nao, nunca, 38.31, 7.0, 200], sim).
paciente([cassia, feminino, 61, nao, nao, sim, 30.11, 6.2, 240], sim).
paciente([elisa, feminino, 26, nao, nao, passado, 27.32, 4.0, 200], nao).
paciente([alice, feminino, 74, nao, nao, passado, 28.12, 5.0, 100], nao).
paciente([jade, feminino, 45, sim, nao, nunca, 23.05, 4.8, 130], nao).
paciente([heloise, masculino, 56, nao, nao, nunca, 26.78, 4.8, 200], nao).
paciente([benicio, masculino, 20, nao, nao, passado, 23.04, 5.7, 160], nao).
paciente([paulo, masculino, 70, nao, nao, passado, 15.94, 5.8, 158], nao).
paciente([otavio, masculino, 30, nao, nao, passado, 15.8, 6.2, 90], nao).
paciente([isis, feminino, 80, nao, nao, nunca, 22.04, 9.0, 209], sim).
paciente([francivaldo, masculino, 63, nao, sim, passado, 27.32, 6.6, 300], sim).
paciente([juvelino, masculino, 58, nao, nao, passado, 32.38, 6.6, 159], sim).
paciente([maya, feminino, 43, sim, nao, nunca, 34.21, 9.0, 160], sim).
paciente([genetildes, masculino, 56, nao, nao, nunca, 37.59, 4.0, 159], nao).
paciente([waldisney, masculino, 60, nao, nao, passado, 25.4, 4.0, 200], nao).
paciente([reinaldo, masculino, 27, nao, nao, passado, 27.32, 3.5, 100], nao).
paciente([frederico, masculino, 54, nao, nao, passado, 30.41, 5.0, 158], nao).

procurar_paciente([Nome | _]):-
    paciente([Nome|_], _).

%REMOVER(passa ao menos o nome que deseja remover)
remover_paciente([Nome | _]):-
    retract(paciente([Nome | _], _)).

nomes([N1|_], [N2 | _]):-
    N1 == N2.

%ADICIONAR PACIENTE(Informacoes do paciente, e seu estaod diabetico)
adicionar_paciente(Novopaciente, Diagnostico):-
    \+ procurar_paciente(Novopaciente),
    assertz(paciente(Novopaciente, Diagnostico)).

%EDITAR PACIENTE (passa ao menos o nome do paciente que deseja modificar, e passa as de um novo, e seu estado de diabete)
editar_paciente(Paciente, Novopaciente, Diabetes):- 
    procurar_paciente(Paciente),
    (nomes(Paciente,Novopaciente) -> true; \+ procurar_paciente(Novopaciente)),
    remover_paciente(Paciente),
    assertz(paciente(Novopaciente, Diabetes)).

%CALCULAR IMC
calcular_IMC(Peso, Altura):- 
    IMC is Peso / (Altura * Altura), write(IMC).

tamanho_da_lista([], 0).
tamanho_da_lista([_| Y], N):-
    tamanho_da_lista(Y, Aux), N is Aux + 1.


%DIAGNOSTICAR (deve passar as Informacoes do paciente, não precisa passar o seu diabete)
diagnosticar(X):-
    tamanho_da_lista(X, Y), (Y < 9 -> write('Informacoes insuficientes, fazer mais exames')).

diagnosticar([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose]):-
    \+ procurar_paciente(Nome),
    calcular_pontuacao(Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose, 0, PontuacaoFinal),
    write('Pontuacao final: '), write(PontuacaoFinal), nl,
    retract(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], _)),
    ((PontuacaoFinal / 7) > 0.4 ->
        assertz(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], sim));
        assertz(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], nao))
    ), 
    paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], X), write(X).

    
calcular_pontuacao(Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose, PontuacaoAtual, PontuacaoFinal) :-
    nova_pontuacao(Idade > 50, PontuacaoAtual, Pontuacao1),
    nova_pontuacao(Hipertensao == sim, Pontuacao1, Pontuacao2),
    nova_pontuacao(Cardiaco == sim, Pontuacao2, Pontuacao3),
    nova_pontuacao((Fumante == passado ; Fumante == sim), Pontuacao3, Pontuacao4),
    nova_pontuacao(IMC > 30.0, Pontuacao4, Pontuacao5),
    nova_pontuacao(Hemoglobina > 7.0, Pontuacao5, Pontuacao6),
    nova_pontuacao(Glicose > 200, Pontuacao6, PontuacaoFinal).
    
nova_pontuacao(Condicao, PontuacaoAtual, PontuacaoAtualizada) :-
    (Condicao -> PontuacaoAtualizada is PontuacaoAtual + 1 ; PontuacaoAtualizada = PontuacaoAtual).

%aqui apenas printa o banco de dados
printar():-
    paciente(X, Y), write(X), write(Y).