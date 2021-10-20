#include <stdio.h>


void kiir(int szam) {
    int mod = szam % 1000;

    if(szam == mod) {
        printf("%d ", szam);
        return;
    }

    kiir(szam / 1000);
    if(mod < 100)
        printf("%c", '0');
    if(mod < 10)
        printf("%c", '0');
    printf("%d ", mod);
}

int main()
{
    kiir(16077216);
    printf("\n");
    kiir(999);
    printf("\n");
    kiir(1000);
    printf("\n");
    kiir(12);
    printf("\n");
    kiir(0);
    printf("\n");
    kiir(1000222);
    printf("\n");
    return 0;
}
