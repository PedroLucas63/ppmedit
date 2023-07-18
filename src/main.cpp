/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief ppm file manipulation program.
 * @version 2.0
 * @date 2023-07-17
 * 
 * Execution of various methods for the transformation of ppm (portable pixmap)
 * images with guaranteed execution according to the expected parameters.
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Manipulator.hpp"

using namespace std;

/**
 * @brief Main function of the program (starting point). 
 * 
 * @param argc Number of arguments.
 * @param argv Arguments values.
 * @return An integer. 
 */
int main(int argc, char* argv[]) {
   Image main_image;
   Image second_image;
   std::string output_file { getOutputFile(argc, argv) };

   if (getManualType(argc, argv)) {
      return 0;
   } else if (searchString(argc, argv, "--list-colors") != -1) {
      listColors();
      return 0;
   } else if (searchString(argc, argv, "--list-emojis") != -1) {
      listEmojis();
      return 0;
   }

   if (searchString(argc, argv, "-i") == -1 && 
      searchString(argc, argv, "--input") == -1) 
   {
      printManual();
      return 0;
   }

   int images { getInputFiles(main_image, second_image, argc, argv) };

   Editor editor { main_image };

   if (images == 2) {
      getCombineFunction(editor, second_image, argc, argv);
   }

   getEffectType(editor, argc, argv);
   getBorderType(editor, argc, argv);
   getText(editor, argc, argv);

   getConvertType(editor, argc, argv);

   exportImage(output_file, editor);
   
   return 0;
}
