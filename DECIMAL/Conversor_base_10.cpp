#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. PROTÓTIPOS DAS FUNÇÕES
// ==========================================
string decParaBinario(unsigned long long numero);
string decParaQuaternario(unsigned long long numero);
string decParaOctal(unsigned long long numero);
string decParaHexadecimal(unsigned long long numero);

// ==========================================
// 2. FUNÇÃO PRINCIPAL (MENU COM REPETIÇÃO)
// ==========================================
int main() {
    int opcao;
    long long numeroDecimal; // Permite ler números negativos para poder bloqueá-los

    // LAÇO DO-WHILE: Mantém o menu rodando até o usuário digitar a opção 5 (Sair)
    do {
        cout << "\n========================================" << endl;
        cout << "      CONVERSOR DE BASE DECIMAL         " << endl;
        cout << "========================================" << endl;
        cout << "Digite a opcao da base desejada:" << endl;
        cout << "1 - Decimal para Binario (Base 2)" << endl;
        cout << "2 - Decimal para Quaternario (Base 4)" << endl;
        cout << "3 - Decimal para Octal (Base 8)" << endl;
        cout << "4 - Decimal para Hexadecimal (Base 16)" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";

        // PROTEÇÃO 1: Valida a opção do menu (apenas números de 1 a 5)
        while (!(cin >> opcao) || opcao < 1 || opcao > 5) {
            cout << "Entrada invalida! Digite apenas um numero entre 1 e 5: ";
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(10000, '\n'); // Descarta caracteres inválidos digitados
        }

        // Se o usuário escolher sair (5), encerra o laço
        if (opcao == 5) {
            cout << "\nEncerrando o programa... Ate logo!" << endl;
            break;
        }

        cout << "\nDigite o numero decimal a ser convertido: ";
        
        // PROTEÇÃO 2: Rejeita letras/símbolos E rejeita números menores ou iguais a 0 (negativos e zero)
        while (!(cin >> numeroDecimal) || numeroDecimal <= 0) {
            cout << "Numero invalido! Digite apenas um numero inteiro positivo (maior que 0): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // DIRECIONAMENTO COM SWITCH
        string resultado = "";
        switch (opcao) {
            case 1:
                resultado = decParaBinario(numeroDecimal);
                cout << "\n--> Resultado em Binario: " << resultado << endl;
                break;
            case 2:
                resultado = decParaQuaternario(numeroDecimal);
                cout << "\n--> Resultado em Quaternario: " << resultado << endl;
                break;
            case 3:
                resultado = decParaOctal(numeroDecimal);
                cout << "\n--> Resultado em Octal: " << resultado << endl;
                break;
            case 4:
                resultado = decParaHexadecimal(numeroDecimal);
                cout << "\n--> Resultado em Hexadecimal: " << resultado << endl;
                break;
        }

    } while (opcao != 5); // Repete o ciclo enquanto a opção não for 5

    return 0;
}

// ==========================================
// 3. IMPLEMENTAÇÃO DAS FUNÇÕES
// ==========================================

// Decimal para Binario (Base 2)
string decParaBinario(unsigned long long numero) {
    string resultado = "";
    while (numero > 0) {
        resultado += to_string(numero % 2);
        numero /= 2;
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

// Decimal para Quaternario (Base 4)
string decParaQuaternario(unsigned long long numero) {
    string resultado = "";
    while (numero > 0) {
        resultado += to_string(numero % 4);
        numero /= 4;
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

// Decimal para Octal (Base 8)
string decParaOctal(unsigned long long numero) {
    string resultado = "";
    while (numero > 0) {
        resultado += to_string(numero % 8);
        numero /= 8;
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

// Decimal para Hexadecimal (Base 16)
string decParaHexadecimal(unsigned long long numero) {
    string digitosHex = "0123456789ABCDEF"; // Mapeia restos de 0 a 15
    string resultado = "";
    while (numero > 0) {
        int resto = numero % 16;
        resultado += digitosHex[resto];
        numero /= 16;
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}