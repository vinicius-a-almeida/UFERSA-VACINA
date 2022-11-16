#include <stdio.h>
#include <stdlib.h>

typedef struct vacinaNO VacinaNO;
typedef struct vacina Vacina;
typedef struct cartao_vacina Cartao_Vacina;
typedef union cpf_rg CPF_RG;
typedef struct cartao_vacina_NO C_V_NO;

Vacina *cria_v();
Cartao_Vacina *cria_c_v();

void inserir_vacina(Vacina *v, FILE *arq);
void retirar_vacina(Vacina *v, FILE *arq);
void listar_vacina(Vacina *v, FILE *arq);
void aplicar_vacina_pessoa(Cartao_Vacina *v, FILE *arq);
VacinaNO *busca(Vacina *v);


//menus//
void menu_principal();
void menu_de_escolha();