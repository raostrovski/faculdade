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


int main()
{
    int escolha, valor;
    char encerrar[] = "N";
    while(strcmp(encerrar,"N") == 0){
        printf("Selecione a informacao desejada.:\n1. Inserir no inicio\n2. Inserir no final\n3. Inserir ordernado\n4. Mostrar lista\n5. Remover do inicio\n6. Remover do final\n7. Remover elemento especifico\n8. Buscar elemento\n\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Selecione o valor que quer inserir: ");
                scanf("%d", &valor);
                inserirInicio(valor);
                break;
        }
        printf("Deseja encerrar o programa (S ou N): ");
        scanf("%s",encerrar);
    }
    return 0;
}
