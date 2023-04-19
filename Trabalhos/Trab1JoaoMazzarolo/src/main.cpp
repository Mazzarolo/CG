#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "gl_canvas2d.h"

#include "Botao.h"
#include "GerenciadorDeBotoes.h"
#include "GerenciadorDeFiguras.h"
#include "Figura.h"
#include "Interface.h"

FILE *arq;  // variavel que guarda ponteiro para o arquivo que pode ser salvo/carregado
Botao *botaoSalvar = NULL;  // variavel onde será alocado o botão de salvar
GerenciadorDeFiguras *figuras = NULL;   //variavel que ira alcoar o gerenciador geral das figuras desenhadas na tela
GerenciadorDeBotoes *botoesGerais = NULL;   // variavel onde sera alocado o gerenciador de botões responsavel pelos botões de desenhar figuras
GerenciadorDeBotoes *cores = NULL;  // variavel onde sera alocado os botões de seleção de cores
GerenciadorDeBotoes *opcoes = NULL; //variavel onde sera alocado o gerenciador de botoes responsavel pelas opções mostradas ao precionar botão direito
bool visivel = false;   // variavel que controla a visualização das opções do botão direito

int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.

int chave = 53;     //chave para a criptografia

// Função render
void render()
{
   colorirFundo(0.5, 0.5, 0.5);

   figuras->desenharFiguras(screenWidth, screenHeight);

   CV::color(0.1, 0.1, 0.1);
   CV::rectFill(0, 0.75 * screenHeight, screenWidth, screenHeight);
   botoesGerais->desenharBotoes(screenWidth, screenHeight);
   cores->desenharBotoes(screenWidth, screenHeight);
   botaoSalvar->setBotaoConfig(screenWidth * 5 / 100, screenHeight * 5 / 100, screenWidth * 12 / 100, screenHeight * 7 / 100);
   botaoSalvar->desenhar();
   if(visivel)
      opcoes->desenharBotoes();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   switch(key)
   {
      case 27:
	     exit(0);
	  break;
   }

   figuras->verificarMudancasTeclado(key);
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   figuras->verificarSoltarTeclado(key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   if(!visivel)
   {
        int figuraAdicionada = botoesGerais->verificarClick(x, y, button, state);

        if(figuraAdicionada != -1)
        {
            figuras->adicionarFigura(botoesGerais->getFigura(figuraAdicionada), screenWidth, screenHeight);
        }

        int corSelect = cores->verificarClick(x, y, button, state);

        if (corSelect != -1)
        {
           botoesGerais->colorirFiguras(corSelect);
           figuras->colorirSelect(corSelect);
        }
   }

   if(botaoSalvar->click(x, y, button, state))
   {
       figuras->salvarFiguras(&arq, chave);
   }

   Figura* selecionada = figuras->getSelected();

   if(button == 2 && y < 0.75 * screenHeight && selecionada)
   {
       visivel = true;
       opcoes->posicionar(x, y);
   }

   if(visivel && selecionada)
   {
       int op = opcoes->verificarClick(x, y, button, state);
       verificarOpcoes(op, selecionada, figuras, &visivel);
   }

   if(button == 0 && state == 1)
      visivel = false;
   if(!opcoes->onBotoes(x, y) || !visivel)
      figuras->verificarClick(x, y, button, state, 0.75 * screenHeight);
   figuras->verificarMudancasMouse(wheel, direction);
}

//Inicialização de muitos gerenciadores usados na aplicação
int main(void)
{
   criarBotoesGerais(&botoesGerais, screenWidth, screenHeight);
   cores = new GerenciadorDeBotoes(14, 2, 93, 5, screenWidth, screenHeight);
   char* textos[] = {"Trocar Preenchimento", "Enviar para Frente", "Enviar para Tras", "Aumentar o Numero de Lados", "Diminuir o Numero de Lados",
                      "Clonar Figura", "Excluir Figura"};
   opcoes = new GerenciadorDeBotoes(7, 50, 50, 300, 30, textos);
   figuras = new GerenciadorDeFiguras();
   botaoSalvar = new Botao(screenWidth * 5 / 100, screenHeight * 5 / 100, screenWidth * 12 / 100, screenHeight * 7 / 100, "Salvar", 0);
   botaoSalvar->colorir(0, 3);

   int cor[14];

   for(int i = 0; i < 14; i++)
      cor[i] = i;

   cores->colorirBotoes(cor);

   figuras->carregarFiguras(&arq, chave);

   CV::init(&screenWidth, &screenHeight, "Editor de imagens");
   CV::run();
}
