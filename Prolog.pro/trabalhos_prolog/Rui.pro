:- dynamic paciente/2.

%paciente([nome,sexo,idade,hipertenso,cardiaco,fumante,IMC,hemoglobina,glicose,diabetes])
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
paciente([ayla,feminino, 61, nao, nao, passado, 34.45, 6.5, 280], sim).
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



%procurar nomes iguais
procurar([Nome, _, _, _, _, _, _, _, _]):-
    paciente([Nome, _, _, _, _, _, _, _, _], _).

%verificar se os nomes são iguais
verificar_nomes([Nome1|_], [Nome2 | _]):-
    Nome1 == Nome2.

% Adicionar paciente
adicionar_paciente([Nome, Sexo, Idade, Tabagismo, Hipertensao, Historico, Peso, Altura, Glicose], Diabetes) :-
    \+ procurar([Nome, Sexo, Idade, Tabagismo, Hipertensao, Historico, Peso, Altura, Glicose]),
    assertz(paciente([Nome, Sexo, Idade, Tabagismo, Hipertensao, Historico, Peso, Altura, Glicose], Diabetes)).

% Editar paciente
editar_paciente(Paciente, NovoPaciente, NovoDiabetes) :-
    procurar(Paciente),
    (verificar_nomes(Paciente,NovoPaciente) ->
        true;
        \+ procurar(NovoPaciente)
    ),
    retract(paciente(Paciente, _)),
    assertz(paciente(NovoPaciente, NovoDiabetes)).

% Remover paciente
remover_paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diabetes) :-
    retract(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diabetes)).

% Calcular IMC
calcular_IMC(Peso, Altura, IMC) :-
    Altura > 0,
    IMC is (Peso / (Altura * Altura)).



% Diagnosticar diabetes 
diagnosticar([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose]) :-
    nonvar(Nome),nonvar(Sexo), nonvar(Idade), nonvar(Cardiaco), nonvar(Fumante), nonvar(IMC), nonvar(Hemoglobina), nonvar(Glicose),
    procurar([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose]),
    diagnosticar_diabetes([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], 0).


diagnosticar_diabetes([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Pont0) :-
    teste(Idade > 50, Pont0, Pont1),
    teste(Hipertensao == sim, Pont1, Pont2),
    teste(Cardiaco == sim, Pont2, Pont3),
    teste((Fumante == passado ; Fumante == sim), Pont3, Pont4),
    teste(IMC > 30.0, Pont4, Pont5),
    teste(Hemoglobina > 7.0, Pont5, Pont6),
    teste(Glicose > 200, Pont6, PontF),

    retract(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], _)),
    
    ((PontF / 7) > 0.4 ->assertz(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], sim)); assertz(paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], nao))).

teste(Condicao, Pont, PontAux) :-
    (Condicao -> PontAux is Pont + 1 ; PontAux = Pont).

%exibir todos os pacientes
exibir_pacientes(X, Y):-
    paciente(X, Y).