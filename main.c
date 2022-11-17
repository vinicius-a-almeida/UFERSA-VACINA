#include <stdio.h>
#include <stdlib.h>
#include "vacina.h"

void menu_principal();
void cabeca();

int main(void){

	cabeca();
	system("pause");
	int op;

    Vacina *v = cria_v(); 
	Cartao_Vacina *c_v = cria_c_v();
	system("color 07");

    while(1){
		system("cls || clear");
        menu_principal();
		printf("\nDigite sua opcao: ");
		scanf("%d", &op);
    	if(op < 1 || op > 8){
			system("color 04");
    		printf("\nOpcao invalida. Tente novamente.");
			printf("\nA opcao deve estar entre 1 e 8 \n");
			for(;op < 1 || op > 8;){
				printf("\nDigite sua opcao: ");
				scanf("%d", &op);
				if(op < 1 || op > 8){
					printf("\n\nerror\n\n");
				}
			} 
			system("color 07");
		}
        
    	if(op == 1){
          inserir_vacina(v);	
		}
		
		else if(op == 2){
 			retirar_vacina(v);
		}		

		else if(op == 3){
			listar_vacina(v);
		}
		else if(op == 4){
            busca(v) ? printf("\n\nachou\n\n") : printf("\n\nnao achou\n\n");	
		}
         
		if(op == 5){
			aplicar_vacina_pessoa(c_v);
		}
		
		
		if(op == 6){
			editar_vacinas_cadastradas(v);
		}
		
		if(op == 7){
			consualtar_pessoas_vacinadas(c_v);
		}
		
		else if(op == 8){
			printf("Obrigado por usar este programa.\n");
			//libera não tá funcionando
			//libera_vacina(v);
			return (0);
		}
			
	}
}

void menu_principal(){
	system("color 07");
	printf("\n\n[1] para -> Adicionar vacina\n");
	printf("[2] para -> Remover vacina\n");
	printf("[3] para -> Listar vacina cadastrada\n");
	printf("[4] para -> Buscar vacinas\n");
	printf("[5] para -> Aplicacao de vacina em uma pessoa\n");
	printf("[6] para -> Editar vacina cadastrada\n");
	printf("[7] para -> Consultar quantitativo de pessoas vacinadas com uma dada vacina\n");
	printf("[8] para -> Sair\n\n");

}
void cabeca(){

	system("color 71");
	printf("        Universidade Federal Rural do Semi-arido (UFERSA)         \n");
	printf("            Bacharelado em Tecnologia da Informacao               \n");
	printf("              --- Projeto Final: Unidade III ---                  \n");
	printf("            Professora: Dra. Rosana Cibely Batista Rego           \n");
	printf("                Discente: Roberto Fernandes Rocha                 \n");
	printf("             Discente: Vinicius Anacleto de Almeida               \n");
	printf("             _+_+_+_ UFERSA MAIS VACINAS _+_+_+_                  \n");
	printf("\n\n        pressione _+_ ENTER _+_ para continuar S2\n\n");
}


/*
void jaka(){


}
*/