# Conversor de Bases Numéricas

Projeto em C++ feito. O programa converte números entre cinco bases numéricas.

## O que são bases numéricas?

É a forma de escrever os números usando uma quantidade diferente de símbolos:

| Base | Nome | Símbolos usados |
|------|------|-----------------|
| 2 | Binário | 0 e 1 |
| 4 | Quaternário | 0, 1, 2 e 3 |
| 8 | Octal | 0 a 7 |
| 10 | Decimal | 0 a 9 (o que usamos no dia a dia) |
| 16 | Hexadecimal | 0 a 9 e A a F |

Exemplo: o número 27 no decimal é `11011` no binário, `123` no quaternário, `33` no octal e `1B` no hexadecimal.

## Como o projeto está organizado

Cada pasta cuida de uma base e converte **a partir dela** para as outras:

| Pasta | O que faz |
|-------|-----------|
| `BINARIO` | Converte do binário para as outras bases |
| `QUARTENARIO` | Converte do quaternário para decimal, binário, octal e hexadecimal |
| `OCTAL` | Em andamento |
| `DECIMAL` | Converte do decimal para binário, quaternário, octal e hexadecimal |
| `HEXADECIMAL` | Converte do hexadecimal para as outras bases |

Dentro de cada pasta tem os arquivos `.cpp` (o código) e um `README.md` com mais detalhes.

## Como usar

1. Instale um compilador de C++ (por exemplo, o g++).
2. Abra o terminal na pasta da base que você quer testar.
3. Compile o arquivo. Exemplo com o quaternário:

   ```
   g++ quartenario.cpp -o quartenario
   ```

4. Execute o programa:

   - Linux ou Mac: `./quartenario`
   - Windows: `quartenario.exe`

5. Escolha a conversão no menu e digite o número.

## Integrantes

- Maria Eduarda (oliveiramariae) – BINARIO
- Carolina (carolinabertoli0911) – DECIMAL
-  – pasta responsável
- Anderson da Silva Assis (Anderson23A) - HEXADECIMAL
- Lucas da Silva Assis (lucasrcfm0) - QUARTENARIO
