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

/**
 * @brief Checks if a string is a directive.
 * 
 * @param str An string.
 * @return An boolean.
 */
bool isDirective(std::string str) {
   if (str == "-b" || str == "--border") {
      return true;
   } else if (str == "-c" || str == "--combine") {
      return true;
   } else if (str == "-C" || str == "--collage") {
      return true;
   } else if (str == "--convert") {
      return true;
   } else if (str == "-e" || str == "--effect") {
      return true;
   } else if (str == "-h" || str == "--help") {
      return true;
   } else if (str == "-i" || str == "--input") {
      return true;
   } else if (str == "-o" || str == "--output") {
      return true;
   } else if (str == "-t" || str == "--text") {
      return true;
   }

   return false;
}

/**
 * @brief Returns the position of a string.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @param str An string.
 * @return An integer. 
 */
int searchString(int argc, char* argv[], std::string str) {
   int position { -1 };

   for (int i { 0 }; i < argc; i++) {
      if (std::string(argv[i]) == str) {
         position = i;
         break;
      }
   }

   return position;
}

/**
 * @brief Checks if help has been requested and what type of operation it is.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean;
 */
bool getManualType(int argc, char* argv[]) {
   bool used { false };
   std::string type;

   for (int i { 0 }; i < argc; i++) {
      if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
         used = true;

         if (i + 1 < argc) {
            type = argv[i + 1];
         }

         break;
      }
   }

   if (type == "+b" || type == "++border") {
      printBorderManual();
   } else if (type == "+c" || type == "++combine") {
      printCombineManual();
   } else if (type == "+C" || type == "++collage") {
      printCollageManual();
   } else if (type == "++convert") {
      printConvertManual();
   } else if (type == "+e" || type == "++effect") {
      printEffectManual();
   } else if (type == "+i" || type == "++input") {
      printInputManual();
   } else if (type == "+o" || type == "++output") {
      printOutputManual();
   } else if (type == "+t" || type == "++text") {
      printTextManual();
   } else if (used) {
      printManual();
   }

   return used;
}

/**
 * @brief Identifies the effect values and runs them in an editor.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @param editor Editor memory position.
 * @return An boolean.
 */
bool getEffectType(int argc, char* argv[], Editor& editor) {
   bool used { false };
   int effects_init { 0 };

   for (int i { 0 }; i < argc; i++) {
      if (std::string(argv[i]) == "-e" || std::string(argv[i]) == "--effect") {
         used = true;
         effects_init = i;

         break;
      }
   }

   for (int i { effects_init + 1 }; i < argc; i++) {
      Effects effect { getEffectByName(argv[i]) };

      if (effect != Effect_None) {
         setEffect(editor, effect);
      } else {
         break;
      }
   }

   return used;
}

/**
 * @brief Identifies if image conversion has been requested and executes.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @param editor Editor memory position.
 */
void getConvertType(int argc, char* argv[], Editor& editor) {
   int convert_search { searchString(argc, argv, "--convert") };
   Types type;

   if (convert_search != -1 && !isDirective(argv[convert_search + 1])) {
      type = getTypeByValue(argv[convert_search + 1]);
   } else if (convert_search != -1) {
      type = Automatic;
   }

   if (convert_search != -1) {
      performConversion(editor, type);
   }
}

/**
 * @brief Opens the images and returns the total amount.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @param first_image First image memory position.
 * @param second_image Second image memory position.
 * @param third_image Third image memory position.
 * @param fourth_image Fourth image memory position.
 * @return An integer.
 * @see isDirective()
 */
int getInputFiles(int argc, char* argv[], Image& first_image,
   Image& second_image, Image& third_image, Image& fourth_image) 
{
   int images { 0 };

   int first_search { searchString(argc, argv, "-i") };
   int second_search { searchString(argc, argv, "--input") };

   int input_position { 0 };

   if (first_search != -1) {
      input_position = first_search;
   } else if (second_search != -1) {
      input_position = second_search;
   }

   openImage(argv[++input_position], first_image);
   images++;

   for (int i { input_position }, j { 0 }; i < argc && j < 3; i++, j++) {
      if (!isDirective(argv[i]) && images == 1) {
         openImage(argv[input_position], second_image);
         images++;
      }

      if (!isDirective(argv[i]) && images == 2) {
         openImage(argv[input_position], third_image);
         images++;
      }

      if (!isDirective(argv[i]) && images == 2) {
         openImage(argv[input_position], fourth_image);
         images++;
      }
   }

   return images;
}

/**
 * @brief Gets the location of the output image.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An string.
 */
std::string getOutputFile(int argc, char* argv[]) {
   int first_search { searchString(argc, argv, "-o") };
   int second_search { searchString(argc, argv, "--output") };

   std::string output_local;

   if (first_search != -1) {
      output_local = std::string(argv[first_search + 1]);
   } else if (second_search != -1) {
      output_local = std::string(argv[second_search + 1]);
   } else {
      output_local = "./a.ppm";
   }

   return output_local;
}

/**
 * @brief Performs the relevant edits on the image.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 */
void performEditing(int argc, char* argv[]) {
   Image main_image;
   Image second_image;
   Image third_image;
   Image fourth_image;
   std::string output_file { getOutputFile(argc, argv) };

   if (getManualType(argc, argv)) {
      return;
   } else if (searchString(argc, argv, "--list-colors") != -1) {
      listColors();
      return;
   } else if (searchString(argc, argv, "--list-emojis") != -1) {
      listEmojis();
      return;
   }

   if (searchString(argc, argv, "-i") == -1 && 
      searchString(argc, argv, "--input") == -1) 
   {
      printManual();
      return;
   }

   getInputFiles(
      argc, 
      argv, 
      main_image, 
      second_image, 
      third_image, 
      fourth_image
   );

   Editor editor { main_image };

   getEffectType(argc, argv, editor);

   getConvertType(argc, argv, editor);

   exportImage(output_file, editor);
}

#endif // MANIPULATOR_HPP
