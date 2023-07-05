/**
 * @file Font.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Stores source information in BDF format.
 * @version 2.0
 * @date 2023-07-03
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef FONT_HPP
#define FONT_HPP

#include <iostream>
#include <string>
#include "Glyph.hpp"

/**
 * @class Font class.
 * @author André Maurício (andre@dimap.ufrn.br)
 * @brief Font definition with attributes and methods.
 */
class Font {
public:
   /**
    * @brief Construct a new Font object.
    */
   Font() :
      name(""),
      num_glyphs(0),
      glyphs(nullptr) { }

   /**
    * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
    * @brief Construct a new Font object with read BDF file.
    * 
    * @param filename Font filename.
    * @see readBDF()
    */
   Font(std::string const filename) : name("") {
      readBDF(filename);
   }

   /**
    * @brief Destroy the Font object.
    */
   ~Font() {
      if (glyphs != nullptr) {
         delete[] glyphs;
      }
   }

   /**
    * @brief Read a BDF file and store the glyphs.
    * 
    * @param filename Font filename.
    */
   void readBDF(std::string const filename) {
      int count_glyphs = 0;
      std::ifstream file(filename);
      std::string prop = "";

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

   /**
    * @brief Find the glyph referring to an encoding.
    * 
    * @param encoding Encoding to search.
    * @return Pointer to glyph.
    */
   Glyph const* getGlyph(int encoding) const {
      for (int i = 0; i < num_glyphs; i++) {
      if (glyphs[i].getEncoding() == encoding) {
         return &glyphs[i];
      }
   }
   return nullptr;
   }

private:
   std::string name; /**< Name */
   int num_glyphs;   /**< Number of glyphs */
   Glyph* glyphs;    /**< Glyphs */
};

#endif // FONT_HPP
