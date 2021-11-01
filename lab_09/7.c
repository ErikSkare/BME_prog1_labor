#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"


/*A függvény az első paraméterként definiált
  sztring (index)-edik eleme után beszúrja a
  harmadik paraméterként definiált sztringet,
  majd visszatér az új memóriacímmel
  a felszabadítás a hívó felelőssége
  használat: char *res = beszur(str, 5, "teszt");*/
char *beszur(char *str, int index, char *a) {
    int kell = strlen(str) + strlen(a);
    char *res = (char*)malloc((kell + 1) * sizeof(char));
    for(int i = 0; i < index; i++)
        res[i] = str[i];
    for(int i = 0; i < strlen(a); i++)
        res[index + i] = a[i];
    for(int i = 0; i < kell - index - strlen(a); i++)
        res[index + strlen(a) + i] = str[index + i];
    res[kell] = '\0';
    return res;
}

int main(void) {

    char *x = beszur("hello!", 5, ", vilag");
    printf("%s\n", x);
    free(x);
    return 0;
}
