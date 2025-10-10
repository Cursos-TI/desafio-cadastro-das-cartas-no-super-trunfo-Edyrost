#include <stdio.h>

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  
  char Estado1[20], Estado2[20], Codigo1[4], Codigo2[4], Cidade1[20], Cidade2[20];
  int Tour1, Tour2, escolha1, escolha2, resultado1, resultado2;
  unsigned long int Populacao1, Populacao2;
  double Dens1, Dens2, Area1, Area2, PIB1, PIB2, PPC1, PPC2, SP1, SP2, valor1a, valor2a, valor1b, valor2b, desempate1, desempate2;

// COLETANDO INFORMAÇÕES DA CARTA 1:
printf("---------------SUPER TRUNFO!----------------\n");
printf("Infome o Estado 1:\n");
scanf("%19s", Estado1);
printf("Infome o Codigo da Carta 1:\n");
scanf("%3s", Codigo1);
printf("Infome a Cidade 1:\n");
scanf("%19s", Cidade1);
printf("Infome a Populacao da cidade 1:\n");
scanf("%lu", &Populacao1);  
printf("Infome a Quantidade de Pontos Turisticos da cidade 1:\n");
scanf("%d", &Tour1);
printf("Infome o PIB da cidade 1:\n");
scanf("%lf", &PIB1);
printf("Infome a Area da cidade 1 (km2):\n");
scanf("%lf", &Area1);
Dens1 = Populacao1 / Area1;
PPC1 = PIB1 / Populacao1;
SP1 = Populacao1 + Tour1 + PIB1 + Area1 + PPC1 + (1.0 / Dens1);
printf("------------------------------------------\n");

// COLETANDO INFORMAÇÕES DA CARTA 2:
printf("Infome o Estado 2:\n");
scanf("%19s", Estado2);
printf("Infome o Codigo da Carta 2:\n");
scanf("%3s", Codigo2);
printf("Infome a Cidade 2:\n");
scanf("%19s", Cidade2);
printf("Infome a Populacao da cidade 2:\n");
scanf("%lu", &Populacao2);  
printf("Infome a Quantidade de Pontos Turisticos da cidade 2:\n");
scanf("%d", &Tour2);
printf("Infome o PIB da cidade 2:\n");
scanf("%lf", &PIB2);
printf("Infome a Area da cidade 2 (km2):\n");
scanf("%lf", &Area2);
Dens2 = Populacao2 / Area2;
PPC2 = PIB2 / Populacao2;
SP2 = Populacao2 + Tour2 + PIB2 + Area2 + PPC2 + (1.0 / Dens2);

printf("***************************************\n");


  // Área para exibição dos dados da cidade

  // EXIBINDO INFORMAÇÕES DA CARTA 1:
  printf("A Carta 01 possui as seguintes caracteristicas:\n");
  printf("Estado: %s\n"
        "Codigo: %3s\n"
        "Cidade: %s\n"
        "Populacao: %lu\n"
        "Pontos Turisticos: %d\n"
        "PIB Total: %.3f\n"
        "PIB per capta da Cidade: %.3f\n"
        "Area da Cidade (km2): %.3f\n"
        "Densidade Demografica da Cidade(Pessoa(as) por km2): %.2f\n",
        Estado1, Codigo1, Cidade1, Populacao1, Tour1, PIB1, PPC1, Area1, Dens1);
  printf("-------------------------------------\n");

 // EXIBINDO INFORMAÇÕES DA CARTA 2:
  printf("A Carta 02 possui as seguintes caracteristicas:\n");
  printf("Estado: %s\n"
        "Codigo: %3s\n"
        "Cidade: %s\n"
        "Populacao: %lu\n"
        "Pontos Turisticos: %d\n"
        "PIB Total: %.3f\n"
        "PIB per capta da Cidade: %.3f\n"
        "Area da Cidade (km2): %.3f\n"
        "Densidade Demografica da Cidade(Pessoa(as) por km2): %.2f\n",
        Estado2, Codigo2, Cidade2, Populacao2, Tour2, PIB2, PPC2, Area2, Dens2);
  printf("***************************************\n");      

 // COMPARANDO AS CARTAS

