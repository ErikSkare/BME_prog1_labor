#include <stdlib.h>

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;

/*
 * 2.feladat:
 * Azért vannak fordítva az elemek, mert a létrehozásnál
 * a lista elejére szúrjuk be az új elemeket.
 */
void lista_kiir(ListaElem *eleje) {
    ListaElem *futo = eleje;
    while(futo != NULL) {
        printf("%d ", futo->adat);
        futo = futo->kov;
    }
}

/*
 * 3.feladat:
 */
int lista_hossz(ListaElem *eleje) {
    int hossz = 0;
    ListaElem *futo = eleje;
    while(futo != NULL) {
        ++hossz;
        futo = futo->kov;
    }
    return hossz;
}

/*
 * 4. feladat:
 */
void lista_felszabadit(ListaElem *eleje) {
    ListaElem *futo = eleje;
    while(futo != NULL) {
        ListaElem *kov = futo->kov;
        free(futo);
        futo = kov;
    }
}

/*
 * 5. feladat:
 */
ListaElem *lista_elejere_beszur(ListaElem *eleje, int szam) {
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    if(uj == NULL)
        return eleje;
    uj->adat = szam;
    uj->kov = eleje;
    return uj;
}

/*
 * 6. feladat:
 */
ListaElem *lista_vegere_beszur(ListaElem *eleje, int szam) {
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    if(uj == NULL)
        return eleje;
    uj->adat = szam;
    uj->kov = NULL;
    if(eleje == NULL)
        return uj;
    ListaElem *futo = eleje;
    while(futo->kov != NULL)
        futo = futo->kov;
    futo->kov = uj;
    return eleje;
}

/*
 * 7. feladat:
 */
ListaElem *kereses_listaban(ListaElem *eleje, int szam) {
    ListaElem *futo = eleje;
    while(futo != NULL && futo->adat != szam)
        futo = futo->kov;
    return futo;
}

int main(void) {
    ListaElem *eleje = NULL;
    eleje = lista_elejere_beszur(eleje, 1);
    eleje = lista_elejere_beszur(eleje, 2);
    eleje = lista_elejere_beszur(eleje, 3);
    eleje = lista_elejere_beszur(eleje, 4);
    eleje = lista_elejere_beszur(eleje, 5);

    lista_kiir(eleje);
    printf("\n");

    printf("%d\n", lista_hossz(eleje));

    eleje = lista_elejere_beszur(eleje, 21);
    eleje = lista_elejere_beszur(eleje, 22);
    lista_kiir(eleje);
    printf("\n");

    eleje = lista_vegere_beszur(eleje, 100);
    lista_kiir(eleje);
    printf("\n");

    ListaElem *keresett = kereses_listaban(eleje, 100);
    if(keresett != NULL)
        printf("Megtalaltam.\n");
    else
        printf("Nem talaltam meg.\n");

    lista_felszabadit(eleje);

    return 0;
}
