#include <stdio.h>
#include <stdlib.h>
#include "labirintus.h"

int main()
{
    Palya palya = beolvas("palya.txt");

    int eredmeny, megtalalt_kincsek = 0;
    char irany;

    printf("Kincsek szama: %d\n\n", megtalalt_kincsek);
    kirajzol(palya);

    printf("\nIrany: ");
    scanf(" %c", &irany);

    system("cls");

    while((eredmeny = leptet(palya, (Irany) irany)) != 1) {
        if(eredmeny == 0)
            printf("Nem mehetsz a kivant iranyba!\n\n");
        else if(eredmeny == 2)
            ++megtalalt_kincsek;

        printf("Kincsek szama: %d\n\n", megtalalt_kincsek);
        kirajzol(palya);

        printf("\nIrany: ");
        scanf(" %c", &irany);

        system("cls");
    }

    if(kincsek_szama(palya) == 0)
        printf("Nyertel!\n");
    else
        printf("Vesztettel!\n");

    felszabadit(palya);

    return 0;
}
