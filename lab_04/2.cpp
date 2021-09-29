#include <iostream>
#include <math.h>

using namespace std;

double kob(double szam);

double abszolut(double szam);

int main()
{
    for(double a = -1; a <= 1; a+=0.1) {
        printf("%.4f, %.4f, %.4f, %.4f\n", a, kob(a), abszolut(a), sin(a));
    }

    return 0;
}

double kob(double szam) {
    return szam * szam * szam;
}

double abszolut(double szam) {
    if(szam >= 0) return szam;
    else return -szam;
}
