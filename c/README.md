### Comandos
Após entrar no diretório `cd c` e executar `make`.  
O comando make executa o comando `make all`, compila os arquivos necessários e executa o comando `make exec`.  
Detalhes dos comandos que são executados:  
`mkdir -p build`  
`gcc -std=c11 -Wall -Wextra -O2 -c -o build/main.o main.c`  
`gcc -std=c11 -Wall -Wextra -O2 -c -o build/io.o io.c`  
`gcc -std=c11 -Wall -Wextra -O2 -c -o build/solution.o solution.c`  
`gcc -std=c11 -Wall -Wextra -O2 -o build/app build/main.o build/io.o build/solution.o`  
`./build/app`  

