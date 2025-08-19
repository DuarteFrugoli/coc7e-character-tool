#ifndef OCUPACAO_H
#define OCUPACAO_H

#include <string>

using namespace std;

struct NivelCredito {
    int min;
    int max;
};

struct Ocupacao {
    string nome;
    string descricao;
    string pericias;
    NivelCredito nivel_credito;
    string formula_pontos_pericias;
};

#endif