#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// base 16 - base 10
// base 16 - base 2
// base 16 - base 4
// base 16 - base 8

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
	cout << entradaLimpa << endl;
	return entradaLimpa;
}

// base 16 - base 10
unsigned long long hexParaDec(string nTexto){
	unsigned long long uhd = 1, resultadoD = 0; //uhd=unidade/elemento hexadecimal
	int nHex;
	string novaEntradaTexto = "", nTHex;
	//limpar entrada
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '0' || nTexto[i] == '1' || nTexto[i] == '2'
			|| nTexto[i] == '3' || nTexto[i] == '4' || nTexto[i] == '5'
			|| nTexto[i] == '6' || nTexto[i] == '7' || nTexto[i] == '8'
			|| nTexto[i] == '9'){
				novaEntradaTexto += nTexto[i];
			}
		if(nTexto[i] == 'A' || nTexto[i] == 'a'){
			novaEntradaTexto += "A";
		}
		if(nTexto[i] == 'B' || nTexto[i] == 'b'){
			novaEntradaTexto += "B";
		}
		if(nTexto[i] == 'C' || nTexto[i] == 'c'){
			novaEntradaTexto += "C";
		}
		if(nTexto[i] == 'D' || nTexto[i] == 'd'){
			novaEntradaTexto += "D";
		}
		if(nTexto[i] == 'E' || nTexto[i] == 'e'){
			novaEntradaTexto += "E";
		}
		if(nTexto[i] == 'F' || nTexto[i] == 'f'){
			novaEntradaTexto += "F";
		}
	}
	// fim limpar entrada

	reverse(novaEntradaTexto.begin(), novaEntradaTexto.end());// inverter entrada do usuário
	for (int i=0; i < novaEntradaTexto.length(); i++){
		nTHex = novaEntradaTexto[i];
		if (nTHex == "A"){
			nHex = 10;
		}else if (nTHex == "B"){
			nHex = 11;
		}else if (nTHex == "C"){
			nHex = 12;
		}else if (nTHex == "D"){
			nHex = 13;
		}else if (nTHex == "E"){
			nHex = 14;
		}else if (nTHex == "F"){
			nHex = 15;
		}else{
			nHex = stoi(nTHex);
		}
		uhd = pow(16, i) * nHex;
		resultadoD += uhd;
	}
	reverse(novaEntradaTexto.begin(), novaEntradaTexto.end()); //inverter2 entrada do usuário
	return resultadoD;
}

// base 16 - base 2
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

// base 16 - base 4
string hexParaB4(string nTexto){
	string entradaLimpa = "", resultado = "", restosD;
	int quociente, resto;
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '0' || nTexto[i] == '1'  || nTexto[i] == '2'
			|| nTexto[i] == '3' || nTexto[i] == '4'  || nTexto[i] == '5'
			|| nTexto[i] == '6' || nTexto[i] == '7' || nTexto[i] == '8' || nTexto[i] == '9'){
				entradaLimpa += nTexto[i];
		}else if (nTexto[i] == 'A' || nTexto[i] == 'a'){
			entradaLimpa += 'A';
		}else if (nTexto[i] == 'B' || nTexto[i] == 'b'){
			entradaLimpa += 'B';
		}else if (nTexto[i] == 'C' || nTexto[i] == 'c'){
			entradaLimpa += 'C';
		}else if (nTexto[i] == 'D' || nTexto[i] == 'd'){
			entradaLimpa += 'D';
		}else if (nTexto[i] == 'E' || nTexto[i] == 'e'){
			entradaLimpa += 'E';
		}else if (nTexto[i] == 'F' || nTexto[i] == 'f'){
			entradaLimpa += 'F';
		}
	}
	if (entradaLimpa.length() <= 0){
		return "entrada vazia";
	}
	for (int i=0; i < entradaLimpa.length(); i++){
		if (entradaLimpa[i] == 'A'){
			quociente = 10;
		}else if (entradaLimpa[i] == 'B'){
			quociente = 11;
		}else if (entradaLimpa[i] == 'C'){
			quociente = 12;
		}else if (entradaLimpa[i] == 'D'){
			quociente = 13;
		}else if (entradaLimpa[i] == 'E'){
			quociente = 14;
		}else if (entradaLimpa[i] == 'F'){
			quociente = 15;
		}else{
			quociente = entradaLimpa[i] - '0';
		}
		restosD = "";
		while (quociente >= 1){
			resto = quociente%4;
			restosD += to_string(resto);
			quociente = quociente/4;
		}
		while (restosD.length() < 2){
			restosD += "0";
		}
		reverse(restosD.begin(), restosD.end());
		resultado += restosD;
	}
	return resultado;
}

string hexParaB8(string nTexto){
	string entradaLimpa = nTexto, resBin = "", resultado = "";
	int soma = 0;
	//Converter cada digito hexadecimal para 4 bits binario
	for (int i=0; i < entradaLimpa.length(); i++){
		resBin += hexParaBin(string(1, entradaLimpa[i]));
	}
	while (resBin.length()%3 != 0){
		resBin = "0" + resBin;
	}
	cout << resBin;
	for (int i=0; i < resBin.length(); i+=3){
		soma += (resBin[i] - '0') * pow(2, 2);
		soma += (resBin[i+1] - '0') * pow(2, 1);
		soma += (resBin[i+2] - '0') * pow(2, 0);

		resultado += to_string(soma);
		soma = 0;
	}
	return resultado;
}

int main(){
	unsigned long long resultadoD;
	int op;
	string nTexto, resultadoH, resultado; //nTexto = entrada do usuário em modo string/texto
	
	cout << "O que voce quer fazer? (1-hex para decimal; 2-hex para binario; 3-hexadecimal para base4; 4-hexadecimal para base8)" << endl;
	cin >> op;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (op){

		case 1:
		cout << "Coloque o valor hexadecimal que sera convertido: " << endl;
		getline(cin, nTexto);

		resultadoD = hexParaDec(nTexto);
		cout << "o resultado da conversao de hexadecimal para decimal eh: " << resultadoD << endl;
		break;

		case 2:
		cout << "Coloque o valor hexadecimal que sera convertido para binario: " << endl;
		getline(cin, nTexto); 

		resultado = hexParaBin(nTexto);
		cout << "o resultado da conversao de hexadecimal para binario eh: " << resultado << endl;
		break;


		case 3:
		cout << "Coloque o valor hexadecimal que sera convertido: " << endl;
		getline(cin, nTexto);

		resultado = hexParaB4(nTexto);
		cout << "o resultado da conversao de hexadecimal para base 4 eh: " << resultado << endl;

		case 4:
		cout << "Coloque o valor hexadecimal que sera convertido para base 8: " << endl;
		getline(cin, nTexto);

		resultado = hexParaB8(nTexto);
		cout << "o resultado da conversao de hexadecimal para base 8 eh: " << resultado << endl;
		break;
	}
	
}