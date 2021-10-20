#include <iostream>

using namespace std;

void kiir(int szam, int szamrendszer) {
    if(szam == 0)
        return;
    kiir(szam / szamrendszer, szamrendszer);
    printf("%d", szam % szamrendszer);
}

int main()
{
    kiir(54, 2);
    return 0;
}
