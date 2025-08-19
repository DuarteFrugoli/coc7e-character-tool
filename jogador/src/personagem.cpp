#include "personagem.h"
#include "atributo.h"
#include "ocupacao.h"
#include "pericia.h"
#include "util.h" // Para funções utilitárias
#include <iostream>

const int IDADE_MINIMA = 15;
const int IDADE_MAXIMA = 90;

void escolhaIdade(int &idade) {
    int opcao;

    do {
        cout << "Escolher idade ou gerar idade aleatoriamente? (1 para escolher, 2 para gerar aleatoriamente): ";
        cin >> opcao;
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1) {
        cout << "Digite a idade do personagem: ";
        cin >> idade;
    } else {
        idade = rand() % (IDADE_MAXIMA - IDADE_MINIMA + 1) + IDADE_MINIMA; // Gera idade aleatória entre 15 e 90
        cout << "Idade gerada: " << idade << endl;
    }
}

void criarPersonagemAleatorio(Personagem &personagem) {
    // Atribuindo valores aos atributos principais e secundários
    gerarAtributos(personagem.atributo);
    calcularAtributosSecundarios(personagem.atributo);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    // Escolhe a idade do personagem
    escolhaIdade(personagem.idade);

    // Aplica modificadores de idade nos atributos
    aplicarModificadoresDeIdade(personagem.atributo, personagem.idade);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
}

void criarPersonagemPseudoAleatorio(Personagem &personagem) {
    // Atribuindo valores aos atributos principais
    gerarAtributos(personagem.atributo);

    // Mudando valores dos atributos principais
    trocarAtributos(personagem.atributo);

    // Atribuindo valores aos atributos secundários
    calcularAtributosSecundarios(personagem.atributo);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    // Escolhe a idade do personagem
    escolhaIdade(personagem.idade);

    // Aplica modificadores de idade nos atributos
    aplicarModificadoresDeIdade(personagem.atributo, personagem.idade);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
}

void criarPersonagemPersonalizado(Personagem &personagem) {
    // Atribuindo valores aos atributos principais e secundários
    escolherAtributos(personagem.atributo);
    calcularAtributosSecundarios(personagem.atributo);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    // Escolhe a idade do personagem
    escolhaIdade(personagem.idade);
    
    // Aplica modificadores de idade nos atributos
    aplicarModificadoresDeIdade(personagem.atributo, personagem.idade);

    // Exibe os atributos principais e secundários
    exibirAtributos(personagem.atributo);

    pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
}