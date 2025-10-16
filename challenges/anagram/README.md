# 🧩 Exercício: Verificar se duas strings são Anagramas

## 📄 Descrição

O objetivo deste exercício é implementar uma função em **C** que verifica se **duas strings são anagramas**.

Duas palavras são consideradas **anagramas** quando contêm exatamente as mesmas letras, com a mesma quantidade de ocorrências, mas possivelmente em ordens diferentes.

Exemplos de anagramas:

* `amor` e `roma`
* `listen` e `silent`
* `eleven plus two` e `twelve plus one`

---

## ⚙️ Lógica do Algoritmo

1. **Normalizar strings:** remover espaços e converter todos os caracteres para minúsculas.
2. **Verificar tamanhos:** se as duas strings tiverem comprimentos diferentes após a normalização, elas **não podem ser anagramas**.
3. **Criar um vetor de frequência:** use um vetor de 256 posições (para cobrir a tabela ASCII), inicializado com zero.
4. **Contar caracteres da primeira string:** incremente `freq[c]` para cada caractere.
5. **Subtrair caracteres da segunda string:** para cada caractere, decrete `freq[c]--`.
6. **Verificar o vetor:** se, ao final, todas as posições estiverem zeradas, as strings são anagramas.

---

## 💡 Observações Importantes

* O código considera diferenciação entre maiúsculas e minúsculas. Para ignorar isso, converta ambas as strings para minúsculas usando `tolower()` da biblioteca `<ctype.h>`.
* Espaços e pontuações são ignorados na contagem.
* Use `size_t` para índices de loops quando iterar sobre strings ou arrays cujo tamanho é dinâmico.
* Para arrays de tamanho fixo pequeno, como `freq[256]`, `int` é suficiente.

---

## 🧪 Casos de Teste Sugeridos

| String A | String B  | Resultado Esperado                             |
| -------- | --------- | ---------------------------------------------- |
| `amor`   | `roma`    | ✅ São anagramas                               |
| `arara`  | `raara`   | ✅ São anagramas                               |
| `listen` | `silent`  | ✅ São anagramas                               |
| `test`   | `ttew`    | ❌ Não são anagramas                           |
| `Ana`    | `naa`     | ✅ (se ignorar maiúsculas)                     |
| `Amor 1` | `1  Roma` | ✅ São anagramas (ignorando espaços e números) |

---

## 🧰 Bibliotecas Utilizadas

* `<stdio.h>`: entrada e saída padrão (`printf`, `scanf`)
* `<stdlib.h>`: para `malloc` e `free`
* `<string.h>`: para usar `strlen()` e manipulação de strings
* `<ctype.h>`: para manipulação de caracteres (`tolower`, `isspace`)

---

## 🚀 Como Compilar e Executar

```bash
cd challenges/anagram
make
```

O programa solicitará duas strings e informará se elas são ou não anagramas.

---

## 🎯 Objetivo de Aprendizado

Este exercício reforça conceitos fundamentais de:

* Manipulação de strings em C
* Uso de arrays de frequência
* Normalização de dados (remoção de espaços, conversão para minúsculas)
* Comparação de estruturas de dados simples
* Princípios de eficiência e economia de memória
