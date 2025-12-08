#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TERRENOS 100


// structs
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


typedef struct {
    char nome[100];
    char cpf[20];
    Data data_nascimento;
    char telefone[20];
} Pessoa;


typedef struct {
    int id;
    float largura, comprimento, area, preco_m2;
    Pessoa dono;
    Data data_compra;
} Terreno;


// funcoes
void inicializarVetor(Terreno ** terrenos) {
    int i;
    for (i = 0; i < MAX_TERRENOS; i++) terrenos[i] = NULL;
}


void criarTerreno(Terreno ** terrenos) {
    int i, pos_vazio = -1;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] == NULL) {
            pos_vazio = i;
            break;
        }
    }
    if (pos_vazio == -1) {
        printf("Nao ha espaco para novos terrenos.\n");
        return;
    }


    Terreno * novo_t = malloc(sizeof(Terreno));
    printf("ID do terreno: ");
    scanf("%d", &(novo_t->id));    
   
    printf("Nome do dono: ");
    getchar();
    fgets(novo_t->dono.nome, 100, stdin);
    novo_t->dono.nome[strcspn(novo_t->dono.nome, "\n")] = 0;


    printf("CPF: ");
    fgets(novo_t->dono.cpf, 20, stdin);
    novo_t->dono.cpf[strcspn(novo_t->dono.cpf, "\n")] = 0;


    printf("Data de nascimento (dd mm aa): ");
    scanf("%d %d %d", &novo_t->dono.data_nascimento.dia, &novo_t->dono.data_nascimento.mes, &novo_t->dono.data_nascimento.ano);


    printf("Telefone: ");
    getchar();
    fgets(novo_t->dono.telefone, 20, stdin);
    novo_t->dono.telefone[strcspn(novo_t->dono.telefone, "\n")] = 0;


    printf("Data da compra (dd mm aa): ");
    scanf("%d %d %d", &novo_t->data_compra.dia, &novo_t->data_compra.mes, &novo_t->data_compra.ano);


    printf("Largura (m): ");
    scanf("%f", &novo_t->largura);


    printf("Comprimento (m): ");
    scanf("%f", &novo_t->comprimento);


    printf("Preco do metro quadrado: ");
    scanf("%f", &novo_t->preco_m2);


    novo_t->area = novo_t->largura * novo_t->comprimento;


    terrenos[pos_vazio] = novo_t;


    printf("Terreno criado com sucesso!\n");
}


void deletarTerreno(Terreno ** terrenos) {
    int id;
    printf("Digite o ID do terreno que deseja deletar: ");
    scanf("%d", &id);


    int i;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] != NULL && id == terrenos[i]->id) {
            free(terrenos[i]);
            terrenos[i] = NULL;
            printf("Terreno deletado com sucesso!\n");
            return;
        }
    }


    printf("Terreno com ID %d nao encontrado!\n", id);
}


void mostrarTerreno(Terreno ** terrenos, int id) {
    int i;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] != NULL && id == terrenos[i]->id) {
            printf("\n--- TERRENO ---\n");
            printf("ID: %d\n", terrenos[i]->id);
            printf("Dono: %s\n", terrenos[i]->dono.nome);
            printf("CPF: %s\n", terrenos[i]->dono.cpf);
            printf("Nascimento: %d/%d/%d\n", terrenos[i]->dono.data_nascimento.dia, terrenos[i]->dono.data_nascimento.mes, terrenos[i]->dono.data_nascimento.ano);
            printf("Telefone: %s\n", terrenos[i]->dono.telefone);
            printf("Data de Compra: %d/%d/%d\n", terrenos[i]->data_compra.dia, terrenos[i]->data_compra.mes, terrenos[i]->data_compra.ano);
            printf("Largura: %.2f\n", terrenos[i]->largura);
            printf("Comprimento: %.2f\n", terrenos[i]->comprimento);
            printf("Area: %.2f\n", terrenos[i]->area);
            printf("Preco/m2: %.2f\n", terrenos[i]->preco_m2);
            return;
        }


    }
    printf("Terreno com ID %d nao encontrado!\n", id);
}


