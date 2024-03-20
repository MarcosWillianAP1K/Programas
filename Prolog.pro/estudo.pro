main() :-
    write("ola mundo\n"),
    read(X),nl,
    write(X).

mulher(pam).
mulher(ann).
mulher(liz).
mulher(pat).
homem(tom).
homem(bob).
homem(jim).
genitor(pam, bob).
genitor(tom, bob).
genitor(tom, liz).
genitor(bob, pat).
genitor(bob, ann).
genitor(pat, liz).

ple(X,Y) :- 
    genitor(Y,X).

maero(X,Y) :- 
    genitor(X,Y), mulher(X).