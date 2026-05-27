#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
        SetConsoleOutputCP(65001);
    // Entrada
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoInicial;

    // Processamento

    // LEITURA DE ALUNOS (Commit 1)
    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;
    cout << " 1 --> Novo relatório" << endl;
    cout << " 2 --> Ver relatório salvo" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcaoInicial;

    // LEITURA DE ARQUIVO (Commit 5)
    if (opcaoInicial == 2)
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }
            leitura.close();
        }
        else
        {
            cout << "Nenhum relatório encontrado." << endl;
        }
        return 0;
    }

    do
    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // NOTAS E MÉDIAS (Commit 2)
    do
    {
        cout << "\nQuantidade de disciplinas (1 a 5): ";
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "  Disciplina " << j + 1 << " (0 a 10): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);

            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    // Saída
    cout << "\n=== ALUNOS CADASTRADOS ===" << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    // CLASSIFICAÇÃO E RELATÓRIO (Commit 3)
    cout << "\n=== RELATORIO DE NOTAS ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " " << nomes[i] << " Media: " << media[i] << " - Status: ";
        if (media[i] >= 7.0)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5.0)
        {
            cout << "Recuperacao" << endl;
            recuperacao++;
        }
        else
        {
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\n=== RESUMO FINAL ===" << endl;
    cout << " Aprovados: " << aprovados << " | Em Recuperacao: " << recuperacao << " | Reprovados: " << reprovados << endl;

    // SALVAR EM ARQUIVO (Commit 4)
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
        arquivo << "==== RELATÓRIO ====" << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << " -- Média --" << media[i] << " - ";
            if (media[i] >= 7)
            {
                arquivo << " APROVADO! " << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << " RECUPERAÇÃO! " << endl;
            }
            else
            {
                arquivo << " REPROVADO! " << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << "aprovados," << recuperacao << " em recuperação," << reprovados << "reprovados." << endl;

        arquivo.close();

        cout << "\nRelatorio salvo com sucesso!" << endl;
    }
    else
    {
        cout << "Erro ao criar arquivo." << endl;
    }

    return 0;
}
