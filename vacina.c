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

void menu();

Vacina *cria();

void inserir_vacina(Vacina *v);

void retirar_vacina(Vacina *v);

void listar_vacina(Vacina *v);

VacinaNO *busca(Vacina *v);


int main(void){
    printf("\\/ Insira o Numero Referente a Rua Opcao \\/ \n\n");

    Vacina *v = cria(); 
    int opcao;
	scanf("%d", &opcao);
	
	do {
        opcao_ligacao();
        switch(op){
        	//op == 1
            case 1:
                inserir_vacina(v);
            break;
        
			//op == 2	
            case 2:
				retirar_vacina(v);
            break;
        
			//op == 3
            case 3:
                listar_vacina(v);
            break;
        
        	//op == 4
			case 4:
                busca(v) ? printf("achou") : printf("nao achou");
			break;
		
		
            //restante 5, 6, 7//
            
            
        	//op == 8
            case 8:;
                printf("Obrigado por usar este programa.");
                exit(1);
				return(0); 
            break;

            default:
                printf("opacao invalida! (error 404)\n\n");
        }
    } while(); 

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
    for(VacinaNO *p = v->prim; p != NULL; p = p->prox){
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
    return NULL;
}

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