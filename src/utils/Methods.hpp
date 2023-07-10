/**
 * @file Methods.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Methods functions.
 * @version 2.0
 * @date 2023-07-07
 * 
 * Manipulates methods in the editor.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef METHODS_HPP
#define METHODS_HPP

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
 * @brief Executes the effect method in the editor.
 * 
 * @param editor Editor memory position.
 * @param type Effect to apply.
 */
void setEffect(Editor& editor, Effects type) {
   switch(type) {
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

/**
 * @brief Executes the border method in the editor.
 * 
 * @param editor Editor memory position.
 * @param type Border to apply.
 * @param size Border size (textual mode).
 * @param extra_size Extra size underneath.
 * @param color Border color.
 * 
 * @todo Filter the values for defining the border.
 */
void setBorder(Editor& editor, Borders type, std::string size = "normal",
   int extra_size = 0, std::string color = "white") { }

/**
 * @brief Executes the border method in the editor.
 * 
 * @param editor Editor memory position.
 * @param type Border to apply.
 * @param size Border size (value mode).
 * @param extra_size Extra size underneath.
 * @param color Border color.
 * 
 * @todo Filter the values for defining the border.
 */
void setBorder(Editor& editor, Borders type, int size = 25,
   int extra_size = 0, std::string color = "white") { }

/**
 * @brief Performs image conversion.
 * 
 * @param Editor memory position.
 * @param type Type to convert.
 */
void performConversion(Editor& editor, Types type) {
   if (type == Text) {
      editor.convertImage(ASCII_TYPE);
   } else if (type == Binary) {
      editor.convertImage(BINARY_TYPE);
   } else {   
      editor.convertImage();
   }
}

#endif // METHODS_HPP
