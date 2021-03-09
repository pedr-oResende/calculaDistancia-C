#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void clear_keyboard_buffer(void);
void caractereEspecial(void); // m�todo para permitir caracteres especiais no programa
void printCidades(int);
void preencheMatriz(int, int[5][5]);
int calculaDistancia(int,int[5][5], char*, char*); // metodo que retorna a distancia total da rota
void printResultado(int, char*);
int indexOfCidade(char); // metodo transforma a cidade (char) em um numero correspondente na matriz
void capturarErros(int, int*);

int main()
{
    int numeroCidade;

    caractereEspecial();
    for(;;)
    {
        system("cls");
        printf("Entre com a quantidade de cidades (M�ximo 5): ");
        scanf("%d", &numeroCidade);
        if (numeroCidade >= 2 && numeroCidade <= 5)
        {
            break;
        }
        else
        {
            system("cls");
            printf("Op��o inv�lida. Entre com um n�mero de cidades entre 2 e 5!\n\n");
            system("pause");
        }
    }

    int matriz[5][5];

    preencheMatriz(numeroCidade, matriz);

    for(;;) //Loop para o usu�rio entrar com quantas rotas quiser
    {
        char rota[30] = "";
        char cidadesCalculadas[20] = "";
        int resposta;

        system("cls");
        printCidades(numeroCidade);
        printf("\n\nEntre com a rota: ");
        gets(rota);
        do
        {
            printResultado(calculaDistancia(numeroCidade, matriz, cidadesCalculadas, rota), cidadesCalculadas);
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

// M�todos

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

void preencheMatriz(int numeroCidade, int matriz[5][5])
{
    for (int i = 0; i < numeroCidade; i++)
    {
        for (int j = i; j < numeroCidade; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 0;
            }
            else
            {
                system("cls");
                printf("Caso n�o houver conex�o entre as cidades digite 0\n\n");
                printf("Dist�ncia entre as cidades %c e %c: ", (i + 65), (j + 65));
                scanf("%d", &matriz[i][j]);
                matriz[j][i] = matriz[i][j]; // l�gica pra preecher os campos abaixo da diagonal principal
                clear_keyboard_buffer();

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

int calculaDistancia(int numeroCidade,int matriz[5][5], char *cidadesCalculadas, char *rota)
{
    char vetorAuxiliar[20] = "";
    int soma = 0, count = 0, aux = 0;
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

                cidadesCalculadas[count] = vetorAuxiliar[j];
                if (count >= 1)
                {
                    if (matriz[indexOfCidade(cidadesCalculadas[count - 1])][indexOfCidade(cidadesCalculadas[count])] == 0)
                    {
                        aux = 1; // L�gica para verificar se n�o h� conex�o entre as cidades
                    }
                    soma += matriz[indexOfCidade(cidadesCalculadas[count - 1])][indexOfCidade(cidadesCalculadas[count])];
                }
                count++;
            }
        }
    }

    if (aux == 1)
    {
        return 0;
    }
    if (strlen(cidadesCalculadas) == 1)
    {
        return -1; // l�gica para verificar caso s� haja uma cidade v�lida
    }
    if (strcmp(cidadesCalculadas, "") == 0)
    {
        return -2; // L�gica para verificar se foi digitado alguma cidade v�lida
    }
    return soma;
}

void printResultado(int distanciaTotal, char *cidadesCalculadas)
{
    int flag = 0;
    system("cls");
    capturarErros(distanciaTotal, &flag);
    if (flag == 0)
    {
        printf("A distancia a ser percorrida na rota entre as cidades:");
        for (int i = 0; i < strlen(cidadesCalculadas); i++)
        {
            printf(" %c", cidadesCalculadas[i]);
        }
        printf(", � de %dKM\n\n", distanciaTotal);
    }
}

int indexOfCidade(char nomeCidade)
{
    return (int) nomeCidade - 65;
}

void capturarErros(int distanciaTotal, int *flag)
{
    system("cls");
    switch (distanciaTotal)
    {
    case 0:
        printf("Erro. N�o h� conex�o entre as cidades!\n\n");
        *flag = 1;
        break;
    case -1:
        printf("Erro. Entre com mais de uma cidade!\n\n");
        *flag = 1;
        break;
    case -2:
        printf("Erro. Entre com cidades v�lidas!\n\n");
        *flag = 1;
        break;
    }

}