// MENUS DE OPÇÕES PARA COMPARAÇÃO
  printf("\nEscolha o primeiro atributo a ser comparado:\n");
  printf("1 - Populacao\n");
  printf("2 - Area\n");
  printf("3 - Pontos Turisticos\n");
  printf("4 - PIB Total\n");
  printf("5 - Densidade Demografica\n");
  scanf("%d", &escolha1);

  switch (escolha1) {
    case 1:
      printf("Voce esciolheu Populacao:\n");
      resultado1 = Populacao1 > Populacao2 ? 1 : 0;
      valor1a = Populacao1;
      valor2a = Populacao2;
      break;
    case 2:
      printf("Voce esciolheu Area:\n");
      resultado1 = (Area1 > Area2) && (Area1 != Area2) ? 1 : 0;
      valor1a = Area1;
      valor2a = Area2;
      break;

    case 3:
      printf("Voce esciolheu Pontos Turisticos:\n");
      resultado1 = (Tour1 > Tour2) && (Tour1 != Tour2) ? 1 : 0;
      valor1a = Tour1;
      valor2a = Tour2;
      break;

    case 4:
      printf("Voce esciolheu PIB Total:\n");
      resultado1 = (PIB1 > PIB2) && (PIB1 != PIB2) ? 1 : 0;
      valor1a = PIB1;
      valor2a = PIB2;
      break;

    case 5:
      printf("Voce esciolheu Densidade Demografica:\n");
      resultado1 = (Dens1 < Dens2) && (Dens1 != Dens2) ? 1 : 0;
      valor1a = 1 / Dens1;
      valor2a = 1 / Dens2;
      break;

    default:
      printf("Opção inválida!\n");
      break;
  }

  printf("\nEscolha o segundo atributo a ser comparado:\n");
  printf("1 - Populacao\n");
  printf("2 - Area\n");
  printf("3 - Pontos Turisticos\n");
  printf("4 - PIB Total\n");
  printf("5 - Densidade Demografica\n");
  scanf("%d", &escolha2);

  if (escolha2 == escolha1)
  {
    printf("Atributo ja escolhido, escolha outro atributo!\n");
    return (0);
  } else {
    switch (escolha2) {
      case 1:
      printf("Voce esciolheu Populacao\n");
      resultado2 = Populacao1 > Populacao2 ? 1 : 0;
      valor1b = Populacao1;
      valor2b = Populacao2;
      break;

      case 2:
      printf("Voce esciolheu Area\n");
      resultado2 = (Area1 > Area2) && (Area1 != Area2) ? 1 : 0;
      valor1b = Area1;
      valor2b = Area2;
      break;

      case 3:
      printf("Voce esciolheu Pontos Turisticos\n");
      resultado2 = (Tour1 > Tour2) && (Tour1 != Tour2) ? 1 : 0;
      valor1b = Tour1;
      valor2b = Tour2;
      break;

      case 4:
      printf("Voce esciolheu PIB Total\n");
      resultado2 = (PIB1 > PIB2) && (PIB1 != PIB2) ? 1 : 0;
      valor1b = PIB1;
      valor2b = PIB2;
      break;

      case 5:
      printf("Voce esciolheu Densidade Demografica\n");
      resultado2 = (Dens1 < Dens2) && (Dens1 != Dens2) ? 1 : 0;
      valor1b = 1 / Dens1;
      valor2b = 1 / Dens2;
      break;

    default:
      printf("Opção inválida!\n");
      break;
  }

  printf("\n----------RESULTADO-------\n");
  desempate1 = valor1a + valor1b;
  desempate2 = valor2a + valor2b;

    if (resultado1 == 1) {
    printf("A Cidade %s venceu a Cidade %s no Primeiro atributo escolhido.\n", Cidade1, Cidade2);
    printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade1, valor1a, Cidade2, valor2a);
  } else if (resultado1 == 0) {
    printf("A Cidade %s venceu a Cidade %s no Primeiro atributo escolhido.\n", Cidade2, Cidade1);
    printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade2, valor2a, Cidade1, valor1a);
  } 

    if (resultado2 == 1) {
    printf("A Cidade %s venceu a Cidade %s no Segundo atributo escolhido.\n", Cidade1, Cidade2);
    printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade1, valor1b, Cidade2, valor2b);
  } else if (resultado2 == 0) {
    printf("A Cidade %s venceu a Cidade %s no Segundo atributo escolhido.\n", Cidade2, Cidade1);
    printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade2, valor2b, Cidade1, valor1b);
  } 
    if (resultado1 != resultado2) {
    printf("Cada cidade venceu em um atributo -> Empate técnico!\n");
    printf("Aplicando critério de desempate (soma dos dois atributos escolhidos)...\n");
      if (desempate1 == desempate2) {
      printf("As cartas empataram no Desempate.\n");
      printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade1, desempate1, Cidade2, desempate2);
    } else if (desempate1 < desempate2) {
      printf("A Cidade %s venceu a Cidade %s no Desempate.\n", Cidade2, Cidade1);
      printf("%s: %.2f Pontos x %s: %.2f Pontos.\n", Cidade2, desempate2, Cidade1, desempate1);
    } 
  }
}  
  return 0;
}