#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Masodfoku egyenlet\n\n");

    double a, b, c;

    printf("A masodfoku tag egyutthatoja: ");
    scanf("%lf", &a);
    printf("Az elsofoku tag egyutthatoja: ");
    scanf("%lf", &b);
    printf("A konstans tag egyutthatoja: ");
    scanf("%lf", &c);

    double diszkriminans = b * b - 4 * a * c;
    if(diszkriminans >= 0) {
        double x1 = (-b + sqrt(diszkriminans)) / (2 * a);
        double x2 = (-b - sqrt(diszkriminans)) / (2 * a);
        if(x1 == x2) {
            printf("Az egyenlet megoldasa: %lf", x1);
        } else {
            printf("Az egyenlet megoldasai: %lf, %lf", x1, x2);
        }
    } else {
        printf("Az egyenletnek nincs valos megoldasa.");
    }
    return 0;
}
