#include <stdio.h>

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };

    /* 0-s versenyz� neve - printf %s */
    printf("%s\n", versenyzok[0].nev);
    /* 2-es versenyz� helyez�se */
    printf("%d\n", versenyzok[2].helyezes);
    /* 4-es versenyz� sz�let�si d�tum�t (�rd meg a datum_kiir f�ggv�nyt!) */
    datum_kiir(versenyzok[4].szuletes);
    printf("\n");
    /* 1-es versenyz� nev�nek kezd�bet�j�t (ne feledd, a sztring karaktert�mb) */
    printf("%c\n", versenyzok[1].nev[0]);
    /* az 1-es versenyz� dobog�s-e? igen/nem, ak�r ?: oper�torral, de egy printf-fel */
    printf("%s", versenyzok[1].helyezes <= 3 ? "igen\n" : "nem\n");
    /* az 4-es versenyz� gyorsabb-e, mint a 3-as versenyz�? */
    printf("%s", (versenyzok[4].helyezes < versenyzok[3].helyezes) ? "igen\n" : "nem\n");
    /* az 1-es versenyz� ugyanabban az �vben sz�letett-e, mint a 2-es? */
    printf("%s", (versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev) ? "igen\n" : "nem\n");
    /* eg�sz�tsd ki a versenyzo_kiir() f�ggv�nyt,
     * azt�n �rd ki az 1-es versenyz� �sszes adat�t */
    versenyzo_kiir(versenyzok[1]);
    printf("\n");
    /* v�g�l list�zd ki az �sszes versenyz�t sorsz�mozva, �sszes adatukkal. */
    for(int i = 0; i < sizeof(versenyzok) / sizeof(Versenyzo); i++) {
        printf("[%d]: ", i);
        versenyzo_kiir(versenyzok[i]);
        printf("\n");
    }

    return 0;
}

void datum_kiir(Datum d) {
    printf("%d.", d.ev);
    if(d.ho <= 9)
        printf("0%d.", d.ho);
    else
        printf("%d.", d.ho);

    if(d.nap <= 9)
        printf("0%d.", d.nap);
    else
        printf("%d.", d.nap);
}

void versenyzo_kiir(Versenyzo v) {
    printf("%s - ", v.nev);
    datum_kiir(v.szuletes);
    printf(" - ");
    printf("%d.", v.helyezes);
}
