#include "GerenciadorDeFiguras.h"

GerenciadorDeFiguras::GerenciadorDeFiguras()
{
    numTotal = 0;
    selected = NULL;
    ctrl = false;
}

void GerenciadorDeFiguras::carregarFiguras(FILE** arq)
{
    *arq = fopen("figuras.gr", "rt");

    fscanf(*arq, "%d", &numTotal);

    printf("\n%d\n", numTotal);

    for(int i = 0; i < numTotal; i++)
    {
        int x, y, raio, numLados, color;
        float angulo;
        bool preenchido;
        fscanf(*arq, "%d%d%d%d%d%f%d", &x, &y, &raio, &numLados, &color, &angulo, &preenchido);
        Figura* fig = new Figura(x, y, raio, numLados, angulo);
        fig->colorir(color);
        if(preenchido)
            fig->trocarPreenchimento();
        listaFiguras.push_back(fig);
    }

    fclose(*arq);
}

void GerenciadorDeFiguras::salvarFiguras(FILE** arq)
{
    *arq = fopen("figuras.gr", "wt");

    fprintf(*arq, "%d ", numTotal);

    list<Figura*>::iterator fig;
    for (fig = listaFiguras.begin(); fig != listaFiguras.end(); ++fig)
    {
        (*fig)->salvar(arq);
    }

    fclose(*arq);
}

void GerenciadorDeFiguras::adicionarFigura(Figura* base, int largTela, int altTela)
{
    int raio;
    Figura* novaFigura = base->clonarFigura();
    if(largTela > altTela)
        raio = 0.1 * altTela;
    else
        raio = 0.1 * largTela;
    novaFigura->setFiguraConfig(largTela / 2, altTela / 2, raio);
    listaFiguras.push_back(novaFigura);
    numTotal++;
}

void GerenciadorDeFiguras::desenharFiguras(int largTela, int altTela)
{
    list<Figura*>::iterator fig;
    for (fig = listaFiguras.begin(); fig != listaFiguras.end(); ++fig)
    {
        (*fig)->desenhar();
    }
}

void GerenciadorDeFiguras::posicionarResponsivo(int largTela, int altTela)
{
    // fazer depois
}

void GerenciadorDeFiguras::verificarClick(int mx, int my, int button, int state, int canvasY)
{
    list<Figura*>::reverse_iterator fig;
    for (fig = listaFiguras.rbegin(); fig != listaFiguras.rend(); ++fig)
    {
        if((*fig)->click(mx, my, button, state))
        {
            if(selected)
                selected->setSelected();
            selected = (*fig);
            selected->setSelected();
            return;
        }
    }
    if(button == 0 && state == 0 && my < canvasY)
    {
        if(selected)
            selected->setSelected();
        selected = NULL;
    }
}

void GerenciadorDeFiguras::verificarMudancasTeclado(int key)
{
    if(selected)
    {
        switch(key)
        {
            case 100:   //preciona d para enviar a imagem para traz no desenho
                listaFiguras.remove(selected);
                listaFiguras.push_front(selected);
                break;
            case 102:   //preciona p para trocar o poreenchimento do desenho
                selected->trocarPreenchimento();
                break;
            case 117:   //preciona d para enviar a imagem para frente no desenho
                listaFiguras.remove(selected);
                listaFiguras.push_back(selected);
                break;
            case 127:
                listaFiguras.remove(selected);
                selected = NULL;
                free(selected);
                break;
            case 200:
                selected->girar(-0.02);
                break;
            case 201:
                selected->redimencionar(2);
                break;
            case 202:
                selected->girar(0.02);
                break;
            case 203:
                selected->redimencionar(-2);
                break;
            case 214:
                ctrl = true;
                break;
        }
    }
}

void GerenciadorDeFiguras::verificarSoltarTeclado(int key)
{
    if(selected)
    {
        switch(key)
        {
            case 214:
                ctrl = false;
                break;
        }
    }
}

void GerenciadorDeFiguras::verificarMudancasMouse(int wheel, int direction)
{
    if(!wheel && selected && !ctrl)
    {
        if(direction == 1)
            selected->redimencionar(2);
        else if(direction == -1)
            selected->redimencionar(-2);
    }
    else if(!wheel && selected && ctrl)
    {
        if(direction == 1)
            selected->girar(0.04);
        else if(direction == -1)
            selected->girar(-0.04);
    }
}

void GerenciadorDeFiguras::colorirSelect(int cor)
{
    if(selected)
        selected->colorir(cor);
}
