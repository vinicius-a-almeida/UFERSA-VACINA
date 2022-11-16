
typedef struct vacinaNO VacinaNO;
typedef struct vacina Vacina;
typedef struct cartao_vacina Cartao_Vacina;
typedef union cpf_rg CPF_RG;
typedef struct cartao_vacina_NO C_V_NO;

Vacina *cria_v();
Cartao_Vacina *cria_c_v();

void inserir_vacina(Vacina *v);
void retirar_vacina(Vacina *v);
void listar_vacina(Vacina *v);
void editar_vacinas_cadastradas(Vacina *v);
void aplicar_vacina_pessoa(Cartao_Vacina *v);
void consualtar_pessoas_vacinadas(Cartao_Vacina *c_v);
VacinaNO *busca(Vacina *v);


//menus//
void menu_principal();
void menu_de_escolha();