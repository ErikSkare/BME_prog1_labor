#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI = 3.14159265;
    double h, d;

    printf("Tartaly festese\n\n");
    printf("Milyen magas? ");
    scanf("%lf", &h);
    printf("Mennyi az atmeroje? ");
    scanf("%lf", &d);

    double a = d * PI * h + 2 * (d / 2) * (d / 2) * PI;

    printf("%lf doboz festek kell.", a / 2);
    return 0;
}
