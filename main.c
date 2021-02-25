#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void caractereEspecial()
{
    printf("%s",setlocale(LC_ALL,"")); //funcao pra permitir caracteres especiais no programa
    system("cls");
}

int main()
{
    int numeroCidade, opcao = 1, flag = 0;

    caractereEspecial();

    for(;;)
    {
inicio:
        system("cls");
        printf("-------------CALCULAR DISTÂNCIA DE CIDADES-------------\n\n");
        printf("0 - Sair");

        switch (flag)
        {
        case 0:
            printf("\n\n1 - Entrar com o número de cidades\n\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 0:
                return 0;
                break;


            case 1:
                system("cls");
                printf("Entre com a quantidade de cidades: ");
                scanf("%d", &numeroCidade);
                flag = 1;
                goto inicio;
                break;
            }
        case 1:
            printf("\n\n1 - Entrar com a distância entre as cidades\n\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 0:
                return 0;
                break;


            case 1:
                system("cls");

                int matriz[numeroCidade][numeroCidade];

                for (int i = 0; i < numeroCidade; i++)
                {
                    for (int j = 0; j < numeroCidade; j++)
                    {
                        if (i <= j) // condição para preencher somente da diagonal principal para cima
                        {
                            if (i == j)
                            {
                                matriz[i][j] = 0;
                            }
                            else
                            {
                                system("cls");
                                printf("Distância entre as cidades %c e %c\n\n", (i + 65), (j + 65));
                                scanf("%d", &matriz[i][j]);
                                matriz[j][i] = matriz[i][j];
                            }
                        }
                    }

                }
                break;
            }

        }
    }
    return 0;
}
