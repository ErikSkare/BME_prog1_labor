#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 1;
    int szorzat = 1;
    while(n <= 8) {
        szorzat = szorzat * n;
        n += 1;
    }
    printf("%d", szorzat);
    return 0;
}
