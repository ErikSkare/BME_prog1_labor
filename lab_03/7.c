#include <stdio.h>
#include <stdlib.h>

int main()
{
    char t[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};
    for(int i = 0; i < 10; i++) {
        //Elemek ki�r�sa
        for(int j = 0; j < 10; j++) {
            printf("%c ", t[j]);
        }
        printf("\n");

        //T�mb elemeinek eltol�sa
        char elso = t[0];
        for(int i = 1; i < 10; i++) {
            t[i-1] = t[i];
        }
        t[9] = elso;
    }
    return 0;
}
