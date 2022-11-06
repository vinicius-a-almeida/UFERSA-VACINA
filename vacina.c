#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vacinaNO VacinaNO;
typedef struct vacina Vacina;

struct vacina{
    VacinaNO *prim;
};

struct vacinaNO{
    char nome[100], lote[100], data[100], validade[100];
    VacinaNO *prox;
};

Vacina *cria(void);
void inserir_vacina(Vacina *v);
void retirar_vacina(Vacina *v);
void imprime(Vacina *v);

int main(void){

    Vacina *v = cria(); 
    inserir_vacina(v);
    inserir_vacina(v);
    retirar_vacina(v);
    imprime(v);
    return 0;
}

Vacina *cria(void){
    Vacina *v = (Vacina *) malloc(sizeof(Vacina));
    v->prim = NULL;
    return v;

}

void inserir_vacina(Vacina *v){
    VacinaNO * novo  = (VacinaNO *) malloc(sizeof(VacinaNO));
    printf("digite o nome da vacina: ");
    scanf(" %s", novo->nome);
    printf("digite o lote da vacina: ");
    scanf(" %s", novo->lote);
    printf("digite a data da vacina: ");
    scanf(" %s", novo->data);
    printf("digite a validade da vacina: ");
    scanf(" %s", novo->validade);
    novo->prox = v->prim;
    v->prim = novo;
}

void retirar_vacina(Vacina *v){
    char nome[100], lote[100], data[100], validade[100];
    printf("qual o nome da vacina que deseja retirar? ");
    scanf(" %s", nome);
    printf("qual o lote que deseja retirar? ");
    scanf(" %s", lote);
    printf("qual a data da vacina que deseja retirar? ");
    scanf(" %s", data);
    printf("qual a validade da vacina que deseja retirar? ");
    scanf(" %s", validade);
    
    VacinaNO *ant = NULL;
    VacinaNO *p = v->prim;
    while(p != NULL && p->nome != nome){
        ant = p;
        p = p->prox;

    }
    while(p != NULL && p->lote != lote){
        ant = p;
        p = p->prox;

    }
    while(p != NULL && p->data != data){
        ant = p;
        p = p->prox;

    }
    while(p != NULL && p->validade != validade){
        ant = p;
        p = p->prox;

    }
    if(p != NULL ){
        if(ant == NULL){
            v->prim = p->prox;
        }
        else{
            ant->prox = p->prox;
        }
        free(p);
    }
}

void imprime(Vacina *v){
    for(VacinaNO *p = v->prim; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        printf("%s\n", p->lote);
        printf("%s\n", p->data);
        printf("%s\n", p->validade);
    }
}