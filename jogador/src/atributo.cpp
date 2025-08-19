#include "atributo.h"
#include "util.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

const int IDADE_MINIMA = 15;
const int IDADE_MAXIMA = 90;
const int REDUCAO_15 = 5;
const int REDUCAO_EDU_15 = 5;
const int REDUCAO_40 = 5;
const int REDUCAO_APA_40 = 5;
const int REDUCAO_MOV_40 = 1;
const int REDUCAO_50 = 10;
const int REDUCAO_APA_50 = 10;
const int REDUCAO_MOV_50 = 2;
const int REDUCAO_60 = 20;
const int REDUCAO_APA_60 = 15;
const int REDUCAO_MOV_60 = 3;
const int REDUCAO_70 = 40;
const int REDUCAO_APA_70 = 20;
const int REDUCAO_MOV_70 = 4;
const int REDUCAO_80 = 80;
const int REDUCAO_APA_80 = 25;
const int REDUCAO_MOV_80 = 5;

const int QNT_ATRIBUTOS_3D6 = 6;
const int QNT_ATRIBUTOS_2D6 = 3;

// Tabela de dano extra (DX) baseada no valor de corpo
const string dx[5] = {"-2", "-1", "0", "1d4", "1d6"};
const string atributo_nomes[9] = {
    "Força",
    "Constituição",
    "Tamanho",
    "Destreza",
    "Aparência",
    "Inteligência",
    "Poder",
    "Educação",
    "Sorte"
};

// Aplica modificadores nos atributos com base na idade do personagem
void aplicarModificadoresDeIdade(Atributo &atributo, int idade) {
    // Referências locais para simplificar o acesso
    int &forca = atributo.forca;
    int &tamanho = atributo.tamanho;
    int &constituicao = atributo.constituicao;
    int &destreza = atributo.destreza;
    int &aparencia = atributo.aparencia;
    int &educacao = atributo.educacao;
    int &sorte = atributo.sorte;
    int &mov = atributo.mov;

    // Aplica modificadores de idade nos atributos
    if (idade < IDADE_MINIMA || idade > IDADE_MAXIMA) {
        cout << "Idade inválida. O personagem deve ter pelo menos 15 anos." << endl;
        return; // Retorna se a idade for inválida
    } else if (idade >= 15 && idade <= 19) {
        sorte = max(sorte, max(dado(3, 6, 5, 0), dado(3, 6, 5, 0))); // Pode aumentar a sorte para personagens jovens
        distribuirReducoes(REDUCAO_15, forca, tamanho); // Reduz força e tamanho para personagens jovens
        educacao -= REDUCAO_EDU_15; // Penalidade na educação
    } else if (idade >= 20 && idade <= 39) {
        verificarMelhoriaAtributo(educacao); // Educação pode ser melhorada
    } else if (idade >= 40 && idade <= 49) {
        for(int i = 0; i < 2; i++) verificarMelhoriaAtributo(educacao);
        verificarMelhoriaAtributo(educacao);
        distribuirReducoes(REDUCAO_40, forca, constituicao, destreza); // Reduz atributos físicos
        aparencia -= REDUCAO_APA_40; // Penalidade na aparência
    } else if (idade >= 50 && idade <= 59) {
        for(int i = 0; i < 3; i++) verificarMelhoriaAtributo(educacao);
        distribuirReducoes(REDUCAO_50, forca, constituicao, destreza); // Penalidade maior nos atributos físicos
        aparencia -= REDUCAO_APA_50; // Penalidade na aparência
    } else if (idade >= 60 && idade <= 69) {
        for(int i = 0; i < 4; i++) verificarMelhoriaAtributo(educacao);
        distribuirReducoes(REDUCAO_60, forca, constituicao, destreza);
        aparencia -= REDUCAO_APA_60; // Penalidade na aparência
    } else if (idade >= 70 && idade <= 79) {
        for(int i = 0; i < 4; i++) verificarMelhoriaAtributo(educacao);
        distribuirReducoes(REDUCAO_70, forca, constituicao, destreza);
        aparencia -= REDUCAO_APA_70; // Penalidade na aparência
    } else if (idade >= 80 && idade <= 90) {
        for(int i = 0; i < 4; i++) verificarMelhoriaAtributo(educacao);
        distribuirReducoes(REDUCAO_80, forca, constituicao, destreza);
        aparencia -= REDUCAO_APA_80; // Penalidade na aparência
    }

    calcularAtributosSecundarios(atributo, idade); // Recalcula os atributos secundários após aplicar modificadores
}

