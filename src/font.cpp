#include "font.h"

Font::Font() :
  name(""),
  num_glyphs(0),
  glyphs(nullptr) {}

Font::~Font() {
  if (glyphs != nullptr) {
    delete[] glyphs;
  }
}

void Font::read_bdf(const string filename) {
  int count_glyphs = 0;
  ifstream file(filename);
  string prop = "";

  while (prop != "CHARS") {
    file >> prop;
  }
  file >> num_glyphs;
  glyphs = new Glyph[num_glyphs];
  while (prop != "ENDFONT") {
    if (prop == "STARTCHAR") {
      glyphs[count_glyphs].read(file);
      count_glyphs++;
    }
    file >> prop;
  }
  file.close();
}

const Glyph* Font::get_glyph(int encoding) {
  for (int i = 0; i < num_glyphs; i++) {
    if (glyphs[i].get_encoding() == encoding) {
      return &glyphs[i];
    }
  }
  return nullptr;
}
