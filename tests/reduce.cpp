#include <iostream>

#include "../libs/Editor.hpp" //! Include Editor header
using namespace std;

//! Main function start
int main() {
   //* Definition of variables to create a editor object
   string type{ "" };
   int width{ 0 };
   int height{ 0 };
   int colors{ 0 };

   //* Get user data
   cin >> type;
   cin >> width >> height;
   cin >> colors;

   //* Calculate image size and create array with "image size" pixels
   int size{ width * height };
   Pixel pixels[size];

   for (int i{ 0 }; i < size; i++) { //* Repeat "image size" times
      //^ Definition of variables to create a pixel's objects
      int red{ 0 };
      int green{ 0 };
      int blue{ 0 };

      //^ Get user data
      cin >> red >> green >> blue;

      //^ Create a pixel and insert it into the array
      Pixel pixel{ red, green, blue, colors };
      pixels[i] = pixel;
   }

   //* Create a editor with data
   Editor editor{ type, width, height, colors, pixels };

   editor.reduce(); //* Reduce image

   editor.save(); //* Save the image output
}
//! End of main function
