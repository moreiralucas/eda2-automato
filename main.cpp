/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include "textos.hpp"
#include "testes.hpp"

/**
* [main aplicação principal]
*/
int main(int argc, const char *argv[]) {
    // int a = executa_testes();
    // write(a);
    // return 0;

    int tam_texto;
    std::string texto, padrao_texto;
    // -------- Lendo os dados de entrada -----------
    std::cin >> tam_texto;
    std::cin.ignore();
    getline(std::cin, texto);
    getline(std::cin, padrao_texto);
    // ------------------------------------------------
    Search_word text(tam_texto, texto, padrao_texto);
    char input;

    text.compute_table();
    while (std::cin >> input, input != 'e') {
        if (input == 's') {
            text.search_pattern();
        }
        else { // input == 'u'
            text.print_table();
        }
    }
    return 0;
}
