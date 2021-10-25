#include <stdio.h>
#include <stdlib.h>

//segédfüggvény
char *karakter_beolvas(int index) {
    char *ptr;
    int ch = getchar();

    if(ch == EOF || ch == '\n') {
        ptr = (char*) malloc((index + 1) * sizeof(char));
        ptr[index] = '\0';
    } else {
        ptr = karakter_beolvas(index + 1);
        ptr[index] = ch;
    }

    return ptr;
}

char *sort_beolvas(void) {
    return karakter_beolvas(0);
}

int main()
{
    char *str = sort_beolvas();
    printf("%s", str);
    free(str);
    return 0;
}
