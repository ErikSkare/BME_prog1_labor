#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tablazat\n\n");

    int n;
    printf("Adja meg az n erteket: ");
    scanf("%d", &n);

    for(int i = 1; i <= n * n; i++) {
        printf("%d ", i);
        if(!(i % n)) printf("\n");
    }
    return 0;
}