// Calcula os atributos secundários: corpo, pontos de vida (PV) e taxa de movimento (MOV)
void calcularAtributosSecundarios(Atributo &atributo, int idade) {
    // Referências locais para simplificar o acesso
    int &forca = atributo.forca;
    int &tamanho = atributo.tamanho;
    int &destreza = atributo.destreza;
    int &constituicao = atributo.constituicao;
    int &corpo = atributo.corpo;
    int &pv = atributo.pv;
    int &mov = atributo.mov;
    
    // Calcula o corpo com base na força e tamanho
    int somaForcaTamanho = forca + tamanho;
    if (somaForcaTamanho <= 64) {
        corpo = -2;
    } else if (somaForcaTamanho <= 84) {
        corpo = -1;
    } else if (somaForcaTamanho <= 124) {
        corpo = 0;
    } else if (somaForcaTamanho <= 164) {
        corpo = 1;
    } else {
        corpo = 2;
    }

    pv = (constituicao + tamanho) / 10;

    if (destreza < tamanho && forca < tamanho) {
        mov = 7;
    } else if (destreza >= tamanho || forca >= tamanho) {
        mov = 8;
    }
    if (destreza > tamanho && forca > tamanho) {
        mov = 9;
    }

    if (idade >= 40) {
        if (idade >= 40 && idade <= 49) {
            mov -= REDUCAO_MOV_40;
        } else if (idade >= 50 && idade <= 59) {
            mov -= REDUCAO_MOV_50;
        } else if (idade >= 60 && idade <= 69) {
            mov -= REDUCAO_MOV_60;
        } else if (idade >= 70 && idade <= 79) {
            mov -= REDUCAO_MOV_70;
        } else if (idade >= 80 && idade <= 90) {
            mov -= REDUCAO_MOV_80;
        }
    }
}

// Função para simular rolagem de dados com multiplicador e modificador
int dado(int dados, int faces, int multiplicador, int modificador) {
    int soma = 0;
    for (int i = 0; i < dados; i++) {
        soma += (rand() % faces) + 1; // Gera um número aleatório entre 1 e o número de faces
    }
    return (soma * multiplicador) + modificador;
}

// Permite ao jogador distribuir reduções entre três atributos
void distribuirReducoes(int reducao, int &atributo1, int &atributo2, int &atributo3) {
    int r1, r2, r3;
    while (true) {
        cout << "Reduza " << reducao << " pontos entre força, constituição e destreza:" << endl;
        cout << "Reduza pontos de força: ";
        cin >> r1;
        cout << "Reduza pontos de constituição: ";
        cin >> r2;
        cout << "Reduza pontos de destreza: ";
        cin >> r3;
    
        // Validações para evitar reduções inválidas
        if (r1 + r2 + r3 != reducao) {
            cout << endl << "A soma das reduções deve ser igual a " << reducao << "." << endl;
        } else if (r1 > atributo1 || r2 > atributo2 || r3 > atributo3) {
            cout << endl << "Redução maior que o atributo original." << endl;
        } else {
            break; // Sai do loop se tudo estiver correto
        }
    }
    atributo1 -= r1;
    atributo2 -= r2;
    atributo3 -= r3;
}

// Permite ao jogador distribuir reduções entre dois atributos
void distribuirReducoes(int reducao, int &atributo1, int &atributo2) {
    int r1, r2;
    while (true) {
        cout << "Reduza " << reducao << " pontos entre força e tamanho:" << endl;
        cout << "Reduza pontos de força: ";
        cin >> r1;
        cout << "Reduza pontos de tamanho: ";
        cin >> r2;

        if(r1 + r2 != reducao) {
            cout << "A soma das reduções deve ser igual a " << reducao << "." << endl;
        } else if (r1 > atributo1 || r2 > atributo2) {
            cout << "Redução maior que o atributo original." << endl; // Validações para evitar reduções inválidas
        } else {
            break; // Sai do loop se tudo estiver correto
        }
    };
    atributo1 -= r1;
    atributo2 -= r2;
}

// Escolhe um atributo manualmente, garantindo que o valor esteja entre 1 e 99
void escolherAtributo(int &atributo, string nome_atributo) {
    do {
        cout << "Escolha o valor para " << nome_atributo << ": ";
        cin >> atributo;
        if (atributo < 1 || atributo > 99) {
            cout << "Valor inválido. Tente novamente: ";
        }
    } while (atributo < 1 || atributo > 99); // Garante que o valor esteja entre 1 e 99
}

