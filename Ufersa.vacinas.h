typedef struct vacinaNO VacinaNO;
typedef struct vacina Vacina;
Vacina *cria(void);
void inserir_vacina(Vacina *v);
void retirar_vacina(Vacina *v);
void listar_vacina(Vacina *v);
VacinaNO *busca(Vacina *v);