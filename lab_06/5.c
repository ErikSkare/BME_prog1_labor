#include <stdio.h>
#include <stdlib.h>


int main()
{
    char* keresztnev[50];
    scanf("%s", &keresztnev);

    for(char *betu = keresztnev; *betu != '\0'; betu++)
        printf("%c\n", *betu);
    return 0;
}
