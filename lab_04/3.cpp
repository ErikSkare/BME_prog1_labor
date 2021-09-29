#include <iostream>
#include <stdbool.h>

using namespace std;

bool maganhangzo(char c);

int main(void) {
    char c;
    while (scanf("%c", &c) != EOF) {
        if (maganhangzo(c))
            printf("%cv%c", c, tolower(c));
        else
            printf("%c", c);
    }

    return 0;
}

bool maganhangzo(char c) {
    char c_kicsi = tolower(c);
    return c_kicsi == 'a' || c_kicsi == 'e' || c_kicsi == 'i'
    || c_kicsi == 'o' || c_kicsi == 'u';
}
