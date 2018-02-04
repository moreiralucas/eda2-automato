/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include "textos.hpp"

using namespace std;

/**
* [main aplicação principal]
*/
int main() {
    int tam_texto;
    string texto, padrao_texto;

    // -------- Lendo os dados de entrada -----------
    cin >> tam_texto;
    cin.ignore();
    getline(cin, texto);
    getline(cin, padrao_texto);
    // ------------------------------------------------
    Search_word text(tam_texto, texto, padrao_texto);
    if(debug) text.print_datas();

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
            text.compute_table();
        }

    }
    print "input: " << input << endl;
    return 0;
}
