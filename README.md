# 📊 Sistema de Gerenciamento de Notas v4.1 

Um sistema em linha de comando robusto desenvolvido em **C++** para automatizar o cadastro de alunos, lançamento de notas por disciplinas, cálculo de médias acadêmicas e persistência de dados em arquivos de texto físicos. Projeto ideal para fins acadêmicos e consolidação de conceitos estruturais de programação.

---

## 🚀 Funcionalidades

* **Menu Inicial Dinâmico:** Opções para gerar um novo relatório do zero ou ler diretamente um histórico pré-existente no disco.
* **Validação Estrita de Entradas:** Controle completo de limites em laços de repetição (de 1 a 20 alunos, de 1 a 5 disciplinas e notas estritamente validadas entre 0.0 e 10.0).
* **Cálculo Automatizado:** Processamento automático de médias aritméticas individuais por aluno.
* **Análise de Status Acadêmico:** Classificação automática com base na média obtida:
    * 🥇 **Aprovado:** Média $\ge$ 7.0
    * ⚠️ **Recuperação:** Média entre 5.0 e 6.9
    * ❌ **Reprovado:** Média < 5.0
* **Resumo Estatístico:** Painel final exibindo o total de alunos aprovados, em recuperação e reprovados em tempo real.
* **Persistência de Dados (Banco de Arquivo):** Exportação formatada de todo o relatório final para um arquivo físico (`relatorio.txt`), permitindo consultas rápidas posteriores.
- Cadastro de alunos e notas por disciplina
- Cálculo de médias por aluno
- Classificação: Aprovado, Recuperação ou Reprovado
- Relatório salvo em arquivo .txt com data e hora
- Leitura de relatório salvo
- Menu "Sobre o sistema"

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (Padrão ISO)
* **Bibliotecas Nativas Utilizadas:**
    * `<iostream>`: Manipulação de fluxos de entrada e saída de dados no console.
    * `<string>`: Gerenciamento avançado de strings de texto e vetores de caracteres.
    * `<fstream>`: Manipulação, abertura, gravação e persistência de arquivos físicos locais.
    * `<windows.h>`: Ativação do suporte ao Code Page UTF-8 (`SetConsoleOutputCP(65001)`) garantindo exibição perfeita de caracteres especiais e acentuações nativas da língua portuguesa dentro do terminal do Windows.

---

## 📁 Estrutura de Armazenamento do Código

O programa utiliza matrizes e vetores estáticos de forma eficiente para gerenciar o escopo de memória do console:
* `nomes[20]`: Vetor unidimensional para armazenamento do nome dos estudantes.
* `notas[20][5]`: Matriz bidimensional associando as respectivas notas por aluno por disciplina.
* `media[20]`: Vetor responsável por guardar as médias calculadas dinamicamente.

---

## ⚙️ Como Executar o Projeto

### Pré-requisitos
Certifique-se de ter um compilador C++ instalado em sua máquina (como o `GCC/G++` ou ambiente integrado no `VS Code`).

### Passo a Passo

1.  **Clone este repositório:**
    ```bash
    git clone [https://github.com/LuisSilva-del/NOME_DO_REPOSITORIO.git](https://github.com/LuisSilva-del/NOME_DO_REPOSITORIO.git)
    ```

2.  **Acesse a pasta do projeto:**
    ```bash
    cd NOME_DO_REPOSITORIO
    ```

3.  **Compile o arquivo principal do programa:**
    ```bash
    g++ -o sistema_notas main.cpp
    ```

4.  **Execute a aplicação:**
    * No Windows:
        ```bash
        sistema_notas.exe
        ```
    * No Linux / macOS:
        ```bash
        ./sistema_notas
        ```

---

## 📝 Histórico de Desenvolvimento (Controle de Commits)

Este projeto foi modularizado passo a passo para demonstrar a evolução de lógica e boas práticas de versionamento Git:
* **Commit 1:** Implementação da lógica base para leitura e validação dos dados dos alunos.
* **Commit 2:** Adicionado o fluxo matricial para captação de notas de múltiplas disciplinas e cálculo de médias.
* **Commit 3:** Criação dos blocos condicionais de classificação de status acadêmico e painel de resumo final.
* **Commit 4:** Integração com a biblioteca de escrita externa (`ofstream`) para salvar os dados formatados em arquivo `.txt`.
* **Commit 5:** Criação do módulo de recuperação e leitura de histórico local (`ifstream`) integrado diretamente ao menu inicial do console.

---

## 📄 Licença

Este projeto está sob a licença MIT. Sinta-se livre para clonar, estudar e sugerir melhorias!

---
Documentação desenvolvida por **Luís Silva** 🚀