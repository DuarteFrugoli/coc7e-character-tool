#ifndef ATRIBUTO_H
#define ATRIBUTO_H

const int IDADE_IDEAL = 20;

struct Atributo {
    int forca;
    int constituicao;
    int tamanho;
    int destreza;
    int aparencia;
    int inteligencia;
    int poder;
    int educacao;
    int sorte;

    int corpo;
    int pv;
    int mov;
};

void aplicarModificadoresDeIdade(Atributo &atributo, int idade);
void calcularAtributosSecundarios(Atributo &atributo, int idade = IDADE_IDEAL);
int dado(int dados, int faces, int multiplicador = 1, int modificador = 0);
void distribuirReducoes(int reducao, int &atributo1, int &atributo2, int &atributo3);
void distribuirReducoes(int reducao, int &atributo1, int &atributo2);
void escolherAtributos(Atributo &atributo);
void exibirAtributos(Atributo &atributo);
void exibirAtributos3d6(Atributo &atributo);
void exibirAtributos2d6p5(Atributo &atributo);
void exibirAtributosPrincipais(Atributo &atributo);
void exibirAtributosSecundarios(Atributo &atributo);
void gerarAtributos(Atributo &atributo);
void trocarAtributos(Atributo &atributo);
void verificarMelhoriaAtributo(int &atributo);

#endif