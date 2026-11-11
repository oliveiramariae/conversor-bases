#include <iostream>
#include <limits>
#include <cmath>

using namespace std;


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

string b8paraB16(string entrada){
    string entradaLimpa = limparEntradaB8(entrada), resultado = "", resGrupo = "", resBin = "";
    int quociente, resto, soma;
    //
    for (int i = 0; i < entradaLimpa.length(); i++){
        quociente = entradaLimpa[i] - '0';
        while (quociente >= 1){
            resto = quociente%2;
            resGrupo += to_string(resto);
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
    cout << resultado << endl;
    return resultado;
}

int main(){
    string entrada;

    cin >> entrada;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    b8paraB16(entrada);

    return 0;
}