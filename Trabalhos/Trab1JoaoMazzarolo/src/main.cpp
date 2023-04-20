/*
Editor de Figuras - João Davi Rigo Mazzarolo

O que foi implementado:

* Trabalho Base:
    - Inserir/excluir figura.
    - Cor da figura.
    - Preenchimento da figura.
    - Editar tamanho da figura.
    - Editar orientação da figura.
    - Enviar para frente/traz.
    - Salvar em arquivo e carregar de arquivo.
* Bônus:
    - Sinalizar qual figura está selecionada;
    - Rotacionar figura em qualquer ângulo;
    - Aplicar criptografia no arquivo (Chave passada por parametro nos métodos de slavar/carregar);
    - Implementação de Sliders;
    - Painel com labels referentes às figuras desenhadas na tela, controlado por um slider;
    - Editor de cores personalizadas;
    - Interface parcialmente responsiva (Elementos de UI interagem com alteração da tela, porém as figuras desenhadas não);
    - Clonar figura;

Uma explicação de como usar o programa está no arquivo README.md, na pasta do projeto.
*/

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
#include "Slider.h"
#include "EditorDeCor.h"
#include "PainelLabels.h"

FILE *arq;  // variavel que guarda ponteiro para o arquivo que pode ser salvo/carregado
Botao *botaoSalvar = NULL;  // variavel onde será alocado o botão de salvar
GerenciadorDeFiguras *figuras = NULL;   //variavel que ira alcoar o gerenciador geral das figuras desenhadas na tela
GerenciadorDeBotoes *botoesGerais = NULL;   // variavel onde sera alocado o gerenciador de botões responsavel pelos botões de desenhar figuras
GerenciadorDeBotoes *cores = NULL;  // variavel onde sera alocado os botões de seleção de cores
GerenciadorDeBotoes *opcoes = NULL; //variavel onde sera alocado o gerenciador de botoes responsavel pelas opções mostradas ao precionar botão direito
EditorDeCor *sliders = NULL;        //variavel onde sera alocado o editor de cores
PainelLabels *labels = NULL;        //variavel que ira guardar o painel com as labels dos objetos
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
   sliders->moverResponsivo(screenWidth);
   botaoSalvar->desenhar();
   sliders->desenhar();
   labels->desenhar(screenWidth, screenHeight, figuras);
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

   if(button == 2 && y < 0.75 * screenHeight && selecionada && !sliders->onEditor(x, y))
   {
       visivel = true;
       opcoes->posicionar(x, y);
   }

   if(visivel && selecionada)
   {
       int op = opcoes->verificarClick(x, y, button, state);
       verificarOpcoes(op, selecionada, figuras, sliders, &visivel);
   }

   if(button == 0 && state == 1)
      visivel = false;
   if((!opcoes->onBotoes(x, y) || !visivel) && !sliders->onEditor(x, y) && y < 0.70 * screenHeight)
      figuras->verificarClick(x, y, button, state, 0.75 * screenHeight);
   figuras->verificarMudancasMouse(wheel, direction);
   if(sliders->verificarMouse(x, y, button, state) && selecionada)
      sliders->colorirFigura(selecionada);
    labels->verificarMouse(x, y, button, state);
}

//Inicialização de muitos gerenciadores usados na aplicação
int main(void)
{
   criarBotoesGerais(&botoesGerais, screenWidth, screenHeight);
   sliders = new EditorDeCor(screenWidth, 200, 100);
   labels = new PainelLabels(screenWidth, screenHeight, 0.7, 0.05);
   cores = new GerenciadorDeBotoes(14, 2, 93, 5, screenWidth, screenHeight);
   char* textos[] = {"Trocar Preenchimento", "Enviar para Frente", "Enviar para Tras", "Aumentar o Numero de Lados", "Diminuir o Numero de Lados",
                      "Aplicar Cor Personalizada", "Clonar Figura", "Excluir Figura"};
   opcoes = new GerenciadorDeBotoes(8, 50, 50, 300, 30, textos);
   figuras = new GerenciadorDeFiguras();
   botaoSalvar = new Botao(screenWidth * 5 / 100, screenHeight * 5 / 100, screenWidth * 12 / 100, screenHeight * 7 / 100, "Salvar", 0);
   botaoSalvar->colorir(0, 3);

   int cor[14];

   for(int i = 0; i < 14; i++)
      cor[i] = i;

   cores->colorirBotoes(cor);

   figuras->carregarFiguras(&arq, chave);

   CV::init(&screenWidth, &screenHeight, "Editor de Figuras");
   CV::run();
}
