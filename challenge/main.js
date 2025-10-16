const readline = require('readline');

// Cria uma interface para ler do teclado
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Função que verifica caracteres repetidos
function repeatString(str) {
  const freq = new Array(256).fill(0); // tabela ASCII
  for (let i = 0; i < str.length; i++) {
    const c = str.charCodeAt(i); // obtém o código ASCII
    if (freq[c] > 0) {
      return true; // caractere repetido
    }
    freq[c]++;
  }
  return false; // todos únicos
}

// Leitura dinâmica da entrada do usuário
rl.question('Digite a frase: ', (txt) => {
  if (repeatString(txt)) {
    console.log('A string possui caracteres repetidos!');
  } else {
    console.log('A string não possui caracteres repetidos!');
  }
  rl.close();
});
