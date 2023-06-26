#ifndef GLYPH_H
#define GLYPH_H

#include <fstream>
using namespace std;

/**
 * Classe que representa um glifo (símbolo) de uma fonte BDF.
 */
class Glyph {
  string name;        /// nome do glifo
  int encoding;       /// código do glifo (caractere), normalmente o valor ASCII
  int width;          /// largura da matriz de bits
  int height;         /// altura da matriz de bits
  int offset_x;       /// deslocamento em x para o início do glifo
  int offset_y;       /// deslocamento em y para o início do glifo
  int device_width_x; /// espaçamento em x a ser usado para o glifo
  int device_width_y; /// espaçamento em y a ser usado para o glifo
  bool* bitmap;       /// matriz de bits do glifo

 public:
  Glyph();
  ~Glyph();

  /**
   * Lê um glifo de um arquivo BDF atualizando os atributos da classe.
   * A leitura do arquivo já deve estar posicionado no início do glifo.
   * @param file canal do arquivo BDF
   */
  void read(istream &file);

  /** Consulta o nome do glifo. */
  string get_name() const { return name; }

  /** Consulta o código do glifo. */
  int get_encoding() const { return encoding; }

  /** Consulta a largura da matriz de bits do glifo. */
  int get_width() const { return width; }

  /** Consulta a altura da matriz de bits do glifo. */
  int get_height() const { return height; }

  /** Consulta o deslocamento em x para o início do glifo. */
  int get_x_offset() const { return offset_x; }

  /** Consulta o deslocamento em y para o início do glifo. */
  int get_y_offset() const { return offset_y; }

  /** Consulta o espaçamento em x a ser usado para o glifo. */
  int get_device_width_x() const { return device_width_x; }

  /** Consulta o espaçamento em y a ser usado para o glifo. */
  int get_device_width_y() const { return device_width_y; }

  /**
   * Consulta um bit da matriz de bit do glifo.
   * @param x coordenada x do bit
   * @param y coordenada y do bit
   * @return true se o bit está ligado (x,y), false caso contrário
   */
  bool get_bit(int x, int y) const { return bitmap[y * width + x]; }
};

#endif  // GLYPH_H