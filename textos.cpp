#include "textos.hpp"

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

int Search_word::caracter_to_int(char c) {
    int ans;
    switch (c) {
        case 46: ans = 26;
            break;
        case 44: ans = 27;
            break;
        case 32: ans = 28;
            break;
        default:
            ans = c - 97;
    }
    return ans;
}


void Search_word::compute_table() {
    const int m = pattern.size();
    const int n = alphabet.size();
    // std::cout << "alphabet.size(): " << alphabet.size() << '\n';
    for (int q = 0; q <= m; q++) {
        for (int i = 0; i < n; i++) {
            int k = std::min(m+1,q+2);
            // std::cout << "k\':" << k << '\n';
            do {
                k--;
                // std::cout << "k--: " << k << ' ' << alphabet[i] << ' ';
            } while(Search_word::is_suffix(k, q, alphabet[i]));
            Search_word::set_delta(i, k);
            // std::cout << "\nletra: " << alphabet[i] << '\n';
            // std::cout << "estado: " << q << ", i: " << i << ", k: " << k << '\n';
        }
        // std::cout << "------------------" << '\n';
    }
}

int Search_word::get_delta(int estado, int caracter) {
    return table[caracter][estado];
}

char Search_word::int_to_caracter(int i) {
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

bool Search_word::is_suffix(const int k, const int q, const char c) {
    if (k > 0 && pattern[k - 1] != c) {
        return true;
    }
    if (k >= 2) {
        for (int i = k - 2, j = q - 1; i >= 0; i--, j--)
            if (pattern[i] != pattern[j]) {
                return true;
        }
    }
    return false;
}

std::string Search_word::to_string(int estado, int caracter, int delta) {
    char c;
    switch (caracter) {
        case 26: c = 46;
            break;
        case 27: c = 44;
            break;
        case 28: c = 32;
            break;
        default:
            c = caracter + 97;
    }
    std::string result;
    result = "[" + std::to_string(estado) + ", ";
    if (c == 32)
         result += "' '";
    else
        result +=  c;
    result += "]: " + std::to_string(delta);
    return result;
}

void Search_word::print_table() {
    const int qtd_caracteres = this->alphabet.size();
    const int qtd_estados = this->pattern.size() + 1;
    char c;

    std::cout << "Tabela Delta:" << std::endl;
    for (int estado = 0; estado < qtd_estados; estado++) {
        for (int caracter = 0; caracter < qtd_caracteres; caracter++) {
            int delta = Search_word::get_delta(estado, caracter);
            if (delta != 0) {
                c = int_to_caracter(caracter);
                std::cout << "[" << std::to_string(estado) << ", ";
                if (c == 32)
                     std::cout << "' '";
                else
                    std::cout << c;
                std::cout << "]: " << std::to_string(delta) << std::endl;
            }
        }
    }
}

void Search_word::search_pattern() { //TODO: Faltar terminar esse método
    const int n = this->size;
    const int m = this->pattern.size();
    int c_int, q = 0;

    for (int i = 0; i < n; i++) {
        // no estado 'q', lendo 'text[i]' ...
        c_int = Search_word::caracter_to_int(text[i]);
        q = Search_word::get_delta(q, c_int);
        if (q == m)
            std::cout << "padrão o ocorre aqui" << std::endl;
    }
}

void Search_word::set_delta(int caracter, int valor) {
    this->table[caracter].push_back(valor);
}
