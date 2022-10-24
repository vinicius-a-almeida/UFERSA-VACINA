#include <stdio.h>

typedef struct vacina{
    char nome[100], lote[100], data[100], validade[100];

}Vacina;

typedef struct cartao_vacina{
    char nome[100], dose[100];
    int data;
}Cartao_vacina;

typedef struct pessoa{
    int idade;
    char nome[100];
}Pessoa;