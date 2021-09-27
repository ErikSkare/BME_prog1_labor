#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void jobbra_lep(int *pozicio) {
    (*pozicio)++;
    if(*pozicio >= 32768) exit(-1);
}

void balra_lep(int *pozicio) {
    (*pozicio)--;
    if(*pozicio < 0) exit(-1);
}

void noveles(signed char *memoria, int pozicio) {
    memoria[pozicio]++;
}

void csokkentes(signed char *memoria, int pozicio) {
    memoria[pozicio]--;
}

void kiir(signed char *memoria, int pozicio, signed char *kimenet, int *kimenet_hossz) {
    kimenet[*kimenet_hossz] = memoria[pozicio];
    (*kimenet_hossz)++;
}

void beolvas(signed char *memoria, int pozicio) {
    scanf("%c", &memoria[pozicio]);
    if(memoria[pozicio] == '\0') memoria[pozicio] = -1;
}

void ciklus_kezdete(int *zarojel_poziciok, int *teteje, int index, int ertek, int *skip) {
    if(ertek == 0) {
        (*skip)++;
        return;
    }
    (*teteje)++;
    zarojel_poziciok[*teteje] = index;
}

int ciklus_vege(int *zarojel_poziciok, int *teteje, int index, int ertek, int *skip) {
    if(*skip > 0) {
        (*skip)--;
        return index + 1;
    }
    int temp = zarojel_poziciok[*teteje];
    (*teteje)--;
    if(ertek == 0) return index + 1;
    else return temp;
}

int main()
{
    // Programkód megadása
    //A keresztnevemet kiíró program
    char programkod[]="+++++++[>++++++++++<-]>-.<+++++[>+++++++++<-]>.---------.++.";

    //Zárójelek helyességének tesztelése
    int zarojelek = 0;
    for(int i = 0; programkod[i] != '\0'; i++) {
        if(programkod[i] == '[') zarojelek++;
        else if(programkod[i] == ']') zarojelek--;
        if(zarojelek < 0) exit(-1);
    }
    if(zarojelek != 0) exit(-1);

    // Változók inicializálása
    signed char memoria[32768];
    int pozicio = 0;

    signed char kimenet[32768];
    int kimenet_hossz = 0;

    int zarojel_poziciok[1000];
    int teteje = -1;
    int skip = 0;

    //Karakterek feldolgozása
    int i = 0;
    while(programkod[i] != '\0') {
        switch(programkod[i]) {
            case '>':
                if(skip == 0) jobbra_lep(&pozicio);
                i++;
                break;
            case '<':
                if(skip == 0) balra_lep(&pozicio);
                i++;
                break;
            case '+':
                if(skip == 0) noveles(memoria, pozicio);
                i++;
                break;
            case '-':
                if(skip == 0) csokkentes(memoria, pozicio);
                i++;
                break;
            case '.':
                if(skip == 0) kiir(memoria, pozicio, kimenet, &kimenet_hossz);
                i++;
                break;
            case ',':
                if(skip == 0) beolvas(memoria, pozicio);
                i++;
                break;
            case '[':
                ciklus_kezdete(zarojel_poziciok, &teteje, i, memoria[pozicio], &skip);
                i++;
                break;
            case ']':
                i = ciklus_vege(zarojel_poziciok, &teteje, i, memoria[pozicio], &skip);
                break;
            default:
                i++;
                break;
        }
    }

    for(int i = 0; i < kimenet_hossz; i++) {
        printf("%c", kimenet[i]);
    }

    return 0;
}
