#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    double *t = NULL;

    double x;
    scanf("%lf", &x);

    while(x != -1) {
        double *uj = (double*) malloc((n + 1) * sizeof(double));

        for(int i = 0; i < n; i++)
            uj[i] = t[i];

        uj[n++] = x;

        free(t);
        t = uj;

        scanf("%lf", &x);
    }

    for(int i = n-1; i >= 0; --i)
        printf("%lf ", t[i]);

    free(t);

    return 0;
}
