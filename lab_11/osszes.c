#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void in_order(BiFa *gyoker) {
    if(gyoker == NULL)
        return;
    in_order(gyoker->bal);
    printf("%d ", gyoker->ertek);
    in_order(gyoker->jobb);
}

void felszabadit(BiFa *gyoker) {
    if(gyoker == NULL)
        return;
    felszabadit(gyoker->bal);
    felszabadit(gyoker->jobb);
    free(gyoker);
}

int elemek_szama(BiFa *gyoker) {
    if(gyoker == NULL)
        return 0;
    return 1 + elemek_szama(gyoker->bal) + elemek_szama(gyoker->jobb);
}

int elemek_osszege(BiFa *gyoker) {
    if(gyoker == NULL)
        return 0;
    return gyoker->ertek + elemek_osszege(gyoker->bal) + elemek_osszege(gyoker->jobb);
}

BiFa *keres(BiFa *gyoker, int keresendo) {
    if(gyoker == NULL)
        return NULL;
    if(gyoker->ertek == keresendo)
        return gyoker;
    if(keresendo < gyoker->ertek)
        return keres(gyoker->bal, keresendo);
    else
        return keres(gyoker->jobb, keresendo);
}

void negalas(BiFa *gyoker) {
    if(gyoker == NULL)
        return;
    gyoker->ertek *= -1;
    negalas(gyoker->bal);
    negalas(gyoker->jobb);
}

BiFa *keres_negalt(BiFa *gyoker, int keresendo) {
    if(gyoker == NULL)
        return NULL;
    if(gyoker->ertek == keresendo)
        return gyoker;
    if(keresendo > gyoker->ertek)
        return keres_negalt(gyoker->bal, keresendo);
    else
        return keres_negalt(gyoker->jobb, keresendo);
}

void tukroz(BiFa *gyoker) {
    if(gyoker == NULL)
        return;
    tukroz(gyoker->bal);
    tukroz(gyoker->jobb);
    BiFa *tmp = gyoker->bal;
    gyoker->bal = gyoker->jobb;
    gyoker->jobb = tmp;
}


int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */
    //2. feladat
    printf("In order bejaras: ");
    in_order(gyoker);
    printf("\n");

    //3. feladat
    printf("Az elemek szama: %d\n", elemek_szama(gyoker));
    printf("Az elemek osszege: %d\n", elemek_osszege(gyoker));

    //4. feladat
    printf("Kereses: %d\n", keres(gyoker, 14)->ertek);

    //5. feladat
    //A negálás után a fa már nem bináris keresõfa, ezért nem mûködik az eredeti keresõfüggvény.
    //Ezért a relációs jelet fel kell cserélni.
    negalas(gyoker);
    printf("Negalt fa: ");
    in_order(gyoker);
    printf("\n");

    //6. feladat
    //Nem mûködik a tükrözés után a módosított keresõ függvény, mert az nem tud bináris keresõfán keresni.
    //(rossz irányba lép)
    tukroz(gyoker);
    printf("Tukrozott: ");
    in_order(gyoker);
    printf("\n");

    //2. feladat
    felszabadit(gyoker);

    return 0;
}
