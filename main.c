#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void clear_keyboard_buffer();
void caractereEspecial();
void printCidades(int);
void preencheMatriz(int, int[][0]);
int calculaDistancia(int,int[][0], char*, char*); // metodo que retorna a distancia total da rota
void printResultado(int, char*);
int indexOfCidade(char); // metodo transforma a cidade (char) em um numero correspondente na matriz

int main()
{
    int numeroCidade;

    caractereEspecial();
    for(;;)
    {
        system("cls");
        printf("Entre com a quantidade de cidades[3, 4, 5]: ");
        scanf("%d", &numeroCidade);
        if (numeroCidade >= 3 && numeroCidade <= 5)
        {
            break;
        }
        else
        {
            system("cls");
            printf("Opção inválida! Entre com um número de cidades entre 3 e 5.\n\n");
            system("pause");
        }
    }

    int matriz[numeroCidade][numeroCidade];

    preencheMatriz(numeroCidade, matriz);

    for(;;) //Loop para o usuário entrar com quantas rotas quiser
    {
        char rota[30] = "";
        char vetorSoma[10] = "";
        int resposta;

        system("cls");
        printCidades(numeroCidade);
        printf("\n\nEntre com a rota: ");
        gets(rota);
        do
        {
            printResultado(calculaDistancia(numeroCidade, matriz,vetorSoma,rota), vetorSoma);
            printf("\n\n0 - Sair");
            printf("\n\n1 - Escolher outra rota\n\n");
            scanf("%d", &resposta);
            clear_keyboard_buffer();
            if (resposta == 0)
            {
                exit(1);
            }
        }
        while(resposta != 1);

    }
}



void clear_keyboard_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

void caractereEspecial()
{
    printf("%s",setlocale(LC_ALL,""));
    system("cls");
}

void preencheMatriz(int numeroCidade, int matriz[numeroCidade][numeroCidade])
{
    system("cls");
    for (int i = 0; i < numeroCidade; i++)
    {
        for (int j = 0; j < numeroCidade; j++)
        {
            if (j > i) // condição para preencher somente da diagonal principal para cima
            {
                if (i == j)
                {
                    matriz[i][j] = 0;
                }
                else
                {
                    system("cls");
                    printf("Distância entre as cidades %c e %c: ", (i + 65), (j + 65));
                    scanf("%d", &matriz[i][j]);
                    matriz[j][i] = matriz[i][j];
                    clear_keyboard_buffer();

                }
            }
        }

    }
}

void printCidades(int numeroCidade)
{
    printf("Cidades:");
    for (int i = 0; i < numeroCidade; i++)
    {
        printf(" %c", i + 65);
    }
}

int calculaDistancia(int numeroCidade,int matriz[numeroCidade][numeroCidade], char *vetorSoma, char *rota)
{
    char vetorAuxiliar[10] = "";
    int soma = 0, count = 0;
    for (int i = 0; i < numeroCidade; i++)
    {
        vetorAuxiliar[i] = i + 65;
    }

    for (int i = 0; i < strlen(rota); i++)
    {
        for (int j = 0; j < strlen(vetorAuxiliar); j++)
        {
            if (toupper(rota[i]) == vetorAuxiliar[j])
            {
                vetorSoma[count] = vetorAuxiliar[j];
                if (count >= 1)
                {
                    soma += matriz[indexOfCidade(vetorSoma[count - 1])][indexOfCidade(vetorSoma[count])];
                }
                count++;
                break;
            }
        }
    }
    return soma;
}

void printResultado(int distanciaTotal, char *vetorSoma)
{
    system("cls");
    printf("A distancia a ser percorrida na rota entre as cidades:");
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


