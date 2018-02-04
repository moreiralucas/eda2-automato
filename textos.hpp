/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include <iostream> // TODO: Remover esse cabeçalho
#include <vector>
#include <string>

// -------------------------------------------
// Trecho utilizado somente para desenvolvimento
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
        std::vector<std::vector<int> > table;
        bool is_suffix(const int, const int, const char);
    public:
        Search_word(const int, const std::string&, const std::string&);
        void compute_table();
        void print_datas();
        void print_table();
        void search_pattern();
};
