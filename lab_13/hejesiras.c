#include <stdio.h>


// 3. feladat: Táblázat
// |          |     l       |       y      |   default  |
// |  alap    | l_volt      |       -      |     -      |
// |  l_volt  | ll_volt     |  alap/cnt+1  |    alap    |
// |  ll_volt |   -         |  alap/cnt+2  |    alap    |


// 4. feladat: Táblázat
//               l               y               default
// alap      l_volt            ki(c)              ki(c)
// l_volt    ll_volt           alap/ki('j')    alap/ki('l' + c)
// ll_volt   ki('l')           alap/ki('jj')   alap/ki('ll' + c)


// 5. feladat: hejesiras.exe > kimenet.txt
//             hejesiras.exe < bemenet.txt
//             hejesiras.exe < bemenet.txt > kimenet.txt


// 8. feladat: Táblázat
//
// 2 új állapot kell!
//
//               l               y               default             L
// kezdet    l_volt          alap/ki(c)         alap/ki(c)         L_volt
// L_volt  l_volt/ki('L')    alap/ki('J')       alap/ki('L' + c)
// alap      l_volt            ki(c)              ki(c)
// l_volt    ll_volt           alap/ki('j')    alap/ki('l' + c)
// ll_volt   ki('l')           alap/ki('jj')   alap/ki('ll' + c)


int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Hasznalat: helyesiras <bemenet> <kimenet>");
        return 1;
    }

    typedef enum LyAllapot {
        kezdo, L_volt, alap, l_volt, ll_volt
    } LyAllapot;
    LyAllapot all;

    FILE *be = fopen(argv[1], "r");
    if(be == NULL) {
        fprintf(stderr, "Hiba: nem nyithato meg a bemeneti fajl.");
        return 2;
    }

    FILE *ki = fopen(argv[2], "w");
    if(ki == NULL) {
        fprintf(stderr, "Hiba: nem nyithato meg a kimeneti fajl.");
        return 3;
    }

    char c;
    all = kezdo;
    while ((c = fgetc(be)) != EOF) {
        switch (all) {
            case kezdo:
                switch(c) {
                    case 'l':
                        all = l_volt;
                        break;
                    case 'L':
                        all = L_volt;
                        break;
                    default:
                        all = alap;
                        fprintf(ki, "%c", c);
                        break;
                }
                break;
            case L_volt:
                switch(c) {
                    case 'l':
                        all = l_volt;
                        fprintf(ki, "L");
                        break;
                    case 'y':
                        all = alap;
                        fprintf(ki, "J");
                        break;
                    default:
                        all = alap;
                        fprintf(ki, "L%c", c);
                        break;
                }
                break;
            case alap:
                if (c == 'l')
                    all = l_volt;
                else
                    fprintf(ki, "%c", c);
                break;

            case l_volt:
                switch (c) {
                    case 'l':
                        all = ll_volt;
                        break;
                    case 'y':
                        all = alap;
                        fprintf(ki, "j");
                        break;
                    default:
                        all = alap;
                        fprintf(ki, "l%c", c);
                        break;
                }
                break;

              case ll_volt:
                switch (c) {
                  case 'l':
                      fprintf(ki, "l");
                      break;
                  case 'y':
                      all = alap;
                      fprintf(ki, "jj");
                      break;
                  default:
                      all = alap;
                      fprintf(ki, "ll%c", c);
                      break;
                }
                break;
        }
        if(c == '\n')
            all = kezdo;
    }

    return 0;
}
