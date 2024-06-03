# Exercise Solutions

## Exercises

1. **alimentare servere**
/*
Funcție pentru calcularea serverului intermediar între două servere date
Argumente:
- server1: o pereche ce reprezintă puterea și consumul curent al primului server
- server2: o pereche ce reprezintă puterea și consumul curent al celui de-al doilea server
Returnează:
O pereche ce reprezintă puterea și consumul curent al serverului intermediar
*/

/*
Funcție principală pentru citirea datelor de intrare din fișierul "servere.in", care conține date despre puterea și consumul curent al serverelor.
Calculează serverele intermediare pentru perechile adiacente de servere și scrie puterea ultimului server în fișierul "servere.out".
Programul calculează apoi serverele intermediare între perechile adiacente de servere conform unui algoritm specificat ( am scris ecuatiile conform ecuatiilor date in cerinta : 
• 6 − |5.5 − 2| = 2.5
• 9 − |5.5 − 4| = 7.5
• 7 − |5.5 − 1| = 2.5
• 5 − |5.5 − 8| = 2.5. 5.5 este x ul si ce este dupa egal este y. Am pus aceste ecuatii pe Geogebra si am constatat ca daca le iau doua cate 2 au o intersectie. Exist un edge case cand nu se intalnesc niciodata solutiile. Acest edge case l-am tratat in main si anume am verificat conditia pt ca ecuatiile sa nu fie satisfacute simultan.Am creat serverul comun si am folosit GREEDY ca sa gasesc solutia finala. intersectia finala cand obtin ultimul server.)
Fișierul de ieșire va conține un singur număr zecimal reprezentând puterea ultimului server după calculul serverului intermediar.
*/

COMPLEXITATE:
Citirea datelor de intrare: O(N), deoarece trebuie citite puterile și consumurile curente ale N servere.
Calculul serverelor intermediare:
Inițializarea vectorului serverPairs: O(N), deoarece trebuie parcurs vectorul de N elemente pentru a construi perechile de servere.
Parcurgerea serverPairs și calculul serverelor intermediare: O(N), deoarece este necesară o singură parcurgere a vectorului pentru a calcula fiecare server intermediar.
Scrierea puterii ultimului server în fișierul de ieșire: O(1), deoarece este o operație de scriere simplă.


2. **colorare**
/*
Funcție pentru calcularea unei puteri modulare rapide folosind tehnica shiftării pe biți pentru a îmbunătăți performanța.
Returnează:
Rezultatul calculării puterii base^exp % modd
*/

/*
Funcție pentru determinarea numărului de modele distincte pentru colorarea unei șiruri de regiuni.
Argumente:
- regiunePrev: o pereche ce reprezintă lungimea și tipul regiunii anterioare
- regiuneCurr: o pereche ce reprezintă lungimea și tipul regiunii curente
- posibilitati: Numărul actual de posibilități de colorare
Returnează:
Numărul actualizat de posibilități de colorare după adăugarea regiunii curente
*/

/*
Funcție principală pentru citirea datelor de intrare din fișierul "colorare.in", care conține date despre lungimile și tipurile regiunilor.
Calculează numărul total de modele distincte pentru colorarea regiunilor și îl scrie în fișierul "colorare.out".
Algoritmul calculează numărul de modele distincte pentru fiecare pereche de regiuni consecutive în funcție de tipurile acestora și lungimile lor, folosind tehnici specifice pentru optimizarea calculului modular.

Descriere:
Pentru fiecare regiune următoare, se calculează numărul de modele distincte pentru colorarea acesteia față de regiunea anterioară.
    a. Se verifică tipurile regiunilor anterioare și curente și se aplică formule specifice în funcție de combinația acestora.
    b. Dacă regiunea anterioară este de tip "V", există 3 posibilități distincte pentru colorarea regiunii curente:
        - Dacă regiunea curentă este și ea de tip "V", se dublează numărul de posibilități și se adaugă numărul de combinații posibile de așezare a pieselor verticale.
        - Dacă regiunea curentă este de tip "H", se dublează numărul de posibilități și se adaugă numărul de combinații posibile de așezare a unei piese orizontale lângă o piesă verticală.
    c. Dacă regiunea anterioară este de tip "H", există 2 posibilități distincte pentru colorarea regiunii curente:
        - Dacă regiunea curentă este de tip "V", se calculează numărul de combinații posibile de așezare a unei piese verticale lângă o piesă orizontală.
        - Dacă regiunea curentă este și ea de tip "H", se dublează numărul de posibilități și se adaugă numărul de combinații posibile de așezare a două piese orizontale lângă o piesă orizontală.
COMPLEXITATE:
Complexitatea funcției `modPow` este O(log exp), deoarece folosește tehnica de ridicare la putere rapidă folosind shiftarea pe biți.

Complexitatea funcției `numarModeleDistincte` depinde de numărul de regiuni și de lungimea acestora. Vom analiza complexitatea acesteia în pașii săi principali:

Complexitatea funcției numarModeleDistincte este O(1), deoarece aceasta efectuează doar operații aritmetice simple și operații de accesare a elementelor în perechile de intrare regiunePrev și regiuneCurr. Aceste operații au o complexitate constantă și nu depind de mărimea datelor de intrare. Astfel, complexitatea rămâne constantă, indiferent de dimensiunea datelor de intrare.

COMPLEXITATE   
In main avem o bucla cu complexitate O(n).
*/

