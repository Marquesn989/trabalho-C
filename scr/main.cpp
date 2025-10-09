#include <iostream>

using namespace std;

int main() {
    int opcao;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Opcao 1" << endl;
        cout << "2. Opcao 2" << endl;
        cout << "3. Jogo do Quente e Frio" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Voce escolheu a Opcao 1." << endl;
                break;
            case 2:
                cout << "Voce escolheu a Opcao 2." << endl;
                break;
            case 3:
            
            
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

