#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char estado1 = 'A';
    char codigo1[5] = "A01";
    char nome1[15] = "São Paulo";
    float populacao1 = 12325; 
    float area1 = "1521.11"; //Em KM²
    float pib1 = "699.28"; //Bilhões de Reais
    int numerodepontosturisticos1 = "50";
    float densidadepopulacional1 = populacao1/area1;
    float pibpercapita1 = pib1/populacao1;
    float superpoder = populacao1 + area1 + pib1 + pibpercapita1 + densidadepopulacional1 + numerodepontosturisticos1;

    char estado2 = 'B';
    char codigo2[5] = "B02";
    char nome2[15] = "Rio de Janeiro";
    float populacao2 = "6740"; 
    float area2 = "1200.25"; //Em KM²
    float pib2 = "300.50"; //Bilhões de Reais
    int numerodepontosturisticos2 = "30";
    float densidadepopulacional2 = populacao2/area2;
    float pibpercapita2 = pib2/populacao2;
    float superpoder2 = populacao2 + area2 + pib2 + pibpercapita2 + densidadepopulacional2 + numerodepontosturisticos2;
    
    int soma1, soma2;
    int numerodepontosturisticos1, numerodepontosturisticos2;
    float populacao1; 
    float populacao2;
    int resultado1 = 0, resultado2 = 0;
    
    printf("carta1: Soma dos atributos é %d\n", soma1);
    printf("carta2: Soma dos atributos é %d\n", soma2);

    soma1 = (int)(numerodepontosturisticos1) + (populacao1);
    soma2 = (int)(numerodepontosturisticos2) + (populacao2);
    printf("Escolha o critério de comparação:\n");

    printf("Soma de atributos\n");
    scanf("%d %d", &soma1, &soma2);

        
        switch (soma1, soma2) {
        case '1':  
            printf("A Soma da carta1 é: %d pontos!\n", soma1);
            break;

        case '2':
            printf("A carta 2 é a vencedora com %d pontos!\n", soma2);
            resultado2 = numerodepontosturisticos2 > numerodepontosturisticos1 ? 1 : 0;
            break;

        case '3':
            printf("A carta 1 é a vencedora com %d pontos!\n", soma1);
            resultado1 = populacao1 > populacao2 ? 1 : 0;
            break;
        case '4':
            printf("A carta 2 é a vencedora com %d pontos!\n", soma2);
            resultado2 = populacao2 > populacao1 ? 1 : 0;
            break;
        default:
            printf("Empate!\n");
            break;

    return 0;
    
    }
        switch (soma1, soma2) {
        case '1':
            printf("A carta 1 é a vencedora com %d pontos!\n", soma1);
            resultado1 = numerodepontosturisticos1 > numerodepontosturisticos2 ? 1 : 0;
            break;

        case '3':
            printf("A carta 1 é a vencedora com %d pontos!\n", soma1);
            resultado1 = populacao1 > populacao2 ? 1 : 0;
            break;
        case '4':
            printf("A carta 2 é a vencedora com %d pontos!\n", soma2);
            resultado2 = populacao2 > populacao1 ? 1 : 0;
            break;
        default:
            printf("Empate!\n");
            break;
    }

    return 0;
}
     
  

