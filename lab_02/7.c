#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Adott hosszusagu vonal\n\n");

    //Kérek egy számot, legyen ez 'hossz'
    int hossz;
    printf("Mekkora legyen a szakasz? ");
    scanf("%d", &hossz);

    //Gondolok egy számra, legyen ez 1
    int szam = 1;

    //Leírom: '+'
    printf("+");

    //Ismétlés amíg a szám <= hossz
    while(szam <= hossz) {
        //Leírom: '-'
        printf("-");

        //Növelem a számot 1-gyel
        szam++;
    }

    //Leírom: '+'
    printf("+");

    return 0;
}
