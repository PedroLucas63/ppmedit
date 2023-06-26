#ifndef __FONT_H__
#define __FONT_H__

#include <string>
#include "glyph.h"

/**
 * Classe que representa uma fonte BDF.
 */
class Font {
  string name;    /// nome da fonte
  int num_glyphs; /// número de glifos na fonte
  Glyph* glyphs;  /// array com os glifos da fonte

 public:
  Font();
  ~Font();

  /**
   * Lê uma fonte BDF de um arquivo atualizando os atributos da classe.
   * @param filename nome do arquivo BDF
   */
  void read_bdf(const string filename);

  /**
   * Retorna o glifo em função da sua codificação (código de caractere).
   * @param encoding código do caractere
   * @return ponteiro para o glifo correspondente ou nullptr se não existir
  */
  const Glyph* get_glyph(int encoding);
};

#endif  // __FONT_H__