/**
 * @file Fonts.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Fonts standards.
 * @version 2.0
 * @date 2023-07-18
 * 
 * Definition of default fonts and functions to pick up a font and/or an 
 * emoji by name.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef FONTS_HPP
#define FONTS_HPP

#include <iostream>
#include "Font.hpp"

/**
 * @brief Global Highlander font.
 */
Font const HIGHLANDER { "assets/fonts/highlander_std.bdf" };

/**
 * @brief Global IBM Bios 16x16 font.
 */
Font const IBM_BIOS { "assets/fonts/ib16x16u.bdf" };

/**
 * @brief Global Satisfy font.
 */
Font const SATISFY { "assets/fonts/satisfy16.bdf" };

/**
 * @brief Global DS Net Child font.
 */
Font const NETCHILD { "assets/fonts/DSnetChild.bdf" };

/**
 * @brief Global Love Script font.
 */
Font const LOVESCRIPT { "assets/fonts/LoveScript.bdf" };

/**
 * @brief Global Pixel Icons Compilation font.
 */
Font const PIXELICONS { "assets/fonts/PixelIconsCompilation.bdf" };

/**
 * @brief Get the global font by font name.
 * 
 * @param font_name Font name.
 * @return An global font.
 */
Font const& getFontByName(std::string font_name) {
   if (font_name == "highlander") {
      return HIGHLANDER;
   } else if (font_name == "satisfy") {
      return SATISFY;
   } else if (font_name == "netchild") {
      return NETCHILD;
   } else if (font_name == "love") {
      return LOVESCRIPT;
   }

   return IBM_BIOS;
}

/**
 * @brief Get the emoji by emoji code.
 * 
 * @param emoji_code Emoji code.
 * @return Pointer to glyph.
 */
Glyph const* getEmojiByCode(std::string emoji_code) {
   char encoding;

   if (emoji_code == ":heart:") {
      encoding = 'B';
   } else if (emoji_code == ":anchor:") {
      encoding = 'C';
   } else if (emoji_code == ":syringe:") {
      encoding = 'D';
   } else if (emoji_code == ":deer:") {
      encoding = 'E';
   } else if (emoji_code == ":dog:") {
      encoding = 'F';
   } else if (emoji_code == ":sun:") {
      encoding = 'G';
   } else if (emoji_code == ":umbrella:") {
      encoding = 'H';
   } else if (emoji_code == ":potion:") {
      encoding = 'I';
   } else if (emoji_code == ":plane:") {
      encoding = 'J';
   } else if (emoji_code == ":tank:") {
      encoding = 'K';
   } else if (emoji_code == ":squid:") {
      encoding = 'L';
   } else if (emoji_code == ":bug:") {
      encoding = 'M';
   } else if (emoji_code == ":cat:") {
      encoding = 'N';
   } else if (emoji_code == ":arrows:") {
      encoding = 'O';
   } else if (emoji_code == ":white-skull:") {
      encoding = 'P';
   } else if (emoji_code == ":farmer:") {
      encoding = 'Q';
   } else if (emoji_code == ":high-heels:") {
      encoding = 'R';
   } else if (emoji_code == ":cutlery:") {
      encoding = 'S';
   } else if (emoji_code == ":shit:") {
      encoding = 'T';
   } else if (emoji_code == ":helicopter:") {
      encoding = 'U';
   } else if (emoji_code == ":television:") {
      encoding = 'V';
   } else if (emoji_code == ":bird:") {
      encoding = 'W';
   } else if (emoji_code == ":snow:") {
      encoding = 'X';
   } else if (emoji_code == ":octopus:") {
      encoding = 'Y';
   } else if (emoji_code == ":sad:") {
      encoding = 'Z';
   } else if (emoji_code == ":ant:") {
      encoding = 'a';
   } else if (emoji_code == ":cup:") {
      encoding = 'b';
   } else if (emoji_code == ":snake:") {
      encoding = 'c';
   } else if (emoji_code == ":rocket:") {
      encoding = 'd';
   } else if (emoji_code == ":truck:") {
      encoding = 'e';
   } else if (emoji_code == ":globe:") {
      encoding = 'f';
   } else if (emoji_code == ":clock:") {
      encoding = 'g';
   } else if (emoji_code == ":cross:") {
      encoding = 'h';
   } else if (emoji_code == ":battery:") {
      encoding = 'i';
   } else if (emoji_code == ":console:") {
      encoding = 'j';
   } else if (emoji_code == ":fish:") {
      encoding = 'k';
   } else if (emoji_code == ":eyes:") {
      encoding = 'm';
   } else if (emoji_code == ":click:") {
      encoding = 'n';
   } else if (emoji_code == ":phone:") {
      encoding = 'o';
   } else if (emoji_code == ":other-cat:") {
      encoding = 's';
   } else if (emoji_code == ":cherry:") {
      encoding = 't';
   } else if (emoji_code == ":dinosaur:") {
      encoding = 'u';
   } else if (emoji_code == ":people:") {
      encoding = 'v';
   } else if (emoji_code == ":frog:") {
      encoding = 'w';
   } else if (emoji_code == ":ghost:") {
      encoding = 'x';
   } else if (emoji_code == ":girls:") {
      encoding = 'y';
   } else if (emoji_code == ":cactus:") {
      encoding = 'z';
   } else if (emoji_code == ":shoe:") {
      encoding = '0';
   } else if (emoji_code == ":board:") {
      encoding = '1';
   } else if (emoji_code == ":face-cat:") {
      encoding = '2';
   } else if (emoji_code == ":apple:") {
      encoding = '3';
   } else if (emoji_code == ":house:") {
      encoding = '4';
   } else if (emoji_code == ":elephant:") {
      encoding = '5';
   } else if (emoji_code == ":folder:") {
      encoding = '6';
   } else if (emoji_code == ":crab:") {
      encoding = '7';
   } else if (emoji_code == ":lamp:") {
      encoding = '8';
   } else if (emoji_code == ":future-eye:") {
      encoding = '9';
   } else if (emoji_code == ":boy:") {
      encoding = '\"';
   } else if (emoji_code == ":stroller:") {
      encoding = '#';
   } else {
      encoding = 'A'; //* Skull pixel icon.
   }

   return PIXELICONS.getGlyph(encoding);
}

#endif // FONTS_HPP
