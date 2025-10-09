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

