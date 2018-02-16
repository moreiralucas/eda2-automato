/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include "textos.hpp"
#include <iostream>

using namespace std;

void teste() {
    string texto = "abababacaba", padrao_texto = "ababaca";
    int tam_texto = texto.size();
    Search_word text(tam_texto, texto, padrao_texto);

    text.compute_table();
    text.print_table();
    text.search_pattern();
}

/**
* [main aplicação principal]
*/
int main() {
    if (debug) {
        teste();
        return 0;
    }
    int tam_texto;
    string texto, padrao_texto;
    // -------- Lendo os dados de entrada -----------
    cin >> tam_texto;
    cin.ignore();
    getline(cin, texto);
    getline(cin, padrao_texto);
    // ------------------------------------------------
    Search_word text(tam_texto, texto, padrao_texto);

    char input;
    text.compute_table();
    while (cin >> input, input != 'e') {
        print "input: " << input << std::endl;
        if (input == 's') {
            print "busca padrão" << '\n';
            text.search_pattern();
        }
        else { // input == 'u'
            print "impressão da tabela" << std::endl;
            text.print_table();
        }

    }
    print "input: " << input << endl;
    return 0;
}
