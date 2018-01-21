#include "textos.hpp"
#include "main.hpp"
#include <iostream>

Search_word::Search_word(int size, std::string text, std::string pattern){
    this->text = text;
    this->pattern = pattern;
    this->size = size;
}

void Search_word::print_datas() { // remover esse método
    print "Text: " << this->text << '\n';
    print "Pattern: " << this->pattern << '\n';
    print "Size: " << this->size << '\n';
}
void Search_word::search_pattern() {
    // TODO: Implement you code here
}

void Search_word::compute_table(std::string pattern, std::string alphabet) {
    const int m = pattern.size();
    const int n = alphabet.size();
    for (int q = 0; q < m; q++) {
        for (int i = 0; i < n; i++) {
            int k = min(m+1,q+2);
            do {
                k--;
            } while(suffix(pattern[k], ));
        }
    }
}
