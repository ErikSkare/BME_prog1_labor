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

int main(void) {
    char *str = masolat("teszt");
    printf("%s", str);
    free(str);
    return 0;
}
