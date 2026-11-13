# Conversor de Hexadecimal

Um programa desenvolvido em C++ que realiza a conversão de números hexadecimais para diferentes sistemas de numeração: decimal, binário, base 4 e octal (base 8).

# Funcionalidades

O programa apresenta um menu interativo para que o usuário selecione o tipo de conversão desejada:

Selecione uma opção:

1 - Hexadecimal para Decimal

2 - Hexadecimal para Binário

3 - Hexadecimal para Base 4

4 - Hexadecimal para Base 8

# Conversões disponíveis

Hexadecimal para Decimal: converte um número hexadecimal para o sistema decimal (base 10).

Hexadecimal para Binário: converte um número hexadecimal para o sistema binário (base 2).

Hexadecimal para Base 4: converte um número hexadecimal para o sistema de base 4.

Hexadecimal para Base 8: converte um número hexadecimal para o sistema octal (base 8).

# Validação de entrada

O programa possui um sistema de validação para identificar caracteres que não são compatíveis com o sistema hexadecimal.

Caso a entrada contenha algum caractere inválido, ela será limpa, impedindo que dados incorretos sejam utilizados durante a conversão.

# São considerados caracteres hexadecimais válidos:

Números de 0 a 9.
Letras de A a F.

# Observações e limitações

Conversão de hexadecimal para decimal:
Essa conversão pode apresentar limitações quando o resultado decimal ultrapassa aproximadamente 19 ou 20 dígitos. Isso ocorre devido à capacidade limitada dos tipos numéricos nativos do C++, que possuem um limite máximo de armazenamento. Dependendo do tipo de dado utilizado, valores muito grandes podem causar overflow, resultando em valores incorretos.