// Escolhe manualmente os atributos
void escolherAtributos(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int* atributos[] = {
        &atributo.forca, &atributo.constituicao, &atributo.tamanho,
        &atributo.destreza, &atributo.aparencia, &atributo.inteligencia,
        &atributo.poder, &atributo.educacao, &atributo.sorte
    };

    const int totalAtributos = sizeof(atributos) / sizeof(atributos[0]);

    // Escolha de atributos
    for(int i = 0; i < totalAtributos; i++) {
        escolherAtributo(*atributos[i], atributo_nomes[i]); // Chama a função para escolher o atributo
    }
}

// Exibe os atributos principais e secundários do personagem
void exibirAtributos(Atributo &atributo) {
    cout << endl << "Atributos principais:" << endl;
    exibirAtributosPrincipais(atributo); // Exibe os atributos principais
    cout << "Atributos secundários:" << endl;
    exibirAtributosSecundarios(atributo); // Exibe os atributos secundários
    cout << endl;
}

// Exibe os atributos principaisdo personagem
void exibirAtributos3d6(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int &forca = atributo.forca;
    int &constituicao = atributo.constituicao;
    int &destreza = atributo.destreza;
    int &aparencia = atributo.aparencia;
    int &poder = atributo.poder;
    int &sorte = atributo.sorte;

    cout << "1. Força: " << forca << endl;
    cout << "2. Constituição: " << constituicao << endl;
    cout << "3. Destreza: " << destreza << endl;
    cout << "4. Aparência: " << aparencia << endl;
    cout << "5. Poder: " << poder << endl;
    cout << "6. Sorte: " << sorte << endl;
}

// Exibe os atributos principaisdo personagem
void exibirAtributos2d6p5(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int &tamanho = atributo.tamanho;
    int &inteligencia = atributo.inteligencia;
    int &educacao = atributo.educacao;

    cout << "1. Tamanho: " << tamanho << endl;
    cout << "2. Inteligência: " << inteligencia << endl;
    cout << "3. Educação: " << educacao << endl;
}

// Exibe os atributos principaisdo personagem
void exibirAtributosPrincipais(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int &forca = atributo.forca;
    int &constituicao = atributo.constituicao;
    int &tamanho = atributo.tamanho;
    int &destreza = atributo.destreza;
    int &aparencia = atributo.aparencia;
    int &inteligencia = atributo.inteligencia;
    int &poder = atributo.poder;
    int &educacao = atributo.educacao;
    int &sorte = atributo.sorte;

    cout << "Força: " << forca << endl;
    cout << "Constituição: " << constituicao << endl;
    cout << "Tamanho: " << tamanho << endl;
    cout << "Destreza: " << destreza << endl;
    cout << "Aparência: " << aparencia << endl;
    cout << "Inteligência: " << inteligencia << endl;
    cout << "Poder: " << poder << endl;
    cout << "Educação: " << educacao << endl;
    cout << "Sorte: " << sorte << endl;
}

// Exibe os atributos secundários do personagem
void exibirAtributosSecundarios(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int &corpo = atributo.corpo;
    int &pv = atributo.pv;
    int &mov = atributo.mov;

    cout << "Corpo: " << corpo << endl;
    cout << "Dano Extra (DX): " << dx[corpo + 2] << endl; // Exibe o dano extra baseado no valor de corpo
    cout << "Pontos de Vida (PV): " << pv << endl;
    cout << "Taxa de Movimento (MOV): " << mov << endl;
}

// Gera os atributos principais do personagem usando rolagens de dados
void gerarAtributos(Atributo &atributo) {
    // Referências locais para simplificar o acesso
    int &forca = atributo.forca;
    int &constituicao = atributo.constituicao;
    int &tamanho = atributo.tamanho;
    int &destreza = atributo.destreza;
    int &aparencia = atributo.aparencia;
    int &inteligencia = atributo.inteligencia;
    int &poder = atributo.poder;
    int &educacao = atributo.educacao;
    int &sorte = atributo.sorte;

    // Gera os valores dos atributos principais
    forca = dado(3, 6, 5, 0);
    constituicao = dado(3, 6, 5, 0);
    tamanho = dado(2, 6, 5, 30);
    destreza = dado(3, 6, 5, 0);
    aparencia = dado(3, 6, 5, 0);
    inteligencia = dado(2, 6, 5, 30);
    poder = dado(3, 6, 5, 0);
    educacao = dado(2, 6, 5, 30);
    sorte = dado(3, 6, 5, 0);
}

