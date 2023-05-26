#include <iostream>
#include "../libs/Editor.hpp" //! Include Editor header

using namespace std;

/**
 * Imprime uma ajuda explicando como o programa deve ser usado.
 * @param program_name Nome do arquivo executável.
 */
void printUsage(string program_name) {
  cerr << "Usage:" << endl;
  cerr << '\t' << program_name << " <operation>" << endl;
  cerr << "Where <operation> can be:" << endl;
  cerr << '\t' << "gray: for creating a grayscale version of the original image." << endl;
  cerr << '\t' << "enlarge: for enlarging the original image 2x." << endl;
  cerr << '\t' << "reduce: for reducing the original image 2x." << endl;
  cerr << '\t' << "rotate: for rotating the image 90 degrees clockwise." << endl;
  cerr << '\t' << "sharp: for sharpening the image." << endl;
  cerr << '\t' << "blur: for blurring the image." << endl;
  cerr << endl;
  cerr << "The original image is read from the standard input and the transformed";
  cerr << "image is sent to the standard output." << endl;
}

/**
 * Função principal: ponto de partida do programa.
 */
int main(int argc, char* argv[]) {
  /*
    argc e argv são parâmetros padrões na função main(). Enquanto argc indica quantos
    argumentos foram passados para o programa, argv contém esses argumentos na ordem
    em que eles foram passados. argc será sempre >= 1, pois argv[0] terá o nome do programa.
    Por exemplo, se um programa com `meu_prog` for chamado assim:
    $ ./meu_prog abc def ghi
    argc terá o valor 4, indicando que há 4 argumentos, sendo o 1º (argv[0]) o nome do
    próprio programa ("./meu_prog"), o 2º (argv[1]) será "abc", o 3º (argv[2]) será "def"
    e, por fim, o 4º (argv[3]) será "ghi."
  */
  if (argc != 2) {
    // se não houver 2 argumentos, então o programa está sendo usado incorretamente.
    // deve-se portanto imprimir como usá-lo.
    printUsage(argv[0]);
  }
  else {
    string operation = argv[1]; // transforma o array de caracteres em string.

    string type { "" };
    int width { 0 };
    int height { 0 };
    int colors { 0 };

    cin >> type >> width >> height >> colors;

    Image image { width, height, colors };

    for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
        int red { 0 };
        int green { 0 };
        int blue { 0 };

        cin >> red >> green >> blue;

        Pixel pixel { red, green, blue, colors };

        image.setPixel(pixel, row, column);
      }
    }

    Editor editor { image };

    if (operation == "gray") {
      editor.grayscaleImage();
    } else if (operation == "enlarge") {
      editor.enlargeImage();
    }

    editor.exportData();
  }

  return 0;
}