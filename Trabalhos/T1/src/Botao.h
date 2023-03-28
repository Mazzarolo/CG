#ifndef BOTAO_H
#define BOTAO_H

class Botao
{
private:
  float altura, largura, x, y;
  int corTexto, corBotao;
  int id;
  char label[100];
  bool escrito;

public:
  Botao(float x, float y, float largura, float altura, char *label, int id);
  Botao(float x, float y, float largura, float altura, int id);

  void colorir(int corTexto, int corBotao);

  void desenhar();

  bool click(int mx, int my, int button, int state);
};

#endif
