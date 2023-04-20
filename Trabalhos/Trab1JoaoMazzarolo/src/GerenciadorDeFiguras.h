// Declaração da classe Gerneciador de Figuras

#ifndef GERENCIADORDEFIGURAS_H
#define GERENCIADORDEFIGURAS_H

#include "Figura.h"
#include "gl_canvas2d.h"
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class GerenciadorDeFiguras
{
private:
    list<Figura*> listaFiguras;
    int numTotal;
    Figura* selected;
    bool ctrl;

public:
    // Construtor da classe, criando um novo gerenciador de figuras vazio
    GerenciadorDeFiguras();

    // Carrega as figuras presentes em um arquivo para o gerenciador
    void carregarFiguras(FILE** arq, int chave);

    // Salva as figuras do gerenciador em um arquivo
    void salvarFiguras(FILE** arq, int chave);

    // Adiciona uma nova figura
    void adicionarFigura(Figura* base, int largTela, int altTela);

    // desenha todas as figuras do gerenciador
    void desenharFiguras(int largTela, int altTela);

    // Trata a verificação dos clicks nas figuras
    void verificarClick(int mx, int my, int button, int state, int canvasY);

    // Trata os inputs do teclado e suas alterações nas figuras
    void verificarMudancasTeclado(int key);

    // Trata mudanças que dependam do soltar de uma tecla do teclado
    void verificarSoltarTeclado(int key);

    // Trata as mudanças que envolvem o mouse, alem do click
    void verificarMudancasMouse(int wheel, int direction);

    // Colore a figura selecionada
    void colorirSelect(int cor);

    // Envia a figura para frente na renderização
    void enviarFrente();

    // Envia a figura para tras na renderização
    void enviarTras();

    // Adiciona uma copia da figura para a lista
    void adicionarClone();

    // Exclui uma figura
    void excluir();

    //Função usada para printar as labels
    void printLabels(int x, int y, int largura, int altura);

    // Retorna a figura selecionada
    Figura* getSelected();

    // Retorna o numero total
    int getNumTotal();
};


#endif // GERENCIADORDEFIGURAS_H
