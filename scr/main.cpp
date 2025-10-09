
#include <iostream>
#include <string>
using namespace std;

void jogo_alterna_case() {
    cin.ignore(); // Limpa o buffer do cin
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

int main() {
    int opcao;
    do {
        cout << "===== MENU =====" << endl;
    cout << "1. Opcao 1" << endl;
    cout << "2. Alterna maiusculas/minusculas" << endl;
    cout << "3. Opcao 3" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Voce escolheu a Opcao 1." << endl;
                break;
            case 2:
                jogo_alterna_case();
                break;
            case 3:
                cout << "Voce escolheu a Opcao 3." << endl;
                break;
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

