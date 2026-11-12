#include <iostream>
using namespace std;

// binario para octal
long long binParaOctal(long long binario)
{
    long long octal = 0, posicao = 1, aux = binario;

    if (aux == 0)
    {
        return 0;
    }

    while (aux > 0)
    {
        long long trio = aux % 1000, digito;

        // isola os digitos e utiliza a regra dos pesos
        long long esquerda = (trio / 100) % 10; // peso 4
        long long meio = (trio / 10) % 10;      // peso 2
        long long direita = trio % 10;          // peso 1

        if ((direita != 0 && direita != 1) || (meio != 0 && meio != 1) || (esquerda != 0 && esquerda != 1))
        {
            return -1;
        }

        digito = (esquerda * 4) + (meio * 2) + (direita * 1);
        octal += digito * posicao;
        posicao *= 10;
        aux /= 1000; // avança para o próximo
    }

    return octal;
}

// converter octal para binario
long long octalParaBin(long long octal)
{
    long long binario = 0, posicao = 1, aux = octal;
    const int binarios[] = {0, 1, 10, 11, 100, 101, 110, 111};

    if (aux == 0)
    {
        return 0;
    }

    while (aux > 0)
    {
        long long digitOctal = aux % 10; // isola o último dígito!

        // se não for de 0 a 7, é inválido
        if (digitOctal < 0 || digitOctal > 7)
        {
            return -1;
        }

        binario += binarios[digitOctal] * posicao;
        posicao *= 1000;
        aux /= 10;
    }

    return binario;
}

int main() {
    long long valor;
    int opcao;

    cout << "-- Conversor octal --" << endl;
    cout << "[1] Binario para Octal" << endl;
    cout << "[2] Octal para Binario" << endl;
    cout << "[3] Sair" << endl;
    cout << "Sua escolha: ";
    cin >> opcao;

    cout << "Digite o valor a ser convertido: ";
    cin >> valor;
    
    switch(opcao) {
        case 1:
            cout << "O valor octal de " << valor << " eh: " << binParaOctal(valor) << endl;
            break;
        case 2:
            cout << "O valor binario de " << valor << " eh: " << octalParaBin(valor) << endl;
            break;
        case 3:
            cout << "Saindo...";
            break;

        default:
            cout << "Valor inválido.";
            break;
    }

    return 0;
    
}