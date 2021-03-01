#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void clear_keyboard_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

void caractereEspecial()
{
    printf("%s",setlocale(LC_ALL,"")); //funcao pra permitir caracteres especiais no programa
    system("cls");
}
void printMenu()
{
    system("cls");
    printf("-------------CALCULAR DISTÂNCIA DE CIDADES-------------\n\n");
    printf("0 - Sair");
    printf("\n\n1 - Entrar com o número de cidades");
    printf("\n\n2 - Entrar com a distância entre as cidades");
    printf("\n\n3 - Entrar com a rota entre as cidades\n\n");
}

void printCidades(int numeroCidade)
{
    printf("Cidades:");
    for (int i = 0; i < numeroCidade; i++)
    {
        printf(" %c", i + 65);
    }
}

void printResultado(int distanciaTotal, char *vetorSoma)
{
    system("cls");
    printf("A distancia a ser percorrida entre as cidades:");
    for (int i = 0; i < strlen(vetorSoma); i++)
    {
        printf(" %c", vetorSoma[i]);
    }
    printf(", é de %dKM\n\n", distanciaTotal);
}

int indexOfCidade(char nomeCidade)
{
    return (int) nomeCidade - 65;
}

int main()
{
    int numeroCidade = 1, opcao, flag = 0, distanciaTotal = 0;

    caractereEspecial();

    for(;;)
    {
        int matriz[numeroCidade][numeroCidade];
        printMenu();
        scanf("%d\n", &opcao);
        clear_keyboard_buffer();

        switch ((int)opcao)
        {
        case 0:
            exit(1);

        case 1:
            system("cls");
            printf("Entre com a quantidade de cidades: ");
            scanf("%d", &numeroCidade);
            flag = 1;
            break;

        case 2:
            if (flag == 1)
            {
                system("cls");

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
                                printf("Distância entre as cidades %c e %c: ", (i + 65), (j + 65));
                                scanf("%d\n", &matriz[i][j]);
                                matriz[j][i] = matriz[i][j];
                            }
                        }
                    }

                }
                flag = 2;
            }
            else
            {
                system("cls");
                printf("ERRO! Número de cidades não preenchido.\n\n");
                system("pause");
            }
            break;
        case 3:
            if (flag == 2)
            {
                int resposta;
                do
                {
                    char vetorAuxiliar[10] = "";
                    char rota[30] = "";
                    char vetorSoma[10] = "";
                    int count = 0;
                    for (int i = 0; i < numeroCidade; i++)
                    {
                        vetorAuxiliar[i] = i + 65;
                    }

                    system("cls");
                    printCidades(numeroCidade);
                    printf("\n\nEntre com a rota: ");
                    gets(rota);
                    gets(rota);
                    for (int i = 0; i < strlen(rota); i++)
                    {
                        for (int j = 0; j < strlen(vetorAuxiliar); j++)
                        {
                            if (toupper(rota[i]) == vetorAuxiliar[j])
                            {
                                vetorSoma[count] = vetorAuxiliar[j];
                                if (count >= 1)
                                {
                                    distanciaTotal += matriz[indexOfCidade(vetorSoma[count - 1])][indexOfCidade(vetorSoma[count])];
                                }
                                count++;
                                break;
                            }
                        }
                    }
                    printResultado(distanciaTotal, vetorSoma);

                    printf("\n\n0 - Sair");
                    printf("\n\n1 - Escolher outra rota");
                    printf("\n\n2 - Voltar ao início\n\n");
                    scanf("%d", &resposta);

                }
                while(resposta == 1);
                switch (resposta)
                {
                case 0:
                    exit(1);
                case 2:
                    flag = 0;
                    break;
                }

            }

            else
            {
                system("cls");
                printf("ERRO! Distancia entre as cidades não preenchida.\n\n");
                system("pause");
            }
            break;
        default:
            system("cls");
            printf("ERRO! Opção inválida.\n\n");
            system("pause");
            break;
        }
    }
}

