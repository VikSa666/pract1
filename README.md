# PRÀCTICA 1
Aquest repositori correspon a la primera pràctica de l'assignatura EDPs que consisteix en implementar els mètodes de Jacobi, Gauss-Seidel, SOR i de Gradients Conjugats per a resoldre una simple EDP.

## Explicació del programa
El programa es compon de quatre fitxers d'extensió ***.c**. El principal és \texttt{main.c}, després hi ha \texttt{itMethods.c} que és on estan definits els mètodes numèrics per resoldre l'exercici (Jacobi, Gauss-Seidel i SOR) i un tercer, anomenat \texttt{auxMethods.c}, on hi ha funcions auxiliars que ajuden a fer més intel·ligible el codi, com ara la funció que calcula $\|\bullet\|_\infty$ de la resta de dues matrius. Per últim, he fet un quart fitxer per ficar les funcions $f(x,y)$ i $g(x,y)$ que han de ser modificades en cada apartat. Explicaré cada fitxer per separat.# pract1
