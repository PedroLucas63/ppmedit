/**
 * @file Manual.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Manual functions.
 * @version 2.0
 * @date 2023-06-25
 * 
 * Defines the Manual functions, either of the program in general or of a
 * specific parameter.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef MANUAL_HPP
#define MANUAL_HPP

#include <iostream>

/**
 * @brief Print the tutorial on how to use the program.
 */
void printManual() {
   std::cout << "Usage: ppmedit [OPTIONS]... -i [INPUT_FILES] -o [OUTPUT_FILE]"
		<< "\n\n";

	std::cout << "Options:\n";
	std::cout << "  -b, --border [OPTIONS]: Add a border to the image\n";
	std::cout << "  -e, --effect [OPTIONS]: Apply an effect to the image\n";
	std::cout << "  -t, --text [OPTIONS]: Add text to the image\n";
	std::cout << "  -h, --Manual [OPTIONS]: Display this Manual manual\n";
	std::cout << "  -i, --input [INPUT_FILES]: Specify input image(s)\n";
	std::cout << "  -o, --output [OUTPUT_FILE]: Specify output image\n" ;
	std::cout << "  -c, --convert: Convert the image to another format\n";
	std::cout << "  -C, --collage [OPTIONS]: Create a collage of images\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Output file: a.ppm\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -b polaroid -i input1.ppm -o output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the border option.
 */
void printBorderManual() {
	std::cout << "Usage: ppmedit [OPTIONS]... -i [INPUT_FILES] -o [OUTPUT_FILE]"
		<< "\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  solid: Add a solid border to the image\n";
	std::cout << "  polaroid: Add a polaroid-style border to the image\n";
	std::cout << "  !s, !!size [SIZE]: Set the border size (pixels or textual: "
		<< "Slim, Normal, Large)\n";
	std::cout << "  !c, !!color [COLOR]: Set the border color (white, black, red"
	<< ", green, blue, yellow, purple, cyan, pink, orange, brown, gray)\n";
	std::cout << "  !e, !!extra [EXTRA_SIZE]: Set extra size for the border\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Border size: Normal\n";
	std::cout << "  Border color: White\n";
	std::cout << "  Extra size: 0px\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -b solid !s large !c red !e 10 -i input.ppm -o "
		<< "output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the effect option.
 * 
 * @todo Set the Manual information for the effects option.
 */
void printEffectManual() { }

/**
 * @brief Print the tutorial on how to use the font option.
 * 
 * @todo Set the Manual information for the font option.
 */
void printFontManual() { }

/**
 * @brief Print the tutorial on how to use the foreground option.
 * 
 * @todo Set the Manual information for the foreground option.
 */
void printForegroundManual() { }

/**
 * @brief Print the tutorial on how to use the input option.
 * 
 * @todo Set the Manual information for the input option.
 */
void printInputManual() { }

/**
 * @brief Print the tutorial on how to use the length option.
 * 
 * @todo Set the Manual information for the length option.
 */
void printLengthManual() { }

/**
 * @brief Print the tutorial on how to use the output option.
 * 
 * @todo Set the Manual information for the output option.
 */
void printOutputManual() { }

/**
 * @brief Print the tutorial on how to use the space option.
 * 
 * @todo Set the Manual information for the space option.
 */
void printSpaceManual() { }

/**
 * @brief Print the tutorial on how to use the text option.
 * 
 * @todo Set the Manual information for the text option.
 */
void printTextManual() { }

#endif // MANUAL_HPP
