#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacina.h"


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

union cpf_rg{
	
		int CPF;
		int RG;
		
};

struct cartao_vacina{ 
	
	C_V_NO *prim_pessoa;

};

struct cartao_vacina_NO{
	
    int dose;
	int idade_pessoa;
	int data_aplicacao;
	char nome_pessoa[100];
	char nome_vacina[100];
	
	CPF_RG doc; 
	C_V_NO *prox_pessoa;
	
};


Vacina *cria_v(){
	
    Vacina *v = (Vacina *) malloc(sizeof(Vacina));
    
    v->prim = NULL;
    
    return v;

}

Cartao_Vacina *cria_c_v(){
    
    Cartao_Vacina *c_v = (Cartao_Vacina *) malloc(sizeof(Cartao_Vacina));
    
    c_v->prim_pessoa = NULL;
    
    return c_v;
    
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
    main();
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
    main();
}

void listar_vacina(Vacina *v){

    VacinaNO *p;
    
    for(p = v->prim; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        
        printf("%s\n", p->lote);
        
        printf("%s\n", p->data);
        
        printf("%s\n", p->validade);
    }
    main();
}

VacinaNO *busca(Vacina *v){
	
    char nome[100], lote[100];
    
    printf("digite o nome da vacina que deseja buscar: ");
    scanf(" %s", nome);
    
    printf("digite o lote da vacina que deseja buscar: ");
    scanf(" %s", lote);
    
    VacinaNO *p;
    p = v->prim;
    
    for(; p != NULL; p = p->prox){
        if(strcmp(p->nome, nome)==0 && strcmp(p->lote, lote)==0){
            return p;
        }
    }
    
 return (NULL);
 main();
}


void aplicar_vacina_pessoa(Cartao_Vacina *c_v){
	
	int opcao;
	
    C_V_NO * cartao_novo  = (C_V_NO *) malloc(sizeof(C_V_NO));
    
    //dados pessoais
    printf("digite o nome do pessoa: ");
    scanf("%s", cartao_novo->nome_pessoa);
    
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
    
    printf("digite o nome da vacina: ");
    scanf("%s", cartao_novo->nome_vacina); 
	   
    printf("digite a dose da vacina: ");
    scanf("%d", cartao_novo->dose);
    
    printf("digite a data de aplicacao da vacina: ");
    scanf("%d", cartao_novo->data_aplicacao);
    
    cartao_novo->prox_pessoa = c_v->prim_pessoa;
    c_v->prim_pessoa = cartao_novo;
    main();
}
//
void editar_vacinas_cadastradas(Vacina *v){

    VacinaNO *cont, *pos;
    cont = v->prim;
    char nome[100], lote[100];
    int aux;
    printf("digite o nome da vacina que deseja editar >: ");
    scanf(" %s", nome);
    
    printf("digite o lote da vacina que deseja editar >: ");
    scanf(" %s", lote);
    
    for(; cont != NULL; cont = cont->prox){
        if(strcmp(cont->nome, nome)==0 && strcmp(cont->lote, lote)==0){
            pos = cont;
        }
    }
    
	   
	for(;aux < 1 || aux > 5;){

		printf("\\/ informe qual dessesas opcoes a baixo deseja editar /\\");
	    printf("\n\ndigite o numero referente a sua escolha!\n\n");

		void menu_de_escolha();
	    
        scanf("%d", &aux);

	    if(aux == 1){
			printf("opcao editar nome\n");
			scanf(" %s", pos->nome);
		}
		else if(aux == 2){
	        printf("opcao editar lote\n");
			scanf(" %s", pos->lote);
		}
		else if(aux == 3){
	       	printf("opcao editar data\n");
			scanf(" %s", pos->data);
		}
		else if(aux == 4){
			printf("opcao editar validade\n");
			scanf(" %s", pos->validade);
		}
		else if(aux == 5){
			printf("opcao editar nome\n");
			scanf(" %s", pos->nome);
			printf("opcao editar lote\n");
			scanf(" %s", pos->lote);
			printf("opcao editar date\n");
			scanf(" %s", pos->data);
	        printf("opcao editar validade\n");
			scanf(" %s", pos->validade);
		}
		else{
			printf("\n\nopcao invalida :(\n\n");
		}
	}
	main();
}


void consualtar_pessoas_vacinadas(Cartao_Vacina *c_v){
    char nome[100];
    int contador_Pessoas_v;
    
    printf("digite o nome da vacina que deseja buscar: ");
    scanf(" %s", nome);
     
     C_V_NO *p;
     p = c_v->prim_pessoa;
    
    for(; p != NULL; p = p->prox_pessoa){
        if(strcmp(p->nome_pessoa, nome)==0){
            contador_Pessoas_v++;
        }
    }
    
    printf("quantidade de pessoas vacinadas com a %s: %d", nome, contador_Pessoas_v);
    main();
}


//menus//

void menu_de_escolha(){
	
	printf("[1] -> nome \n");
	printf("[2] -> lote \n");
	printf("[3] -> data \n");
	printf("[4] -> validade \n");
	printf("[5] -> todas as opcao a cima\n>: ");
	
}









