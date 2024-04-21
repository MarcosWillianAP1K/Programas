bruxo(rony).
temVarinha(harry).
jogadorQuadribol(harry).

bruxo(X) :- 
    temVassoura(X), temVarinha(X).

temVassoura(X) :- 
    jogadorQuadribol(X).