void editarTerreno(Terreno **terrenos, int id) {
    int i;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] != NULL && id == terrenos[i]->id) {
            printf("\n--- EDITAR TERRENO ---\n");
            printf("Novo nome: ");
            getchar();
            fgets(terrenos[i]->dono.nome, 100, stdin);
            terrenos[i]->dono.nome[strcspn(terrenos[i]->dono.nome, "\n")] = 0;


            printf("Novo telefone: ");
            fgets(terrenos[i]->dono.telefone, 20, stdin);
            terrenos[i]->dono.telefone[strcspn(terrenos[i]->dono.telefone, "\n")] = 0;


            printf("Nova largura: ");
            scanf("%f", &terrenos[i]->largura);


            printf("Novo comprimento: ");
            scanf("%f", &terrenos[i]->comprimento);


            terrenos[i]->area = terrenos[i]->largura * terrenos[i]->comprimento;


            printf("Novo preco por m2: ");
            scanf("%f", &terrenos[i]->preco_m2);


            terrenos[i]->area = terrenos[i]->largura * terrenos[i]->comprimento;


            printf("Terreno atualizado.\n");


            return;
        }
    }
    printf("Terreno com ID %d nao encontrado!\n", id);
}


double calcularValorTerreno(Terreno ** terrenos, int id) {
    int i;
    double total;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] != NULL && id == terrenos[i]->id) {
            total = terrenos[i]->area * terrenos[i]->preco_m2;
            return total;
        }
    }
    return -1;
}


int contarTerrenosOcupados(Terreno ** terrenos) {
    int total = 0;
    int i;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] != NULL) total++;
    }
    return total;
}


int contarTerrenosLivres(Terreno ** terrenos) {
    int total = 0;
    int i;
    for (i = 0; i < MAX_TERRENOS; i++) {
        if (terrenos[i] == NULL) total++;
    }


    return total;
}


int main()
{
    Terreno * terrenos[MAX_TERRENOS];
    inicializarVetor(terrenos);
    int opcao;
    // Menu do programa
    while (1) {
        printf("=============================================\n");
        printf("              SISTEMA DE TERRENOS            \n");
        printf("=============================================\n");
        printf("  [1] -> Criar terreno\n");
        printf("  [2] -> Deletar terreno\n");
        printf("  [3] -> Mostrar terreno\n");
        printf("  [4] -> Editar terreno\n");
        printf("  [5] -> Calcular valor do terreno\n");
        printf("  [6] -> Contar terrenos ocupados\n");
        printf("  [7] -> Contar terrenos livres\n");
        printf("  [8] -> Valor total dos terrenos\n");
        printf("  [9] -> Salvar no arquivo\n");
        printf("  [0] -> Sair\n");
        printf("=============================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        int id_user;
        switch (opcao)
        {
        case 1:
            criarTerreno(terrenos);
            break;
        case 2:
            deletarTerreno(terrenos);
            break;
        case 3:
            printf("Digite o ID do terreno que deseja visualizar: ");
            scanf("%d", &id_user);
            mostrarTerreno(terrenos, id_user);
            break;
        case 4:
            printf("Digite o ID do terreno que deseja editar: ");
            scanf("%d", &id_user);
            editarTerreno(terrenos, id_user);
            break;
        case 5:
            printf("Digite o ID do terreno que deseja calcular: ");
            scanf("%d", &id_user);
            double result = calcularValorTerreno(terrenos, id_user);
            if (result == -1) printf("Terreno com ID %d nao encontrado!\n", id_user);
            else printf("O terreno custa R$ %.2lf\n", result);
            break;
        case 6:
            printf("Ocupados: %d\n", contarTerrenosOcupados(terrenos));
            break;
        case 7:
            printf("Livres: %d\n", contarTerrenosLivres(terrenos));
            break;
        case 8:
            break;
        case 9:
            break;
        case 0:    
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opcao invalida!\n");
        }
    }
   
    return 0;
}
