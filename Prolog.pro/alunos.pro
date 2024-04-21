aluno(joao, calculo).
aluno(maria, calculo).
aluno(joel, programacao).
aluno(joel, estrutura).

frequenta(joao, ufpi).
frequenta(maria, ufpi).
frequenta(joel, ufma).

professor(carlos, calculo).
professor(ana_paula, estrutura).
professor(pedro, programacao).

funcionario(pedro, ufma).
funcionario(ana_paula, ufpi).
funcionario(carlos, ufpi). 


alunos_do_prof(X, Y):-
    professor(X, W), aluno(Y, W).

pessoas_ass(X, Y):-
    frequenta(X, Y); funcionario(X, Y).
