#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include "ocupacao.h"
#include "pericia.h"
#include "atributo.h"

using namespace std;

struct Personagem {
    string nome_jogador;
    string nome;
    int idade;
    Ocupacao ocupacao;
    Atributo atributo;
    vector<Pericia> pericia;
};

void criarPersonagemAleatorio(Personagem &personagem);
void criarPersonagemPersonalizado(Personagem &personagem);
void criarPersonagemPseudoAleatorio(Personagem &personagem);
void escolhaIdade(int &idade);

#endif