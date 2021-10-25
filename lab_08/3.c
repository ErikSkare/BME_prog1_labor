#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *t = (char*) malloc(1 * sizeof(char));
    t[0] = '\0';

    char c;
    scanf("%c", &c);

    while(c != '\n') {
        int hossz = strlen(t) + 1;

        char *uj = (char*) malloc((hossz + 1) * sizeof(double));
        for(int i = 0; i < hossz - 1; i++)
            uj[i] = t[i];
        uj[hossz - 1] = c;
        uj[hossz] = '\0';

        free(t);
        t = uj;

        scanf("%c", &c);
    }

    printf("%s", t);
    free(t);

    return 0;
}
