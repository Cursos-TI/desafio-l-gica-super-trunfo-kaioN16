#include <stdio.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib; 
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

void calcular_estatisticas(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = (c->pib * 1e6) / c->populacao;
}

void ler_carta(Carta *c, int numero) {
    printf("Cadastro da Carta %d\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Código da Carta: ");
    scanf(" %[^\n]", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("População: ");
    scanf("%d", &c->populacao);

    printf("Área (em km²): ");
    scanf("%f", &c->area);

    printf("PIB (em milhões): ");
    scanf("%f", &c->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontos_turisticos);

    calcular_estatisticas(c);
}

int main() {
    Carta carta1, carta2;

    ler_carta(&carta1, 1);
    printf("\n");
    ler_carta(&carta2, 2);
    printf("\n");

    printf("Comparação de Cartas (Atributo: População)\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nome, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", carta2.nome, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