// Troca atributos entre si, permitindo ao jogador escolher quais trocar
void trocarAtributos(Atributo &atributo) {
    // Array de ponteiros para os atributos e seus nomes
    int* atributos[] = {
        &atributo.forca, &atributo.constituicao, &atributo.destreza,
        &atributo.aparencia, &atributo.poder, &atributo.sorte,
        &atributo.tamanho, &atributo.inteligencia, &atributo.educacao
    };
    // Array de nomes dos atributos
    const string nomesAtributos[] = {
        "Força", "Constituição", "Destreza",
        "Aparência", "Poder", "Sorte",
        "Tamanho", "Inteligência", "Educação"
    };
    const int totalAtributos = sizeof(atributos) / sizeof(atributos[0]);
    int escolha1, escolha2, aux; // Variável auxiliar para troca de atributos
    int opcao; // Variável para armazenar a opção do usuário

    // Exibe os atributos principais antes da troca
    exibirAtributos3d6(atributo);

    cout << endl << "Deseja trocar atributos principais? (1 para sim, 0 para não): ";
    cin >> opcao;

    if (opcao > 0) {
        do {
            cout << "Escolha dois atributos para trocar (1 a " << QNT_ATRIBUTOS_3D6 << "):" << endl;
            do {
                cin >> escolha1 >> escolha2;
            } while (escolha1 < 1 || escolha1 > QNT_ATRIBUTOS_3D6 || escolha2 < 1 || escolha2 > QNT_ATRIBUTOS_3D6 || escolha1 == escolha2); // Valida a entrada do usuário

            aux = *atributos[escolha1 - 1];
            *atributos[escolha1 - 1] = *atributos[escolha2 - 1];
            *atributos[escolha2 - 1] = aux;

            cout << "Trocando " << nomesAtributos[escolha1 - 1] << " e " << nomesAtributos[escolha2 - 1] << "..." << endl << endl;
            cout << endl << "Atributos após a troca:" << endl;
            exibirAtributos3d6(atributo); // Exibe os atributos após a troca

            cout << "Deseja trocar mais atributos principais? (1 para sim, 0 para não): ";
            cin >> opcao;
            limparTela(); // Limpa a tela antes de exibir o menu novamente
        } while (opcao > 0);
    } else {
        cout << "Nenhuma troca de atributos principais será realizada." << endl;
        pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
    }

    exibirAtributos2d6p5(atributo); // Exibe os atributos secundários antes da troca

    cout << endl << "Deseja trocar atributos secundários? (1 para sim, 0 para não): ";
    cin >> opcao;

    if (opcao > 0) {
        do {
            cout << "Escolha dois atributos para trocar (1 a " << QNT_ATRIBUTOS_2D6 << "):" << endl;
            do {
                cin >> escolha1 >> escolha2;
            } while (escolha1 < 1 || escolha1 > QNT_ATRIBUTOS_2D6 || escolha2 < 1 || escolha2 > QNT_ATRIBUTOS_2D6 || escolha1 == escolha2); // Valida a entrada do usuário

            aux = *atributos[escolha1 - 1 + QNT_ATRIBUTOS_3D6];
            *atributos[escolha1 - 1 + QNT_ATRIBUTOS_3D6] = *atributos[escolha2 - 1 + QNT_ATRIBUTOS_3D6];
            *atributos[escolha2 - 1 + QNT_ATRIBUTOS_3D6] = aux;

            cout << "Trocando " << nomesAtributos[escolha1 - 1 + QNT_ATRIBUTOS_3D6] << " e " << nomesAtributos[escolha2 - 1 + QNT_ATRIBUTOS_3D6] << "..." << endl;
            cout << "Atributos após a troca:" << endl;
            exibirAtributos2d6p5(atributo); // Exibe os atributos após a troca

            cout << "Deseja trocar mais atributos secundários? (1 para sim, 0 para não): ";
            cin >> opcao;
            limparTela(); // Limpa a tela antes de exibir os atributos secundários
        } while (opcao > 0);
    } else {
        cout << "Nenhuma troca de atributos secundários será realizada." << endl;
        pausarExecucao(); // Pausa a execução para o usuário ler a mensagem
    }
}

// Verifica se o atributo pode ser melhorado com base em uma rolagem de 1d100
void verificarMelhoriaAtributo(int &atributo) {
    int roll = (rand() % 100) + 1;
    if (roll > atributo) {
        atributo += (rand() % 10) + 1; // Incrementa o atributo em até 10 pontos
        if (atributo > 99) atributo = 99; // Limita o atributo ao máximo de 99
    }
}