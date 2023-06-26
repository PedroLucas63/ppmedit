# Polaroid

Nossa sociedade é em parte definida pelas ferramentas que usamos. Isso porque as informações que consumimos (e as que geramos) são criadas pelas ferramentas (tecnologias) que temos à disposição. As câmeras embutidas nos nossos celulares certamente fazem parte desse rol de ferramentas que ajudaram a transformar nossa sociedade, seja pela divulgação viral de um momento espontâneo "fofo", seja pela denúncia de atrocidades ocorrendo, ali "ao vivo".

Hoje, é fácil registrar um fato ocorrido e rapidamente ver a foto (ou filme) do que se passou. Mas imagine como era há algumas décadas, quando, para ver o resultado de um "click", era necessário aguardar o rolo do filme da máquina fotográfica terminar, ir numa loja de revelação, esperar mais alguns dias para as fotos serem reveladas... e finalmente ver que (talvez) aquela desejada foto não prestou!

Foi tentando suprir essa frustação que um gadget ressurgiu com força nos anos 80's e 90's. Sim, a tecnologia era antiga (do final dos anos 40's), mas só conseguiu ser tendência quando um maior número de pessoas tiveram capital para adquiri-la. Bem... não muitos, mas o suficiente para se vender como "objeto de desejo".

Era uma câmera fotográfica especial chamada Polaroid, cujas fotos eram reveladas no instante em que eram tiradas. A Polaroid moldou o comportamento de parte de uma geração, permitindo que jovens (com um certo poder aquisitivo) tirassem fotos "instagramáveis", numa época que Instagram podia ser confundido com uma unidade de medida (uhg! desculpa a piada sem graça... foi mais forte do que eu!).

Ao revelar suas fotos, a Polaroid deixava uma borda branca ao redor da imagem e uma borda ainda maior na base da foto. Não era uma questão de design. Era uma limitação da tecnologia. Mas o que era limitação virou uma "feature", uma marca registrada indicando que a foto foi tirada numa Polaroid! E ainda dava espaço para o autor escrever um texto sobre a lembrança do momento. A limitação (oops! feature) ganhou tanto respaldo que algumas lojas de revelação davam a opção de revelar "estilo Polaroid" (mesmo entregando as fotos dias depois).

Como toda tecnologia que revoluciona uma época, ela morre com a próxima tecnologia revolucionária. Não foi diferente com a Polaroid. Assim que o primeiro smartphone (de verdade) surgiu (o iPhone), a empresa Polaroid decretou falência. Não tinha como competir com um celular, que, entre várias utilidades, podia também tirar fotos, conferir no mesmo momento como elas ficaram... e sem o custo da revelação.

O que ficou da Polaroid foi nostalgia. Uma nostalgia tão forte que aquela limitação tecnológica, que tinha virado marca registrada, passou a ser introduzida nas imagens, agora digitais, como "efeito visual". As câmeras embutidas nos smartphones e softwares de edição de fotos passaram a aplicar efeitos para gerar imagens semelhantes às geradas na época da Polaroid.

É nessa linha que o presente projeto se enquadra. O projeto tem como objetivo desenvolver um programa para aplicar o efeito Polaroid em uma imagem, criando bordas brancas ao seu redor e uma mais larga na sua base. De quebra, uma mensagem ainda pode ser escrita na base... como "nos velhos tempos".

## O programa a ser desenvolvido

O programa a ser desenvolvido deverá:
1. ler uma imagem PPM, seja ela no formato P3 ou P6 (descrito a seguir);
1. aumentar o tamanho da imagem adicionando bordas brancas ao redor;
1. deixar a borda branca na base da imagem com um espaço ainda maior;
1. ler uma fonte de texto no formato BDF (descrito a seguir);
1. ler um texto da entrada-padrão;
1. escrever o texto na imagem usando a fonte lida, e por fim;
1. salvar a imagem alterada no formato PPM P6.


## Imagens PPM P6

Na primeira atividade, você trabalhou com imagens no formato PPM tipo P3, no qual os valores dos componentes RGB dos pixels são definidos por valores inteiros no formato textual. Porém, há um tipo de imagem PPM mais compacta, chamado P6, que armazena as mesmas informações, mas o arquivo fica significativamente menor.

O tipo P6 tira vantagem do fato dos valores dos componentes RGB se encontrarem normalmente na faixa de 0 a 255. Ou seja, eles usam valores que podem ser representados por um byte (8 bits). Assim, no arquivo P6, cada componente é guardado em apenas um byte.

O cabeçaho do arquivo é similar ao tipo P3, contendo inicialmente a informação sobre o tipo (só que nesse caso a informação é "P6"), as dimensões (largura e altura), o valor 255 indicando o valor máximo na escala de cores e, por fim, uma sequência de bytes. Nessa sequência, um novo pixel é definido a cada 3 bytes, correspondendo aos valores R, G e B do pixel.

Por exemplo, o arquivo P6 abaixo contém um cabeçalho com as informações do tipo (P6), as dimensões (largura 3 e altura 2) em pixel, o valor máximo da cor (255) e, na linha seguinte, uma sequência de 18 bytes. Os valores dos bytes são representados visualmente (usando a tabela ASCII) pelo texto `zzz!!!~~~000]]]LLL`.

```ppm
P6
3 2
255
zzz!!!~~~000]]]LLL
```

Esse exemplo usa apenas caracteres visíveis para facilitar a representação de valores inteiros. Porém, os bytes a serem armazenados no arquivo podem ser qualquer valor entre 0 e 255, independentemente se seu caractere correspondente na table ASCII é visível ou não.

Como na tabela ASCII `z` vale 122, `!` vale 33, `~` vale 126, `0` vale 48, `]` vale 93 e `L` vale 76, o arquivo P6 acima equivaleria ao seguinte arquivo P3.

```ppm
P3
3 2
255
122 122 122 33 33 33 126 126 126
 48  48  48 93 93 93  76  76  76
```

Veja que, nessa imagem de dimensões pequenas (3 x 2) o arquivo P3 já é bem maior que o arquivo P6. Imagine então um arquivo de tamanho 1024 x 600.


## Fonte (tipográfica) BDF

Fontes tipográficas são usadas desde a criação do primeiro livro impresso. Elas definem o conjunto de símbolos (glifos), junto com suas formas e características, a serem usados na impressão de um texto. Nos séculos passados, tínhamos as fontes metálicas usadas nas prensas de jornais (impressão) ou nas máquinas de datilografar. Atualmente, as fontes são definidas em arquivos e usadas para informar como cada caractere será representado visualmente.

Há basicamente 3 tipos de fontes usadas digitalmente:
* **Fontes baseadas em vetores**: usam instruções de como os traços devem ser desenhados através de fórmulas matemáticas como curvas de Bézier, por exemplo, para representar as letras.
* **Fontes baseadas em strokes**: especificam um conjunto de linhas e suas características que, juntas, formam as letras.
* **Fontes baseadas em bitmaps**: definem matrizes de pontos (ou pixels) a serem ativados para cada letra.

As duas formas iniciais de representação são mais flexíveis e amplamente utilizadas em praticamente todos editores de imagem. A representação através de bitmaps não é mais tão usada atualmente, mas é, entretanto, mais simples de representar e eficiente. Por isso, alguns jogos 2D ainda a utilizam na renderização de textos durante o jogo.

Além da eficiência, há a vantagem para o presente projeto do formato ser mais simples que os demais. Entre os diferentes formatos de arquivo de fontes baseadas em bitmap, o formato BDF (*Glyph Bitmap Distribution Format*) é o mais simples de se trabalhar devido a ser textual. 

Um exemplo de arquivo BDF encontra-se abaixo. Nesse arquivo exemplo, especificamos apenas a letra `A`.

```bdf
STARTFONT 2.1
FONT -gnu-unifont-medium-r-normal--16-160-75-75-c-80-iso10646-1
SIZE 16 75 75
FONTBOUNDINGBOX 16 16 0 -2
STARTPROPERTIES 2
FONT_ASCENT 14
FONT_DESCENT 2
ENDPROPERTIES
CHARS 1
STARTCHAR A
ENCODING 65
SWIDTH 500 0
DWIDTH 8 0
BBX 8 16 0 -2
BITMAP
00
00
00
00
18
24
24
42
42
7E
42
42
42
42
00
00
ENDCHAR
ENDFONT
```

O projeto fornece um conjunto de arquivos `.h` e `.cpp` para facilitar a leitura de um arquivo BDF.

## Recursos iniciais

Para o pontapé inicial do projeto, foram disponibilizados alguns recursos úteis, organizados nas seguintes pastas:

* fonts
* imgs
* src

### Pasta `fonts`

Na pasta `fonts`, há quatro arquivos no formato BDF para você testar junto ao teu programa. A fonte no arquivo `a.bdf` possui uma única letra representada, o `A`. Essa fonte pode ser útil para você testar a "impressão" de um caractere simples em uma imagem vazia, por exemplo.

O arquivo `ib16x16u.bdf` é uma fonte utilizada nos terminais dos antigos PCs (modelo IBM). Ela foi baixada do site de [fontes da IBM](https://github.com/farsil/ibmfonts). Outras fontes BDF podem ser baixadas desse site e utilizadas no teu programa.

Os arquivos `highlander_std.bdf` e `satisfy16.bdf` são arquivos gerados por um programa de conversão de fontes TrueType (baseada em vetor) para BDF através do utilitário `otf2bdf`. Este utilitário foi [baixado](https://github.com/jirutka/otf2bdf) e compilado para Linux.

Assim, caso você queira usar uma fonte nas tuas fotos que seja diferente das fornecidas aqui, você poderá converter a fonte desejada, se ela estiver nos formatos `.ttf` ou `.otf`, usando o utilitário `otf2bdf`. Para saber as possíveis opções e como usá-lo, digite:

```sh
.\otf2bdf -h
```

### Pasta `imgs`

Na pasta `imgs`, há três imagens PPM que você poderá usar como teste no teu programa. A imagem `empty.ppm` é uma imagem P6 de tamanho pequeno (100 x 100) e completamente preta (todos os bytes são 0). Ela serve para você validar a leitura de um arquivo no formato PPM e para usá-la como imagem de teste na impressão dos caracteres.

A imagem `galinhos.ppm` é a mesma imagem P3 utilizada na 1a atividade. É uma imagem pequena (72 x 128) e serve para testar a leitura no formato P3, seguida da gravação da mesma imagem no formato P6.

A imagem `farol.ppm` também é uma cena de galinhos, porém é uma imagem maior (1200 x 400) útil validar a leitura de uma imagem de tamanho qualquer.

Você também pode usar tuas próprias imagens no projeto. Caso a imagem que você deseja "Polaroidizar" esteja em um formato diferente (.jpg, .png,...), você pode usar aplicativos como o [IrfanView](https://www.irfanview.com/) (se estiver no Windows) ou serviços online de conversão de imagens. Normalmente, os programas convertem para o formato P6, que agora teu programa irá dar suporte.

### Pasta `src`

Esta pasta contém arquivos com código C++ a ser usado como pontapé inicial do teu programa. Os arquivos são:
* `main.cpp`: contém a função `main()`.
* `font.h` e `font.cpp`: definem a classe `Font`, que representa uma fonte para impressão do texto. Essa classe deve ser completada por você para que ela possa ser usada.
* `glyph.h` e `glyph.cpp`: definem a classe `Glyph`, que representa um glifo (símbolo). A classe está completa e pode ser usada tal como foi definida aqui no teu projeto.
* `Makefile`: esse é um arquivo para automatizar o processo de compilação do teu programa. Você deve alterá-lo em função dos novos arquivos que você criar no projeto.

## Funcionamento do programa

O programa deverá aplicar o efeito de Polaroid de acordo com argumentos passados em linha de comando. Teu programa deverá portanto responder aos seguintes argumentos:

* `-h` (*help*): Imprime informações sobre o uso do programa, indicando os possíveis argumentos e o que eles fazem.
* `-i` (*input*): Indica no argumento seguinte o caminho do arquivo da imagem PPM cujo efeito Polaroid será aplicado.
* `-o` (*output*): Indica no argumento seguinte o caminho do arquivo onde a imagem com efeito Polaroid será salva.
* `-f` (*font*): Indica no argumento seguinte o caminho do arquivo de fonte a ser usado para imprimir a mensagem na imagem.
* `-b` (*border*): Indica em pixels a largura das bordas a serem acrescentadas ao redor da imagem.
* `-s` (*space*): Indica e pixels a largura da borda adicional na base da imagem.

Caso algum desses argumentos não seja fornecido pelo usuário, o programa deverá assumir um valor padrão. Por exemplo, pode-se assumir uma fonte padrão para os textos, um arquivo de saída padrão, uma espessura de borda etc.

Ao executar o programa, ele deve solicitar da entrada-padrão a mensagem a ser impressa na imagem. Vale salientar que as imagens podem ser de qualquer tamanho.

Além dessas funcionalidades, você pode ser criativo e incluir novos usos para teu programa. Por exemplo, pode-se aplicar decalques (imagens menores) sobre a imagem, inserir emojis ou balões de falas... Enfim, esta é uma parte de desenvolvimento livre. 


## Critérios de correção

**Funcionalidades**

* Argumentos em linha de comando
    * Todos os argumentos passados são lidos da linha de comando?
    * Caso algum argumento não seja passado, é assumido um valor padrão?
* Leitura do arquivo de imagem
    * a leitura se adequa à informação do tipo que se encontra no cabeçalho (P3 ou P6)?
    * a leitura se adequa ao tamanho da imagem (pode ser de qualquer tamanho)?
* Criação do efeito Polaroid
    * a imagem é redimensionada corretamente em função da largura das bordas e do espaço para o texto?
* Leitura da fonte
    * o arquivo de fonte é lido corretamente, com todos os glifos?
* Impressão do texto
    * a fonte é usada corretamente para imprimir o texto lido da entrada-padrão?
* Gravação do arquivo de imagem
    * a gravação do arquivo com a nova imagem é realizada no formato P6 de forma correta?
* ????
    * Este é um item aberto para você inserir uma nova funcionalidade no teu programa.

**Código**

* Novas classes
    * Novas classes foram especificadas usando os arquivos `.h` e `.cpp` adequadamente?
    * Nas novas classes, há atributos e métodos, alguns privados outros públicos?
* Alocação dinâmica
    * Utilizou-se alocação dinâmica de forma adequada?
    * Tomou-se cuidado para desalocar o que não era mais útil?
* Organização e documentação
    * O código foi devidamente documentado (seguindo o modelo de documentação no código existente)?
    * O código segue um padrão de identação, nomenclatura e organização?

Vale salientar que estes requisitos se referem ao que *você* irá codificar. Ou seja, o código fornecido na pasta `src` não será levado em conta na avaliação do projeto. Se necessário, ele poderá ser, entretanto, alterado em função das necessidades do teu código.

