#include <stdio.h>
#include <stdlib.h>
#include "vacina.h"

void menu(){

	printf("[1] para -> Adicionar vacina\n");
	printf("[2] para -> Remover vacina\n");
	printf("[3] para -> Listar vacina cadastrada\n");
	printf("[4] para -> Buscar vacinas\n");
	printf("[5] para -> Aplicaçao de vacina em uma pessoa\n");
	printf("[6] para -> Editar vacina cadastrada\n");
	printf("[7] para -> Consultar quantitativo de pessoas vacinadas com uma dada vacina\n");
	printf("[8] para -> Sair\n\n");

}

int main(void){
	int op;

	FILE *arq = fopen("entrada.txt", "rw");
	if(arq == NULL){
		print("não foi possivel criar o arquivo");
		exit(1);
	}
    Vacina *v = cria_v(); 
	Cartao_Vacina *c_v = cria_c_v();
    do{
        menu();
		printf("\nDigite sua opcao: ");
		scanf("%d", &op);
    	if(op < 1 || op > 8){
    		printf("\nOpcao invalida. Tente novamente.");
			printf("\nA opcao deve estar entre 1 e 8 \n");
			for(; op < 1 || op > 8;){
				printf("\nDigite sua opcao: ");
				scanf("%d", &op);
				if(op < 1 || op > 8){
					printf("\n\nerror\n\n");
				}
			} 
		}
        
    	if(op == 1){
          inserir_vacina(v, arq);	
		}
		
		else if(op == 2){
 			retirar_vacina(v, arq);
		}		

		else if(op == 3){
			listar_vacina(v, arq);
		}
		else if(op == 4){
            busca(v) ? printf("achou") : printf("nao achou");
				return 0;
		}
   	 	
         
		if(op == 5){
			aplicar_vacina_pessoa(c_v, arq);
		}
		
		/*
		if(op == 6){
			editar_vacinas_cadastradas(c_v);
		}
		
		if(op == 7){
			consualtar_pessoas_vacinadas(c_v);
		}
		*/

		else if(op == 8){
			printf("Obrigado por usar este programa.\n");
		return(0);
		}
			
    	else{
	   		printf("Este programa possui um bug.");
		return 1;
	    }	
    }while(op != 8);
 return(0);
}