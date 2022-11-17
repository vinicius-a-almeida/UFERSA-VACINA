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
	
		char CPF[11];
		char RG[7];
		
};

struct cartao_vacina{ 
	
	C_V_NO *prim_pessoa;

};

struct cartao_vacina_NO{
	
    int dose;
	int idade_pessoa;
	char data_aplicacao[12];
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
    system("cls || clear");
	
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
    system("cls || clear");
	
    char nome[100], lote[100];
    
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
    
    system("cls || clear");

    VacinaNO *p;
    
    for(p = v->prim; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        
        printf("%s\n", p->lote);
        
        printf("%s\n", p->data);
        
        printf("%s\n\n", p->validade);
    }

}

VacinaNO *busca(Vacina *v){
	system("cls || clear");
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
}


void aplicar_vacina_pessoa(Cartao_Vacina *c_v){
	system("cls || clear");
	int opcao;
	
    C_V_NO * cartao_novo  = (C_V_NO *) malloc(sizeof(C_V_NO));
    
    //dados pessoais
    printf("digite o nome do pessoa: ");
    scanf("%s", cartao_novo->nome_pessoa);
    system("cls || clear");
    printf("qual documento deseja informar?\n");
    printf("[1] para CPF\n");
    printf("[2] para RG\n");
    printf("insira a opcao desejada >:");
    do{
        scanf("%d", &opcao);
        if(opcao > 2 || opcao < 1){
            system("color 04");
            printf("opcao invalida\n\n:(\n\n");
            printf("++ digite um valor entre 1 e 2 ++\n\n");
            printf("insira a opcao desejada >:");
        }
    }while(opcao > 2 || opcao < 1);
    system("color 07");
    switch(opcao){
		case 1:
			printf("informe o CPF \n>:");
			scanf(" %s", cartao_novo->doc.CPF);
            system("cls || clear");
		break;
		
		case 2:
			printf("informe o RG \n>:");
			scanf(" %s", cartao_novo->doc.RG);
            system("cls || clear");
		break;
		
	}
	
    printf("digite a idade da pessoa: ");
    scanf("%d", &cartao_novo->idade_pessoa);
    
    printf("digite o nome da vacina: ");
    scanf(" %s", cartao_novo->nome_vacina); 
	   
    printf("digite a dose da vacina: ");
    scanf("%d", &cartao_novo->dose);
    
    printf("digite a data de aplicacao da vacina: ");
    scanf(" %s", cartao_novo->data_aplicacao);
    system("cls || clear");
    cartao_novo->prox_pessoa = c_v->prim_pessoa;
    c_v->prim_pessoa = cartao_novo;

}
//
void editar_vacinas_cadastradas(Vacina *v){
    system("cls || clear");
    VacinaNO *cont, *pos;
    cont = v->prim;
    char nome[100], lote[100];
    int aux;
    printf("digite o nome da vacina que deseja editar >: ");
    scanf(" %s", nome);
    
    printf("digite o lote da vacina que deseja editar >: ");
    scanf(" %s", lote);
    system("cls || clear");
    for(cont; cont != NULL; cont = cont->prox){
        if(strcmp(cont->nome, nome)==0 && strcmp(cont->lote, lote)==0){
            pos = cont;
        }
    }
    system("color 07");
    printf("\\/ informe qual dessas opcoes a baixo deseja editar /\\\n");
    menu_de_escolha();
    scanf("%d", &aux);
    
	do{
        system("color 04");
        printf("\n\nopcao invalida :(\n\n");
	    printf("\n\ndigite o numero referente a sua escolha!\n\n");
        menu_de_escolha();
        scanf("%d", &aux);
    }while(aux < 1 || aux > 5);
        system("color 07");
	    if(aux == 1){
			printf("opcao editar nome\n");
            printf("\\// ATENCAO \\//");
            printf("a troca do nome sera irreversivel...\n\n");
			scanf(" %s", pos->nome);
            system("cls || clear");
		}
        
		else if(aux == 2){
	        printf("opcao editar lote\n");
            printf("\\// ATENCAO \\//");
            printf("a troca do nome sera irreversivel...\n\n");
			scanf(" %s", pos->lote);
            system("cls || clear");
		}

		else if(aux == 3){
	       	printf("opcao editar data\n");
            printf("\\// ATENCAO \\//");
            printf("a troca do nome sera irreversivel...\n\n");
			scanf(" %s", pos->nome);
            system("cls || clear");
		}
        
		else if(aux == 4){
			printf("opcao editar validade\n");
            printf("\\// ATENCAO \\//");
            printf("a troca do nome sera irreversivel...\n\n");
			scanf(" %s", pos->validade);
            system("cls || clear");
		}
        
		if(aux == 5){
            printf("\\// ATENCAO \\//");
            printf("a troca do nome sera irreversivel...\n\n");
			printf("opcao editar nome\n");
			scanf(" %s", pos->nome);
			printf("opcao editar lote\n");
			scanf(" %s", pos->lote);
			printf("opcao editar date\n");
			scanf(" %s", pos->data);
	        printf("opcao editar validade\n");
			scanf(" %s", pos->validade);
            system("cls || clear");
		}
}


void consualtar_pessoas_vacinadas(Cartao_Vacina *c_v){
    char nome[100];
    int contador_Pessoas_v = 0;
    
    printf("digite o nome da vacina que deseja buscar: ");
    scanf(" %s", nome);
     
     C_V_NO *p;
     p = c_v->prim_pessoa;
    
    for(p; p != NULL; p = p->prox_pessoa){
        if(strcmp(p->nome_vacina, nome)==0){
            contador_Pessoas_v++;
        }
    }
    
    printf("quantidade de pessoas vacinadas com a: %d\n", contador_Pessoas_v);
    system("pause");
}


/*void libera_vacina(Vacina *v){
    Vacina *p = v;
    Vacina *t;
    while(p != NULL){
        t = p->prim;
        free(p);
        p = t;
    }
}*/

void menu_de_escolha(){

	system("cls || clear");
	printf("[1] -> nome \n");
	printf("[2] -> lote \n");
	printf("[3] -> data \n");
	printf("[4] -> validade \n");
	printf("[5] -> todas as opcao a cima\n>: ");
	
}