#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// base 2
// base 4
// base 8
// base 10
// base 16


string decParaHex(string nTexto){
	unsigned long long n, quociente, resto;
	string novaEntradaTexto = "", resultadoH;
	//limpar entrada nTexto
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '0' || nTexto[i] == '1' || nTexto[i] == '2'
			|| nTexto[i] == '3' || nTexto[i] == '4' || nTexto[i] == '5'
			|| nTexto[i] == '6' || nTexto[i] == '7' || nTexto[i] == '8'
			|| nTexto[i] == '9'){
				novaEntradaTexto += nTexto[i];
			}
	}
	//

	if (novaEntradaTexto.length() > 19){
			novaEntradaTexto = novaEntradaTexto.substr(0, 19);
			cout << "Excedeu 19 digitos, pegara so os primeiros 19 digitos. Sua nova entrada eh: " << endl;
			cout << novaEntradaTexto << endl;
		}

		n = stoull(novaEntradaTexto); //mudar tipo da variavel de texto para unsigned long long
		//decimal para hex
		quociente = n;
		while (n > 0){
			quociente = n/16;
			resto = n%16;
			n = quociente;
			if (resto == 10){
				resultadoH += "A";
			}else if (resto == 11){
				resultadoH += "B";
			}else if (resto == 12){
				resultadoH += "C";
			}else if (resto == 13){
				resultadoH += "D";
			}else if (resto == 14){
				resultadoH += "E";
			}else if (resto == 15){
				resultadoH += "F";
			}else{
				resultadoH += to_string(resto);
			}
		}
	reverse(resultadoH.begin(), resultadoH.end()); //Inverter o resultado hexadecimal

	return resultadoH;
}

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

string binParaHex(string nTexto){
	string entradaLimpa = "", grupoBin = "", resultado = "";
	unsigned long long valorGrupoDec;
	int a, b, nUsados = 0;
	bool separando_grupos = true;
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '1' || nTexto[i] == '0'){
			entradaLimpa += nTexto[i];
		}
	}
	// entrada teste: 101010100
	a = entradaLimpa.length()-4;
	b = 4;
	if (a < 4){
		a = 0;
		b = entradaLimpa.length();
	}
	
	while (separando_grupos){
		grupoBin = entradaLimpa.substr(a, b);
		//Código para converter em hex
		valorGrupoDec = 0;
		reverse(grupoBin.begin(), grupoBin.end()); // inverter grupo (texto)
		for (int i=0; i < grupoBin.length(); i++){
			valorGrupoDec += pow(2, i) * (grupoBin[i] - '0');
		}
		if (valorGrupoDec == 10){
			resultado += 'A';
		}else if (valorGrupoDec == 11){
			resultado += 'B';
		}else if (valorGrupoDec == 12){
			resultado += 'C';
		}else if (valorGrupoDec == 13){
			resultado += 'D';
		}else if (valorGrupoDec == 14){
			resultado += 'E';
		}else if (valorGrupoDec == 15){
			resultado += 'F';
		}else{
			resultado += to_string(valorGrupoDec);
		}
		//
		if (a < 4 && a > 0){
			b = a;
			a = 0;
		}else{
			a -= 4;
		}
		nUsados += grupoBin.length();
		if (nUsados >= entradaLimpa.length()){
			separando_grupos = false;
		}
	}
	reverse(resultado.begin(), resultado.end());
	return resultado;
}

string hexParaBin(string nTexto){
	string resultado = "", entradaLimpa, restosE; //restosE=restos de cada elemento hexadecimal
	unsigned long long quociente;
	//limpar entrada
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '0' || nTexto[i] == '1' || nTexto[i] == '2'
			|| nTexto[i] == '3' || nTexto[i] == '4' || nTexto[i] == '5'
			|| nTexto[i] == '6' || nTexto[i] == '7' || nTexto[i] == '8'
			|| nTexto[i] == '9'){
				entradaLimpa += nTexto[i];
			}
		if(nTexto[i] == 'A' || nTexto[i] == 'a'){
			entradaLimpa += "A";
		}
		if(nTexto[i] == 'B' || nTexto[i] == 'b'){
			entradaLimpa += "B";
		}
		if(nTexto[i] == 'C' || nTexto[i] == 'c'){
			entradaLimpa += "C";
		}
		if(nTexto[i] == 'D' || nTexto[i] == 'd'){
			entradaLimpa += "D";
		}
		if(nTexto[i] == 'E' || nTexto[i] == 'e'){
			entradaLimpa += "E";
		}
		if(nTexto[i] == 'F' || nTexto[i] == 'f'){
			entradaLimpa += "F";
		}
	}
	//
	//converter para binario
	for (int i=0; i < entradaLimpa.length(); i++){
		//Converter letras para numeros
		if (entradaLimpa[i] == 'A'){
			quociente = 10;
		}else if(entradaLimpa[i] == 'B'){
			quociente = 11;
		}else if(entradaLimpa[i] == 'C'){
			quociente = 12;
		}else if(entradaLimpa[i] == 'D'){
			quociente = 13;
		}else if(entradaLimpa[i] == 'E'){
			quociente = 14;
		}else if(entradaLimpa[i] == 'F'){
			quociente = 15;
		}else{
			quociente = (entradaLimpa[i] - '0'); //converter string para int
		}
		//
		while (quociente > 0){
			restosE += to_string(quociente%2);
			quociente = quociente/2;
		}
		while (restosE.length() < 4){
			restosE += "0";
		}
		reverse(restosE.begin(), restosE.end());

		resultado += restosE;
		restosE = "";
	}
	//
	return resultado;
}

