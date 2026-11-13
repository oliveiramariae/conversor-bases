#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// ==========================================================
// CONVERSOR OCTAL - junta as partes de cada pasta do projeto
//
// BINARIO     : binParaOctal e octalParaBin
// DECIMAL     : decParaOctal e octalParaDec
// HEXADECIMAL : b8paraB16 (octal para hexa) e hexParaB8 (hexa para octal)
// QUARTENARIO : octalParaQuart e quartParaOctal
//
// As funcoes das outras pastas foram copiadas como estavam.
// ==========================================================

// ==========================================================
// PARTE DO BINARIO (pasta BINARIO)
// ==========================================================

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

// ==========================================================
// PARTE DO DECIMAL (pasta DECIMAL)
// ==========================================================

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

// ==========================================================
// PARTE DO HEXADECIMAL (pasta HEXADECIMAL)
// ==========================================================

string limparEntradaB8(string entrada){
    string entradaLimpa = "";
    char caractere;
    for (int i=0; i < entrada.length(); i++){
        caractere = entrada[i];
        if (caractere == '0' || caractere == '1' || caractere == '2' || caractere == '3' ||
            caractere == '4' || caractere == '5' || caractere == '6' || caractere == '7' ){
                entradaLimpa += caractere;
            }
    }
    return entradaLimpa;
}

// octal para hexadecimal
string b8paraB16(string entrada){
    string entradaLimpa = limparEntradaB8(entrada), resultado = "", resGrupo = "", resBin = "";
    int quociente, resto, soma;
    //
    for (int i = 0; i < entradaLimpa.length(); i++){
        quociente = entradaLimpa[i] - '0';
        while (quociente >= 1){
            resto = quociente%2;
            resGrupo = to_string(resto) + resGrupo; // CORRIGIDO: era "resGrupo += to_string(resto);" e deixava os bits de tras para frente (octal 2, 4 e 6 saiam errados)
            quociente = quociente/2;
        }
        while (resGrupo.length() < 3){
            resGrupo = "0" + resGrupo;
        }
        resBin += resGrupo;
        resGrupo = "";
    }
    //===
    while (resBin.length()%4 != 0){
        resBin = "0" + resBin;
    }
    for (int i=0; i < resBin.length(); i+=4){
        soma = 0;
        soma += (resBin[i]-'0') * pow(2, 3);
        soma += (resBin[i+1]-'0') * pow(2, 2);
        soma += (resBin[i+2]-'0') * pow(2, 1);
        soma += (resBin[i+3]-'0') * pow(2, 0);

        if (soma == 10){
            resultado += 'A';
        }else if (soma == 11){
            resultado += 'B';
        }else if (soma == 12){
            resultado += 'C';
        }else if (soma == 13){
            resultado += 'D';
        }else if (soma == 14){
            resultado += 'E';
        }else if (soma == 15){
            resultado += 'F';
        }else{
            resultado += to_string(soma);
        }
    }
    // (o cout que ficava aqui foi tirado: quem mostra o resultado eh o main)
    return resultado;
}

string limparEntradaB16(string nTexto){
	string entradaLimpa = "";
	char caractere;
	for (int i=0; i < nTexto.length(); i++){
		caractere = nTexto[i];
		if (caractere == 'a' || caractere == 'A'){
			entradaLimpa += 'A';
		}else if(caractere == 'b' || caractere == 'B'){
			entradaLimpa += 'B';
		}else if(caractere == 'c' || caractere == 'C'){
			entradaLimpa += 'C';
		}else if(caractere == 'd' || caractere == 'D'){
			entradaLimpa += 'D';
		}else if(caractere == 'e' || caractere == 'E'){
			entradaLimpa += 'E';
		}else if(caractere == 'f' || caractere == 'F'){
			entradaLimpa += 'F';
		}else if (caractere == '0' || caractere == '1' || caractere == '2' || caractere == '3'
				|| caractere == '4' || caractere == '5' || caractere == '6' || caractere == '7'
				|| caractere == '8' || caractere == '9' ){
			entradaLimpa += caractere;
		}
	}
	return entradaLimpa;
}

// base 16 - base 2 (usada pelo hexParaB8)
string hexParaBin(string nTexto){
	string entradaLimpa = limparEntradaB16(nTexto), resultado = "", restosQ = "";
	char caractere;
	int resto;
	unsigned long long quociente;

	if (entradaLimpa.length() <= 0){
		return "vazio";
	}
	for (int i=0; i < entradaLimpa.length(); i++){
		caractere = entradaLimpa[i];
		if (caractere == 'A'){
			quociente = 10;
		}else if(caractere == 'B'){
			quociente = 11;
		}else if(caractere == 'C'){
			quociente = 12;
		}else if(caractere == 'D'){
			quociente = 13;
		}else if(caractere == 'E'){
			quociente = 14;
		}else if(caractere == 'F'){
			quociente = 15;
		}else{
			quociente = caractere - '0';
		}
		while (quociente >= 1){
			resto = quociente%2;
			restosQ = to_string(resto) + restosQ;
			quociente = quociente/2;
		}
		while (restosQ.length() < 4){
			restosQ = "0" + restosQ;
		}
		resultado += restosQ;
		restosQ = "";
	}
	return resultado;
}

