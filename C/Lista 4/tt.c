#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void tabuleiro(char casas2[3][3])
{
    system("cls");
    printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    do
    {
        printf("1 - Novo Jogo\n2 - Ranking\n3 - Estatística\n");
        scanf("%d", &opcao);
        char casas[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
        };
        char res;
        int vitoriax = 0, vitoriao = 0, empate = 0;
        int cont_jogadas, l, c, vez = 0, i, j;
        switch (opcao)
        {
        case 1:
        {
            do
            {
                cont_jogadas = 1;
                for (i = 0; i <= 2; i++)
                {
                    for (j = 0; j <= 2; j++)
                    {
                        casas[i][j] = ' ';
                    }
                }
                do
                {
                    tabuleiro(casas);
                    if (vez % 2 == 0)
                    {
                        printf("Jogador X\n");
                    }
                    else
                    {
                        printf("Jogador O\n");
                    }
                    printf("Digite a linha: ");
                    scanf("%i", &l);
                    printf("Digite a coluna: ");
                    scanf("%i", &c);
                    if (l < 1 || c < 1 || l > 3 || c > 3)
                    {
                        l = 0;
                        c = 0;
                    }
                    else if (casas[l - 1][c - 1] != ' ')
                    {
                        l = 0;
                        c = 0;
                    }
                    else
                    {
                        if (vez % 2 == 0)
                        {
                            casas[l - 1][c - 1] = 'X';
                        }
                        else
                        {
                            casas[l - 1][c - 1] = 'O';
                        }
                        vez++;
                        cont_jogadas++;
                    }
                    if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X')
                    {
                        cont_jogadas = 11;
                    }
                    if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X')
                    {
                        cont_jogadas = 11;
                    }

                    if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                    if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O')
                    {
                        cont_jogadas = 12;
                    }
                } while (cont_jogadas <= 9);
                tabuleiro(casas);
                if (cont_jogadas == 10)
                {
                    printf("Jogo empatado\n");
                }
                if (cont_jogadas == 11)
                {
                    printf("Vencedor X\n");
                }
                if (cont_jogadas == 12)
                {
                    printf("Vencedor O\n");
                }

            } while (res == ' ');
        }
        break;
        case 2:
        {
            if (cont_jogadas == 11)
            {
                vitoriax = vitoriax + 1;
            }
            else if (cont_jogadas == 12)
            {
                vitoriao = vitoriao + 1;
            }
            else if (cont_jogadas == 10)
            {
                empate = empate + 1;
            }
            printf("Resultados\nX:%d\nO:%d\nEmpate:%d\n ", vitoriax, vitoriao, empate);
        }
        case 3:
        {
        }
        }
    } while (opcao != 4);
    return 0;
}