/**
 * @file Helpers.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Help functions.
 * @version 2.0
 * @date 2023-06-25
 * 
 * Defines the help functions, either of the program in general or of a
 * specific parameter.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>

/**
 * @brief Print the tutorial on how to use the program.
 */
void printHelp() {
   std::cout << "Usage: ppmedit [OPTION]... -i [FILE] -o [OUTPUT_FILE]" 
      << std::endl;
   std::cout << "Edit ppm images and save to the specified file." << std::endl;

   std::cout << std::endl;

   std::cout << "Without an OUTPUT_FILE it saves to \"a.ppm\"." << std::endl;

   std::cout << std::endl;

   std::cout << "\t-b, --border\t\tsize of border." << std::endl;
   std::cout << "\t-e, --effect\t\teffect to be applied." << std::endl;
   std::cout << "\t-f, --font\t\tfont name for writing." << std::endl;
   std::cout << "\t-F, --foreground\tforeground in image combination." 
      << std::endl;
   std::cout << "\t-h, --help\t\thelp command." << std::endl;
   std::cout << "\t-i, --input\t\tinput image." << std::endl;
   std::cout << "\t-l, --length\t\tfont length." << std::endl;
   std::cout << "\t-o, --output\t\toutput image." << std::endl;
   std::cout << "\t-s, --space\t\tadditional bottom border space." << std::endl;
   std::cout << "\t-t, --text\t\ttext to overlay image." << std::endl;

   std::cout << std::endl;

   std::cout << "Examples:" << std::endl;
   std::cout << "\tppmedit -e gray -i image.ppm\t\t\tadd the gray effect to" 
      << "image.ppm and save to a.ppm." << std::endl;
   std::cout << "\tppmedit -e polaroid -s 25 -i i.ppm -o p.ppm\t" 
      << "add the polaroid border effect to i.ppm with additional space below" 
      << "25 pixels and save to p.ppm." << std::endl;
}

/**
 * @brief Print the tutorial on how to use the border option.
 */
void printBorderHelp() {
   std::cout << "Usage: ppmedit [OPTION]... -i [INPUT_FILE] -o [OUTPUT_FILE]" 
   << std::endl;
   std::cout << "Edit ppm images and save to the specified file." << std::endl;

   std::cout << std::endl;

   std::cout << "Without an OUTPUT_FILE it saves to \"a.ppm\"." << std::endl;
   std::cout << "Without setting the \"-b\" option, but using the solid " 
      << "border or polaroid effect, the default value is 25(px). \"a.ppm\"." 
      << std::endl;

   std::cout << std::endl;

   std::cout << "\t-b, --border\t\tsize of border." << std::endl;
   std::cout << "Works in conjunction with the solid edge and Polaroid "
      << "edge effects." << std::endl;
   std::cout << "It defines the size of the borders in pixels or intensity." 
      << std::endl;
   std::cout << "It is accompanied by an integer value (number of pixels) or "
      << "a string (slim, normal or large)." << std::endl;

   std::cout << std::endl;

   std::cout << "Examples:" << std::endl;
   std::cout << "\tppmedit -e b-solid -b 50 -i i.ppm\t\t\tadd a solid border "
    << "to the image with size 50(px)." << std::endl;
}

/**
 * @brief Print the tutorial on how to use the effect option.
 */
void printEffectHelp() {
   /* TODO: Set the help information for the effects option. */
}

/**
 * @brief Print the tutorial on how to use the font option.
 */
void printFontHelp() {
   /* TODO: Set the help information for the font option. */
}

/**
 * @brief Print the tutorial on how to use the foreground option.
 */
void printForegroundHelp() {
   /* TODO: Set the help information for the foreground option. */
}

/**
 * @brief Print the tutorial on how to use the input option.
 */
void printInputHelp() {
   /* TODO: Set the help information for the input option. */
}

/**
 * @brief Print the tutorial on how to use the length option.
 */
void printLengthHelp() {
   /* TODO: Set the help information for the length option. */
}

/**
 * @brief Print the tutorial on how to use the output option.
 */
void printOutputHelp() {
   /* TODO: Set the help information for the output option. */
}

/**
 * @brief Print the tutorial on how to use the space option.
 */
void printSpaceHelp() {
   /* TODO: Set the help information for the space option. */
}

/**
 * @brief Print the tutorial on how to use the text option.
 */
void printTextHelp() {
   /* TODO: Set the help information for the text option. */
}

#endif // HELPERS_HPP