// hexadecimal para octal
string hexParaB8(string nTexto){
	string entradaLimpa = limparEntradaB16(nTexto), resBin = "", resultado = "";
	int soma = 0;
	if (entradaLimpa.length() <= 0){
		return "entrada vazia";
	}
	//Converter cada digito hexadecimal para 4 bits binario
	for (int i=0; i < entradaLimpa.length(); i++){
		resBin += hexParaBin(string(1, entradaLimpa[i]));
	}
	while (resBin.length()%3 != 0){
		resBin = "0" + resBin;
	}
	for (int i=0; i < resBin.length(); i+=3){
		soma += (resBin[i] - '0') * pow(2, 2);
		soma += (resBin[i+1] - '0') * pow(2, 1);
		soma += (resBin[i+2] - '0') * pow(2, 0);

		resultado += to_string(soma);
		soma = 0;
	}
	return resultado;
}

// ==========================================================
// PARTE DO QUARTENARIO (pasta QUARTENARIO)
// ==========================================================

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

// octal para quartenario: usa o octalParaDec do DECIMAL e depois divide por 4
string octalParaQuart(string octal)
{
    return decParaBase(octalParaDec(octal), 4);
}

// quartenario para octal: vai para decimal e depois divide por 8
string quartParaOctal(string quartenario)
{
    return decParaBase(quartParaDec(quartenario), 8);
}

// ==========================================================
// AUXILIARES DO MENU
// ==========================================================

// confere se o texto so tem os digitos permitidos (ex.: "01" para binario)
bool soTem(string texto, string permitidos)
{
    if (texto.length() == 0)
    {
        return false;
    }

    for (int i = 0; i < texto.length(); i++)
    {
        if (permitidos.find(texto[i]) == string::npos)
        {
            return false;
        }
    }

    return true;
}

// tira os zeros da esquerda (deixa um zero se o numero for 0)
string tirarZeros(string texto)
{
    while (texto.length() > 1 && texto[0] == '0')
    {
        texto.erase(0, 1);
    }

    return texto;
}

// ==========================================================
// MENU PRINCIPAL
// ==========================================================

int main()
{
    int opcao;
    string numero, resultado;

    do
    {
        cout << "\n--- Conversor Octal (Base 8) ---" << endl;
        cout << "[1] Octal para Binario" << endl;
        cout << "[2] Binario para Octal" << endl;
        cout << "[3] Octal para Decimal" << endl;
        cout << "[4] Decimal para Octal" << endl;
        cout << "[5] Octal para Hexadecimal" << endl;
        cout << "[6] Hexadecimal para Octal" << endl;
        cout << "[7] Octal para Quartenario" << endl;
        cout << "[8] Quartenario para Octal" << endl;
        cout << "[9] Sair" << endl;
        cout << "Sua escolha: ";

        // se digitar letra, limpa a entrada e volta pro menu
        if (!(cin >> opcao))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = 0;
        }

        if (opcao >= 1 && opcao <= 8)
        {
            cout << "Digite o numero: ";
            cin >> numero;
            resultado = "";

            switch (opcao)
            {
            case 1: // a funcao guarda o binario num long long: no maximo 6 digitos octais
                if (soTem(numero, "01234567") && numero.length() <= 6)
                {
                    resultado = to_string(octalParaBin(stoll(numero)));
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 7 (ate 6 digitos)." << endl;
                }
                break;

            case 2: // a funcao recebe o binario num long long: no maximo 19 digitos
                if (soTem(numero, "01") && numero.length() <= 19)
                {
                    resultado = to_string(binParaOctal(stoll(numero)));
                }
                else
                {
                    cout << "Numero invalido! Use so 0 e 1 (ate 19 digitos)." << endl;
                }
                break;

            case 3: // octal tem no maximo 21 digitos para caber no unsigned long long
                if (soTem(numero, "01234567") && numero.length() <= 21)
                {
                    resultado = to_string(octalParaDec(numero));
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 7 (ate 21 digitos)." << endl;
                }
                break;

            case 4: // decimal tem no maximo 19 digitos (limite do decParaOctal)
                if (soTem(numero, "0123456789") && numero.length() <= 19)
                {
                    resultado = decParaOctal(numero);
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 9 (ate 19 digitos)." << endl;
                }
                break;

            case 5:
                if (soTem(numero, "01234567"))
                {
                    resultado = tirarZeros(b8paraB16(numero));
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 7." << endl;
                }
                break;

            case 6:
                if (soTem(numero, "0123456789ABCDEFabcdef"))
                {
                    resultado = tirarZeros(hexParaB8(numero));
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 9 e letras de A a F." << endl;
                }
                break;

            case 7:
                if (soTem(numero, "01234567") && numero.length() <= 21)
                {
                    resultado = octalParaQuart(numero);
                }
                else
                {
                    cout << "Numero invalido! Use so digitos de 0 a 7 (ate 21 digitos)." << endl;
                }
                break;

            case 8:
                if (ehQuaternario(numero))
                {
                    resultado = quartParaOctal(numero);
                }
                else
                {
                    cout << "Numero invalido! Use so os digitos 0, 1, 2 e 3 (ate 32 digitos)." << endl;
                }
                break;
            }

            if (resultado != "")
            {
                cout << "Resultado: " << resultado << endl;
            }
        }
        else if (opcao == 9)
        {
            cout << "Saindo do programa..." << endl;
        }
        else
        {
            cout << "Opcao invalida." << endl;
        }

    } while (opcao != 9);

    return 0;
}
