    PROBLEMA 1 - ALIMENTARE SERVERE
    Am creat o functie auxiliara putere care calculeaza puterea de alimentare a intregului sistem pentru un curent de alimentare dat, prin calculul indiviual al puterii fiecarui server si alegerea minimului dintre acestea.
    Se citesc datele din fisierul de intrare. Pe parcursul citirii se calculeaza curentul de alimentare minim si maxim din cele date.
    Se aplica algoritmul de cautare binara, cu cele 2 valori aflate initial ale curentului, cea minima si cea maxima. O data ce puterea de mijloc calculata este mai mare atat decat cea de minim, cat si decat cea de maxim, s-a gasit curentul de alimentare optim si se opreste cautarea. Altfel, se modifica corespunzator fie curentul minim, fie cel maxim.
    Complexitatea algoritmului folosit este O(n * log(n)), din cauza calculului puterii imbricat in cautarea binara.

    PROBLEMA 2 - COLORARE
    Am creat o functie auxiliara care calculeaza base la puterea exponent, folosind algoritmul de exponentiere rapida.
    In main, am citit datele de intrare. Pe parcursul citirii, am retinut numarul de sectiuni de un anumit tip si tipul acestora. In functie de tipul sectiunii curente si tipul sectiunii precedente, am calculat numarul de cazuri folosind metoda produsului.
    Complexitatea algoritmului este O(n * log(n)), din cauza calcului puterii si parcurgerii datelor de intrare.

    PROBLEMA 3 - COMPRESIE
    Am calculat suma elementelor din vectorul A, respectiv B. Daca cele 2 sume nu sunt egale, atunci operatia nu este posibila si se afiseaza -1.
    In caz contrar, se reinitializeaza suma lui A si suma lui B cu A[0] si respectiv B[0], si se mai parcurg inca o data cei 2 vectori. Daca cele 2 sume sunt egale, se poate realiza operatia cu succes, lungimea sirului rezultant se incrementeaza si se reinitializeaza sumele cu elementele curente din vectori.
    Daca sumele sunt diferite, atunci cea mai mica se mareste cu elementul curent din vectorul corespunzator.
    Complexitatea algoritmului este O(n).
    
    PROBLEMA 5 - OFERTA
    Am citit datele de intrare si am stocat pretul fiecarui produs intr-un vector a.
    Am implementat un algoritm de programare dinamica. Am parcurs vectorul de preturi a, tratand toate cele 3 cazuri: fie cel mai avantajos este produsul singur, fie grupat cu cel anterior, fie grupat cu cele 2 anterioare. Pe baza celei mai avantajoase oferte, se actualizeaza vectorul de programare dinamica pret in mod corespunzator. Pretul final este ultimul element din acest vector.
    Complexitatea algoritmului este O(n).