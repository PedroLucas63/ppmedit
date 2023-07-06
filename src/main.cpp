/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief ppm file manipulation program.
 * @version 2.0
 * @date 2023-06-25
 * 
 * Execution of various methods for the transformation of ppm (portable pixmap)
 * images with guaranteed execution according to the expected parameters.
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <fstream>
#include "Manual.hpp"
#include "Editor.hpp"

#define MIN_ARGUMENTS 4 /**< Minimum arguments when executed */

using namespace std;

/**
 * @brief Get image informations.
 * 
 * @param local Image Location.
 * @param[out] image Image memory position.
 */
void getImage(string local, Image &image);

/**
 * @brief Export image to program output.
 * @param local Image location.
 * @param editor Editor memory position.
 */
void exportImage(string local, Editor &editor);

/**
 * @brief Main function of the program (starting point). 
 * 
 * @todo Define the new program usage pattern.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return An integer. 
 */
int main(int argc, char* argv[]) {
   int minimum_args { MIN_ARGUMENTS };

   for (int index { 0 }; index < argc; index++) {
      if (strcmp(argv[index], "combine") == 0) {
         minimum_args++;
         break;
      }
   }

   /*
    * Checks that the program was executed with at least the required number
    * of arguments.
    */
   if (argc < minimum_args) {
      printManual();
      return 1;
   }

   int options { 0 };

   if (minimum_args == 4) {
      options = argc - 2;
   } else {
      options = argc - 3;
   }

   Image image;
   getImage(argv[options], image);

   Editor editor { image };
      
   /*
   * Perform the functions.
   */
   for (int index { 1 }; index < options; index++) {
      string operation { argv[index] };
      if (operation == "gray") {
         editor.grayscaleImage();
      } else if (operation == "negative") {
         editor.negativeImage();
      } else if (operation == "rotate") {
         editor.rotateImage();
      } else if (operation == "rotate-l") {
         editor.rotateImage("left");
      } else if (operation == "invert") {
         editor.rotateImage("invert");
      } else if (operation == "enlarge") {
         editor.enlargeImage();
      } else if (operation == "reduce") {
         editor.reduceImage();
      } else if (operation == "sharp") {
         editor.applyImageEffects();
      } else if (operation == "sharp-e") {
         editor.applyImageEffects("edge-sharpening");
      } else if (operation == "blur") {
         editor.applyImageEffects("blurring");
      } else if (operation == "embossing") {
         editor.applyImageEffects("embossing");
      } else if (operation == "b-solid") {
         editor.applyBorder("normal");
      } else if (operation == "b-polaroid") {
         editor.applyBorder("normal", "polaroid");
      } else if (operation == "combine") {
         Image foreground;
         getImage(argv[argc - 2], foreground);
         
         editor.combineImages(foreground);
      }
   }

   exportImage(argv[argc - 1], editor);
   
   return 0;
}

void getImage(string local, Image& image) {
   string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };

   ifstream file(local, ios::binary);

   if (!file.is_open()) {
      cerr << "Reading error!" << endl;
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

void exportImage(string local, Editor& editor) {
   ofstream file(local);

   if (!file.is_open()) {
      cerr << "Writing error!" << endl;
      abort();
   }

   file << editor.getImage().toString() << endl;
   file.close();
}
