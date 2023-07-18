/**
 * @file Methods.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Methods functions.
 * @version 2.0
 * @date 2023-07-18
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
 * @brief Performs the image blending function
 * 
 * @param editor Editor memory position.
 * @param foreground Foreground image.
 * @param x Displacement in X axis.
 * @param y Displacement in Y axis
 */
void setCombine(Editor& editor, Image& foreground, int x, int y) {
   editor.combineImages(foreground, x, y);
}

/**
 * @brief Performs the image blending function
 * 
 * @param editor Editor memory position.
 * @param foreground Foreground image.
 * @param position Displacement of the image in textual form.
 * @see setCombine()
 */
void setCombine(Editor& editor, Image& foreground, std::string position) {
   int back_width { editor.getWidth() };
   int back_height { editor.getHeight() };
   int fore_width { foreground.getWidth() };
   int fore_height { foreground.getHeight() };

   int x { 0 };
   int y { 0 };

   if (position == "center") {
      x = (back_width - fore_width) / 2;
      y = (back_height - fore_height) / 2;
   } else if (position == "top") {
      x = (back_width - fore_width) / 2;
   } else if (position == "bottom") {
      x = (back_width - fore_width) / 2;
      y = back_height - fore_height;
   } else if (position == "left") {
      y = (back_height - fore_height) / 2;
   } else if (position == "right") {
      x = back_width - fore_width;
      y = (back_height - fore_height) / 2;
   } else if (position == "top-r") {
      x = back_width - fore_width;
   } else if (position == "bottom-l") {
      y = back_height - fore_height;
   } else if (position == "bottom-r") {
      x = back_width - fore_width;
      y = back_height - fore_height;
   }

   setCombine(editor, foreground, x, y);
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
 * @brief Get the border size.
 * 
 * @param size Border size in numerical mode.
 * @param image_width Image width.
 * @param image_height Image height.
 * @return An integer. 
 */
int getBorderSize(int size, int image_width, int image_height) {
   int border_size { 25 };

   if (size > 0) {
      border_size = size;
   }

   return border_size;
}

/**
 * @brief Get the border size.
 * 
 * @param size Border size in textual mode.
 * @param image_width Image width.
 * @param image_height Image height.
 * @return An integer. 
 */
int getBorderSize(std::string size, int image_width, int image_height) {
   int border_size { 25 };

   if (size == "slim") {
      border_size = image_width > image_height ? 
         image_height / 10 : 
         image_width / 10;
   } else if (size == "normal") {
      border_size = image_width > image_height ? 
         image_height / 5 : 
         image_width / 5;
   } else if (size == "large") {
      border_size = image_width > image_height ?
         image_height / 2 : 
         image_width / 2;
   }

   return border_size;
}

/**
 * @brief Executes the border method in the editor.
 * 
 * @details The template used does the validation accepting only the type
 * std::string or int.
 * 
 * @tparam T Type of border size.
 * @param editor Editor memory position.
 * @param type Border to apply.
 * @param size Border size.
 * @param extra_size Extra size underneath.
 * @param color Border color.
 * @see getBorderSize()
 */
template <
   typename T,
   typename = typename std::enable_if<
      std::is_same<T, std::string>::value || 
      std::is_same<T, int>::value
   >::type
>
void setBorder(Editor& editor, Borders type, T size,
   int extra_size, std::string color) 
{
   Pixel color_pixel { getColorByName(color) };
   int border_size { 0 };
   int additional_size { 0 };

   color_pixel.setColors(editor.getColors());
   
   int image_width { editor.getWidth() };
   int image_height { editor.getHeight() };

   border_size = getBorderSize(size, image_width, image_height);

   if (type == Polaroid && extra_size == 0) {
      additional_size = border_size * 2;
   } else if (type == Polaroid) {
      additional_size = extra_size;
   } else {
      additional_size = 0;
   }

   editor.applyBorder(color_pixel, border_size, additional_size);
}

/**
 * @brief Separates text data into pairs and uses the editor method.
 * 
 * @param editor Editor memory position.
 * @param text Text to write.
 * @param x Displacement in X axis.
 * @param y Displacement in Y axis.
 * @param font_name Font name.
 */
void setText(Editor& editor, std::string text, int x, int y,
   std::string font_name) 
{
   Font const& font { getFontByName(font_name) };

   std::string word;
   std::vector<Pair<TypeText, std::string>> mapped_text;

   for (auto c : text) {
      if (c == ' ') {
         Pair<TypeText, std::string> pair { getTypeByText(word), word };
         mapped_text.push_back(pair);

         word = "";
      } else {
         word += c;
      }
   }

   if (word != "") {
      Pair<TypeText, std::string> pair { getTypeByText(word), word };
      mapped_text.push_back(pair);
   }

   editor.writeText(mapped_text, x, y, font);
}

/**
 * @brief Performs image conversion.
 * 
 * @param editor Editor memory position.
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
