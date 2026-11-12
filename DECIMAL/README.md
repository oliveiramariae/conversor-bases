Conversor de Bases Numéricas em C++

Um programa de console interativo, robusto e eficiente desenvolvido em C++ para converter números inteiros da Base Decimal (Base 10) para Binário (Base 2), Quaternário (Base 4), Octal (Base 8) e Hexadecimal (Base 16).

O projeto foi projetado focando em usabilidade, modularidade e tratamento rigoroso de erros de entrada (blindagem contra falhas).

Funcionalidades
Menu Interativo: Navegação contínua que permite realizar múltiplas conversões sem reiniciar o aplicativo.
Conversões Suportadas:
Decimal -> Binário (Base 2)
Decimal -> Quaternário (Base 4)
Decimal -> Octal (Base 8)
Decimal -> Hexadecimal (Base 16)
Tratamento e Validação de Erros (Anti-Falhas):
Bloqueio de Texto e Símbolos: Limpeza do buffer (cin.clear() e cin.ignore()) se o usuário digitar letras ou caracteres inválidos.
Bloqueio de Números Negativos e Zero: Aceita estritamente números inteiros positivos (> 0).
Proteção contra Divisão por Zero: Menu restrito com opções válidas de 1 a 5, impedindo divisões por bases inválidas.
Suporte a Grandes Valores: Utilização do tipo unsigned long long para processar números decimais extensos.
Tecnologias Utilizadas
Linguagem: C++ (C++11 ou superior)
Compiladores Suportados: g++, clang++, MSVC (Visual Studio)
Bibliotecas Padrão: <iostream>, <string>, <algorithm>

Como Compilar e Executar
Pré-requisitos
Ter um compilador C++ instalado em sua máquina (como g++ via GCC, MinGW, Clang ou Visual Studio).

Passos de Execução
Baixar o repositório:

cd conversor-de-bases-cpp
Compilar o código:

g++ -std=c++11 main.cpp -o conversor
Executar o programa:

Linux/macOS:
./conversor
Windows:
conversor.exe
Estrutura do Código
O programa é dividido em três seções bem definidas:

Protótipos das Funções: Declaração das assinaturas para organização do código.
Função main(): Contém o menu principal (do-while), o leitor seguro de dados (cin) e o direcionamento das operações (switch).
Implementações:
decParaBinario(): Algoritmo de divisões sucessivas por 2.
decParaQuaternario(): Algoritmo de divisões sucessivas por 4.
decParaOctal(): Algoritmo de divisões sucessivas por 8.
decParaHexadecimal(): Algoritmo de divisões sucessivas por 16 com mapeamento de restos (0-9 e A-F).

Exemplo de Uso
========================================
      CONVERSOR DE BASE DECIMAL  
========================================
Digite a opcao da base desejada:
1 - Decimal para Binario (Base 2)
2 - Decimal para Quaternario (Base 4)
3 - Decimal para Octal (Base 8)
4 - Decimal para Hexadecimal (Base 16)
5 - Sair
Opcao: 4

Digite o numero decimal a ser convertido: 255

--> Resultado em Hexadecimal: FF
