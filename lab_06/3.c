#include <stdio.h>
#include <stdlib.h>

void felulet_terfogat(double oldalhossz, double *felulet, double *terfogat) {
    (*felulet) = 6 * oldalhossz * oldalhossz;
    (*terfogat) = oldalhossz * oldalhossz * oldalhossz;
}

int main()
{
    double oldalhossz = 2.7;
    double felulet, terfogat;

    felulet_terfogat(2.7, &felulet, &terfogat);

    printf("Felulet: %f\n", felulet);
    printf("Terfogat: %f\n", terfogat);
    return 0;
}
