#include <stdio.h>

using namespace std;

int visszaallit(int a);
int hozzaad(int a);
int megfordit(int a);
int szorzas(int a);

int main() {
    int a = 1;

    int vezerles;
    do {
        printf("Az ertek: %d\n", a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
           "1. Hozzaad 1-et\n"
           "2. Megforditja az elojelet\n"
           "3. Szorozza 2-vel\n"
           "9. Kilepes\n");
        scanf("%d", &vezerles);
        switch(vezerles) {
            case 0:
                a = visszaallit(a);
                break;
            case 1:
                a = hozzaad(a);
                break;
            case 2:
                a = megfordit(a);
                break;
            case 3:
                a = szorzas(a);
                break;
            default:
                break;
        }
        printf("--------------------------------");
    } while(vezerles != 9);

    return 0;
}

int visszaallit(int a) {
    return 1;
}

int hozzaad(int a) {
    return a + 1;
}

int megfordit(int a) {
    return -a;
}

int szorzas(int a) {
    return 2 * a;
}
