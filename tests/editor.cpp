#include "../libs/Editor.hpp"  //! Include Editor header

#include <iostream>
using namespace std;

//! Main function start
int main() {
   //* Definition of variables to create a editor object
   string type{""};
   int width{0};
   int height{0};
   int colors{0};

   //* Get user data
   cin >> type;
   cin >> width >> height;
   cin >> colors;

   //* Calculate image size and create array with "image size" pixels
   int size{width * height};
   Pixel pixels[size];

   for (int i{0}; i < size; i++) {  //* Repeat "image size" times
      //^ Definition of variables to create a pixel's objects
      int red{0};
      int green{0};
      int blue{0};

      //^ Get user data
      cin >> red >> green >> blue;

      //^ Create a pixel and insert it into the array
      Pixel pixel{red, green, blue, colors};
      pixels[i] = pixel;
   }

   Editor editor1, editor2; //* Create two editor's without data
   //* Create a editor with data
   Editor editor3{type, width, height, colors, pixels};
   Editor editor4{editor3}; //* Create a editor with other editor
   editor2 = editor4; //* Receipt operator of editor

   //* Save images output (show values)
   //~ editor1.save(); -> Error because no image opens
   editor2.save();
   editor3.save();
   editor4.save();
}
//! End of main function
