# template_c
## [Estrutura simples](./c/README.md)
## [Estrutura SOLID](./c-solid/README.md)
## [Desafios](./challenges)

#### Printf  
| Especificador | Tipo esperado                                    | Exemplo de uso                             | Saída                  |
| ------------- | ------------------------------------------------ | ------------------------------------------ | ---------------------- |
| `%d`          | `int` (decimal com sinal)                        | `printf("%d", -42);`                       | `-42`                  |
| `%i`          | `int` (igual a %d)                               | `printf("%i", 42);`                        | `42`                   |
| `%u`          | `unsigned int`                                   | `printf("%u", 42u);`                       | `42`                   |
| `%ld`         | `long int`                                       | `printf("%ld", 123456789L);`               | `123456789`            |
| `%lu`         | `unsigned long int`                              | `printf("%lu", 4000000000UL);`             | `4000000000`           |
| `%lld`        | `long long int`                                  | `printf("%lld", 9223372036854775807LL);`   | `9223372036854775807`  |
| `%llu`        | `unsigned long long int`                         | `printf("%llu", 18446744073709551615ULL);` | `18446744073709551615` |
| `%f`          | `float` ou `double`                              | `printf("%f", 3.1415);`                    | `3.141500`             |
| `%lf`         | `double` (igual a %f)                            | `printf("%lf", 2.71828);`                  | `2.718280`             |
| `%e` / `%E`   | `float` ou `double` (notação científica)         | `printf("%e", 3.14);`                      | `3.140000e+00`         |
| `%g` / `%G`   | `float` ou `double` (auto formato entre %f e %e) | `printf("%g", 3.14);`                      | `3.14`                 |
| `%c`          | `char`                                           | `printf("%c", 'A');`                       | `A`                    |
| `%s`          | `char *` (string)                                | `printf("%s", "texto");`                   | `texto`                |
| `%p`          | ponteiro (endereços de memória)                  | `printf("%p", texto);`                     | `0x7ffeefbff618`       |
| `%x` / `%X`   | `unsigned int` (hexadecimal)                     | `printf("%x", 255);`                       | `ff`                   |
| `%o`          | `unsigned int` (octal)                           | `printf("%o", 8);`                         | `10`                   |
| `%zu`         | `size_t` (tamanho de objeto)                     | `printf("%zu", strlen(texto));`            | `12`                   |
| `%%`          | Imprime o símbolo `%`                            | `printf("%%");`                            | `%`                    |

#### Principais bibliotecas e funções  

##### 1. <stdio.h> — Standard Input/Output
Funções de entrada e saída (tela, teclado e arquivos)
| Função                    | O que faz                                   |
| ------------------------- | ------------------------------------------- |
| `printf()`                | Imprime dados formatados na tela            |
| `scanf()`                 | Lê dados do teclado formatados              |
| `puts()`                  | Imprime uma string com `\n` automático      |
| `gets()` ❌               | (insegura, não usar — use `fgets()`)        |
| `fgets()`                 | Lê uma linha com limite de tamanho          |
| `putchar()` / `getchar()` | Imprime / lê um caractere                   |
| `fprintf()` / `fscanf()`  | Entrada e saída formatada em arquivos       |
| `fopen()` / `fclose()`    | Abre / fecha arquivos                       |
| `fread()` / `fwrite()`    | Lê / escreve blocos binários                |
| `fseek()` / `ftell()`     | Move e obtém posição do ponteiro do arquivo |
| `perror()`                | Exibe uma mensagem de erro no `stderr`      |

##### 2. <stdlib.h> — Standard Library (geral e memória)
Controle de memória, conversões, aleatoriedade e sistema
| Função                         | O que faz                                           |
| ------------------------------ | --------------------------------------------------- |
| `malloc()` / `calloc()`        | Aloca memória dinâmica                              |
| `realloc()`                    | Redimensiona memória alocada                        |
| `free()`                       | Libera memória                                      |
| `exit()`                       | Finaliza o programa                                 |
| `atoi()`, `atof()`, `strtol()` | Convertem strings para números                      |
| `rand()` / `srand()`           | Geração de números aleatórios                       |
| `system()`                     | Executa comandos do sistema (ex: `system("clear")`) |
| `abs()` / `labs()`             | Valor absoluto                                      |

