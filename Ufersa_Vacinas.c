#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ufersa.vacinas.h""


struct vacina{

    VacinaNO *prim;

};

struct vacinaNO{

    char nome[100];
    char lote[100];
    char data[100]; 
    char validade[100];
    VacinaNO *prox;

};

Vacina *cria(){
	
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
    VacinaNO *ant = NULL;
    VacinaNO *p = v->prim;
    while(p != NULL && strcmp(p->nome, nome)!=0  && strcmp(p->lote, lote)!=0){
        ant = p;
        p = p->prox;

    }
    if(p != NULL){
        if(ant == NULL){
            v->prim = p->prox;
        }
        else{
            ant->prox = p->prox;
        }
        free(p);
    }
    
}

void listar_vacina(Vacina *v){

    VacinaNO *p;
    for(p = v->prim; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        printf("%s\n", p->lote);
        printf("%s\n", p->data);
        printf("%s\n", p->validade);
    }
}

VacinaNO *busca(Vacina *v){
	
    char nome[100], lote[100];
    printf("digite o nome da vacina que deseja buscar: ");
    scanf(" %s", nome);
    printf("digite o lote da vacina que deseja buscar: ");
    scanf(" %s", lote);
    VacinaNO *p;
    p = v->prim;
    for(p; p != NULL; p = p->prox){
        if(strcmp(p->nome, nome)==0 && strcmp(p->lote, lote)==0){
            return p;
        }
    }
 return (NULL);
    
}