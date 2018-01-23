#include <vector>
#include <string>

class Search_word {
        int size;
        std::string text;
        std::string pattern;
        std::vector<std::vector<int> > table;
    public:
        Search_word(int size, std::string text, std::string pattern);
        void compute_table(std::string pattern, std::string alphabet);
        void print_datas();
        void search_pattern();
        void Search_word::print_table()
};
