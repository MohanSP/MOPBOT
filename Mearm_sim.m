clc; clear;

syms a;
syms b;
syms c;

%Desired 3D coordinates for which joint angles are to be obtained
x=7; y=3; z=3; 

%Transformation Matrices
F01=[cos(a) -sin(a) 0 0 ; sin(a) cos(a) 0 0 ; 0 0 1 3 ; 0 0 0 1];
F12=[cos(b) -sin(b) 0 1.5; 0 0 1 2.7 ; -sin(b) -cos(b) 0 0 ; 0 0 0 1];
F23=[cos(c) -sin(c) 0 8.5 ; sin(c) cos(c) 0 0 ; 0 0 1 0 ; 0 0 0 1];
F3H=[1 0 0 8 ; 0 1 0 0 ; 0 0 1 0 ; 0 0 0 1];
F0H=F01*F12*F23*F3H;

%Forming a system of linear equations and solving for the unknowns
eqns=[F0H(13)==x,F0H(14)==y, F0H(15)==z];
vars=[a,b,c];
[sola , solb, solc, param, cond] = solve(eqns,vars,'ReturnConditions', true);

%Limiting solutions to preferred range and obtaining the solutions
assume(cond(1));
interval = [sola >=-pi, sola <=pi];
solk=solve(interval,param(1));
vala=subs(sola, param(1), solk);

assume(cond(2));
interval = [solb >=-pi, solb <=pi];
soll=solve(interval,param(2));
valb=subs(solb, param(2), soll);

assume(cond(3));
interval = [solc >=-pi, solc <=pi];
solm=solve(interval,param(3));
valc=subs(solc, param(3), solm);