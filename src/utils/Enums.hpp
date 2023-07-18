/**
 * @file Enums.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Enums functions.
 * @version 2.0
 * @date 2023-07-18
 * 
 * Definition of enumerations useful for the whole program and definition
 * of functions that relate a text to the members of each enumeration.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>
#include "Colors.hpp"
#include "Fonts.hpp"

/**
 * @enum Effects enumeration.
 * @brief Enumeration with all effects of the "Editor" class.
 */
enum Effects {
   Blurring,
   Edge_Sharpening,
   Embossing,
   Enlarge,
   Gray,
   Invert,
   Negative,
   Reduce,
   Rotate_Left,
   Rotate_Right,
   Sharpening,
   Effect_None
};

/**
 * @enum Borders enumeration.
 * @brief Enumeration with all borders of the "Editor" class.
 */
enum Borders {
   Solid,
   Polaroid,
   Border_None
};

/**
 * @enum Types enumeration.
 * @brief Enumeration with all types of the "Editor" class.
 */
enum Types {
   Text,
   Binary,
   Automatic
};

/**
 * @enum Types text enumeration.
 * @brief Enumeration with all types of the text.
 */
enum TypeText {
   String,
   Color,
   Emoji
};

/**
 * @brief Get the value from Effects enum by effect name.
 * 
 * @param effect_name Effect name.
 * @return An Effects value.
 */
Effects getEffectByName(std::string effect_name) {
   if (effect_name == "gray") {
      return Gray;
   } else if (effect_name == "negative") {
      return Negative;
   } else if (effect_name == "rotate") {
      return Rotate_Right;
   } else if (effect_name == "rotate-l") {
      return Rotate_Left;
   } else if (effect_name == "invert") {
      return Invert;
   } else if (effect_name == "enlarge") {
      return Enlarge;
   } else if (effect_name == "reduce") {
      return Reduce;
   } else if (effect_name == "sharp") {
      return Sharpening;
   } else if (effect_name == "sharp-e") {
      return Edge_Sharpening;
   } else if (effect_name == "blur") {
      return Blurring;
   } else if (effect_name == "embossing") {
      return Embossing;
   }

   return Effect_None;
}

/**
 * @brief Get the value from Borders enum by border type.
 * 
 * @param borders_type Border type.
 * @return An Borders value.
 */
Borders getBorderByType(std::string borders_type) {
   if (borders_type == "polaroid") {
      return Polaroid;
   } else if (borders_type == "solid") {
      return Solid;
   }

   return Border_None;
}

/**
 * @brief Get the value from type enum.
 * 
 * @param type_to_convert Type to convert.
 * @return An Type value.
 */
Types getTypeByValue(std::string type_to_convert) {
   if (type_to_convert == "text") {
      return Text;
   } else if (type_to_convert == "binary") {
      return Binary;
   }

   return Automatic;
}

/**
 * @brief Get the value from type text enum.
 * 
 * @param text Text.
 * @return An TypeText value.
 */
TypeText getTypeByText(std::string text) {
   Pixel const& default_color { getColorByCode("#WHITE") };
   Pixel const& text_color { getColorByCode(text) };

   Glyph const* default_emoji { getEmojiByCode(":skull:") };
   Glyph const* text_emoji { getEmojiByCode(text) };

   if (text_color != default_color || text == "#WHITE") {
      return Color;
   } else if (text_emoji != default_emoji || text == ":skull:") {
      return Emoji;
   }

   return String;
}

#endif // ENUMS_HPP
