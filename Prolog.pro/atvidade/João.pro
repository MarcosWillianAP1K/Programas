nasceu(joao, pelotas).
nasceu(jean, paris).

local(pelotas, riograndedosul).
local(paris, franca).

gaucho(X):-
    local(L, riograndedosul), 
    nasceu(X, L).