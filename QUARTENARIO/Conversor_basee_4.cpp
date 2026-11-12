#include <iostream>
#include <string>
using namespace std;

// verifica se o texto tem so digitos de 0 a 3 (maximo 32 digitos)
bool ehQuaternario(string texto)
{
    if (texto.length() == 0 || texto.length() > 32)
    {
        return false;
    }

    for (int i = 0; i < texto.length(); i++)
    {
        if (texto[i] < '0' || texto[i] > '3')
        {
            return false;
        }
    }

    return true;
}

// quaternario para decimal
unsigned long long quartParaDec(string quartenario)
{
    unsigned long long decimal = 0;

    for (int i = 0; i < quartenario.length(); i++)
    {
        int digito = quartenario[i] - '0';
        decimal = decimal * 4 + digito;
    }

    return decimal;
}

// decimal para outra base (2, 8 ou 16) com divisoes sucessivas
string decParaBase(unsigned long long numero, int base)
{
    string digitos = "0123456789ABCDEF";
    string resultado = "";

    if (numero == 0)
    {
        return "0";
    }

    while (numero > 0)
    {
        resultado = digitos[numero % base] + resultado;
        numero = numero / base;
    }

    return resultado;
}

int main()
{
    int opcao;
    string quartenario;

    do
    {
        cout << "\n--- Conversor Quartenario (Base 4) ---" << endl;
        cout << "[1] Quartenario para Decimal" << endl;
        cout << "[2] Quartenario para Binario" << endl;
        cout << "[3] Quartenario para Octal" << endl;
        cout << "[4] Quartenario para Hexadecimal" << endl;
        cout << "[5] Sair" << endl;
        cout << "Sua escolha: ";

        // se digitar letra, limpa a entrada e volta pro menu
        if (!(cin >> opcao))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = 0;
        }

        if (opcao >= 1 && opcao <= 4)
        {
            cout << "Digite o numero quartenario: ";
            cin >> quartenario;

            if (!ehQuaternario(quartenario))
            {
                cout << "Numero invalido! Use apenas os digitos 0, 1, 2 e 3 (ate 32 digitos)." << endl;
                continue;
            }

            // todas as conversoes passam pelo decimal
            unsigned long long decimal = quartParaDec(quartenario);

            switch (opcao)
            {
            case 1:
                cout << "O valor decimal de " << quartenario << " eh: " << decimal << endl;
                break;
            case 2:
                cout << "O valor binario de " << quartenario << " eh: " << decParaBase(decimal, 2) << endl;
                break;
            case 3:
                cout << "O valor octal de " << quartenario << " eh: " << decParaBase(decimal, 8) << endl;
                break;
            case 4:
                cout << "O valor hexadecimal de " << quartenario << " eh: " << decParaBase(decimal, 16) << endl;
                break;
            }
        }
        else if (opcao == 5)
        {
            cout << "Saindo do programa..." << endl;
        }
        else
        {
            cout << "Opcao invalida." << endl;
        }

    } while (opcao != 5);

    return 0;
}
