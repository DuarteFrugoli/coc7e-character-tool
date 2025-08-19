#include <iostream> // Para cout e cin
#include <cstdlib> // Para rand(), srand() e system()
#include <ctime> // Para time()
#include <locale> // Para setlocale()
#include <string> // Para string
#include <vector> // Para as perícias modificadas ou criadas pelo jogador
#include <limits>
#include "atributo.h"
#include "ocupacao.h"
#include "pericia.h"
#include "personagem.h"
#include "util.h" // Para funções utilitárias

using namespace std;

void exibirMenuPrincipal() {
    cout << "Escolha uma opção:" << endl;
    cout << "\t1. Criar personagem" << endl;
    cout << "\t2. Carregar personagem" << endl;
    cout << "\t3. Modificar personagem" << endl;
    cout << "\t4. Mostrar personagem" << endl;
    cout << "\t5. Exportar personagem" << endl;
    cout << "\t6. Sair" << endl;
    cout << "Opção: ";
}

void exibirMenuCriarPersonagem() {
    cout << "Escolha uma opção para gerar atributos:" << endl;
    cout << "\t1. Criar personagem aleatório" << endl;
    cout << "\t2. Criar personagem pseudo-aleatório" << endl;
    cout << "\t3. Criar personagem personalizado" << endl;
    cout << "Opção: ";
}

void processarOpcaoCriarPersonagem(int opcao, Personagem &personagem) {
    limparTela(); // Limpa a tela antes de exibir o menu
    switch (opcao) {
        case 1:
            cout << "Criando personagem aleatório..." << endl;
            criarPersonagemAleatorio(personagem);
            break;
        case 2:
            cout << "Criando personagem pseudo-aleatório..." << endl;
            criarPersonagemPseudoAleatorio(personagem);
            break;
        case 3:
            cout << "Criando personagem personalizado..." << endl;
            criarPersonagemPersonalizado(personagem);
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
    }
}

void processarOpcaoMenuPrincipal(int opcao, Personagem &personagem) {
    limparTela(); // Limpa a tela antes de exibir o menu
    switch (opcao) {
        case 1:
            exibirMenuCriarPersonagem();
            opcao = obterEntradaValida();
            processarOpcaoCriarPersonagem(opcao, personagem); // Processa a opção escolhida
            break;
        case 2:
            cout << "Carregando personagem..." << endl;
            // TODO: Carregar personagem de um arquivo JSON
            break;
        case 3:
            cout << "Modificando personagem..." << endl;
            // TODO: Adicionar lógica para modificar o personagem
            break;
        case 4:
            cout << "Mostrando personagem..." << endl;
            exibirAtributos(personagem.atributo); // Exibe os atributos do personagem
            pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
            // TODO: Adicionar lógica para mostrar todas as informações do personagem
            break;
        case 5:
            cout << "Expotando personagem..." << endl;
            // TODO: Adicionar lógica para exportar o personagem para um arquivo JSON
        case 6:
            cout << "Saindo..." << endl;
            exit(0);
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.utf8"); // Configura o idioma para UTF-8
    srand(time(0)); // Inicializa a semente do gerador aleatório

    Personagem personagem; // Cria uma instância do personagem
    string nome_jogador;
    int opcao; // Auxiliar para o menu de opções
    string nome; 
    int idade;
    int pts_pericias_ocupacionais = 0, pts_interesses_pessoais = 0; // Pontos para perícias

    limparTela(); // Limpa a tela
    cout << "Bem-vindo ao Criador de Personagem de Call of Cthulhu 7e!" << endl;
    cout << "Qual é o seu nome?" << endl;
    getline(cin, nome_jogador);
    
    while(true) {
        limparTela(); // Limpa a tela
        exibirMenuPrincipal(); // Exibe o menu principal
        opcao = obterEntradaValida();

        processarOpcaoMenuPrincipal(opcao, personagem); // Processa a opção escolhida
    }

    return 0;
}