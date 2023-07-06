/**
 * @file Manual.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Manual functions.
 * @version 2.0
 * @date 2023-07-06
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
	std::cout << "  -c, --combine [OPTIONS]: Combines two images\n";
	std::cout << "  -C, --collage [OPTIONS]: Create a collage of images\n";
	std::cout << "  --convert: Convert the image to another format\n";
	std::cout << "  -e, --effect [OPTIONS]: Apply an effect to the image\n";
	std::cout << "  -h, --help [OPTIONS]: Display this Manual manual\n";
	std::cout << "  -i, --input [INPUT_FILES]: Specify input image(s)\n";
	std::cout << "  -o, --output [OUTPUT_FILE]: Specify output image\n" ;
	std::cout << "  -t, --text [OPTIONS]: Add text to the image\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Output file: a.ppm\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -b polaroid -i input1.ppm -o output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the border option.
 */
void printBorderManual() {
	std::cout << "Usage: ppmedit -b, --border [BORDER_TYPE] [OPTIONS]... -i "
		<< "[INPUT_FILES] -o [OUTPUT_FILE]\n\n";
	
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
 * @brief Print the tutorial on how to use the combine option.
 */
void printCombineManual() {
	std::cout << "Usage: ppmedit -c, --combine -i [BACKGROUND_IMAGE] "
		<< "[FOREGROUND_IMAGE] -o [OUTPUT_FILE]\n\n";
	
	std::cout << "Options: No options\n\n";
	
	std::cout << "Defaults: No defaults\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -c -i background.ppm foreground.ppm -o "
		<< "output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the collage option.
 */
void printCollageManual() {
	std::cout << "Usage: ppmedit -C, --collage [COLLAGE_TYPE] -i [INPUT_FILES] "
		<< "... -o [OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  [COLLAGE_TYPE]: Specify the collage type (Full, Square)\n";
	
	std::cout << "Collage Types:\n";
	std::cout << "  Full: The entire image will be pasted onto the others\n";
	std::cout << "  Square: The images will be resized to fit a square "
		<< "format\n\n";
	
	std::cout << "Image Arrangement:\n";
	std::cout << "  2 images: Side by side\n";
	std::cout << "  3 images: First image next to the second, third image "
		<< "below the first two\n";
	std::cout << "  4 images: First two images side by side, last two images "
		<< "below them\n\n";
	
	std::cout << "Defaults: No defaults\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -C Full -i image1.ppm image2.ppm image3.ppm "
		<< "-o output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the convert option.
 * 
 * @todo Set the Manual information for the convert option.
 */
void printConvertManual() { }

/**
 * @brief Print the tutorial on how to use the effect option.
 */
void printEffectManual() { 
	std::cout << "Usage: ppmedit -e, --effect [EFFECT_TYPE]... -i "
		<< "[INPUT_FILES] -o [OUTPUT_FILE]\n\n";

	std::cout << "Options:\n";
	std::cout << "  gray: Convert the image to grayscale\n";
	std::cout << "  negative: Invert the colors of the image\n";
	std::cout << "  rotate: Rotate the image clockwise by 90 degrees\n";
	std::cout << "  rotate-l: Rotate the image counter-clockwise by 90 "
		<< "degrees\n";
	std::cout << "  invert: Invert the colors of the image\n";
	std::cout << "  enlarge: Enlarge the image (2x)\n";
	std::cout << "  reduce: Reduce the image (2x)\n";
	std::cout << "  sharp: Apply a sharpening effect to the image\n";
	std::cout << "  sharp-e: Apply an edge sharpening effect to the image\n";
	std::cout << "  blur: Apply a blur effect to the image\n";
	std::cout << "  embossing: Apply an embossing effect to the image\n\n";

	std::cout << "Defaults:\n";
	std::cout << "  No effect is applied\n\n";

	std::cout << "Example:\n";
	std::cout << "  ppmedit -e gray negative rotate -i input.ppm -o "
		<< "output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the input option.
 * 
 * @todo Set the Manual information for the input option.
 */
void printInputManual() { }

/**
 * @brief Print the tutorial on how to use the output option.
 * 
 * @todo Set the Manual information for the output option.
 */
void printOutputManual() { }

/**
 * @brief Print the tutorial on how to use the text option.
 * 
 * @todo Set the Manual information for the text option.
 */
void printTextManual() { }

#endif // MANUAL_HPP
