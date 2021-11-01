#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"


/* A függvény kivágja a paraméterként megadott
  sztringbõl az adott intervallumot
  majd visszatér annak memóriacímével
  a felszabadítás a hívó felelõssége
  használat: char *res = kivag(str, 3, 9);*/
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
