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

        switch (opcao)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
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
