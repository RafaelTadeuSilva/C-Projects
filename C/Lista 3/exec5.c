#include <stdio.h>
// #include <unistd.h>

int main()
{
    int menuOpcao = 0;
    int novoJogo = 0;
    int golsZero[25] = {0};
    int golsGalo[25] = {0};
    int totalJogos = 0;
    int vitZero = 0;
    int vitGalo = 0;

    do
    {
        system("cls");

        printf("Menu\n");
        printf("1-Incluir novo resultado de jogo.\n");
        printf("2-Quantidade de Zero x Galo nas estatisticas.\n");
        printf("3-Vitorias do Cruzeiro.\n");
        printf("4-Vitorias do Atletico.\n");
        printf("5-Numero de Empates.\n");
        printf("6-Maior Vencedor.\n");
        printf("7-Porcentagem de Vitorias, Derrotas e Empates.\n");
        printf("Outras numeros - Sair\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &menuOpcao);

        system("cls");

        if (menuOpcao == 1)
        {
            do
            {
                for (int i = 0; i < 25; i++)
                {
                    printf("Digite os gols do Cruzeiro na partida %d :", i + 1);
                    scanf("%d", &golsZero[i]);
                    printf("Digite os gols do Atletico na partida %d :", i + 1);
                    scanf("%d", &golsGalo[i]);

                    totalJogos++;

                    if (golsZero[i] > golsGalo[i])
                    {
                        printf("Vencedor Cruzeiro\n\n");
                        vitZero++;
                    }
                    else if (golsGalo[i] > golsZero[i])
                    {
                        printf("Vencedor Atletico\n\n");
                        vitGalo++;
                    }
                    else
                        printf("EMPATE\n\n");
                }
                printf("\nNovo Zero x Galo 1.Sim 2.Nao? ");
                scanf("%d", &novoJogo);
            } while (novoJogo == 1);
        }
        if (menuOpcao == 2)
        {
            if (totalJogos == 0)
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            else
                printf("Fizeram parte desta estatistica:\n%d - Zero x Galo\n%d - jogos disputados\n\n", totalJogos / 25, totalJogos);
            system("pause");
        }
        if (menuOpcao == 3)
        {
            if (totalJogos == 0)
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            else if (vitZero == 0)
                printf("Cruzeiro nao teve vitorias.\n\n");
            else
                printf("Vitorias do Cruzeiro: %d.\n\n", vitZero);
            system("pause");
        }
        if (menuOpcao == 4)
        {
            if (totalJogos == 0)
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            else if (vitGalo == 0)
                printf("Atletico nao teve vitorias.\n\n");
            else
                printf("Vitorias do Atletico: %d.\n\n", vitGalo);
            system("pause");
        }
        if (menuOpcao == 5)
        {
            int empates = totalJogos - vitGalo - vitZero;
            if (totalJogos == 0)
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            else if (empates == 0)
                printf("Nao foi registrado nenhum empate.\n\n");
            else
                printf("Numero de Empates: %d.\n\n", empates);
            system("pause");
        }
        if (menuOpcao == 6)
        {
            if (totalJogos == 0)
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            else if (vitGalo > vitZero)
                printf("MAIOR VENCEDOR: Atletico!\n\n");
            else if (vitZero > vitGalo)
                printf("MAIOR VENCEDOR: Cruzeiro!\n\n");
            else
                printf("NAO HOUVE VENCEDOR!\n\n");
            system("pause");
        }
        if (menuOpcao == 7)
        {
            if (totalJogos == 0)
            {
                printf("Ainda nao foi registrado nenhuma partida.\n\n");
            }
            else
            {

                int empates = totalJogos - vitGalo - vitZero;

                printf("Resumo das Estatisticas\n\n");
                printf("Total de Jogos: %d\n\n", totalJogos);
                printf("Vitorias Cruzeiro: %d - %.2f%%\n", vitZero, (float)vitZero / totalJogos * 100);
                printf("Derrotas Cruzeiro: %d - %.2f%%\n\n", vitGalo, (float)vitGalo / totalJogos * 100);

                printf("Vitorias Atletico: %d - %.2f%%\n", vitGalo, (float)vitGalo / totalJogos * 100);
                printf("Derrotas Atletico: %d - %.2f%%\n\n", vitZero, (float)vitZero / totalJogos * 100);

                printf("Empates: %d - %.2f%%\n\n", empates, (float)empates / totalJogos * 100);
            }
            system("pause");
        }
    } while (menuOpcao > 0 && menuOpcao < 8);

    printf("Fim da Execucao.");
    
    return 0;
}