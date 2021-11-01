#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"


/*A függvény elhagyja a paraméterként adott
  sztringbõl az [a, b[ intervallumot és visszatér
  az új sztring memóriacímével
  a felszabadítás a hívó felelõssége
  használat: char *res = elhagy(str, 4, 8);*/
char *elhagy(char *str, int a, int b) {
    if(a < 0) a = 0;
    if(b > strlen(str)) b = strlen(str);
    int kell = strlen(str) - (b - a);
    char *res = (char*)malloc((kell + 1) * sizeof(char));
    for(int i = 0; i < a; i++)
        res[i] = str[i];
    for(int i = b; i < strlen(str); i++)
        res[a + i - b] = str[i];
    res[kell] = '\0';
    return res;
}

int main(void) {
    char *x = elhagy("hello, vilag", 4, 8);
    printf("%s\n", x);
    free(x);
    return 0;
}
