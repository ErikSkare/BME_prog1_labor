#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"


/* A f�ggv�ny kiv�gja a param�terk�nt megadott
  sztringb�l az adott intervallumot
  majd visszat�r annak mem�riac�m�vel
  a felszabad�t�s a h�v� felel�ss�ge
  haszn�lat: char *res = kivag(str, 3, 9);*/
char *kivag(char *str, int a, int b) {
    if(a < 0) a = 0;
    if(b > strlen(str)) b = strlen(str);
    char *res = malloc((b - a + 1) * sizeof(char));
    for(int i = a; i < b; i++)
        res[i - a] = str[i];
    res[b - a] = '\0';
    return res;
}

int main(void) {
    char *x = kivag("hello, vilag", 3, 9);
    printf("%s\n", x);
    free(x);
    return 0;
}
