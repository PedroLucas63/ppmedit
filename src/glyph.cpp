#include <iostream>
#include <fstream>
#include <string>
#include "glyph.h"

using namespace std;

Glyph::Glyph() :
  encoding(0),
  width(0),
  height(0),
  offset_x(0),
  offset_y(0),
  device_width_x(0),
  device_width_y(0),
  bitmap(nullptr) {}

Glyph::~Glyph() {
  if (bitmap != nullptr) {
    delete[] this->bitmap;
  }
}

void Glyph::read(istream &file) {
  int swx0, swy0;
  int xoff, yoff;

  string prop = "";
  file >> this->name;

  while (prop != "ENDCHAR") {
    if (prop == "ENCODING") {
      file >> encoding;
    } else if (prop == "SWIDTH" || prop == "SWIDTH1") {
      file >> swx0 >> swy0; // SWIDTH é ignorado
    } else if (prop == "DWIDTH" || prop == "DWIDTH1") {
      file >> device_width_x >> device_width_y;
    } else if (prop == "VVECTOR") {
      file >> xoff >> yoff; // VVECTOR é ignorado
    } else if (prop == "BBX") {
      file >> width >> height >> offset_x >> offset_y;
    } else if (prop == "BITMAP") {
      string line;
      int size = width > 8 ? 16 : 8; // a quantidade de bits pode ser 8 ou 16
      this->bitmap = new bool[width * height]; // matriz como array unidimensional
      file.ignore(); // salta a linha porque a partir de agora todos os bytes serão lidos
      for (int i = 0; i < height; i++) {
        unsigned int v;
        getline(file, line);
        sscanf(line.c_str(), "%x", &v); // lê um inteiro no formato hexadecimal hexadecimal
        for (int j = 0; j < width; j++) {
          unsigned long long mask = 1 << (size - j - 1); // byte com apenas um bit ligado 
          bool isOn = (v & mask) != 0;  // verifica se o bit em v está ligado
          this->bitmap[i * width + j] = isOn; // atualiza o bit na matriz
        }
      }
    }
    file >> prop;
  }
}