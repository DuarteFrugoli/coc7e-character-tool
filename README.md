[English version](README_en.md)

# Criar e Salvar Personagens Call of Cthulhu 7e

Este projeto tem como objetivo criar um sistema para gerar, personalizar e salvar personagens para o RPG de mesa **Call of Cthulhu 7ª Edição**. Ele está sendo desenvolvido com o auxílio de inteligência artificial, incluindo o **GitHub Copilot** (sou eu, olá pessoal! 👋), diretamente no Visual Studio Code.

## O que o projeto é no momento

Atualmente, o projeto está em fase de desenvolvimento inicial, com foco em:
- Criar personagens com atributos aleatórios e não aleatórios.
- Permitir a distribuição de pontos de perícia.
- Adicionar antecedentes e equipamentos aos personagens.
- Implementar um menu funcional no terminal.
- Salvar os personagens em arquivos JSON para fácil acesso e edição.

## O que o projeto pretende se tornar

O objetivo final é transformar este sistema em uma ferramenta completa e eficiente, com:
- Dois arquivos executáveis:
  - Um para os jogadores, onde será possível criar personagens da maneira que preferirem, seguindo as regras do jogo. Essas regras serão explicadas conforme o usuário for criando o personagem. No final, o programa gerará um arquivo `.json` contendo os dados do personagem.
  - Outro para o mestre, que permitirá carregar os arquivos `.json` enviados pelos jogadores. Este programa exibirá os detalhes das fichas conforme necessário e permitirá que o mestre faça alterações nas mesmas.
- Interface gráfica para facilitar o uso.

## Origem do projeto

Este projeto é uma versão melhorada de um antigo trabalho desenvolvido no primeiro período da faculdade. Ele foi reformulado e expandido para atender às necessidades de jogadores de **Call of Cthulhu 7e**, com novas funcionalidades e uma abordagem mais profissional.

Fique à vontade para acompanhar o progresso e contribuir com ideias ou sugestões. Vamos juntos criar algo incrível!

## Requisitos

- Ter o [CMake](https://cmake.org/download/) instalado.
- Ter um compilador C++ (g++ ou MSVC) instalado.

## Como clonar o projeto

```bash
git clone https://github.com/DuarteFrugoli/coc7e-character-tool.git
cd coc7e-character-tool
```

## Como executar o projeto

1. Crie uma pasta para os arquivos de build:
```bash
mkdir build
cd build
```

2. Gere os arquivos de build usando o CMake:
```bash
cmake ..
```

3. Compile o projeto:
```bash
cmake --build .
```

4. Execute o programa:

- No Windows:
```bash
jogador\jogador.exe
```

- No Linux:
```bash
./jogador/jogador
```

## Licença

Licença MIT

Copyright (c) 2025 Duarte Frugoli

A permissão é concedida, gratuitamente, a qualquer pessoa que obtenha uma cópia
deste software e dos arquivos de documentação associados (o "Software"), para
lidar com o Software sem restrições, incluindo, sem limitação, os direitos de
usar, copiar, modificar, mesclar, publicar, distribuir, sublicenciar e/ou vender
cópias do Software, e permitir que pessoas a quem o Software é fornecido o façam,
sujeito às seguintes condições:

O aviso de copyright acima e este aviso de permissão deverão ser incluídos em todas
as cópias ou partes substanciais do Software.

O SOFTWARE É FORNECIDO "NO ESTADO EM QUE SE ENCONTRA", SEM GARANTIA DE QUALQUER
ESPÉCIE, EXPRESSA OU IMPLÍCITA, INCLUINDO MAS NÃO SE LIMITANDO ÀS GARANTIAS DE
COMERCIALIZAÇÃO, ADEQUAÇÃO A UM DETERMINADO FIM E NÃO INFRAÇÃO. EM NENHUMA
HIPÓTESE OS AUTORES OU DETENTORES DOS DIREITOS AUTORAIS SERÃO RESPONSÁVEIS POR
QUALQUER REIVINDICAÇÃO, DANO OU OUTRA RESPONSABILIDADE, SEJA EM UMA AÇÃO DE
CONTRATO, ATO ILÍCITO OU DE OUTRA FORMA, DECORRENTE DE OU EM CONEXÃO COM O
SOFTWARE OU O USO OU OUTRAS.