#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labirintus.h"

static Pozicio kovetkezo_pozicio(Pozicio jatekos, Irany merre) {
    Pozicio kov;
    switch(merre) {
        case FEL:
            kov = (Pozicio) {jatekos.Y - 1, jatekos.X};
            break;
        case LE:
            kov = (Pozicio) {jatekos.Y + 1, jatekos.X};
            break;
        case BALRA:
            kov = (Pozicio) {jatekos.Y, jatekos.X - 1};
            break;
        case JOBBRA:
            kov = (Pozicio) {jatekos.Y, jatekos.X + 1};
            break;
    };
    return kov;
}

static bool bejaras(Palya palya, Pozicio aktualis, bool latogatottak[10][10]) {
    if(latogatottak[aktualis.Y][aktualis.X] || palya[aktualis.Y][aktualis.X] == '#')
        return false;
    if(aktualis.Y == 0 || aktualis.Y == 9 || aktualis.X == 0 || aktualis.X == 9)
        return true;

    latogatottak[aktualis.Y][aktualis.X] = true;

    return bejaras(palya, (Pozicio) {aktualis.Y - 1, aktualis.X}, latogatottak) ||
           bejaras(palya, (Pozicio) {aktualis.Y + 1, aktualis.X}, latogatottak) ||
           bejaras(palya, (Pozicio) {aktualis.Y, aktualis.X - 1}, latogatottak) ||
           bejaras(palya, (Pozicio) {aktualis.Y, aktualis.X + 1}, latogatottak);
}

void kirajzol(Palya palya) {
    for(int i = 0; i < 10; ++i)
        printf("%s\n", palya[i]);
}

Pozicio jatekos_koordinatai(Palya palya) {
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            if(palya[i][j] == '@')
                return (Pozicio) {i, j};
    return (Pozicio) {-1, -1};
}

int kincsek_szama(Palya palya) {
    int db = 0;
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            if(palya[i][j] == '$')
                db++;
    return db;
}

bool helyes_irany(Palya palya, Irany merre) {
    Pozicio jatekos = jatekos_koordinatai(palya);
    Pozicio kov = kovetkezo_pozicio(jatekos, merre);
    return palya[kov.Y][kov.X] != '#';
}

int leptet(Palya palya, Irany merre) {
    if(!helyes_irany(palya, merre))
        return 0; //Rossz irány

    Pozicio jatekos = jatekos_koordinatai(palya);
    Pozicio kov = kovetkezo_pozicio(jatekos, merre);
    char kov_karakter = palya[kov.Y][kov.X];

    palya[kov.Y][kov.X] = '@';
    palya[jatekos.Y][jatekos.X] = ' ';

    if(kov.Y == 0 || kov.Y == 9 || kov.X == 0 || kov.X == 9)
        return 1; //Kijáratba lépett

    if(kov_karakter == '$')
        return 2; //Kincset talált

    if(kov_karakter == ' ')
        return 3; //Üres mezõre lépett

    return -1;
}

bool utkereso(Palya palya, Pozicio kezdo) {
    bool latogatottak[10][10];
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            latogatottak[i][j] = false;
    return bejaras(palya, kezdo, latogatottak);
}

Palya beolvas(char *fajlnev) {
    FILE *fp = fopen(fajlnev, "r");

    Palya palya = (char**) malloc(10 * sizeof(char*));
    for(int i = 0; i < 10; ++i)
        palya[i] = (char*) malloc(11 * sizeof(char));

    char buffer[11];
    for(int i = 0; i < 10; ++i) {
        fgets(buffer, 11, fp);
        fscanf(fp, "\n");
        strcpy(palya[i], buffer);
    }

    fclose(fp);
    return palya;
}

void felszabadit(Palya palya) {
    for(int i = 0; i < 10; ++i)
        free(palya[i]);
    free(palya);
}
