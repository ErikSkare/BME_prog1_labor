#include <stdio.h>
#include <stdlib.h>


void jobbra_lep(int *pozicio) {
    (*pozicio)++;
    if(*pozicio > 32767) exit(-1);
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

void kiir(signed char *memoria, int pozicio) {
    putchar(memoria[pozicio]);
}

void beolvas(signed char *memoria, int pozicio) {
    int eredmeny = getchar();
    if(eredmeny == EOF) memoria[pozicio] = -1;
    else memoria[pozicio] = eredmeny;
}

void ciklus_kezdete(signed char *memoria, int pozicio, char *programkod, int *index) {
    if(memoria[pozicio] == 0) {
        int hanyadik = 0;
        while(programkod[*index] != ']' || hanyadik != 1) {
            if(programkod[*index] == '[') hanyadik++;
            else if(programkod[*index] == ']') hanyadik--;
            (*index)++;
        }
    }
    (*index)++;
}

void ciklus_vege(signed char *memoria, int pozicio, char *programkod, int *index) {
    if(memoria[pozicio] != 0) {
        int hanyadik = 0;
        while(programkod[*index] != '[' || hanyadik != 1) {
            if(programkod[*index] == ']') hanyadik++;
            else if(programkod[*index] == '[') hanyadik--;
            (*index)--;
        }
    }
    (*index)++;
}

int main()
{
    //A keresztnevemet kiíró program
    char programkod[] = "+++++++[>++++++++++<-]>-.<+++++[>+++++++++<-]>.---------.++.";

    //Memória
    signed char memoria[32768];
    int pozicio = 0;

    //Zárójelek helyességének tesztelése
    int elojeles_zarojelek = 0;
    for(int i = 0; programkod[i] != '\0'; i++) {
        if(programkod[i] == '[') elojeles_zarojelek++;
        else if(programkod[i] == ']') elojeles_zarojelek--;
        if(elojeles_zarojelek < 0) exit(-1);
    }
    if(elojeles_zarojelek != 0) exit(-1);

    //Programkód feldolgozása
    int index = 0;
    while(programkod[index] != '\0') {
        switch(programkod[index]) {
            case '>':
                jobbra_lep(&pozicio);
                index++;
                break;

            case '<':
                balra_lep(&pozicio);
                index++;
                break;

            case '+':
                noveles(memoria, pozicio);
                index++;
                break;

            case '-':
                csokkentes(memoria, pozicio);
                index++;
                break;

            case '.':
                kiir(memoria, pozicio);
                index++;
                break;

            case ',':
                beolvas(memoria, pozicio);
                index++;
                break;

            case '[':
                ciklus_kezdete(memoria, pozicio, programkod, &index);
                break;

            case ']':
                ciklus_vege(memoria, pozicio, programkod, &index);
                break;

            default:
                index++;
                break;
        }
    }
    return 0;
}
