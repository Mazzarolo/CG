# Editor de Figuras
## João Davi Rigo Mazzarolo

### Como usar o programa:

* Os botões com figuras na tela inicial servem para gerar figuras com 3, 4, 6 e 30(circulo) lados respectivamente;
* Figuras podem ser selecionadas com o mouse, e arrastadas também pelo mouse (Figuras selecionadas possuem uma animação de seleção ao seu redor);
* Os botões com cores na tela inicial servem para colorir as figuras, caso elas estejam selecionadas, ou gerar a proxima figura com cor selecionada;
* O menu no canto superior direito permite trocar a cor da figura selecionada para uma cor personalizada (Clicando na cor do menu ou nos Sliders);
* Caso uma figura esteja selecionada, precionar o botão direito do mouse revela um menu, com as seguintes opções:
    - Trocar Preenchimento (Preenche a cor da figura se ela estiver despreenchida, ou despreenche caso ela já esteja preenchida);
    - Enviar para Frente (Faz a figura ser desenhada por cima de todas as outras);
    - Enviar para Trás (Faz a figura ser desenhada atrás de todas as outras);
    - Aumentar o Número de Lados (Aumenta em um o numero de lados da figura selecionada);
    - Diminuir o Número de Lados (Diminui em um o numero de lados da figura selecionada);
    - Aplicar Cor Personalizada (Outra forma de colorir a figura com a cor personalizada do painel no canto superior direito);
    - Clonar Figura (Cria uma copia exata da figura selecionada no mesmo lugar);
    - Excluir Figura (Exclui a figura selecionada);
* Caso uma figura esteja selecionada, também é possivel interagir com ele utilizando inputs com o mouse e teclado, sendo eles:
    - Scroll do Mouse/Setas para cima e para baixo (Aumentam e Diminuem a figura);
    - (Ctrl + Scrol do Mouse)/Setas para os lado (Rotacionam a figura);
    - Tecla D (Envia a figura para tras);
    - Tecla U (Envia a figura para frente);
    - Tecla P (Troca o preenchimento da figura);
    - Del (Exclui a figura);
* O botão Salvar no canto superior esquerdo salva configuração atual do desenho no arquivo figuras.gr;
* O arquivo figuras.gr é carregado quando a aplicação é aberta;

### O que foi implementado:

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
    - Editor de cores personalizadas;
    - Interface parcialmente responsiva (Elementos de UI interagem com alteração da tela, porém as figuras desenhadas não);
    - Clonar figura;
