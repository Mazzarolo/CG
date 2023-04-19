// Declaração das funções do arquivo Interface.cpp

#ifndef INTERFACE_H
#define INTERFACE_H

#include "GerenciadorDeBotoes.h"
#include "GerenciadorDeFiguras.h"
#include "EditorDeCor.h"

// Colore o fundo da aplicação
void colorirFundo(float r, float g, float b);

// Função que cria os botoes gerais da aplicação
void criarBotoesGerais(GerenciadorDeBotoes** botoesGerais, int screenWidth, int screenHeight);

// Possui a verificação das opções do gerenciador de botoes mostrados no botão direito
void verificarOpcoes(int op, Figura* selecionada, GerenciadorDeFiguras* figuras, EditorDeCor* sliders, bool* visivel);

#endif // INTERFACE_H
