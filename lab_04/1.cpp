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

    // A negatív számokat tároló tömbnek annyi elemûnek kell lennie
    // ahány számunk van, mert lehetséges, hogy az összes negatív.

    // Egy változóban eltároljuk, hogy ténylegesen hány negatív számunk van.

    return 0;
}
