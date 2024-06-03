# My Project with Exercises

## Table of Contents
- [Exercises](#exercises)
  - [Exercise 1](#exercise-1)
  - [Exercise 2](#exercise-2)
  - [Exercise 3](#exercise-3)

## Exercises

### Exercise 1

Facem sortare topologica pentru a avea nodurile intr-o ordine asa incat daca avem muchie de la a la b , nodul a sa fie pus inaintea nodului b
Utilizam programare dinamica pe sortarea topologica astfel:
- exista un lant de la 1 la 1
- toate celelalte dp uri le initializam cu 0
- Pentru fiecare nod u din ordinea topologica:
- Pentru fiecare nod v succesor al lui u:
- Adăugam numărul de lanțuri care duc la u (adică dp[u]) la numărul de lanțuri care duc la v (adică dp[v]).
- Returnam tot vectorul dp insa pt numarul de lanturi pana la N vom accesa dp[N].

Functii folosite:

vector<long long> count_paths(int N, vector<vector<int>>& graph, vector<int>& topo_order):
Aceasta functie va forma vectorul dp cu programare dinamica. dp[i] va contine numarul de lanturi elementare pana la nodul i, de la nodul 1.
Functia primeste ca argumente numarul de noduri, graph-ul si sortarea topologica a graph-ului.
_Analiza complexitatii_:
Initializarea vectorului dp are complexitate O(N);
Parcurgerea nodurilor este tot O(N);
Parcurgerea muchiilor este O(numar muchii);

vector<int> topological_sort(int N, vector<vector<int>>& graph)
Aceasta functie este o sortare topologica care foloseste 
BFS: algoritmul lui Kahn (lab 7)
Algoritm TopSort cu BFS:
- se initializeaza coada de la BFS cu toate nodurile din graf care au grad inten 0
- se porneste parcurgerea BFS
- la fiecare pas se vizitează un nod node
- se șterg toate muchiile care pleacă din node: (node,neigh)
- neigh este adaugat in coada doar daca devine un nod cu grad intern 0
- se verifica la finalul parcugerii daca mai sunt muchii ramase in graf
- daca inca mai exista muchii neșterse, atunci graful conține cel puțin un ciclu - nu se poate determina o sortare topologică
- altfel, ordinea in care s-au scos nodurile din coada reprezinta o sortare topologica
_Analiza complexitatii_:
Initializarea gradelor: O(N);
Calcularea gradului de intrare pentru fiecare nod: O(N + numar muchii);
O(N) pentru verificarea daca intrarea este 0;
Procesarea cozii: O(N+M);
In final ar fi un O(N+M) pt sortarea topologica, asa cum este specificat si in lab 7.

*Complexitate*
Pentru main complexitatea este ~ O(M+N).


### Exercise 2

Acest exercitiu pune problema unui graph care trebuie parcurs din nodul a in nodul b trecand prin cat mai multe noduri.
Nu exista cicluri in graph.
Am folosit aceeasi abordare ca la prima problema , cu mici modificari.
Nu am asociat valori nodurilor ci am format graph-ul cu Strnguri ca noduri.
Avand in vedere lucrul cu noduri, am considerat eu personal mai usor sa fac un DFS pentru sortarea topologica 
Nu am mai facut o functie separata pentru partea de dp ci am scris in main implementarea de porgramare dinamica usor adaptata cerintei 2.

Functii folosite:

void topological_sort_util(string u, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, vector<string>& topo_order)
Aceasta functie face dfs ca in lab 7 pentru a sorta topologic graph ul de orase.
Am adaptat sa fie cu string-uri.
_Analiza complexitatii_:
DFS: O(n + m);

Programarea dinamica:
Vectorul pt dp: dist[u] reprezintă numărul maxim de noduri care pot fi vizitate pornind de la nodul u până la destinație.
- Deci dist[start] va contine numarul maxim de noduri care pleaca din start si pana la nodul de destinatie.
- Distanța maximă de la u este determinată de distanța maximă a vecinilor săi plus 1 pentru ca mai adaugam un nod.
- dacă putem ajunge la v și distanța maximă de la v la destinație este dist[v], atunci distanța maximă de la u la destinație este dist[v] + 1.
- distanta de la nodul u pana la el insusi este 0
- la final vom obtine numarul maxim de noduri - 1 si deci la afisare adaugam 1.
_Analiza complexitatii_:
O(m+n)

*Complexitate totala*
O(M + N) 


### Exercise 3

In acest exercitiu este vorba de un graph in care trebuie sa gasim combo-ul care are costul total cel mai mic intre 3 noduri.
Logica:
- compunem 2 graph-uri: unul normal si unul cu muchiile inversate.
- aplicam disjktra pentru a afla distantele minime de la nodul x la toate nodurile
- aplicam disjktra pentru a afla distantele minime de la nodul y la toate nodurile
- aplicam disjktra pentru a afla distantele minime de la nodul z (pe graph reversed) la toate nodurile
- obtinem 3 vectori de distante minime de la x, y, z pentru toate restul nodurilor. 
- unule din aceste distante vor fi infinit asta inseamna ca nu exista drum de la nodul in cauza pana la nodul i
- in cei trei vectori, nodul i corespunde peste tot
- deci daca adunam pentru fiecare nod i toate cele 3 distante o sa obtinem costuri
- costul minim este minimul dintre aceste sume pentru cei 3 vectori.

Functii folosite:

vector<long long> dijkstra(long long start, const vector<vector<Edge>>& graph)
Aici este un disktra adaptat cu un min-heap ca sa tinem cont mai usor de acele costuri minime.
_Analiza complexitatii_
O((M+N)logM)
(ceva la coada cred ca e cu logaritm)

Alte operatii la acest exercitiu am incercat sa le explic mai in detaliu in cod.







## NOTESSSS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

##### VM CHECKER IS DOWN!!!
Nu am putut verifica daca punctajul da si pe Checker (nu pe local).

Exista momente cand la rulare am avut cateva timeout-uri. Nu stiu dac cauza este masina
virtuala pe care lucrez sau codul in sine.

Stiu ca am cateva implementari nu foarte eficiente. Cred ca lucrul cu stringuri la problema 2 
ar fi mai anevoioas decat lucrul cu numere. De asemenea dfs-ul recursiv ar putea supraincarca stiva.

Voiam sa verific aceste chestii pe VM CHECKEER inainte sa trimit varianta finala a temei, insa 
pare sa fie o coada de o saptamana si ceva pe acolo.

Acesta este output-ul pe local care merge chiar daca am facut recursivitate si lucru cu string-uri:
```
                                                                                                                                                                           
┌──(kali㉿kali)-[~/Pa/t2]
└─$ ./check cpp
g++ (Debian 13.2.0-13) 13.2.0
gcc (Debian 13.2.0-13) 13.2.0
Picked up _JAVA_OPTIONS: -Dawt.useSystemAAFontSettings=on -Dswing.aatext=true
javac 17.0.10
Python 3.11.8
timeout (GNU coreutils) 9.4
---------------------- Run public_tests -------------------
------------------------------------------------------------
------------------------------------------------------------
---------------------- Problema 1: numarare -----------------
---------------------- timp C++ => 2 s -----------------
Test 0 problema 1 .......... 1.0/1.0 - OK  - 0.007 s
Test 1 problema 1 .......... 1.0/1.0 - OK  - 0.006 s
Test 2 problema 1 .......... 1.0/1.0 - OK  - 0.006 s
Test 3 problema 1 .......... 1.0/1.0 - OK  - 0.014 s
Test 4 problema 1 .......... 1.0/1.0 - OK  - 0.006 s
Test 5 problema 1 .......... 1.0/1.0 - OK  - 0.009 s
Test 6 problema 1 .......... 1.0/1.0 - OK  - 0.009 s
Test 7 problema 1 .......... 1.0/1.0 - OK  - 0.009 s
Test 8 problema 1 .......... 1.0/1.0 - OK  - 0.009 s
Test 9 problema 1 .......... 1.0/1.0 - OK  - 0.010 s
Test 10 problema 1 .......... 1.0/1.0 - OK  - 0.180 s
Test 11 problema 1 .......... 1.0/1.0 - OK  - 0.141 s
Test 12 problema 1 .......... 1.0/1.0 - OK  - 0.122 s
Test 13 problema 1 .......... 1.0/1.0 - OK  - 0.128 s
Test 14 problema 1 .......... 1.0/1.0 - OK  - 0.118 s
Test 15 problema 1 .......... 1.0/1.0 - OK  - 0.117 s
Test 16 problema 1 .......... 1.0/1.0 - OK  - 0.182 s
Test 17 problema 1 .......... 1.0/1.0 - OK  - 0.157 s
Test 18 problema 1 .......... 1.0/1.0 - OK  - 0.107 s
Test 19 problema 1 .......... 1.0/1.0 - OK  - 0.128 s
Test 20 problema 1 .......... 1.0/1.0 - OK  - 0.109 s
Test 21 problema 1 .......... 1.0/1.0 - OK  - 0.119 s
Test 22 problema 1 .......... 1.0/1.0 - OK  - 0.123 s
Test 23 problema 1 .......... 1.0/1.0 - OK  - 0.116 s
Test 24 problema 1 .......... 1.0/1.0 - OK  - 0.182 s
Test 25 problema 1 .......... 1.0/1.0 - OK  - 0.105 s
Test 26 problema 1 .......... 1.0/1.0 - OK  - 0.104 s
Test 27 problema 1 .......... 1.0/1.0 - OK  - 0.132 s
Test 28 problema 1 .......... 1.0/1.0 - OK  - 0.129 s
Test 29 problema 1 .......... 1.0/1.0 - OK  - 0.109 s
Test 30 problema 1 .......... 1.0/1.0 - OK  - 0.099 s
Test 31 problema 1 .......... 1.0/1.0 - OK  - 0.128 s
Test 32 problema 1 .......... 1.0/1.0 - OK  - 0.121 s
Test 33 problema 1 .......... 1.0/1.0 - OK  - 0.141 s
Test 34 problema 1 .......... 1.0/1.0 - OK  - 0.208 s
=============>>>>>> Scor : 35.0/35 <<<<<< =============
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
---------------------- Problema 2: trenuri -----------------
---------------------- timp C++ => 3 s -----------------
Test 0 problema 2 .......... 1.0/1.0 - OK  - 0.010 s
Test 1 problema 2 .......... 1.0/1.0 - OK  - 0.021 s
Test 2 problema 2 .......... 1.0/1.0 - OK  - 0.017 s
Test 3 problema 2 .......... 1.0/1.0 - OK  - 0.021 s
Test 4 problema 2 .......... 1.0/1.0 - OK  - 0.063 s
Test 5 problema 2 .......... 1.0/1.0 - OK  - 0.019 s
Test 6 problema 2 .......... 1.0/1.0 - OK  - 0.032 s
Test 7 problema 2 .......... 1.0/1.0 - OK  - 0.021 s
Test 8 problema 2 .......... 1.0/1.0 - OK  - 0.041 s
Test 9 problema 2 .......... 1.0/1.0 - OK  - 0.031 s
Test 10 problema 2 .......... 1.0/1.0 - OK  - 0.181 s
Test 11 problema 2 .......... 1.0/1.0 - OK  - 0.302 s
Test 12 problema 2 .......... 1.0/1.0 - OK  - 0.344 s
Test 13 problema 2 .......... 1.0/1.0 - OK  - 0.148 s
Test 14 problema 2 .......... 1.0/1.0 - OK  - 0.152 s
Test 15 problema 2 .......... 1.0/1.0 - OK  - 0.156 s
Test 16 problema 2 .......... 1.0/1.0 - OK  - 0.380 s
Test 17 problema 2 .......... 1.0/1.0 - OK  - 0.335 s
Test 18 problema 2 .......... 1.0/1.0 - OK  - 0.298 s
Test 19 problema 2 .......... 1.0/1.0 - OK  - 0.209 s
Test 20 problema 2 .......... 1.0/1.0 - OK  - 0.236 s
Test 21 problema 2 .......... 1.0/1.0 - OK  - 0.144 s
Test 22 problema 2 .......... 1.0/1.0 - OK  - 0.149 s
Test 23 problema 2 .......... 1.0/1.0 - OK  - 0.456 s
Test 24 problema 2 .......... 1.0/1.0 - OK  - 0.485 s
Test 25 problema 2 .......... 1.0/1.0 - OK  - 0.168 s
Test 26 problema 2 .......... 1.0/1.0 - OK  - 0.350 s
Test 27 problema 2 .......... 1.0/1.0 - OK  - 0.146 s
Test 28 problema 2 .......... 1.0/1.0 - OK  - 0.379 s
Test 29 problema 2 .......... 1.0/1.0 - OK  - 0.213 s
Test 30 problema 2 .......... 1.0/1.0 - OK  - 0.305 s
Test 31 problema 2 .......... 1.0/1.0 - OK  - 0.311 s
Test 32 problema 2 .......... 1.0/1.0 - OK  - 0.364 s
Test 33 problema 2 .......... 1.0/1.0 - OK  - 0.433 s
Test 34 problema 2 .......... 1.0/1.0 - OK  - 0.431 s
Test 35 problema 2 .......... 1.0/1.0 - OK  - 0.318 s
Test 36 problema 2 .......... 1.0/1.0 - OK  - 0.399 s
Test 37 problema 2 .......... 1.0/1.0 - OK  - 0.651 s
Test 38 problema 2 .......... 1.0/1.0 - OK  - 0.187 s
Test 39 problema 2 .......... 1.0/1.0 - OK  - 0.370 s
=============>>>>>> Scor : 40.0/40 <<<<<< =============
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
---------------------- Problema 3: drumuri -----------------
---------------------- timp C++ => 2.5 s -----------------
Test 0 problema 3 .......... 1.0/1.0 - OK  - 0.019 s
Test 1 problema 3 .......... 1.0/1.0 - OK  - 0.014 s
Test 2 problema 3 .......... 1.0/1.0 - OK  - 0.018 s
Test 3 problema 3 .......... 1.0/1.0 - OK  - 0.021 s
Test 4 problema 3 .......... 1.0/1.0 - OK  - 0.082 s
Test 5 problema 3 .......... 1.0/1.0 - OK  - 0.016 s
Test 6 problema 3 .......... 1.0/1.0 - OK  - 0.023 s
Test 7 problema 3 .......... 1.0/1.0 - OK  - 0.017 s
Test 8 problema 3 .......... 1.0/1.0 - OK  - 0.074 s
Test 9 problema 3 .......... 1.0/1.0 - OK  - 0.075 s
Test 10 problema 3 .......... 1.0/1.0 - OK  - 0.441 s
Test 11 problema 3 .......... 1.0/1.0 - OK  - 0.497 s
Test 12 problema 3 .......... 1.0/1.0 - OK  - 0.615 s
Test 13 problema 3 .......... 1.0/1.0 - OK  - 0.478 s
Test 14 problema 3 .......... 1.0/1.0 - OK  - 0.455 s
Test 15 problema 3 .......... 1.0/1.0 - OK  - 0.474 s
Test 16 problema 3 .......... 1.0/1.0 - OK  - 0.503 s
Test 17 problema 3 .......... 1.0/1.0 - OK  - 0.411 s
Test 18 problema 3 .......... 1.0/1.0 - OK  - 0.459 s
Test 19 problema 3 .......... 1.0/1.0 - OK  - 0.463 s
Test 20 problema 3 .......... 1.0/1.0 - OK  - 0.399 s
Test 21 problema 3 .......... 1.0/1.0 - OK  - 0.601 s
Test 22 problema 3 .......... 1.0/1.0 - OK  - 0.480 s
Test 23 problema 3 .......... 1.0/1.0 - OK  - 0.364 s
Test 24 problema 3 .......... 1.0/1.0 - OK  - 0.503 s
Test 25 problema 3 .......... 1.0/1.0 - OK  - 0.351 s
Test 26 problema 3 .......... 1.0/1.0 - OK  - 0.532 s
Test 27 problema 3 .......... 1.0/1.0 - OK  - 0.471 s
Test 28 problema 3 .......... 1.0/1.0 - OK  - 0.596 s
Test 29 problema 3 .......... 1.0/1.0 - OK  - 0.626 s
Test 30 problema 3 .......... 1.0/1.0 - OK  - 0.453 s
Test 31 problema 3 .......... 1.0/1.0 - OK  - 0.696 s
Test 32 problema 3 .......... 1.0/1.0 - OK  - 0.534 s
Test 33 problema 3 .......... 1.0/1.0 - OK  - 0.352 s
Test 34 problema 3 .......... 1.0/1.0 - OK  - 0.815 s
Test 35 problema 3 .......... 1.0/1.0 - OK  - 0.512 s
Test 36 problema 3 .......... 1.0/1.0 - OK  - 0.625 s
Test 37 problema 3 .......... 1.0/1.0 - OK  - 0.622 s
Test 38 problema 3 .......... 1.0/1.0 - OK  - 0.504 s
Test 39 problema 3 .......... 1.0/1.0 - OK  - 0.585 s
=============>>>>>> Scor : 40.0/40 <<<<<< =============
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
---------------------- Problema 4: scandal -----------------
Numele sursei care contine functia main trebuie sa fie:
scandal.c, scandal.cpp sau Scandal.java
=============>>>>>> Scor : 0/25 <<<<<< =============
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
================>>>>>> Check README.md <<<<<< ================
README.md OK. Punctajul final se va acorda la corectare.
===============>>>>>> README.md: 5/5 <<<<<< ===============
-------------------------------------------------------------
-------------------------------------------------------------
-------------------------------------------------------------
-------------------------------------------------------------
===============>>>>>> Check coding style <<<<<< ===============
/home/kali/Pa/t2/_utils/coding_style/check_cpp.py:57: DeprecationWarning: module 'sre_compile' is deprecated
  import sre_compile
Done processing ./drumuri.cpp
Done processing ./numarare.cpp
Done processing ./trenuri.cpp

Coding style OK. Punctajul final se poate modifica la corectare.
===============>>>>>> Coding style: 5/5 <<<<<< ===============
-------------------------------------------------------------
-------------------------------------------------------------
Erorile de coding style se gasesc in cpp.errors / java.errors
=============>>>>>> Total: 125.0/150 <<<<<< =============
                                                                                                                                                                              
┌──(kali㉿kali)-[~/Pa/t2]
└─$ 
```
