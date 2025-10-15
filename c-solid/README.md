## Camadas e responsabilidades  

- main: pontos de entrada (executáveis). Apenas orquestram leitura mínima e chamam os runners/aplicação.  
- presentation: camada de interface/adaptação. Converte entradas de usuário para formatos do domínio e delega para as funções de domínio (ex.: `runner_*`). Não contém regra de negócio.  
- infra: serviços do sistema (I/O, alocação segura, utilidades de baixo nível). Ex.: `io.h`/`io.c` para `readline`, `xmalloc` etc.  
- utils: utilitários transversais sem acoplamento ao domínio (ex.: parsing, trim). Reutilizáveis por presentation/infra/main.  
- domain: regras de negócio/soluções puras (ex.: `solution_array`, `solution_range`, `solution_strings`). Não fazem I/O nem dependem de presentation.  
- data: reservada para repositórios/adapters de dados (ex.: arquivos, DB, HTTP). Ainda não utilizada neste template.  

Observações  
- Os binários e objetos são gerados em `build/` (ignorados pelo Git).  
- O `Makefile` compila cada app combinando domain + presentation + infra + utils, mantendo o domínio isolado.  

## Árvore SOLID (por camadas)

c-solid/  
├─ include/  
│  ├─ presentation/  
│  │  ├─ runner_array.h  
│  │  ├─ runner_range.h  
│  │  ├─ runner_strings.h  
│  ├─ infra/  
│  │  ├─ io.h  
│  ├─ utils/  
│  │  ├─ parse.h  
│  ├─ domain/         (headers de domínio, se necessário)  
├─ main/
│  ├─ linked_list_main.c  
│  ├─ return_smallest_main.c  
│  ├─ six_sided_main.c  
│  ├─ odd_numbers_main.c  
│  ├─ anagram_main.c  
├─ presentation/  
│  ├─ runner_array.c  
│  ├─ runner_range.c  
│  ├─ runner_strings.c  
├─ infra/  
│  ├─ io.c  
├─ utils/  
│  ├─ parse.c  
├─ domain/
│  ├─ linked_list_solution.c         // int solution_array(const int *A, int N)  
│  ├─ return_smallest_solution.c     // int solution_array(int *A, int N)  
│  ├─ six_sided_solution.c           // int solution_array(const int *A, int N)  
│  ├─ odd_numbers_solution.c         // int* solution_range(int l,int r,int *count_out)  
│  ├─ anagram_solution.c             // bool solution_strings(const char *a,const char *b,int n)  
├─ build/  
├─ Makefile  