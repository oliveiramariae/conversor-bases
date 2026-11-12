Conversor de Base Quaternária em C++

Programa de console que converte números da Base Quaternária (Base 4) para Decimal (Base 10), Binário (Base 2), Octal (Base 8) e Hexadecimal (Base 16).

Funcionalidades
Menu interativo: permite fazer várias conversões sem reiniciar o programa.
Conversões suportadas:
Quaternário -> Decimal
Quaternário -> Binário
Quaternário -> Octal
Quaternário -> Hexadecimal
Validação de entrada:
Aceita apenas os dígitos 0, 1, 2 e 3, com no máximo 32 dígitos (limite do unsigned long long).
Se o usuário digitar letras na opção do menu, o programa limpa a entrada e volta ao menu.

Como compilar e executar
g++ -std=c++11 quartenario.cpp -o quartenario
Linux/macOS: ./quartenario
Windows: quartenario.exe

Como funciona
ehQuaternario(): confere se o texto digitado só tem dígitos de 0 a 3.
quartParaDec(): percorre os dígitos da esquerda para a direita, fazendo decimal = decimal * 4 + dígito.
decParaBase(): divisões sucessivas pela base desejada (2, 8 ou 16), guardando os restos (0-9 e A-F).
Todas as conversões passam primeiro pelo decimal.

Exemplo de uso
--- Conversor Quartenario (Base 4) ---
[1] Quartenario para Decimal
[2] Quartenario para Binario
[3] Quartenario para Octal
[4] Quartenario para Hexadecimal
[5] Sair
Sua escolha: 4
Digite o numero quartenario: 3333
O valor hexadecimal de 3333 eh: FF
