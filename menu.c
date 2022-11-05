#include <stdio.h>
#include <stdarg.h>

#define TITULO_OPCAO1 "Adicionar vacina"
#define TITULO_OPCAO2 "Remover vacina"
#define TITULO_OPCAO3 "Listar vacina cadastrada"
#define TITULO_OPCAO4 "Buscar vacinas"
#define TITULO_OPCAO5 "Aplicaçao de vacina em uma pessoa"
#define TITULO_OPCAO6 "Editar vacina cadastrada"
#define TITULO_OPCAO7 "Consultar quantitativo de pessoas vacinadas com uma dada vacina"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

/****
* Função: LimpaBuffer()
* Descrição: Lê e descarta caracteres encontrados na entrada
* Parâmetros: Nenhum
* Retorno: Nada
****/
void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/****
* Função: LeOpcao()
* Descrição: Lê e valida a opção digitada pelo usuário
* Parâmetros:
*   menorValor (entrada): o menor valor válido
*   maiorValor (entrada): o maior valor válido
* Retorno: A opção lida é validada
****/
int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}
/****
* Função: LeInteiro()
* Descrição: Lê um número inteiro introduzido pelo usuário
* Parâmetros: Nenhum
* Retorno: O inteiro lido
****/
int LeInteiro(void) {
    int umInt, nValoresLidos;
    printf("Digite um valor inteiro: ");
    nValoresLidos = scanf("%d", &umInt);
    while (nValoresLidos == 0) { /*Nenhum inteiro foi lido*/
        LimpaBuffer();
        printf("Entrada incorreta. Digite um valor inteiro: ");
        nValoresLidos = scanf("%d", &umInt);
    }
    LimpaBuffer();
    return umInt;
}
/****
* Função: ApresentaMenu
* Descrição: Apresenta menu com número indeterminado de opções
* Parâmetros:
*   nItens (entrada): número de itens no menu
*   menorOpcao (entrada): caractere associado ao item I
* Retorno: Nada
****/
void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menorOpcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main_menu(void) {
    unsigned char op;
    int inteiro1, inteiro2;
    unsigned int saida = 0;

    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4,
                      TITULO_OPCAO5, TITULO_OPCAO6,
                      TITULO_OPCAO7, TITULO_OPCAO8);
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            //falta fazer a linkagem das funções do menu.c para vacina.c
            case OPCAO1:
                inteiro1 = LeInteiro();
                inteiro2 = LeInteiro();
                printf("%d + %d = %d\n", inteiro1, inteiro2,
                       inteiro1 + inteiro2);
                break;

            case OPCAO2:
                inteiro1 = LeInteiro();
                inteiro2 = LeInteiro();
                printf("%d * %d = %d\n", inteiro1, inteiro2,
                       inteiro1 * inteiro2);
                break;

            case OPCAO3:
                inteiro1 = LeInteiro();
                inteiro2 = LeInteiro();
                printf("%d / %d = %d\n", inteiro1, inteiro2,
                       inteiro1 / inteiro2);
                break;

            case OPCAO8:
                saida = 1;
                printf("Obrigado por usar este programa.");
                break;

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}