3. **compresie**
/*
Algoritmul pentru compresia vectorilor A și B poate fi descris astfel:

Se citește dimensiunea vectorului A, apoi elementele acestuia.
Se citește dimensiunea vectorului B, apoi elementele acestuia.
Se calculează suma elementelor vectorului A și suma elementelor vectorului B.
Dacă suma elementelor vectorului A nu este egală cu suma elementelor vectorului B, se scrie -1 în fișierul de ieșire.
În caz contrar, se inițializează doi indici, i și j, cu valoarea 0, și un contor count cu valoarea 0.
Se definește o etichetă "loop_start" pentru a controla bucla principală.
În bucla principală, se verifică dacă indicii i și j sunt mai mici decât dimensiunile vectorilor A și B, respectiv.
Dacă elementele de la pozițiile i și j din cei doi vectori sunt egale, se incrementă ambii indici și count, apoi se sare la eticheta "loop_start".
În caz contrar, se compară elementele de la pozițiile i și j și se ajustează vectorii în consecință pentru a face elementele egale. Adica daca la pozitia i avem un numar mai mare decat la pozitia j se va adauga la suma elementul de la pozitia mai mica si tot asa pana cand se ajunge la o egalitate intre termenul de la pozitia i si cel de la pozitia j.
Se incrementă contorul count pentru fiecare element adăugat.
Se sare la eticheta "loop_start" pentru a continua verificarea elementelor.
La finalul buclei, se scrie valoarea contorului count în fișierul de ieșire.

Se parcurg vectorii deci complexitatea este O(m + n);
*/


4. **criptat**
/*
Algoritmul pentru determinarea lungimii maxime a parolei care îndeplinește condițiile date poate fi descris după cum urmează:
Se determină cele 8 litere distincte care apar în cuvintele citite.
Se construiește un map care asociază fiecărei litere un vector de perechi, fiecare pereche reprezentând numărul de apariții al literei într-un cuvânt și lungimea cuvântului respectiv.
Pentru fiecare literă, vectorul de perechi asociat este sortat descrescător după raportul dintre numărul de apariții al literei și lungimea cuvântului.
Se iterează prin fiecare literă și se încearcă construirea unei parole cu lungime maximă astfel:
    a. Se iau perechile de apariții și lungimi asociate literei și se adună progresiv aparițiile și lungimile cuvintelor.
    b. Dacă noua pereche de apariții și lungimi nu face ca litera să devină dominantă în parolă, se trece la următoarea pereche.
    c. Dacă noua pereche face ca litera să devină dominantă, se actualizează lungimea maximă a parolei.

COMPLEXITATE:
Identificarea celor 8 litere distincte care apar în cuvintele citite necesită parcurgerea tuturor cuvintelor și adăugarea literelor într-un set. Aceasta are o complexitate de O(N), unde N este numărul total de caractere din toate cuvintele.
Construirea unui map care asociază fiecărei litere un vector de perechi are o complexitate de O(N), deoarece trebuie parcurse toate cuvintele și adăugate informațiile despre fiecare literă în map.
Sortarea vectorului de perechi asociat fiecărei litere după raportul dintre numărul de apariții al literei și lungimea cuvântului are o complexitate de O(M * log M), unde M este numărul total de perechi asociate tuturor literelor.
Iterarea prin fiecare literă și încercarea construirii unei parole cu lungime maximă necesită parcurgerea fiecărei perechi de apariții și lungimi asociate literei și actualizarea lungimii maxime a parolei. Aceasta are o complexitate de O(M), unde M este numărul total de perechi asociate tuturor literelor.
*/


5. **oferta**
/*
Algoritmul:
Se setează dp[0] = 0 ca caz de bază, deoarece nu este nevoie de nicio cumpărătură.
Pentru fiecare produs i de la 1 la N:
    a. Se calculează costul minim pentru a cumpăra primele i produse:
        - Se adaugă costul produsului i la costul minim pentru a cumpăra primele i-1 produse.
        - Se calculează un cost special dacă sunt disponibile cel puțin două produse și cel puțin trei produse, respectiv.
    b. Se actualizează dp[i] cu costul minim obținut.
Costul minim pentru a cumpăra cele N produse este stocat în dp[N] și este returnat ca rezultat al funcției.
Costul minim este scris în fișierul de ieșire "oferta.out" cu o precizie de 1 zecimală.
COMPLEXITATE:
Complexitatea este O(N).
*/



