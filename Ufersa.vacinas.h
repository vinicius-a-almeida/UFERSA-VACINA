typedef struct vacinaNO VacinaNO;
typedef struct vacina Vacina;
typedef struct cartao_vacina Cartao_Vacina;
typedef union cpf_rg CPF_RG;
typedef struct cartao_vacina_NO C_V_NO;

Vacina *cria();
Cartao_Vacina *cria();

void inserir_vacina(Vacina *v);
void retirar_vacina(Vacina *v);
void listar_vacina(Vacina *v);
void aplicar_vacina_pessoa(Cartao_Vacina *v);
VacinaNO *busca(Vacina *v);
