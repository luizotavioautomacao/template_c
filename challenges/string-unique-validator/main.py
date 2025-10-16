def repeat_string(s: str) -> bool:
    freq = [0] * 256  # tabela ASCII (0–255)
    for char in s:
        c = ord(char)  # obtém código numérico do caractere
        if freq[c] > 0:
            return True  # caractere repetido
        freq[c] += 1
    return False  # todos os caracteres são únicos


def main():
    txt = input("Digite a frase: ")  # leitura dinâmica da entrada
    if repeat_string(txt):
        print("A string possui caracteres repetidos!")
    else:
        print("A string não possui caracteres repetidos!")


if __name__ == "__main__":
    main()
