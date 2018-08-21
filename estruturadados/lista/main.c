#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{

    int info;
    struct node *prox;

};

typedef struct node no;
no *plista;

void inserirInicio(int elemen){

    no *aux;
    aux       = (no*) malloc(sizeof(no));
    aux->info = elemen;
    aux->prox = plista;
    plista    = aux;
    aux       = NULL;

}

void inserirFinal(int elemen){

    no *aux = plista;
    no *auxUltimo;
    if(aux == NULL){

        inserirInicio(elemen);

    } else {

        while(aux->prox != NULL){
        aux = aux->prox;
        }
        auxUltimo       = (no*) malloc(sizeof(no));
        auxUltimo->info = elemen;
        auxUltimo->prox = aux->prox;
        aux->prox       = auxUltimo;
    }
}

void inserirOrdenado(int elemen){

    no *aux;
    no *pesquisa    = plista;
    no *auxAnterior = plista;
    if(elemen >= pesquisa->info){

        inserirInicio(elemen);

    } else {

        while(pesquisa->info >= elemen && pesquisa->prox != NULL){
            pesquisa = pesquisa->prox;
        }
        if(pesquisa->prox == NULL){

        inserirFinal(elemen);

        } else {

            aux = (no*) malloc(sizeof(no));
            aux->info = elemen;
            aux->prox = pesquisa;
            while(auxAnterior->prox != pesquisa){
                auxAnterior = auxAnterior->prox;
            }
            auxAnterior->prox = aux;
        }
    }

}

void mostrarLista(){

    no *aux = plista;
    while(aux != NULL){
        if(aux->prox == NULL){
            printf("%d", aux->info);
        } else {
            printf("%d, ", aux->info);
        }

        aux = aux->prox;
    }
    printf("\n");
}

void removerInicio(){

    no *aux = plista;
    if(aux == NULL){

        printf("Não existe lista\n");
    } else {
        aux     = aux->prox;
        plista  = aux;
        aux     = NULL;
        printf("Valor removido do inicio\n");
    }
}

void removerFinal(){

    no *aux = plista;
    no *auxUltimo = plista;
    if(aux == NULL){

        printf("Não existe lista\n");

    } else {

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        while(auxUltimo->prox != aux){
            auxUltimo = auxUltimo->prox;
        }
        auxUltimo->prox = NULL;
        printf("Removido primeiro elemento da lista.\n");
    }
}

void removerEspecifico(int elemen){

    int posicao = 1;
    no *aux = plista;
    no *aux2 = plista;
    if(aux == NULL){

        printf("Não existe lista\n");

    } else {

        while(posicao != elemen){
        aux = aux->prox;
        posicao++;
        }
        if(elemen == 1){

            removerInicio();

        } else {

            while(aux2->prox != aux){
            aux2 = aux2->prox;

            }

            aux2->prox = aux->prox;
            aux->prox = NULL;
            printf("Removido elemento da lista.\n");
        }
    }
}

int buscarElemento(int elemen){

    int posicao = 0;
    no *aux;
    for(aux = plista; aux != NULL; aux=aux->prox){
        posicao++;
        if(aux->info == elemen){
            return posicao;
        }
    }
    return 0;
}

int main()
{
    int escolha, valor, retornoBusca = 0;
    plista = NULL;
    char encerrar[] = "N";
    while((strcmp(encerrar,"N") == 0 || strcmp(encerrar,"n") == 0)){
        printf("Selecione a informacao desejada.:\n1. Inserir no inicio\n2. Inserir no final\n3. Inserir ordernado\n4. Mostrar lista\n5. Remover do inicio\n6. Remover do final\n7. Remover elemento especifico\n8. Buscar elemento\n9. Sair\n\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Selecione o valor que quer inserir: ");
                scanf("%d", &valor);
                inserirInicio(valor);
                break;
            case 2:
                printf("Selecione o valor que quer inserir: ");
                scanf("%d", &valor);
                inserirFinal(valor);
                break;
            case 3:
                printf("Selecione o valor que quer inserir: ");
                scanf("%d", &valor);
                inserirOrdenado(valor);
                break;
            case 4:
                printf("Mostrando a lista formada até agora: \n");
                mostrarLista();
                break;
            case 5:
                removerInicio();
                break;
            case 6:

                removerFinal();
                break;
            case 7:
                printf("Qual é o elemento que deseja remover? ");
                scanf("%d", &valor);
                removerEspecifico(valor);
                break;
            case 8:
                printf("Selecione o elemento que deseja procurar: ");
                scanf("%d", &valor);
                retornoBusca = buscarElemento(valor);
                if(retornoBusca == 0){

                    printf("Valor não encontrado.\n");

                } else {

                    printf("Valor localizado na posição: %d\n", retornoBusca);

                }
                break;
             case 9:
                printf("Até a proxima");
                return 0;
            default:
                printf("Opção inválida\n");
                break;
        }
        printf("Deseja encerrar o programa (S ou N): ");
        scanf("%s",encerrar);
    }
    return 0;
}
