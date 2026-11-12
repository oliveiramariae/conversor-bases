#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. DECIMAL PARA OCTAL
// ==========================================
string decParaOctal(string nTexto) {
    unsigned long long n, quociente, resto;
    string novaEntradaTexto = "", resultadoO = "";

    // Limpar entrada nTexto (mantém apenas dígitos de 0 a 9)
    for (int i = 0; i < nTexto.length(); i++) {
        if (nTexto[i] >= '0' && nTexto[i] <= '9') {
            novaEntradaTexto += nTexto[i];
        }
    }

    if (novaEntradaTexto.length() == 0) {
        return "0";
    }

    // Trava de tamanho para não estourar o limite de 19 dígitos do unsigned long long
    if (novaEntradaTexto.length() > 19) {
        novaEntradaTexto = novaEntradaTexto.substr(0, 19);
        cout << "Excedeu 19 digitos, pegara so os primeiros 19 digitos. Sua nova entrada eh: " << endl;
        cout << novaEntradaTexto << endl;
    }

    n = stoull(novaEntradaTexto); // Mudar tipo da variável de texto para unsigned long long

    quociente = n;
    while (quociente > 0) {
        resto = quociente % 8;
        resultadoO += to_string(resto);
        quociente = quociente / 8;
    }

    reverse(resultadoO.begin(), resultadoO.end()); // Inverter o resultado octal

    if (resultadoO.empty()) {
        return "0";
    }

    return resultadoO;
}

// ==========================================
// 2. OCTAL PARA DECIMAL
// ==========================================
unsigned long long octalParaDec(string nTexto) {
    unsigned long long uo = 1, resultadoD = 0; // uo = unidade/elemento octal
    int nOct;
    string novaEntradaTexto = "", nTOct;

    // Limpar entrada (mantém apenas dígitos octais válidos de 0 a 7)
    for (int i = 0; i < nTexto.length(); i++) {
        if (nTexto[i] >= '0' && nTexto[i] <= '7') {
            novaEntradaTexto += nTexto[i];
        }
    }

    if (novaEntradaTexto.length() == 0) {
        return 0;
    }

    reverse(novaEntradaTexto.begin(), novaEntradaTexto.end()); // Inverter entrada do usuário

    for (int i = 0; i < novaEntradaTexto.length(); i++) {
        nTOct = novaEntradaTexto[i];
        nOct = stoi(nTOct);
        uo = pow(8, i) * nOct; // Cálculo do peso octal (8^i * dígito)
        resultadoD += uo;
    }

    return resultadoD;
}

// ==========================================
// 3. FUNÇÃO PRINCIPAL (MAIN)
// ==========================================
int main() {
    unsigned long long resultadoD;
    int op;
    string nTexto, resultadoO;

    cout << "O que voce quer fazer? (1-decimal para octal; 2-octal para decimal; 3-sair)" << endl;
    cin >> op;

    switch (op) {
        case 1: // Decimal para Octal
            cout << "Coloque o numero que sera convertido (Aguenta no maximo 19 digitos): " << endl;
            cin >> nTexto;

            resultadoO = decParaOctal(nTexto);
            cout << "o resultado da conversao decimal para octal eh: " << resultadoO << endl;
            break;

        case 2: // Octal para Decimal
            cout << "Coloque o valor octal que sera convertido: " << endl;
            cin >> nTexto;

            resultadoD = octalParaDec(nTexto);
            cout << "o resultado da conversao de octal para decimal eh: " << resultadoD << endl;
            break;

        case 3:
            cout << "Saindo..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
    }

    return 0;
}