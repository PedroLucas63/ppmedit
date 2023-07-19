/**
 * @file Manipulator.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Manipulator functions.
 * @version 2.0
 * @date 2023-07-17
 * 
 * It reads, processes, and writes data, be it image files or directives.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <iostream>
#include <fstream>
#include "Manual.hpp"
#include "Methods.hpp"

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
 * @brief Checks that the help has been used and runs properly.
 * 
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 */
bool getManualType(int argc, char* argv[]) {
   int directive_search1 { searchString(argc, argv, "-h") };
   int directive_search2 { searchString(argc, argv, "--help") };

   int help_position { 0 };

   if (directive_search1 != -1) {
      help_position = directive_search1;
   } else if (directive_search2 != -1) {
      help_position = directive_search2;
   } else {
      return false;
   }

   std::string type { argv[help_position + 1] };

   if (type == "+b" || type == "++border") {
      printBorderManual();
   } else if (type == "+c" || type == "++combine") {
      printCombineManual();
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
   } else {
      printManual();
   }

   return true;
}

/**
 * @brief Checks that the combine has been used and runs properly.
 * 
 * @param editor Editor memory position.
 * @param foreground Position of the foreground image memory.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 */
bool getCombineFunction(Editor& editor, Image& foreground, 
   int argc, char* argv[]) 
{
   int directive_search1 { searchString(argc, argv, "-c") };
   int directive_search2 { searchString(argc, argv, "--combine") };

   int combine_position { 0 };

   if (directive_search1 != -1) {
      combine_position = directive_search1;
   } else if (directive_search2 != -1) {
      combine_position = directive_search2;
   } else {
      return false;
   }

   if (editor.getWidth() < foreground.getWidth() ||
      editor.getHeight() < foreground.getHeight()) 
   {
      std::cerr << "The foreground image should not be larger than the "
         << "background image.\n" << std::endl;
      return false;
   }

   std::string first_position;
   std::string second_position;

   if (std::string(argv[combine_position + 1]) == "+p" ||
      std::string(argv[combine_position + 1]) == "++position")
   {
      first_position = argv[combine_position + 2];
      second_position = argv[combine_position + 3];
   }

   /*
    * An attempt is made to convert the positions to integers, if an invalid
    * argument fails, it means that the position was passed in the textual
    * model and not in the height x width mode.
    */
   try {
      int position_x { std::stoi(first_position) };
      int position_y { std::stoi(second_position) };

      setCombine(editor, foreground, position_x, position_y);
   } catch (const std::invalid_argument&) {
      setCombine(editor, foreground, first_position);
   }

   return true;
}

/**
 * @brief Checks that the effect has been used and runs properly.
 * 
 * @param editor Editor memory position.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 */
bool getEffectType(Editor& editor, int argc, char* argv[]) {
   int directive_search1 { searchString(argc, argv, "-e") };
   int directive_search2 { searchString(argc, argv, "--effect") };

   int effect_position { 0 };

   if (directive_search1 != -1) {
      effect_position = directive_search1;
   } else if (directive_search2 != -1) {
      effect_position = directive_search2;
   } else {
      return false;
   }

   for (int i { effect_position + 1 }; i < argc; i++) {
      Effects effect { getEffectByName(argv[i]) };

      if (effect != Effect_None) {
         setEffect(editor, effect);
      } else {
         break;
      }
   }

   return true;
}

/**
 * @brief Checks that the border has been used and runs properly.
 * 
 * @param editor Editor memory position.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 */
