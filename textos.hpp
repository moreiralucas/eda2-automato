/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include <vector>
#include <string>
#include <iostream>
#define TAM_ALPHABET 29

// -------------------------------------------
// Trecho utilizado somente para desenvolvimento
#include <iostream> // TODO: Remover essa linha
#include <map>
#define debug true

#ifndef print
#define print if(debug)std::cout <<
#endif
// -------------------------------------------

class Search_word {
    private:
        int size;
        std::string text;
        std::string pattern;
        std::vector<char> alphabet;
        std::vector<int> table[TAM_ALPHABET];
        bool is_suffix(const int, const int, const char);
        char int_to_caracter(int);
        int caracter_to_int(char);
        int get_delta(int, int);
        void set_delta(int, int);
        std::string to_string(int, int, int);
    public:
        Search_word(const int, const std::string&, const std::string&);
        void compute_table();
        void print_table();
        void search_pattern();
};