##### 3. <string.h> — Manipulação de strings
Ferramentas para lidar com char[]
| Função                   | O que faz                              |
| ------------------------ | -------------------------------------- |
| `strlen()`               | Retorna o tamanho da string            |
| `strcpy()` / `strncpy()` | Copia strings                          |
| `strcat()` / `strncat()` | Concatena strings                      |
| `strcmp()` / `strncmp()` | Compara strings                        |
| `strchr()` / `strrchr()` | Procura um caractere                   |
| `strstr()`               | Procura uma substring                  |
| `strtok()`               | Quebra string em tokens                |
| `memcpy()` / `memmove()` | Copia blocos de memória                |
| `memset()`               | Preenche bloco de memória com um valor |
| `strcspn()` / `strspn()` | Busca trechos com certos caracteres    |

##### 4. <math.h> — Funções matemáticas
Operações matemáticas e trigonométricas
| Função                         | O que faz                        |
| ------------------------------ | -------------------------------- |
| `sqrt()`                       | Raiz quadrada                    |
| `pow()`                        | Potência                         |
| `sin()` / `cos()` / `tan()`    | Funções trigonométricas          |
| `asin()` / `acos()` / `atan()` | Inversas trigonométricas         |
| `log()` / `log10()`            | Logaritmos                       |
| `exp()`                        | Exponencial                      |
| `ceil()` / `floor()`           | Arredondamento para cima / baixo |
| `fabs()`                       | Valor absoluto de número real    |
| `fmod()`                       | Resto da divisão real            |

##### 5. <time.h> — Tempo e datas
Trabalhar com horas, datas e medição de tempo
| Função                     | O que faz                                      |
| -------------------------- | ---------------------------------------------- |
| `time()`                   | Retorna o tempo atual (em segundos desde 1970) |
| `localtime()` / `gmtime()` | Converte `time_t` em data legível              |
| `strftime()`               | Formata data/hora em string                    |
| `clock()`                  | Mede tempo de execução do programa             |
| `difftime()`               | Calcula diferença entre dois tempos            |

##### 6. <ctype.h> — Classificação e conversão de caracteres
Trabalha com letras, números e símbolos individuais
| Função                    | O que faz                         |
| ------------------------- | --------------------------------- |
| `isalpha()`               | É letra?                          |
| `isdigit()`               | É número?                         |
| `isalnum()`               | É letra ou número?                |
| `isspace()`               | É espaço, tab ou quebra de linha? |
| `islower()` / `isupper()` | É minúscula / maiúscula?          |
| `tolower()` / `toupper()` | Converte case                     |
| `ispunct()`               | É pontuação?                      |

##### 7. <stdbool.h> — Tipo booleano
Introduz bool, true, false
#include <stdbool.h>
bool ativo = true;
if (ativo) printf("Ligado!\n");

##### 8. <assert.h> — Depuração e testes
Garante que certas condições sejam verdadeiras
| Função         | O que faz                                 |
| -------------- | ----------------------------------------- |
| `assert(expr)` | Interrompe o programa se `expr` for falsa |
Ex: `assert(ptr != NULL);`

##### 9. <errno.h> — Tratamento de erros globais
| Função / variável | O que faz                         |
| ----------------- | --------------------------------- |
| `errno`           | Variável global com o último erro |
| `perror()`        | Imprime mensagem de erro amigável |
| `strerror(errno)` | Retorna string do erro atual      |

##### 10. Extras úteis
| Biblioteca   | Uso                                                          |
| ------------ | ------------------------------------------------------------ |
| `<limits.h>` | Limites de tipos inteiros (`INT_MAX`, `CHAR_MIN`, etc.)      |
| `<float.h>`  | Limites de tipos float/double (`FLT_MAX`, `DBL_MIN`, etc.)   |
| `<stdint.h>` | Tipos inteiros com tamanho fixo (`int8_t`, `uint32_t`, etc.) |
| `<signal.h>` | Tratamento de sinais do sistema (ex: Ctrl+C)                 |
