#include <iostream>
#include <fstream>
#include "../libs/Editor.hpp" //! Include Editor header

using namespace std;

//! Main function start
int main(int argc, char* argv[]) {
   //^ Created all the variables to create an image
   string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };
   int red { 0 };
   int green { 0 };
   int blue { 0 };

   //^ Background image
   ifstream background("../docs/imgs/flowers.ppm"); //~ Open image

   //~ Get information (without pixels)
   background >> type;
   background >> width;
   background >> height;
   background >> colors;

   //~ Create a background image
   Image background_image { width, height, colors };

   //~ Scroll through the pixels
   for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
         //? Get pixels informations
         background >> red;
         background >> green;
         background >> blue;

         //?  Create a pixel and set in the image
         Pixel pixel { red, green, blue, colors };
         background_image.setPixel(pixel, row, column);
      }
   }

   //~ Create a real editor
   Editor real_editor { background_image };

   //~ Close image
   background.close(); 

   //^ Foreground image
   ifstream foreground("../docs/imgs/bill.ppm"); //~ Open image

   //~ Get information (without pixels)
   foreground >> type;
   foreground >> width;
   foreground >> height;
   foreground >> colors;

   //~ Create a foreground image
   Image foreground_image { width, height, colors };

   //~ Scroll through the pixels
   for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
         //? Get pixels informations
         foreground >> red;
         foreground >> green;
         foreground >> blue;

         //?  Create a pixel and set in the image
         Pixel pixel { red, green, blue, colors };
         foreground_image.setPixel(pixel, row, column);
      }
   }

   //~ Close image
   foreground.close(); 

   //^ Edited image
   ifstream edited("../docs/imgs/combine.ppm"); //~ Open image

   //~ Get information (without pixels)
   edited >> type;
   edited >> width;
   edited >> height;
   edited >> colors;

   //~ Create a expected image
   Image expected_image { width, height, colors };
   
   //~ Scroll through the pixels

   for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
         //? Get pixels informations
         edited >> red;
         edited >> green;
         edited >> blue;

         //?  Create a pixel and set in the image
         Pixel pixel { red, green, blue, colors };
         expected_image.setPixel(pixel, row, column);
      }
   }
   
   //~ Close image
   edited.close();

   real_editor.combineImages(foreground_image); //^ Blurring filter int the image

   //^ Get the name of the test
   string full_name { argv[0] };
   std::size_t last_separator { full_name.find_last_of("/\\") };
   string program_name { full_name.substr(last_separator) };

   //^ Write program name
   cout << "." << program_name << " - ";

   //^ Check equality
   if (real_editor.getImageOutput() == expected_image) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << "✕ Test error!" << endl;
   }
} //! End of main function
