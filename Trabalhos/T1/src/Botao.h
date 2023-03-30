#ifndef BOTAO_H
#define BOTAO_H

#include "Figura.h"

class Botao
{
private:
  float altura, largura, x, y;
  int corTexto, corBotao;
  int id;
  char label[100];
  bool escrito, clickDown;
  Figura* fig;

public:
  Botao(float x, float y, float largura, float altura, char *label, int id);
  Botao(float x, float y, float largura, float altura, int id);

  void atribuirFigura(int nLados, float angulo, int cor);

  void colorir(int corTexto, int corBotao);

  void desenhar();

  bool click(int mx, int my, int button, int state);

  void setBotaoConfig(int x, int y, int largura, int altura);

  void colorirFigura(int cor);
};

#endif
