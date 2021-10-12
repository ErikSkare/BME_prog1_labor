#include <stdio.h>
#include <stdlib.h>

//Indexet ad vissza
int keres_1(int *tomb, int meret, int keresendo) {
    int *aktualis = tomb;
    while(aktualis - tomb < meret && *aktualis != keresendo)
        aktualis++;

    return (aktualis - tomb < meret) ? aktualis - tomb : -1;
}

//Memóriacímet ad vissza
int *keres_2(int *tomb, int meret, int keresendo) {
    int *aktualis = tomb;
    while(aktualis - tomb < meret && *aktualis != keresendo)
        aktualis++;

    return (aktualis - tomb < meret) ? aktualis : NULL;
}

int main()
{
    int tomb[5] = {6, 2, 3, 4, 5};

    printf("a tomb: ");
    for(int *aktualis = tomb; aktualis - tomb < 5; aktualis++)
        printf("%d.: %d;  ", aktualis - tomb, *aktualis);
    printf("\n");

    int eredmeny_1 = keres_1(tomb, 5, 3);

    printf("keres_1: ");
    if(eredmeny_1 == -1)
        printf("nincs talalat.\n");
    else
        printf("index %d\n", eredmeny_1);

    int *eredmeny_2 = keres_2(tomb, 5, 5);

    printf("keres_2: ");
    if(eredmeny_1 == NULL)
        printf("nincs talalat.\n");
    else
        printf("index %d\n", eredmeny_2 - tomb);

    return 0;
}