string b4ParaHex(string nTexto){
	string entradaLimpa = "", resultado = "";
	int n1, n2, r = 0, i=0, soma;
	for (int i=0; i < nTexto.length(); i++){
		if (nTexto[i] == '0' || nTexto[i] == '1' || nTexto[i] == '2' || nTexto[i] == '3'){
			entradaLimpa += nTexto[i];
		}
	}
	if (entradaLimpa.length() <= 0){
		return "Entrada vazia";
	}
	// calculo
	r = entradaLimpa.length()%2;
	while (i < entradaLimpa.length()){
	 	if (r !=0 && i == 0){
	 		n1 = 0;
	 		n2 = entradaLimpa[i] - '0';
	 		i += 1;
	 	}else {
	 		n1 = entradaLimpa[i] - '0';
	 		n2 = entradaLimpa[i+1] - '0';
	 		i += 2;
	 	}
	 	n1 = pow(4,1) * n1;
	 	n2 = pow(4,0) * n2;
	 	soma = n1+n2;
	 	if (soma == 10){
	 		resultado +=  'A';
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
	// fim calculo
	return resultado;
}

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

int main(){
	unsigned long long resultadoD;
	int op;
	string nTexto, resultadoH, resultado; //nTexto = entrada do usuário em modo string/texto
	
	cout << "O que você quer fazer? (1-decimal para hex; 2-hex para decimal; 3-binario para hexadecimal; 4-hex para binario; 5-base4 para hexadecimal; 6-hexadecimal para b4)" << endl;
	cin >> op;

	switch (op){
		case 1: // decimal para hexadecimal
		cout << "Coloque o numero que sera convertido (Aguenta no maximo 19 digitos): " << endl;
		cin >> nTexto; //numero teste: 2019037120983812738912098912839012

		resultadoH = decParaHex(nTexto);
		cout << "o resultado da conversao decimal para hexadecimal eh: " << resultadoH << endl;
		break;
		
		case 2: //Hex para decimal
		cout << "Coloque o valor hexadecimal que sera convertido: " << endl;
		cin >> nTexto;

		resultadoD = hexParaDec(nTexto);
		cout << "o resultado da conversao de hexadecimal para decimal eh: " << resultadoD << endl;
		break;

		case 3:
		cout << "Coloque o valor binario que sera convertido: " << endl;
		cin >> nTexto;

		resultado = binParaHex(nTexto);
		cout << "o resultado da conversao de binario para hexadecimal eh: " << resultado << endl;
		break;

		case 4:
		cout << "Coloque o valor hexadecimal que sera convertido: " << endl;
		cin >> nTexto; //entradas testes: 1; 

		resultado = hexParaBin(nTexto);
		cout << "o resultado da conversao de hexadecimal para binario eh: " << resultado << endl;
		break;

		case 5:
		cout << "Coloque o valor de base 4 que sera convertido: " << endl;
		cin >> nTexto; //entradas testes: 312

		resultado = b4ParaHex(nTexto);
		cout << "o resultado da conversao da base 4 para hexadecimal eh: " << resultado << endl;
		break;

		case 6:
		cout << "Coloque o valor hexadecimal que sera convertido: " << endl;
		cin >> nTexto; //entradas testes: 3E

		resultado = hexParaB4(nTexto);
		cout << "o resultado da conversao de hexadecimal para base 4 eh: " << resultado << endl;
		break;
	}
	
}