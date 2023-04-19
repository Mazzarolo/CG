// Declara��o das fun��es do arquivo Interface.cpp

#ifndef INTERFACE_H
#define INTERFACE_H

#include "GerenciadorDeBotoes.h"
#include "GerenciadorDeFiguras.h"
#include "EditorDeCor.h"

// Colore o fundo da aplica��o
void colorirFundo(float r, float g, float b);

// Fun��o que cria os botoes gerais da aplica��o
void criarBotoesGerais(GerenciadorDeBotoes** botoesGerais, int screenWidth, int screenHeight);

// Possui a verifica��o das op��es do gerenciador de botoes mostrados no bot�o direito
void verificarOpcoes(int op, Figura* selecionada, GerenciadorDeFiguras* figuras, EditorDeCor* sliders, bool* visivel);

#endif // INTERFACE_H
