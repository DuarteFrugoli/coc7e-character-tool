#include "util.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int obterEntradaValida() {
    int valor;
    while (!(cin >> valor)) {
        cout << "Entrada inválida. Tente novamente: ";
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a entrada inválida
    }
    return valor;
}

void limparTela() {
#ifdef _WIN32
    system("cls"); // Comando para Windows
#else
    system("clear"); // Comando para Linux/macOS
#endif
}

void pausarExecucao() {
    cout << "Pressione Enter para continuar..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
    cin.get(); // Aguarda o usuário pressionar Enter
}