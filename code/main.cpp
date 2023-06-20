/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief ppm file manipulation program.
 * @version 1.1
 * @date 2023-06-20
 * 
 * Execution of various methods for the transformation of ppm (portable pixmap)
 * images with guaranteed execution according to the expected parameters.
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <fstream>
#include "libs/Editor.hpp"

#define MIN_ARGUMENTS 2 /**< Minimum arguments when executed */

using namespace std;

/**
 * @brief Format the program name to the last name in the local file.
 * 
 * @param program_name Full program name (argv[0]).
 * @return A string. 
 */
string formatProgramName(string program_name);

/**
 * @brief Print the tutorial on how to use the program.
 * 
 * @param program_name Program name.
 */
void printUsage(string program_name);

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
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return An integer. 
 */
int main(int argc, char* argv[]) {
   string program_name { formatProgramName(argv[0]) };
   int minimum_args { 4 };

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
      printUsage(program_name);
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
      } else if (operation == "combine") {
         Image foreground;
         getImage(argv[argc - 2], foreground);
         
         editor.combineImages(foreground);
      }
   }

   exportImage(argv[argc - 1], editor);
   
   return 0;
}

string formatProgramName(string program_name) {
   /*
    * Gets the position of the last separator and creates a substring from this
    * found position concatenated with a dot at the beginning.
    */
   std::size_t last_separator { program_name.find_last_of("/\\") };
   string name { "." + program_name.substr(last_separator) };

   return name;
}

void printUsage(string program_name) {
   cerr << "Usage:" << endl;
   cerr << "\t" << program_name << " [options] input_file " <<
      "[additional_input_file] output_file" << endl;
   cerr << "Where each <options> should be:" << endl;
   cerr << "\t" << "gray: to transform the image into grayscale." << endl;
   cerr << "\t" << "negative: to transform the image into negative." << endl;
   cerr << "\t" << "rotate: to rotate the image 90 degrees to the right." << 
      endl;
   cerr << "\t" << "rotate-l: to rotate the image 90 degrees to the left." << 
      endl;
   cerr << "\t" << "invert: to invert the image." << endl;
   cerr << "\t" << "enlarge: to enlarge the image by 2x." << endl;
   cerr << "\t" << "reduce: to reduce the image by 2x." << endl;
   cerr << "\t" << "sharp: to apply the sharpening filter to the image." << 
      endl;
   cerr << "\t" << "sharp-e: to apply the edge sharpening filter to the" <<
      " image." << endl;
   cerr << "\t" << "blur: to apply the blurring filter to the image." << endl;
   cerr << "\t" << "embossing: to apply the embossing filter to the image." <<
      endl;
   cerr << "\t" << "combine: combine first image (background) with the" << 
      " secund image (foreground). (*) (**)" << endl;
   cerr << "The original image is read from the standard input and the" <<
      "transformed image is sent to the standard output." << endl;
   cerr << "(*) Operations marked by this pointer cannot have concatenated" <<
      " options to their right and are the only ones that must receive an" <<
      " additional input image." << endl;
}

void getImage(string local, Image &image) {
   string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };

   ifstream file(local);

   file >> type;
   file >> width;
   file >> height;
   file >> colors;

   image.setSize(width, height);
   image.setColors(colors);

   for (int row { 1 }; row <= height; row++) {
      for (int column { 1 }; column <= width; column++) {
         int red { 0 };
         int green { 0 };
         int blue { 0 };

         file >> red >> green >> blue;
         Pixel pixel { red, green, blue, colors };

         image.setPixel(pixel, row, column);
      }
   }
}

void exportImage(string local, Editor& editor) {
   ofstream file(local);
   file << editor.getImage().toString() << endl;
}
