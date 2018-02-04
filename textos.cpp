#include "textos.hpp"
#include <iostream> // TODO: Remover esse cabeçalho

Search_word::Search_word(const int size, const std::string& text, const std::string& pattern){
    this->text = text;
    this->pattern = pattern;
    this->size = size;
    for (char caracter = 97; caracter < 123; caracter++) {
        alphabet.push_back(caracter);
    }
    alphabet.push_back('.');
    alphabet.push_back(',');
    alphabet.push_back(' ');
}

void Search_word::print_datas() { // remover esse método
    print "Text: " << this->text << std::endl;
    print "Pattern: " << this->pattern << std::endl;
    print "Size: " << this->size << std::endl;
}
void Search_word::search_pattern() {
    // TODO: Implement you code here
}

void Search_word::compute_table() {
    const int m = pattern.size();
    const int n = alphabet.size();
    // std::cout << "alphabet.size(): " << alphabet.size() << '\n';
    for (int q = 0; q < m; q++) {
        for (int i = 0; i < n; i++) {
            int k = std::min(m+1,q+2);
            // std::cout << "k\':" << k << '\n';
            do {
                k--;
            } while(Search_word::is_suffix(k, q, alphabet[i]));
            // std::cout << "letra: " << alphabet[i] << '\n';
            // std::cout << "q: " << q << ", i: " << i << ", k: " << k << '\n';
        }
        // std::cout << "------------------" << '\n';
    }
}

bool Search_word::is_suffix(const int k, const int q, const char c) {
    if (pattern[k - 1] != c)
        return false;

    for (int i = k - 2, j = q - 1; i >= 0; i--, j--)
        if (pattern[i] != pattern[j])
            return false;

    return true;
}
