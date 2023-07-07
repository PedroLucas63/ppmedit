/**
 * @file Effects.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Effects functions.
 * @version 2.0
 * @date 2023-07-07
 * 
 * Manipulates effects in the editor.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef EFFECTS_HPP
#define EFFECTS_HPP

#include <iostream>
#include "Editor.hpp"

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
   None
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

   return None;
}

void setEffect(Editor& editor, Effects effect) {
   switch(effect) {
      case Blurring:
         editor.applyImageEffects("blurring");
         break;
      case Edge_Sharpening:
         editor.applyImageEffects("edge-sharpening");
         break;
      case Embossing:
         editor.applyImageEffects("embossing");
         break;
      case Enlarge:
         editor.enlargeImage();
         break;
      case Gray:
         editor.grayscaleImage();
         break;
      case Invert:
         editor.rotateImage("invert");
         break;
      case Negative:
         editor.negativeImage();
         break;
      case Reduce:
         editor.reduceImage();
         break;
      case Rotate_Left:
         editor.rotateImage("left");
         break;
      case Rotate_Right:
         editor.rotateImage("right");
         break;
      case Sharpening:
         editor.applyImageEffects("sharpening");
         break;
      default:
         break;
   }
}

void setEffect(Editor& editor, std::string effect_name) {
   Effects effect { getEffectByName(effect_name) };
   setEffect(editor, effect);
}

#endif // EFFECTS_HPP
