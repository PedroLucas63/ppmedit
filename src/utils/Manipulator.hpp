/**
 * @file Manipulator.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Manipulator functions.
 * @version 2.0
 * @date 2023-07-07
 * 
 * It reads, processes, and writes data, be it image files or directives.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <iostream>
#include <fstream>
#include "Methods.hpp"
#include "Manual.hpp"
#include "Editor.hpp"

/**
   * @brief Open an image from the location and save in image object.
   * 
   * @param local Image Location.
   * @param[out] image Image memory position.
   */
void openImage(std::string local, Image& image) {
   std::string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };

   std::ifstream file(local);

   if (!file.is_open()) {
      std::cerr << "Reading error!" << std::endl;
      abort();
   }

   file >> type;
   file >> width;
   file >> height;
   file >> colors;

   image.setType(type);
   image.setSize(width, height);
   image.setColors(colors);

   if (type == BINARY_TYPE) {
      colors = image.getColors();
      file.ignore();
   }

   for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
         int red { 0 };
         int green { 0 };
         int blue { 0 };
         Pixel pixel;
         pixel.setColors(colors);

         if (type == ASCII_TYPE) {
            file >> red >> green >> blue;

            pixel.setRed(red);
            pixel.setGreen(green);
            pixel.setBlue(blue);
         } else {
            char color;

            file.get(color);
            pixel.setRed((unsigned char) color);
            file.get(color);
            pixel.setGreen((unsigned char) color);
            file.get(color);
            pixel.setBlue((unsigned char) color);
         }

         image.setPixel(pixel, row, column);
      }
   }

   file.close();
}

/**
 * @brief Export image to program output.
 * @param local Image location.
 * @param editor Editor memory position.
 */
void exportImage(std::string local, Editor &editor) {
   std::ofstream file(local);

   if (!file.is_open()) {
      std::cerr << "Writing error!" << std::endl;
      abort();
   }

   file << editor.getImage().toString() << std::endl;
   file.close();
}

#endif // MANIPULATOR_HPP
