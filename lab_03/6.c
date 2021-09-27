#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98};

    //A t�mb ki�r�sa
    printf("A tomb: ");
    for(int i = 0; i < 10; i++) {
        printf("[%d]=%d ", i, t[i]);
    }
    printf("\n");

    //Legkisebb hely meghat�roz�sa
    int legkisebb = t[0];
    int legkisebb_helye = 0;
    for(int i = 1; i < 10; i++) {
        if(t[i] < legkisebb) {
            legkisebb = t[i];
            legkisebb_helye = i;
        }
    }
    printf("A legkisebb szam: %d\n", legkisebb);
    printf("A legkisebb indexe: %d\n", legkisebb_helye);

    //Legkisebb hely jel�l�se
    printf("Jelolve: ");
    for(int i = 0; i < 10; i++) {
        printf("%d", t[i]);
        if(i == legkisebb_helye) {
            printf("[MIN]");
        }
        printf(" ");
    }
    return 0;
}
