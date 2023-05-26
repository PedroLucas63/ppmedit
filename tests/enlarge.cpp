#include <iostream>
#include <fstream>
#include "../libs/Editor.hpp" //! Include Editor header

using namespace std;

//! Main function start
int main() {
   //^ Created all the variables to create an image
   string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };
   int red { 0 };
   int green { 0 };
   int blue { 0 };

   //^ Not edited image
   ifstream not_edited("../docs/imgs/galinhos.ppm"); //~ Open image

   //~ Get information (without pixels)
   not_edited >> type;
   not_edited >> width;
   not_edited >> height;
   not_edited >> colors;

   //~ Create a real image
   Image real_image { width, height, colors };

   //~ Scroll through the pixels
   for (int row { 0 }; row < height; row++) {
      for (int column { 0 }; column < width; column++) {
         //? Get pixels informations
         not_edited >> red;
         not_edited >> green;
         not_edited >> blue;

         //?  Create a pixel and set in the image
         Pixel pixel { red, green, blue, colors };
         real_image.setPixel(pixel, row, column);
      }
   }

   //~ Create a real editor
   Editor real_editor { real_image };

   //~ Close image
   not_edited.close(); 

   //^ Edited image
   ifstream edited("../docs/imgs/enlarge.ppm"); //~ Open image

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

   real_editor.enlargeImage(); //^ Enlarge image

   //^ Check equality
   if (real_editor.getImageOutput() == expected_image) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << " ✕ Test error!" << endl;
   }
} //! End of main function
