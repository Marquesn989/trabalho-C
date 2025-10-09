// Função para alternar maiúsculas/minúsculas em uma frase
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

void jogo_alterna_case() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);
    for (size_t i = 0; i < frase.length(); ++i) {
        if (isalpha(frase[i])) {
            if (i % 2 == 0)
                frase[i] = toupper(frase[i]);
            else
                frase[i] = tolower(frase[i]);
        }
    }
    cout << "Frase alternada: " << frase << endl;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void jogo_inverte_letras() {
    // limpar newline pendente
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Escreva uma frase: ";
    string frase;
    getline(cin, frase);    
    if (frase.empty()) {
        cout << "Nada a inverter." << endl;
        return;
    }

    cout << "Como deseja inverter?" << endl;
    cout << "1 - Inverter tudo (todos os caracteres)" << endl;
    cout << "2 - Inverter a ordem das palavras" << endl;
    cout << "3 - Inverter letras em cada palavra" << endl;
    cout << "Escolha (1-3): ";
    int modo;
    if (!(cin >> modo)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcao invalida." << endl;
        return;
    }

    string resultado;
    if (modo == 1) {
        resultado = frase;
        reverse(resultado.begin(), resultado.end());
    } else if (modo == 2) {
        istringstream iss(frase);
        vector<string> words;
        string w;
        while (iss >> w) words.push_back(w);
        for (int i = (int)words.size() - 1; i >= 0; --i) {
            resultado += words[i];
            if (i > 0) resultado += ' ';
        }
    } else if (modo == 3) {
        istringstream iss(frase);
        string w;
        bool first = true;
        while (iss >> w) {
            reverse(w.begin(), w.end());
            if (!first) resultado += ' ';
            resultado += w;
            first = false;
        }
    } else {
        cout << "Opcao invalida." << endl;
        return;
    }

    cout << "Original: " << frase << endl;
    cout << "Invertida: " << resultado << endl;
}

int main() {
    int opcao;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Inverter frase" << endl;
        cout << "2. Opcao 2" << endl;
        cout << "3. Opcao 3" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Tente novamente." << endl << endl;
            continue;
        }

        switch(opcao) {
            case 1:
                jogo_inverte_letras();
                break;
            case 2:
                jogo_alterna_case();
                break;
            case 3: {
                cout << "\nBem-vindo ao jogo do Quente e Frio!" << endl;
                srand(time(0));
                int numero_secreto = rand() % 100 + 1;
                int palpite, tentativas = 0;
                do {
                    cout << "Digite seu palpite (1 a 100): ";
                    cin >> palpite;
                    tentativas++;
                    int diff = abs(palpite - numero_secreto);
                    if (palpite == numero_secreto) {
                        cout << "Parabens! Voce acertou o numero em " << tentativas << " tentativas!" << endl;
                    } else if (diff <= 5) {
                        cout << "Quente!" << endl;
                    } else if (diff <= 15) {
                        cout << "Morno." << endl;
                    } else {
                        cout << "Frio." << endl;
                    }
                } while (palpite != numero_secreto);
                cout << endl;
                break;
            }
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
        cout << endl;
    } while(opcao != 0);
    return 0;
}

