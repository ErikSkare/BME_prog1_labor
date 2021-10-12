#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char* forras, char* cel) {
    char *elso_jobb = forras;

    while(*elso_jobb == ' ')
        ++elso_jobb;

    char *elso_bal = forras + strlen(forras) - 1;

    while(*elso_bal == ' ')
        --elso_bal;

    int db = 0;
    while(elso_jobb != elso_bal + 1) {
        cel[db++] = (*elso_jobb);
        elso_jobb++;
    }
    cel[db] = '\0';
}

int main()
{
    char* forras = "  hello, mizu?  ";
    char* cel;

    trim(forras, cel);

    printf("%d, %s\n", strlen(forras), forras);
    printf("%d, %s", strlen(cel), cel);

    // Meg kell kapnia a forrástömb méretét, mert a legrosszabb eset az
    // ha nincs se az elején se a végén szóköz.
    return 0;
}
