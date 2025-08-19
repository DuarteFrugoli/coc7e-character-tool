# Criar e Salvar personagens Call of Cthulhu 7e

1. Criar jogador sem usar atributos aleatórios
2. Distribuir pontos de perícia
3. Criar antecedentes
4. Equipar o investigador
5. Menu no terminal
7. Salvar os personagens em JSON
9. Criar interface gráfica

## O que fazer no momento:

1. Conferir troca de atributos e geração personalizada
2. Terminar ocupacao.cpp e pericias.cpp
3. conferir .hs
4. aplicar jsons

g++ src\main.cpp src\atributo.cpp src\ocupacao.cpp src\pericia.cpp src\personagem.cpp src\util.cpp -I include -o build\personagem_coc7e.exe