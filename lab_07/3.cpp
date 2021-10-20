#include <iostream>

using namespace std;

void iterativ_elore(int *tomb, int meret) {
    for(int i = 0; i < meret; i++)
        printf("%d; ", tomb[i]);
}

void iterativ_hatra(int *tomb, int meret) {
    for(int i = meret - 1; i >= 0; i--)
        printf("%d; ", tomb[i]);
}

void rekurziv_elore(int *tomb, int meret) {
    if(meret == 0)
        return;
    printf("%d; ", tomb[0]);
    rekurziv_elore(tomb + 1, meret - 1);
}

void rekurziv_hatra(int *tomb, int meret) {
    if(meret == 0)
        return;
    printf("%d; ", tomb[meret-1]);
    rekurziv_hatra(tomb, meret - 1);
}

int main()
{
    int tiz[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ot[5] = {1, 2, 3, 4, 5};

    //Tiz elemu
    printf("Iterativ_elore(10): ");
    iterativ_elore(tiz, 10);
    printf("\nRekurziv_elore(10): ");
    rekurziv_elore(tiz, 10);

    printf("\nIterativ_hatra(10): ");
    iterativ_hatra(tiz, 10);
    printf("\nRekurziv_hatra(10): ");
    rekurziv_hatra(tiz, 10);

    //Ot elemu
    printf("\n\nIterativ_elore(5): ");
    iterativ_elore(ot, 5);
    printf("\nRekurziv_elore(5): ");
    rekurziv_elore(ot, 5);

    printf("\nIterativ_hatra(5): ");
    iterativ_hatra(ot, 5);
    printf("\nRekurziv_hatra(5): ");
    rekurziv_hatra(ot, 5);

    return 0;
}
