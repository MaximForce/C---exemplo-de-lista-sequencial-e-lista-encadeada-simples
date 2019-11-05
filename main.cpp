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

Num numero;

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
    novo->prox = NULL;
}
int excluirInicio(){
    nodo *noPrimeiro= L->prox;
    L->prox= noPrimeiro->prox;
    free(noPrimeiro);
}
int excluirMeio(){
    printf("Deseja excluir qual valor?(utilize a identificação)\n");
    scanf(" %c", &iden);
    nodo *noAnterior= L;
    nodo *noAtual= L->prox;
    while(noAtual->prox != NULL){
        if((noAtual->valor.idn) == iden){
            noAnterior->prox= noAtual->prox;
            free (noAtual);
        }
        noAnterior= noAtual;
        noAtual= noAtual->prox;
    }
}
int excluirFinal(){
    nodo *noAnterior= L;
    nodo *noAtual= L->prox;
    while(noAtual->prox != NULL){
        noAnterior= noAtual;
        noAtual= noAtual->prox;
    }
    noAnterior->prox= NULL;
    free(noAtual);
}
int pesquisa(){
    printf("Digite a identificacao do valor para encontra-lo.\n");
    scanf(" %c", &iden);
    nodo *no= L->prox;
    printf("ID\t\tvalor\n");
    while(no != NULL){
        if(no->valor.idn == iden){
            printf(" %c\t\t%f\n\n", no->valor.idn, no->valor.nume);
        }
        no= no->prox;
    }
}
int imprimeLista(){
    nodo *no = L->prox;
    printf("lista atual:\n");
    printf("ID\t\tValor\n");
    while(no->prox != NULL) {
        printf(" %c\t\t", no->valor.idn);
        printf(" %f \n", no->valor.nume);
        no = no->prox;
    }
    printf(" %c\t\t", no->valor.idn);
    printf(" %f \n", no->valor.nume);
    return 0;
}

int main() {
    iniciar();
    int opcao;
    do {
        printf("Para sair tecle 0\n");
        printf("Para inserir um valor na lista tecle 1\n");
        printf("Para excluir um valor da lista tecle 2\n");
        printf("Para pesquisar na lista tecle 3\n");
        printf("Para ver a sua lista atual tecle 4\n");
        scanf(" %d", &opcao);
        if(opcao == 1) {
            printf("Para inserir na primeira posicao tecle 1\n");
            printf("Para inserir no meio da lista tecle 2\n");
            printf("Para inserir no final da lista tecle 3\n");
            scanf(" %d", &opcao);
            if (opcao == 1) {
                inserirInicio();
            } else if (opcao == 2) {
                inserirMeio();
            } else if (opcao == 3) {
                inserirFinal();
            }
        } else if(opcao == 2) {
            printf("Para excluir o valor na primeira posicao tecle 1\n");
            printf("Para excluir um valor no meio da lista tecle 2\n");
            printf("Para excluir o valor no final da lista tecle 3\n");
            scanf(" %d", &opcao);
            if (opcao == 1) {
                printf("tem certeza? 1 para sim e 2 para nao.\n");
                scanf(" %d", &opcao);
                if (opcao == 1) {
                    excluirInicio();
                }
            } else if (opcao == 2) {
                excluirMeio();
            } else if (opcao == 3) {
                printf("tem certeza? 1 para sim e 2 para nao.\n");
                scanf(" %d", &opcao);
                if (opcao == 1) {
                    excluirFinal();
                }
            }
            } else if (opcao == 3) {
                pesquisa();
            } else if(opcao == 4){
            imprimeLista();
        }

    }while (opcao != 0);
        nodo *no = L->prox;
        printf("lista final:");
        printf("ID\t\tValor\n");
        while(no->prox != NULL) {
            printf(" %c\t\t", no->valor.idn);
            printf(" %f \n", no->valor.nume);
            no = no->prox;
        }
        printf(" %c\t\t", no->valor.idn);
        printf(" %f", no->valor.nume);
        return 0;

    }

