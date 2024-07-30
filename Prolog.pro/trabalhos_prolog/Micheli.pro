:- dynamic pacientes/1.

pacientes([
    [maria, feminino, 37.0, nao, nao, passado, 30.5, 5.7, nao],
    [gorete, feminino, 53.0, nao, nao, passado, 26.37, 4.5, 100, nao],
    [pedro, masculino, 54.0, nao, nao, nunca, 31.86, 6.6, 112, nao],
    [juliana, feminino, 37.0, nao, nao, passado, 21.25, 6.1, 145, nao],
    [catisvalda, feminino, 56.0, nao, nao, nunca, 30.95, 6.5, 145, nao],
    [ursulino, masculino, 79.0, nao, nao, passado, 31.19, 5.8, 155, nao],
    [jose, masculino, 67.0, nao, nao, sim, 27.32, 6.8, 220, sim],
    [marta, feminino, 74.0, nao, nao, sim, 29.51, 8.2, 240, sim],
    [jussara, feminino, 37.0, nao, nao, passado, 36.87, 8.8, 160, sim],
    [katia, feminino, 65.0, sim, sim, nunca, 33.55, 8.9, 202, sim],
    [marcelo, masculino, 55.0, nao, sim, passado, 30.42, 6.2, 300, sim],
    [ayla, feminino, 61.0, nao, nao, passado, 34.45, 6.5, 280, sim],
    [rafaela, feminino, 58.0, sim, nao, nunca, 38.31, 7.0, 200, sim],
    [cassia, feminino, 61.0, nao, nao, sim, 30.11, 6.2, 240, sim],
    [elisa, feminino, 26.0, nao, nao, passado, 27.32, 4.0, 200, nao],
    [alice, feminino, 74.0, nao, nao, passado, 28.12, 5.0, 100, nao],
    [jade, feminino, 45.0, sim, nao, nunca, 23.05, 4.8, 130, nao],
    [heloise, masculino, 56.0, nao, nao, nunca, 26.78, 4.8, 200, nao],
    [benicio, masculino, 20.0, nao, nao, passado, 23.04, 5.7, 160, nao],
    [paulo, masculino, 70.0, nao, nao, passado, 15.94, 5.8, 158, nao],
    [otavio, masculino, 30.0, nao, nao, passado, 15.8, 6.2, 90, nao],
    [isis, feminino, 80.0, nao, nao, nunca, 22.04, 9.0, 209, sim],
    [francivaldo, masculino, 63.0, nao, sim, passado, 27.32, 6.6, 300, sim],
    [juvelino, masculino, 58.0, nao, nao, passado, 32.38, 6.6, 159, sim],
    [maya, feminino, 43.0, sim, nao, nunca, 34.21, 9.0, 200, sim],
    [genetildes, masculino, 56.0, nao, nao, nunca, 37.59, 4.0, 160, nao],
    [waldisney, masculino, 60.0, nao, nao, passado, 25.4, 4.0, 159, nao],
    [reinaldo, masculino, 27.0, nao, nao, passado, 27.32, 3.5, 200, nao],
    [frederico, masculino, 54.0, nao, nao, passado, 30.41, 5.0, 100, nao]
]).


adicionar_paciente(Paciente) :-
    pacientes(ListaPacientes),
    Paciente = [Nome|_],
    \+ member([Nome|_], ListaPacientes),
    append(ListaPacientes, [Paciente], NovaLista),
    retract(pacientes(ListaPacientes)),
    assert(pacientes(NovaLista)).

editar_paciente(NovoPaciente) :-
    pacientes(ListaPacientes),
    NovoPaciente = [Nome|_],
    select([Nome|_], ListaPacientes, TempLista),
    \+ (member([Nome|_], TempLista)),
    append(TempLista, [NovoPaciente], NovaLista),
    retract(pacientes(ListaPacientes)),
    assert(pacientes(NovaLista)).

remover_paciente(Nome) :-
    pacientes(ListaPacientes),
    select([Nome|_], ListaPacientes, NovaLista),
    retract(pacientes(ListaPacientes)),
    assert(pacientes(NovaLista)).

calcular_IMC(Peso, Altura, IMC) :-
    IMC is Peso / (Altura * Altura).

% Verifica se o paciente possui informações suficientes
diagnosticar(Paciente) :-
    length(Paciente, Tamanho),
    (Tamanho < 9 ->
        write('Informações insuficientes. Favor fornecer mais dados.')
    ;
        realizar_diagnostico(Paciente)
    ).

% Realiza o diagnóstico e atualiza o banco de dados
realizar_diagnostico([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose]) :-
    pacientes(ListaPacientes),
    (   \+ member([Nome, _, _, _, _, _, _, _, _, _], ListaPacientes)
    ->  write('Paciente não encontrado na base de dados.')
    ;   calcular_pontuacao(Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose, PontuacaoFinal),
        write('Pontuacao calculada: '), write(PontuacaoFinal), nl,
        determinar_diagnostico(PontuacaoFinal, Diagnostico),
        atualizar_paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico)
    ).

calcular_pontuacao(Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose, PontuacaoFinal) :-
    Condicoes = [Idade > 50, Hipertensao == sim, Cardiaco == sim, (Fumante == passado ; Fumante == sim), IMC > 30.0, Hemoglobina > 7.0, Glicose > 200],
    contar_verdadeiras(Condicoes, 0, PontuacaoFinal).

contar_verdadeiras([], Pontuacao, Pontuacao).
contar_verdadeiras([Condicao | Resto], PontuacaoAtual, PontuacaoFinal) :-
    (Condicao -> NovaPontuacao is PontuacaoAtual + 1 ; NovaPontuacao = PontuacaoAtual),
    contar_verdadeiras(Resto, NovaPontuacao, PontuacaoFinal).

determinar_diagnostico(Pontuacao, Diagnostico) :-
    (Pontuacao / 7 > 0.4 ->
        Diagnostico = sim
    ;
        Diagnostico = nao
    ).

atualizar_paciente([Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose], Diagnostico) :-
    pacientes(ListaPacientes),
    select([Nome, _, _, _, _, _, _, _, _, _], ListaPacientes, TempLista),
    append(TempLista, [[Nome, Sexo, Idade, Hipertensao, Cardiaco, Fumante, IMC, Hemoglobina, Glicose, Diagnostico]], NovaLista),
    retract(pacientes(ListaPacientes)),
    assert(pacientes(NovaLista)),
    write('Diagnostico atualizado para o paciente: '), write(Diagnostico), nl.

print([X | Y]):-
    write(X), nl, print(Y).

printar_pacientes():-
    pacientes(X), print(X).