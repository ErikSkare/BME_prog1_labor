#include <stdio.h>
#include <stdlib.h>

typedef struct BinFa {
    int adat;
    struct BinFa *jobbra, *balra;
} BinFa;

typedef struct SorElem {
    BinFa *gyoker;
    struct SorElem *kov;
} SorElem;

typedef struct Sor {
    SorElem *eleje, *vege;
} Sor;

//Beszúrás a sorba O(1)
void beszur(BinFa *gyoker, Sor *sor) {
    SorElem *uj = (SorElem*) malloc(sizeof(SorElem));
    uj->gyoker = gyoker;
    uj->kov = NULL;

    if(sor->eleje == NULL)
        sor->eleje = uj;
    else
        sor->vege->kov = uj;

    sor->vege = uj;
}

//Kiszedés a sorból O(1)
BinFa *kiszed(Sor *sor) {
    SorElem *tmp = sor->eleje;
    BinFa *gyoker = tmp->gyoker;
    sor->eleje = tmp->kov;
    free(tmp);
    return gyoker;
}

//Felépít egy bináris fát a megadott tömbbõl
BinFa *fa_epit(int *t, int n, int index) {
    if(index >= n)
        return NULL;

    BinFa *gyoker = (BinFa*) malloc(sizeof(BinFa));
    gyoker->adat = t[index];
    gyoker->balra = fa_epit(t, n, 2 * index + 1);
    gyoker->jobbra = fa_epit(t, n, 2 * index + 2);

    return gyoker;
}

//Felszabadítja a bináris fát
void fa_felszabadit(BinFa *gyoker) {
    if(gyoker == NULL)
        return;

    fa_felszabadit(gyoker->balra);
    fa_felszabadit(gyoker->jobbra);

    free(gyoker);
}

int main()
{
    int n = 7;
    int t[] = {0, 1, 2, 3, 4, 5, 6};
    BinFa *gyoker = fa_epit(t, n, 0);

    Sor sor = {NULL, NULL};
    beszur(gyoker, &sor);

    while(sor.eleje != NULL) {
        BinFa *aktualis = kiszed(&sor);

        if(aktualis->balra != NULL)
            beszur(aktualis->balra, &sor);
        if(aktualis->jobbra != NULL)
            beszur(aktualis->jobbra, &sor);

        printf("%d ", aktualis->adat);
    }

    fa_felszabadit(gyoker);
    return 0;
}
