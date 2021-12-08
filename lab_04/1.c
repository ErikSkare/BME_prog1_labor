#include <iostream>

using namespace std;

int main()
{
    double szamok[10] = {2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};
    int osszesen = sizeof(szamok) / sizeof(double);
    int negativok_db = 0;
    int negativ_indexek[10];

    printf("Osszesen %d szam van.\n", osszesen);
    for(int i = 0; i < osszesen; i++) {
        printf("[%d]=%g ", i, szamok[i]);
        if(szamok[i] < 0)
            negativ_indexek[negativok_db++] = i;
    }

    printf("\n\nEbbol %d szam negativ.\n", negativok_db);
    for(int i = 0; i < negativok_db; i++)
        printf("[%d]=%g ", negativ_indexek[i], szamok[negativ_indexek[i]]);

    // A negat�v sz�mokat t�rol� t�mbnek annyi elem�nek kell lennie
    // ah�ny sz�munk van, mert lehets�ges, hogy az �sszes negat�v.

    // Egy v�ltoz�ban elt�roljuk, hogy t�nylegesen h�ny negat�v sz�munk van.

    return 0;
}
