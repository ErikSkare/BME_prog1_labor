#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Adott hosszusagu vonal\n\n");

    //K�rek egy sz�mot, legyen ez 'hossz'
    int hossz;
    printf("Mekkora legyen a szakasz? ");
    scanf("%d", &hossz);

    //Gondolok egy sz�mra, legyen ez 1
    int szam = 1;

    //Le�rom: '+'
    printf("+");

    //Ism�tl�s am�g a sz�m <= hossz
    while(szam <= hossz) {
        //Le�rom: '-'
        printf("-");

        //N�velem a sz�mot 1-gyel
        szam++;
    }

    //Le�rom: '+'
    printf("+");

    return 0;
}
