#ifndef BOTAO_H
#define BOTAO_H

class Botao
{
  float altura, largura, x, y;
  int corTexto, corBotao;
  char label[100];
  bool escrito;

public:
  Botao(float x, float y, float largura, float altura, char *label);
  Botao(float x, float y, float largura, float altura);

  void colorir(int corTexto, int corBotao);

  void desenhar();

  bool colidiu(int mx, int my);
};

#endif
