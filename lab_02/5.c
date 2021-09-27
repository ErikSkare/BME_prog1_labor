#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b, c;

    printf("Masodfoku egyenlet diszkutalasa\n\n");
    printf("Masodfoku tag egyutthatoja: ");
    scanf("%lf", &a);
    printf("Elsofoku tag egyutthatoja: ");
    scanf("%lf", &b);
    printf("Konstans tag egyutthatoja: ");
    scanf("%lf", &c);

    double diszkriminans = b * b - 4 * a * c;

    if(diszkriminans < 0) {
        printf("Az egyenletnek %d valos megoldasa van.", 0);
    } else if(diszkriminans == 0) {
        printf("Az egyenletnek %d valos megoldasa van.", 1);
    } else {
        printf("Az egyenletnek %d valos megoldasa van.", 2);
    }
    return 0;
}
