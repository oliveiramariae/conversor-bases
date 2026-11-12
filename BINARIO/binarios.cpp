#include <iostream>
#include <string>
using namespace std;

// converter binario para quartenario
long long binParaQuart(long long binario)
{
    long long quartenario = 0, posicao = 1, aux = binario;

    // caso a auxiliar não receber nada
    if (aux == 0)
    {
        return 0;
    }

    while (aux > 0)
    {
        // divide por 100 e isola os dois últimos números
        long long par = aux % 100, digito;

        // se par for 0 ou 1, mantém o valor
        if (par == 0 || par == 1)
        {
            digito = par;
            // caso par for 10, o digito recebe 2
        }
        else if (par == 10)
        {
            digito = 2;
        }
        else if (par == 11)
        {
            digito = 3;
        }
        else
        {
            return -1; // inválido
        }

        quartenario += digito * posicao;
        posicao *= 10; // avança uma casa decimal
        aux /= 100;
    }

    return quartenario;
}

// converter quartenario para binario
long long quartParaBin(long long quartenario)
{
    long long binario = 0, posicao = 1, aux = quartenario;

    if (aux == 0)
    {
        return 0;
    }

    while (aux > 0)
    {
        long long digito = aux % 10;
        long long equivalente = 0;

        if (digito == 0)
        {
            equivalente = 0;
        }
        else if (digito == 1)
        {
            equivalente = 1;
        }
        else if (digito == 2)
        {
            equivalente = 10;
        }
        else if (digito == 3)
        {
            equivalente = 11;
        }
        else
        {
            return -1; // inválido
        }

        binario += equivalente * posicao;
        posicao *= 100;
        aux /= 10;
    }

    return binario;
}

// converter binario para octal
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

// converter binario para decimal
long long binParaDecimal(long long binario)
{
    long long decimal = 0, base = 1, aux = binario; // aux recebe uma copia do binario

    while (aux > 0)
    {
        long long ultimoDigito = aux % 10; // pega o resto da divisao
        if (ultimoDigito != 0 && ultimoDigito != 1)
        {
            return -1; // inválido
        }

        if (ultimoDigito == 1)
        {
            decimal += base;
        }
        base *= 2; // multiplica a base por 2
        aux /= 10; // divisao inteira
    }

    return decimal;
}

// converter decimal para binario
long long decimalParaBin(long long decimal)
{
    long long binario = 0, posicao = 1, aux = decimal;

    if (aux == 0){
        return 0;
    }

    while (aux > 0){
        int resto = aux % 2;
        binario = binario + (resto * posicao);
        posicao *= 10;
        aux /= 2;
    }

    return binario;
}

// binario para hexadecimal
string binParaHexa(long long binario){
    const char digitosHexa[] = "0123456789ABCDEF"; // array de hexadecimal
    string hexadecimal;
    long long aux = binario;

    if (binario < 0){
        return "Erro: valor negativo!";
    }

    while (aux > 0){
        int valorGrupo = 0;
        int peso = 1;

        for (int i = 0; i < 4 && aux > 0; i++)
        {                       // i maior que quatro e auxiliar maior que zero
            int bit = aux % 10; // bit recebe o resto da divisão por 10 da auxiliar
            aux /= 10;

            if (bit != 0 && bit != 1)
            {
                return "Erro! Deve ser binario...";
            }
            valorGrupo += bit * peso;
            peso *= 2;
        }

        hexadecimal = digitosHexa[valorGrupo] + hexadecimal;
    }

    return hexadecimal;
}

// hexadecimal para binario
string hexaParaBin(string hexadecimal){
    // lista de binarios!
    const string grupoBinarios[] = {"0000", "0001", "0010", "0011",  // 0, 1, 2, 3
                                    "0100", "0101", "0110", "0111",  // 4, 5, 6,7
                                    "1000", "1001", "1010", "1011",  // 8, 9, A, B
                                    "1100", "1101", "1110", "1111"}; // C, D, E, F

    string resultado;

    for (int i = 0; i < hexadecimal.length(); i++){
        char letra = hexadecimal[i];
        int indice;

        if (letra >= '0' && letra <= '9'){
            indice = letra - '0';
        }
        else if (letra >= 'A' && letra <= 'F'){
            indice = letra - 'A' + 10;
        }
        else if (letra >= 'a' && letra <= 'f'){
            indice = letra - 'a' + 10;
        }
        else{
            return "";
        }

        resultado += grupoBinarios[indice];
    }

    return resultado;
}

int main(){
    int opcao;
    long long valor;

    do{
        cout << " --- Conversao Binaria ---" << endl;
        cout << "[1] Binario para Quartenario" << endl;
        cout << "[2] Quartenario para Binario" << endl;
        cout << "[3] Binario para Octal" << endl;
        cout << "[4] Octal para Binario" << endl;
        cout << "[5] Binario para Decimal" << endl;
        cout << "[6] Decimal para Binario" << endl;
        cout << "[7] Binario para Hexadecimal" << endl;
        cout << "[8] Hexadecimal para Binario" << endl;
        cout << "[9] Sair do programa" << endl;
        cout << "Sua escolha: ";
        cin >> opcao;

        // if especial por conta do hexadecimal
        if (opcao >=1 && opcao <= 7){
            cout << "Digite o valor a ser convertido: ";
            cin >> valor;

        if (valor < 0) {
            cout << "Nao eh possivel executar numeros negativos. Tente novamente: ";
            continue;
        }
    }
        switch (opcao){
        case 1: 
        {
            cout << "O valor quartenario de " << valor << " eh: " << binParaQuart(valor) << endl;
            break;
        }
        case 2:
        {
            cout << "O valor binario de " << valor << " eh: " << quartParaBin(valor) << endl;
            break;
        }
        case 3:
        {
            cout << "O valor o octal de " << valor << " eh: " << binParaOctal(valor) << endl;
            break;
        }
        case 4:
        {
            cout << "O valor binario de " << valor << " eh: " << octalParaBin(valor) << endl;
            break;
        }
        case 5:
        {
            cout << "O valor decimal de " << valor << " eh: " << binParaDecimal(valor) << endl;
            break;
        }
        case 6:
        {
            cout << "O valor binario de " << valor << " eh: " << decimalParaBin(valor) << endl;
            break;
        }
        case 7:
        {
            cout << "O valor hexadecimal de " << valor << " eh: " << binParaHexa(valor) << endl;
            break;
        }
        case 8:
        {
            string valorHexa;
            cout << "Digite o valor a ser convertido: ";
            cin >> valorHexa;
            cout << "O valor binario de " << valorHexa << " eh: " << hexaParaBin(valorHexa) << endl;
            break;
        }
        case 9:{
            cout << "Saindo do programa...";
            break;
        }
            default:
                cout << "Opção inválida.";
                break;
        } 
    } while (opcao != 9);
    return 0;
}
