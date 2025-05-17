#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void calcular_densidade(Carta *c) {
    if (c->area != 0) {
        c->densidade = c->populacao / c->area;
    } else {
        c->densidade = 0;
    }
}

void exibir_dados(const Carta *c1, const Carta *c2, const char *atributo, float valor1, float valor2, int resultado) {
    printf("\nComparação de Cartas (Atributo: %s)\n\n", atributo);
    printf("Carta 1 - %s: %.2f\n", c1->nome_pais, valor1);
    printf("Carta 2 - %s: %.2f\n", c2->nome_pais, valor2);

    if (resultado == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1->nome_pais);
    } else if (resultado == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2->nome_pais);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Cartas já cadastradas (você pode mudar os valores aqui)
    Carta carta1 = {"Brasil", 214000000, 8516000.0, 16000.0, 120, 0};
    Carta carta2 = {"Canadá", 38000000, 9985000.0, 20000.0, 80, 0};

    // Calcular densidade demográfica
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int opcao;

    do {
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (carta1.populacao > carta2.populacao) {
                    exibir_dados(&carta1, &carta2, "População", carta1.populacao, carta2.populacao, 1);
                } else if (carta2.populacao > carta1.populacao) {
                    exibir_dados(&carta1, &carta2, "População", carta1.populacao, carta2.populacao, 2);
                } else {
                    exibir_dados(&carta1, &carta2, "População", carta1.populacao, carta2.populacao, 0);
                }
                break;
            }
            case 2: {
                if (carta1.area > carta2.area) {
                    exibir_dados(&carta1, &carta2, "Área", carta1.area, carta2.area, 1);
                } else if (carta2.area > carta1.area) {
                    exibir_dados(&carta1, &carta2, "Área", carta1.area, carta2.area, 2);
                } else {
                    exibir_dados(&carta1, &carta2, "Área", carta1.area, carta2.area, 0);
                }
                break;
            }
            case 3: {
                if (carta1.pib > carta2.pib) {
                    exibir_dados(&carta1, &carta2, "PIB", carta1.pib, carta2.pib, 1);
                } else if (carta2.pib > carta1.pib) {
                    exibir_dados(&carta1, &carta2, "PIB", carta1.pib, carta2.pib, 2);
                } else {
                    exibir_dados(&carta1, &carta2, "PIB", carta1.pib, carta2.pib, 0);
                }
                break;
            }
            case 4: {
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    exibir_dados(&carta1, &carta2, "Pontos Turísticos", carta1.pontos_turisticos, carta2.pontos_turisticos, 1);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    exibir_dados(&carta1, &carta2, "Pontos Turísticos", carta1.pontos_turisticos, carta2.pontos_turisticos, 2);
                } else {
                    exibir_dados(&carta1, &carta2, "Pontos Turísticos", carta1.pontos_turisticos, carta2.pontos_turisticos, 0);
                }
                break;
            }
            case 5: {
                if (carta1.densidade < carta2.densidade) {
                    exibir_dados(&carta1, &carta2, "Densidade Demográfica", carta1.densidade, carta2.densidade, 1);
                } else if (carta2.densidade < carta1.densidade) {
                    exibir_dados(&carta1, &carta2, "Densidade Demográfica", carta1.densidade, carta2.densidade, 2);
                } else {
                    exibir_dados(&carta1, &carta2, "Densidade Demográfica", carta1.densidade, carta2.densidade, 0);
                }
                break;
            }
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
