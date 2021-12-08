#ifndef LABIRINTUS_H
#define LABIRINTUS_H
#include <stdbool.h>

typedef char **Palya;

typedef struct Pozicio {
    int Y, X;
} Pozicio;

typedef enum Irany {
    LE = 's',
    FEL = 'w',
    JOBBRA = 'd',
    BALRA = 'a'
} Irany;

void kirajzol(Palya palya);

Pozicio jatekos_koordinatai(Palya palya);

int kincsek_szama(Palya palya);

bool helyes_irany(Palya palya, Irany merre);

int leptet(Palya palya, Irany merre);

bool utkereso(Palya palya, Pozicio kezdo);

Palya beolvas(char *fajlnev);

void felszabadit(Palya palya);

#endif
