#include <bits/stdc++.h>
#include "textos.hpp"

namespace {
    class Randomness {
    public:
        Randomness() {
            FILE *f = fopen("/dev/urandom", "r");
            uint32_t value;
            fread(&value, sizeof value, 1, f);
            srand(value);
        }
    };
    Randomness randomness;
}

char int_to_caracter(int i) {
    char c;
    switch (i) {
        case 26: c = 46;
        break;
        case 27: c = 44;
        break;
        case 28: c = 32;
        break;
        default:
        c = i + 97;
    }
    return c;
}

std::string generate(int tam) {
    std::string palavra = "";
    for (int j = 0; j < tam; j++) {
        int n = rand()%29;
        while ((j == 0 || j == tam-1 ) && n == 28) {
            n = rand()%29;
        }
        palavra+= int_to_caracter(n);
    }
    return palavra;
}

void teste (int t) {
    int tam_texto;
    std::string texto = "", padrao_texto = "";

    padrao_texto = generate(51);
    for (int j = 0; j < 73; j++) {
        texto+= generate(67) + padrao_texto;
    }
    tam_texto = texto.size();

    std::string path = "input" + std::to_string(t);
    std::ofstream my_file(path);
    if (my_file.is_open()) {
        my_file << tam_texto << '\n';
        my_file << texto << '\n';
        my_file << padrao_texto << '\n';
        my_file << "u\n";
        my_file << "s\n";
        my_file << "e\n";
    }
    else {
        std::cout << "Erro ao abrir o arquivo " << path << std::endl;
    }

    Search_word text1(tam_texto, texto, padrao_texto);
    text1.compute_table();
    text1.print_table();
    text1.search_pattern();
}

int executa_testes() {
    std::ifstream my_file("controle.txt");
    int read_number;
    if (my_file.is_open()) {
        my_file >> read_number;
        // std::cout << "read_number: " << read_number << '\n';
        teste(read_number);
        read_number++;

    }
    else {
        std::cout << "Erro ao abrir o arquivo" << '\n';
    }
    return read_number;
}

void write(int number) {
    std::ofstream my_file("controle.txt");
    if (my_file.is_open()) {
        my_file << number;
        // std::cout << "gravando numero: " << number << '\n';
    }
    else {
        std::cout << "Erro ao abrir o arquivo" << '\n';
    }
}