bool getBorderType(Editor& editor, int argc, char* argv[]) {
   int directive_search1 { searchString(argc, argv, "-b") };
   int directive_search2 { searchString(argc, argv, "--border") };

   int border_position { 0 };

   if (directive_search1 != -1) {
      border_position = directive_search1;
   } else if (directive_search2 != -1) {
      border_position = directive_search2;
   } else {
      return false;
   }
   
   Borders border_type { getBorderByType(argv[++border_position]) };

   if (border_type == Border_None) {
      return false;
   }

   std::string border_size;
   int extra_size { 0 };
   std::string color;

   for (int i { border_position + 1 }; i < argc; i++) {
      if (isDirective(argv[i])) {
         break;
      } else if (std::string(argv[i]) == "+s" ||
         std::string(argv[i]) == "++size") 
      {
         border_size = argv[i + 1];
      } else if (std::string(argv[i]) == "+c" || 
         std::string(argv[i]) == "++color") 
      {
         color = argv[i + 1];
      } else if (std::string(argv[i]) == "+e" || 
         std::string(argv[i]) == "++extra") 
      {
         extra_size = std::stoi(argv[i + 1]);
      }
   }

   /* 
    * An attempt is made to convert the border size to integer, if an invalid
    * argument fails, it means that the position was passed in the textual
    * model and not in the "size px" mode. 
    */
   try {
      int size_integer { std::stoi(border_size) };
      setBorder(editor, border_type, size_integer, extra_size, color);
   } catch (const std::invalid_argument&) {
      setBorder(editor, border_type, border_size, extra_size, color);
   }

   return true;
}

/**
 * @brief Checks that the text has been used and runs properly.
 * 
 * @param editor Editor memory position.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 * @see isDirective()
 */
bool getText(Editor& editor, int argc, char* argv[]) {
   int directive_search1 { searchString(argc, argv, "-t") };
   int directive_search2 { searchString(argc, argv, "--text") };

   int text_position { 0 };

   if (directive_search1 != -1) {
      text_position = directive_search1;
   } else if (directive_search2 != -1) {
      text_position = directive_search2;
   } else {
      return false;
   }

   std::string x;
   std::string y;
   std::string font;

   for (int i { text_position + 1 }; i < argc; i++) {
      std::string expression { std::string(argv[i]) };

      if (isDirective(expression)) {
         break;
      } else if (expression == "+p" || expression == "++position") {
         x = argv[i + 1];
         y = argv[i + 2];
      } else if (expression == "+f" || expression == "++font") {
         font = argv[i + 1];
      }
   }

   std::string text;

   std::cout << "Enter a text: ";
   std::getline(std::cin, text);

   int position_x { 0 };
   int position_y { 0 };

   /*
    * An attempt is made to convert the size of the text positions to integer.
    * If an invalid arguments error occurs, it means that a specific position
    * was not defined and in that case the position will be given by 
    * "0px x 0px" if no border was implemented in the image, or aligned with 
    * the image border.
    */
   try {
      position_x = std::stoi(x);
      position_y = std::stoi(y);
   } catch (const std::invalid_argument&) {
      if (editor.getBorderSize() != 0) {
         position_x = editor.getBorderSize();
         position_y = editor.getHeight() - editor.getBorderSize() - 
            editor.getExtraBorderSize();
      }
   }

   setText(editor, text, position_x, position_y, font);

   return true;
}

/**
 * @brief Checks that the convert has been used and runs properly.
 * @param editor Editor memory position.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An boolean.
 * @see searchString()
 */
bool getConvertType(Editor& editor, int argc, char* argv[]) {
   int convert_search { searchString(argc, argv, "--convert") };
   
   if (convert_search == -1) {
      return false;
   }

   Types type { getTypeByValue(argv[convert_search + 1]) };

   performConversion(editor, type);

   return true;
}

/**
 * @brief Opens the images and returns the total amount.
 * 
 * @param first_image First image memory position.
 * @param second_image Second image memory position.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return An integer.
 * @see searchString()
 * @see isDirective()
 */
int getInputFiles(Image& first_image, Image& second_image, 
   int argc, char* argv[]) 
{
   int directive_search1 { searchString(argc, argv, "-i") };
   int directive_search2 { searchString(argc, argv, "--input") };

   int input_position { 0 };

   if (directive_search1 != -1) {
      input_position = directive_search1;
   } else if (directive_search2 != -1) {
      input_position = directive_search2;
   }

   int images { 0 };

   openImage(argv[input_position + 1], first_image);
   images++;

   if (argc < input_position + 2) {
      if (!isDirective(argv[input_position + 2])) {
         openImage(argv[input_position + 2], second_image);
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
 * @see searchString()
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

#endif // MANIPULATOR_HPP
