# PRÀCTICA 1
Aquest repositori correspon a la primera pràctica de l'assignatura EDPs que consisteix en implementar els mètodes de Jacobi, Gauss-Seidel, SOR i de Gradients Conjugats per a resoldre una simple EDP.

## Explicació del programa
El programa es compon de quatre fitxers d'extensió ***.c**. El principal és [```main.c```](https://github.com/VikSa666/pract1/blob/main/main.c), després hi ha [```itMethods.c```](https://github.com/VikSa666/pract1/blob/main/itMethods.h) que és on estan definits els mètodes numèrics per resoldre l'exercici (Jacobi, Gauss-Seidel i SOR) i un tercer, anomenat [```auxMethods.c```](https://github.com/VikSa666/pract1/blob/main/auxMethods.h), on hi ha funcions auxiliars que ajuden a fer més intel·ligible el codi, com ara la funció que calcula la norma infinit de la resta de dues matrius. Per últim, he fet un quart fitxer per ficar les funcions _f(x,y)_ i _g(x,y)_ que han de ser modificades en cada apartat. Explicaré cada fitxer per separat.

### Fitxer ```itMethods.h```
En aquest fitxer hi són principalment les funcions dels mètodes iteratius estudiats. El primer és Jacobi, el segon és Gauss-Seidel i el tercer és SOR. Com que Gauss-Seidel és un cas particular de SOR amb _w = 1_ el que he fet ha estat cridar a SOR passant manualment _w = 1_ per estalviar codi.

1. **Jacobi**. Per treballar amb Jacobi cal fer una matriu auxiliar, que anomeno _xx_, per guardar cada iteració i, abans de reemplaçar-les a la meva matriu del sistema _A_, calcular la diferència entre _xx_ i la _A_ corresponent a la iteració anterior. D'aquesta manera podem saber quan el mètode convergeix i sortir-ne. 
    
Llavors, per a aqueta matriu _xx_ guardo espai i després li defineixo ``la frontera'' igual que la _A_. Després faig el mètode guardant la iteració a _xx_, calculo la diferència, miro si he de sortir ja o encara no, i aleshores escric la nova iteració a _A_.
2. **SOR**. Similar a Jacobi, però no cal guardar tota una matriu auxiliar per calcular l'error en cada iteració, només un paràmetre que anomeno ```error```.
3. **Gauss-Seidel**. És el mètode de SOR però amb _w = 1_.
4. **Gradients Conjugats**. Aquest mètode el baso en les fórmules proporcionades a la teoria. El que passa és que, en un moment determinat, necessito un "vector" auxiliar i, per això, defineixo un vector _q_ que teòricament no apareix a les fórmules. 
    
Per a definir els vectors he fet com si fossin matrius _n x n_, en comptes de vectors de dimensió _n^2_, la qual cosa és el mateix en realitat. Però d'aquesta manera, adaptant algunes funcions que he posat a l'arxiu ```mave.h```, és més simple el càlcul. 


### Fitxer ```auxMethods.h```
Aquest fitxer conté algunes de les funcions útils per a fer els mètodes iteratius o, simplement, per estalviar omplir massa el ```main.c```. Les tres funcions que hi ha són:
* Funció ```valors_frontera()```. El que fa és simplement assignar a tots els valors de la vora de la matriu els valors que li corresponen mitjançant la funció $g$ donada a l'enunciat.
* Funció ```producte_metodes()```. És una funció per calcular el producte de malla en cada punt de la matriu. Així estalvio carregar massa el codi pel mètode de Gradients Conjugats.
* Funció ```error```. Com que les solucions exactes es donen explícitament, he fet una funció per calcular l'error en cada exercici. Em retorna el màxim error fent la resta, component a component, de les dues matrius de solucions.

### Fitxer ```mave.h```
La paraula "mave" és una abreviació de Matrius i Vectors. Aquest fitxer té funcions relacionades amb les matrius i els vectors, com ara productes, guardar memòria i alliberar-la, etc. No em detendré a explicar-les totes.


### Fitxer ```funcions.h```
Conté les funcions _f_ i _g_ per a cada exercici. Mitjançant el paràmetre ```option``` que al principi demana, s'escull quina funció s'utilitza depenent de quin exercici s'estigui realitzant. El paràmetre ```option``` es va arrosegant pel tot el programa fins arribar aquí.


### Fitxer ```main.c```
Implementació del programa: llegim paràmetres dimensió i tolerància, guardem memòria, definim el pas de malla i la frontera i implementem els mètodes. He posat uns paràmetres temporals per mesurar quant de temps triga cada mètode i així poder comparar-los.


## Resultats
Els resultats els adjuntaré en un arxiu pdf editat en LaTeX en format de taula