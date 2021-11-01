#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

/*A függvény a paraméterként kapott sztringrõl
  készít másolatot egy dinamikus memóriaterületen
  és ennek a memóriacímét adja vissza
  a felszabadítás a hívó felelõssége
  használat: char *res = masolat(a);*/
char *masolat(char *str) {
    char *res = (char*)malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i <= strlen(str); i++)
        res[i] = str[i];
    return res;
}

/*A függvény hozzáfûzi az elsõ stringhez
  a másodikat, majd visszatér a memóriacímmel
  a felszabadítás a hívó felelõssége
  használat: char *res = hozzafuz(a, "fa");*/
char *hozzafuz(char *a, char *b) {
    int a_hossz = strlen(a), b_hossz = strlen(b);
    int kell = a_hossz + b_hossz;
    char *str = (char*)realloc(a, (kell + 1) * sizeof(char));
    for(int i = 0; i < b_hossz; i++)
        str[a_hossz + i] = b[i];
    str[kell] = '\0';
    return str;
}

int main(void) {
    char *x = masolat("alma");  /* az elõzõ feladatból */

    x = hozzafuz(x, "fa");
    printf("%s\n", x);    /* almafa */

    free(x);
    return 0;
}
