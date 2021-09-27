#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Szorzotabla fejleccel\n\n");

    int n;
    printf("Adja meg a tablazat meretet: ");
    scanf("%d", &n);

    printf("\n  ");
    for(int i = 0; i < n; i++) {
        if(!i) printf("|  %d", i+1);
        else if(i+1 < 10) printf("   %d", i+1);
        else printf("  %d", i+1);
    }
    printf("\n--");
    for(int i = 0; i < n; i++) {
        if(!i) printf("+---");
        else printf("----");
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        if(i+1 < 10) printf(" %d|", i+1);
        else printf("%d|", i+1);
        for(int j = 0; j < n; j++) {
            int val = (i+1) * (j+1);
            if(val < 10) printf("  %d", val);
            else if(val < 100) printf(" %d", val);
            else printf("%d", val);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
