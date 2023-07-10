/**
 * @file Manual.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Manual functions.
 * @version 2.0
 * @date 2023-07-06
 * 
 * These functions provide the manual for various options and
 * parameters of the ppmedit program.
 * 
 * @note This file is generated with the help of ChatGPT.
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
	std::cout << "  polaroid: Add a polaroid-style border to the image\n\n";

	std::cout << "Additional Parameters:\n";
	std::cout << "  +s, ++size [SIZE]: Set the border size (pixels or textual: "
		<< "slim, normal, large)\n";
	std::cout << "  +c, ++color [COLOR]: Set the border color (white, black, red"
	<< ", green, blue, yellow, purple, cyan, pink, orange, brown, gray)\n";
	std::cout << "  +e, ++extra [EXTRA_SIZE]: Set extra size for the border\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Border size: Normal\n";
	std::cout << "  Border color: White\n";
	std::cout << "  Extra size: 0px\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -b solid +s large +c red +e 10 -i input.ppm -o "
		<< "output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the combine option.
 */
void printCombineManual() {
	std::cout << "Usage: ppmedit -c, --combine [OPTIONS] ... -i "
		<< "[BACKGROUND_IMAGE] [FOREGROUND_IMAGE] -o [OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  +p, ++position [POSITION_X] [POSITION_Y]: Sets the "
		<< "position of the background to start the collage\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Position: 0px 0px\n\n";
	
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
 */
void printConvertManual() {
	std::cout << "Usage: ppmedit --convert [CONVERSION_TYPE] -i [INPUT_FILE] "
		<< "-o [OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  [CONVERSION_TYPE]: Specify the conversion type "
		<< "(text, binary, )\n\n";
	
	std::cout << "Conversion Types:\n";
	std::cout << "  text: Convert the image from binary (P6) to textual (P3)\n";
	std::cout << "  binary: Convert the image from textual (P3) to binary "
		<< "(P6)\n\n";
	
	std::cout << "Defaults: Automatically convert the image type based on the "
		<< "initial format\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit --convert text -i input.ppm -o output.ppm\n";
}

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
 */
void printInputManual() { 
	std::cout << "Usage: ppmedit -i, --input [INPUT_FILES]... -o "
		<< "[OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  [INPUT_FILES]...: Specify input image(s)\n\n";
	
	std::cout << "Note: The number of input images may vary depending on "
		<< "the specific function.\n";
	std::cout << "Please refer to the manual of the specific function for "
		<< "the exact number of required input images.\n\n";
	
	std::cout << "Defaults: No defaults\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -i input.ppm -o output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the output option.
 */
void printOutputManual() { 
	std::cout << "Usage: ppmedit -i [INPUT_FILES]... -o, --output "
		<< "[OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  [OUTPUT_FILE]: Specify the output file\n\n";
	
	std::cout << "Note: If not defined, the default output file is a.ppm. "
		<< "If the file already exists, it will be overwritten.\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -i input.ppm -o output.ppm\n";
}

/**
 * @brief Print the tutorial on how to use the text option.
 */
void printTextManual() { 
	std::cout << "Usage: ppmedit -t, --text [TEXT]... -i [INPUT_FILES] "
		<< "-o [OUTPUT_FILE]\n\n";
	
	std::cout << "Options:\n";
	std::cout << "  [TEXT]...: Specify the text to be written\n\n";
	
	std::cout << "Additional Parameters:\n";
	std::cout << "  +p, ++position [X] [Y]: Set the starting position "
		<< "(default: 0 0)\n";
	std::cout << "  +a, ++align [ALIGNMENT]: Set the text alignment "
		<< "(left, right, center)\n";
	std::cout << "  +f, ++font [FONT]: Set the font to be used (Highlander, "
		<< "IBM, Satisfy, Netchild, Love, or specify a .bdf font file)\n\n";
	
	std::cout << "Text Format:\n";
	std::cout << "  Enclose the text in double quotes, e.g., \"My text\"\n";
	std::cout << "  Color can be defined using the format \"#COLOR\", e.g., "
		<< "\"My #RED love\"\n";
	std::cout << "  Emojis can be included using their reference between "
		<< "colons, e.g., \"My love :heart:\"\n\n";
	
	std::cout << "Defaults:\n";
	std::cout << "  Position: 0px 0px\n";
	std::cout << "  Alignment: Left\n";
	std::cout << "  Font: Highlander\n\n";

	std::cout << "Available Colors:\n";
   std::cout << "  To see the list of available colors, use the command: "
		<< "ppmedit --list-colors\n\n";
   
   std::cout << "Available Emojis:\n";
   std::cout << "  To see the list of available emojis, use the command: "
		<< "ppmedit --list-emojis\n\n";
	
	std::cout << "Example:\n";
	std::cout << "  ppmedit -t \"My #RED love\" -i input.ppm -o output.ppm\n";
}

/**
 * @brief Lists all the colors accepted for the program.
 */
void listColors() {
	std::cout << "Available Colors in ppmedit:\n";
	std::cout << "  white: White color\n";
	std::cout << "  black: Black color\n";
	std::cout << "  red: Red color\n";
	std::cout << "  blue: Blue color\n";
	std::cout << "  green: Green color\n";
	std::cout << "  yellow: Yellow color\n";
	std::cout << "  cyan: Cyan color\n";
	std::cout << "  gray: Gray color\n";
	std::cout << "  orange: Orange color\n";
	std::cout << "  pink: Pink color\n";
	std::cout << "  purple: Purple color\n";
	std::cout << "  brown: Brown color\n";
}

/**
 * @brief Lists all the emojis accepted for the program.
 */
void listEmojis() {
	std::cout << "Accepted Emojis in ppmedit:\n";
	std::cout << "  :heart: - Heart emoji\n";
	std::cout << "  :skull: - Skull emoji\n";
	std::cout << "  :anchor: - Anchor emoji\n";
	std::cout << "  :syringe: - Syringe emoji\n";
	std::cout << "  :deer: - Deer emoji\n";
	std::cout << "  :dog: - Dog emoji\n";
	std::cout << "  :sun: - Sun emoji\n";
	std::cout << "  :umbrella: - Umbrella emoji\n";
	std::cout << "  :potion: - Potion emoji\n";
	std::cout << "  :plane: - Plane emoji\n";
	std::cout << "  :tank: - Tank emoji\n";
	std::cout << "  :squid: - Squid emoji\n";
	std::cout << "  :bug: - Bug emoji\n";
	std::cout << "  :cat: - Cat emoji\n";
	std::cout << "  :arrows: - Arrows emoji (pointing in opposite directions)\n";
	std::cout << "  :white-skull: - White skull emoji\n";
	std::cout << "  :farmer: - Farmer emoji\n";
	std::cout << "  :high-heels: - High heels emoji\n";
	std::cout << "  :cutlery: - Cutlery emoji\n";
	std::cout << "  :shit: - Poop emoji\n";
	std::cout << "  :helicopter: - Helicopter emoji\n";
	std::cout << "  :television: - Television emoji\n";
	std::cout << "  :bird: - Bird emoji\n";
	std::cout << "  :snow: - Snow emoji\n";
	std::cout << "  :octopus: - Octopus emoji\n";
	std::cout << "  :sad: - Sad emoji\n";
	std::cout << "  :ant: - Ant emoji\n";
	std::cout << "  :cup: - Cup emoji\n";
	std::cout << "  :snake: - Snake emoji\n";
	std::cout << "  :rocket: - Rocket emoji\n";
	std::cout << "  :truck: - Truck emoji\n";
	std::cout << "  :globe: - Globe emoji\n";
	std::cout << "  :clock: - Clock emoji\n";
	std::cout << "  :cross: - Cross emoji\n";
	std::cout << "  :battery: - Battery emoji\n";
	std::cout << "  :console: - Game console emoji\n";
	std::cout << "  :fish: - Fish emoji\n";
	std::cout << "  :eyes: - Eyes emoji\n";
	std::cout << "  :click: - Click emoji\n";
	std::cout << "  :phone: - Phone emoji\n";
	std::cout << "  :other-cat: - Other cat emoji\n";
	std::cout << "  :cherry: - Cherry emoji\n";
	std::cout << "  :dinosaur: - Dinosaur emoji\n";
	std::cout << "  :people: - People emoji\n";
	std::cout << "  :frog: - Frog emoji\n";
	std::cout << "  :ghost: - Ghost emoji\n";
	std::cout << "  :girls: - Girls emoji\n";
	std::cout << "  :cactus: - Cactus emoji\n";
	std::cout << "  :shoe: - Shoe emoji\n";
	std::cout << "  :board: - Board emoji\n";
	std::cout << "  :face-cat: - Cat face emoji\n";
	std::cout << "  :apple: - Apple emoji\n";
	std::cout << "  :house: - House emoji\n";
	std::cout << "  :elephant: - Elephant emoji\n";
	std::cout << "  :folder: - Folder emoji\n";
	std::cout << "  :crab: - Crab emoji\n";
	std::cout << "  :lamp: - Lamp emoji\n";
	std::cout << "  :future-eye: - Future eye emoji\n";
	std::cout << "  :boy: - Boy emoji\n";
	std::cout << "  :stroller: - Stroller emoji\n";
}

#endif // MANUAL_HPP
