#include <vector>
#include <string>

class Search_word {
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
        void search_pattern();
};
