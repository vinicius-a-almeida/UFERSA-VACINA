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

struct cartao_vacina{
	C_V_NO *prim_pessoa
};

union cpf_rg{
		int CPF;
		int RG;
};

struct cartao_vacina_NO{
	
	int idade_pessoa;
	char nome_pessoa[100];
	char nome_vacina[100];
	int dose;
	int data_aplicacao;
	
	CPF_RG doc; 
	
	C_V_NO *prox_pessoa;
	
};

Cartao_Vacina *cria(){
    Cartao_Vacina *c_v = (Cartao_Vacina *) malloc(sizeof(Cartao_Vacina));
    c_v->prim_pessoa = NULL;
    return c_v;
    
}

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

void aplicar_vacina_pessoa(Cartao_Vacina *c_v){
	int opcao;
    C_V_NO * cartao_novo  = (C_V_NO *) malloc(sizeof(C_V_NO));
    
    //dados pessoais
    printf("digite o nome do pessoa: ");
    scanf("%s", cartao_novo->nome_pessoa);
    
    
    //não entendi essa parte!!!!!
    
    printf("qual documento deseja informar?\n");
    printf("[1] para CPF\n");
    printf("[2] para RG\n");
    printf("insira a opcao desejada >:");
    scanf("%d", &opcao);
    switch(opcao){
		case 1:
			printf("informe o CPF \n>:");
			scanf("%d", cartao_novo->doc);
			
			break;
		case 2:
			printf("informe o RG \n>:");
			scanf("%d", cartao_novo->doc);
			break;
		
		default:
			break;
	}
	
    printf("digite a idade da pessoa: ");
    scanf("%d", cartao_novo->idade_pessoa);
    
    //dados da aplicação da vacina
    printf("digite o nome da vacina: ");
    scanf("%s", cartao_novo->nome_vacina);    
    printf("digite a dose da vacina: ");
    scanf("%d", cartao_novo->dose);
    printf("digite a data de aplicacao da vacina: ");
    scanf("%d", cartao_novo->data_aplicacao);
    
    cartao_novo->prox_pessoa = c_v->prim_pessoa;
    c_v->prim_pessoa = cartao_novo;
}