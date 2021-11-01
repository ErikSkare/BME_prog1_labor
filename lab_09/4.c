#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

/*A f�ggv�ny a param�terk�nt kapott sztringr�l
  k�sz�t m�solatot egy dinamikus mem�riater�leten
  �s ennek a mem�riac�m�t adja vissza
  a felszabad�t�s a h�v� felel�ss�ge
  haszn�lat: char *res = masolat(a);*/
char *masolat(char *str) {
    char *res = (char*)malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i <= strlen(str); i++)
        res[i] = str[i];
    return res;
}

/*A f�ggv�ny hozz�f�zi az els� stringhez
  a m�sodikat, majd visszat�r a mem�riac�mmel
  a felszabad�t�s a h�v� felel�ss�ge
  haszn�lat: char *res = hozzafuz(a, "fa");*/
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
    char *x = masolat("alma");  /* az el�z� feladatb�l */

    x = hozzafuz(x, "fa");
    printf("%s\n", x);    /* almafa */

    free(x);
    return 0;
}
