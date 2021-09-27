#include <stdio.h>
#include <stdlib.h>

int main()
{
    int szam = 1;

	printf("Szamok kiirasa\n\n");
    printf("while ciklussal: ");
    while(szam <= 20) {
        printf("%d ", szam);
        szam++;
    }

    printf("\n\n");

    printf("for ciklussal: ");
    for(int szam = 1; szam <= 20; szam++) {
        printf("%d ", szam);
    }
    return 0;
}
