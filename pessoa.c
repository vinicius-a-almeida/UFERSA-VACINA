#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacina.h"
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

Cartao_Vacina *cria_c_v(){
    
    Cartao_Vacina *c_v = (Cartao_Vacina *) malloc(sizeof(Cartao_Vacina));
    
    c_v->prim_pessoa = NULL;
    
    return c_v;
    
}

void aplicar_vacina_pessoa(Cartao_Vacina *c_v){
	system("cls || clear");
	int opcao;
	
	FILE *arq_pessoa = fopen("entrada_pessoa.txt", "a");
    if(arq_pessoa == NULL){
        printf("erro ao abrir o arquivo\n");
        exit (1);
    }
	
    C_V_NO * cartao_novo  = (C_V_NO *) malloc(sizeof(C_V_NO));
    
    //dados pessoais
    printf("digite o nome do pessoa: ");
    scanf("%s", cartao_novo->nome_pessoa);
    fprintf(arq_pessoa, "nome da pessoa: %s\t\n", cartao_novo->nome_pessoa);
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
			fprintf(arq_pessoa, "documento da pessoa: %s\t\n", cartao_novo->doc.CPF);
            system("cls || clear");
		break;
		
		case 2:
			printf("informe o RG \n>:");
			scanf(" %s", cartao_novo->doc.RG);
			fprintf(arq_pessoa, "documento da pessoa: %s\t\n", cartao_novo->doc.RG);
            system("cls || clear");
		break;
		
	}
	
    printf("digite a idade da pessoa: ");
    scanf("%d", &cartao_novo->idade_pessoa);
    fprintf(arq_pessoa, "idade da pessoa: %i\t\n", cartao_novo->idade_pessoa);
    
    printf("digite o nome da vacina: ");
    scanf(" %s", cartao_novo->nome_vacina); 
	fprintf(arq_pessoa, "nome da vacina: %s\t\n", cartao_novo->nome_vacina); 
	  
    printf("digite a dose da vacina: ");
    scanf("%d", &cartao_novo->dose);
	fprintf(arq_pessoa, "dose da vacina: %i\t\n", cartao_novo->dose);
	
    printf("digite a data de aplicacao da vacina: ");
    scanf(" %s", cartao_novo->data_aplicacao);
	fprintf(arq_pessoa, "data de aplicacao da vacina: %s\t\n", cartao_novo->data_aplicacao);
    
    fclose(arq_pessoa);
    
    cartao_novo->prox_pessoa = c_v->prim_pessoa;
    c_v->prim_pessoa = cartao_novo;
    
}

void consualtar_pessoas_vacinadas(Cartao_Vacina *c_v){
    char nome[100];
    int contador_Pessoas_v = 0;
    
    printf("digite o nome da vacina que deseja buscar: ");
    scanf(" %s", nome);
     
     C_V_NO *p;
     p = c_v->prim_pessoa;
    
    for(; p != NULL; p = p->prox_pessoa){
        if(strcmp(p->nome_vacina, nome)==0){
            contador_Pessoas_v++;
        }
    }
    
    printf("quantidade de pessoas vacinadas com a: %d\n", contador_Pessoas_v);
    system("pause");
    getchar();
}

