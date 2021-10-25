#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Hany darab valos szamot olvassak be? ");
    scanf("%d", &n);

    double *tomb = (double*) malloc(n * sizeof(double));

    for(int i = 0; i < n; ++i)
        scanf("%lf", &tomb[i]);

    for(int i = n-1; i >= 0; i--)
        printf("%lf; ", tomb[i]);

    free(tomb);

    return 0;
}
