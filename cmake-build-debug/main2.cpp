
#include <iostream>
#include <string.h>
float valor;
char iden, iden2;
typedef struct {
    char idn;
    float nume;
}Num;
struct  Nodo{
    Num valor;
    struct Nodo *prox;
};
typedef struct Nodo nodo;

/*Num numero;*/
nodo *L= (nodo *) malloc(sizeof(nodo));

int iniciar() {
    L->prox= NULL;
}
int inserirInicio(){
    printf("Qual valor deseja inserir na primeira posicao?\n");
    scanf(" %f", &valor);
    printf("De uma identificacao ao valor(char)\n");
    scanf(" %c", &iden);
    nodo *novo= (nodo *) malloc(sizeof(nodo));
    novo->valor.nume= valor;
    novo->valor.idn= iden;
    novo->prox= L->prox;
    L->prox= novo;
}
/*int tamanho(){
    int i=0;
    nodo *no= L->prox;
    do{
        no= no->prox;
        i++;
    }while(no != NULL);
    return i;
}*/
int inserirMeio() {
    printf("Deseja inserir qual valor:\n");
    scanf(" %f", &valor);
    printf("De uma identificacao ao valor(char)\n");
    scanf(" %c", &iden);
    printf("Deseja inserir o novo valor depois de qual item?(utilize a identificação)\n");
    scanf(" %c", &iden2);

    nodo *novo = (nodo *) malloc(sizeof(nodo));
    novo->valor.nume = valor;
    novo->valor.idn = iden;

    nodo *tmp = NULL;
    nodo *no = L->prox;    //CONSERTAR
    while (no != NULL) {
        if (no->valor.idn == iden2) {

            tmp = no->prox;
            no->prox = novo;
            novo->prox = tmp;

        }
        no = no->prox;
    }
}
int inserirFinal(){
    nodo *novo= (nodo *) malloc(sizeof(nodo));
    printf("Deseja inserir qual valor?\n");
    scanf(" %f", &valor);
    printf("De um identificador ao valor(char)\n");
    scanf(" %c", &iden);
    nodo *no= L->prox;
    while(no->prox != NULL){
        no= no->prox;
    }
    no->prox= novo;
    novo->valor.nume= valor;
    novo->valor.idn= iden;
}
/*int excluirInicio(){
    nodo *noPrimeiro= L->prox;
    L->prox= noPrimeiro->prox;
    free(noPrimeiro);
}*/

int main() {
    iniciar();
    inserirInicio();
    inserirFinal();
    inserirMeio();
    inserirInicio();
}