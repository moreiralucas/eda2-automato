#include "textos.hpp"
#include <iostream> // TODO: Remover esse cabeçalho

Search_word::Search_word(const int size, const std::string& text, const std::string& pattern){
    this->text = text;
    this->pattern = pattern;
    this->size = size;
    // for (char caracter = 97; caracter < 123; caracter++) {
        // alphabet.push_back(caracter);
    // }
    // alphabet.push_back('.');
    // alphabet.push_back(',');
    // alphabet.push_back(' ');
    alphabet.push_back('a');
    alphabet.push_back('b');
    alphabet.push_back('c');
}

void Search_word::set_delta(int caracter, int valor) {
    this->table[caracter].push_back(valor);
}

void Search_word::compute_table() {
    const int m = pattern.size();
    const int n = alphabet.size();
    std::cout << "alphabet.size(): " << alphabet.size() << '\n';
    for (int q = 0; q <= m; q++) {
        for (int i = 0; i < n; i++) {
            int k = std::min(m+1,q+2);
            std::cout << "k\':" << k << '\n';
            do {
                k--;
                std::cout << "k--: " << k << ' ' << alphabet[i] << ' ';
            } while(!Search_word::is_suffix(k, q, alphabet[i]));
            Search_word::set_delta(i, k);
            std::cout << "\nletra: " << alphabet[i] << '\n';
            std::cout << "estado: " << q << ", i: " << i << ", k: " << k << '\n';
        }
        std::cout << "------------------" << '\n';
    }
}

/**
 * [Search_word::delta description]
 * @param  q        [description]
 * @param  caracter [description]
 * @return          [description]
 */void Search_word::print_datas() { // TODO: remover esse método
    print "Text: " << this->text << std::endl;
    print "Pattern: " << this->pattern << std::endl;
    print "Size: " << this->size << std::endl;
}
int Search_word::delta(int q, char caracter) {
    const int id_caracter = caracter_to_int(caracter);
    return table[q][id_caracter];
}

// Inverter true e false e tirar a negação da chamada da função
bool Search_word::is_suffix(const int k, const int q, const char c) {
    if (k > 0 && pattern[k - 1] != c) {
        return false;
    }
    if (k >= 2) {
        for (int i = k - 2, j = q - 1; i >= 0; i--, j--)
            if (pattern[i] != pattern[j]) {
                return false;
        }
    }
    return true;
}

void Search_word::print_table() {
    // TODO: Implement you code here
}

void Search_word::search_pattern() {
    const int n = this->size;
    const int m = this->pattern.size();
    int q = 0;

    for (int i = 0; i < n; i++) {
        // no estado 'q', lendo 'text[i]' ...
        q = delta(q, text[i]);
        if (q == m)
            std::cout << "padrão o ocorre aqui" << std::endl;
    }
}
