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

int main(void) {
    char *str = masolat("teszt");
    printf("%s", str);
    free(str);
    return 0;
}
