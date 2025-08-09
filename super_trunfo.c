#include <stdio.h>
    int main() {
        printf("Carta 1\n");
       
        char estado = 'A';
        char codigo[] = "A01";
        char nome[20] = "São Paulo";
        int populacao = 12325000;
        float area = 1521.11; // Área em km²
        float pib = 700000.00; // PIB em milhões de reais
        int pontos = 50;
        
        printf("Estado 1: %c\n", estado);
        printf("Código 1: %s\n", codigo);
        printf("Nome da Cidade: %s\n", nome);
        printf("População: %d\n", populacao);
        printf("Área: %.2f km²\n", area);
        printf("PIB: %.2f milhões de reais\n", pib);
        printf("Pontos Turísticos: %d\n", pontos);
        

    return 0;
}