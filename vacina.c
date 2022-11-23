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


Vacina *cria_v(){
	
    Vacina *v = (Vacina *) malloc(sizeof(Vacina));
    
    v->prim = NULL;
    
    return v;

}


void inserir_vacina(Vacina *v){
    system("cls || clear");

    FILE *arq = fopen("entrada.txt", "a");
    if(arq == NULL){
        printf("erro ao abrir o arquivo\n");
        exit (1);
    }
	
    VacinaNO * novo  = (VacinaNO *) malloc(sizeof(VacinaNO));
    
    printf("digite o nome da vacina: ");
    scanf(" %s", novo->nome);
    
    printf("digite o lote da vacina: ");
    scanf(" %s", novo->lote);
    
    printf("digite a data da vacina: ");
    scanf(" %s", novo->data);
    
    printf("digite a validade da vacina: ");
    scanf(" %s", novo->validade);

    fprintf(arq, "nome da vacina: %s\t\n", novo->nome);
    fprintf(arq, "lote da vacina: %s\t\n", novo->lote);
    fprintf(arq, "data da vacina: %s\t\n", novo->data);
    fprintf(arq, "validade da vacina: %s\n", novo->validade);
    
    fclose(arq);
    
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
    
    //system("cls || clear");
    getchar();
    VacinaNO *p;
    
    for(p = v->prim; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        
        printf("%s\n", p->lote);
        
        printf("%s\n", p->data);
        
        printf("%s\n\n", p->validade);
    }

}

VacinaNO *busca(Vacina *v){
	//system("cls || clear");
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
    for(; cont != NULL; cont = cont->prox){
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

void menu_de_escolha(){

	system("cls || clear");
	printf("[1] -> nome \n");
	printf("[2] -> lote \n");
	printf("[3] -> data \n");
	printf("[4] -> validade \n");
	printf("[5] -> todas as opcao a cima\n>: ");
	
}