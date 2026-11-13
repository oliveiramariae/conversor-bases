Conversor de Base Octal em C++

Programa de console que junta, em um único arquivo, as conversões de octal que cada integrante fez na sua pasta, mais a parte do quaternário. Ele converte entre a Base Octal (Base 8) e Binário, Decimal, Hexadecimal e Quaternário, nos dois sentidos.

De onde veio cada parte
Pasta BINARIO: binParaOctal (binário -> octal) e octalParaBin (octal -> binário).
Pasta DECIMAL: decParaOctal (decimal -> octal) e octalParaDec (octal -> decimal).
Pasta HEXADECIMAL: b8paraB16 (octal -> hexadecimal) e hexParaB8 (hexadecimal -> octal), com as funções de apoio limparEntradaB8, limparEntradaB16 e hexParaBin.
Pasta QUARTENARIO: ehQuaternario, quartParaDec e decParaBase, usadas por octalParaQuart (octal -> quaternário) e quartParaOctal (quaternário -> octal).

As funções das outras pastas foram copiadas como estavam. Só a função b8paraB16 teve duas mudanças:
1. O cout que mostrava o resultado dentro da função foi tirado, porque agora quem mostra o resultado é o menu (senão ele apareceria duas vezes).
2. Uma linha foi corrigida: os bits de cada dígito octal ficavam de trás para frente, e por isso octal 2, 4 e 6 davam resultado errado em hexadecimal. A linha está marcada com "CORRIGIDO" no código.

Funcionalidades
Menu interativo: permite fazer várias conversões sem reiniciar o programa.
Conversões suportadas:
Octal <-> Binário
Octal <-> Decimal
Octal <-> Hexadecimal
Octal <-> Quaternário
Validação de entrada:
Só aceita dígitos que existem na base escolhida (por exemplo, 8 e 9 não existem no octal).
No hexadecimal, aceita letras maiúsculas ou minúsculas.
Se o usuário digitar letra no menu, o programa limpa a entrada e volta ao menu.

Tamanho máximo do número
Algumas funções guardam o número em um tipo que tem limite, então cada conversão aceita até:
Octal -> Binário: 6 dígitos
Binário -> Octal: 19 dígitos
Octal -> Decimal: 21 dígitos
Decimal -> Octal: 19 dígitos
Octal -> Hexadecimal: sem limite
Hexadecimal -> Octal: sem limite
Octal -> Quaternário: 21 dígitos
Quaternário -> Octal: 32 dígitos

Como compilar e executar
g++ -std=c++11 conversor_octal.cpp -o conversor_octal
Linux/macOS: ./conversor_octal
Windows: conversor_octal.exe

Exemplo de uso
--- Conversor Octal (Base 8) ---
[1] Octal para Binario
[2] Binario para Octal
[3] Octal para Decimal
[4] Decimal para Octal
[5] Octal para Hexadecimal
[6] Hexadecimal para Octal
[7] Octal para Quartenario
[8] Quartenario para Octal
[9] Sair
Sua escolha: 5
Digite o numero: 377
Resultado: FF
