#include <iostream>
#include "../../libs/Image.hpp" //! Include Image header

using namespace std;

//! Main function start
int main() {
   //* Definition of variables to create a image object
   //? The type is set automatically, however it is still received on input
   string type { "" };
   int width { 0 };
   int height { 0 };
   int colors { 0 };

   //* Get user data
   cin >> type;
   cin >> width >> height;
   cin >> colors;

   //* Calculate image size and create array with "image size" pixels
   int size { width * height };
   Pixel pixels[size];

   for (int i { 0 }; i < size; i++) { //* Repeat "image size" times
      //^ Definition of variables to create a pixel's objects
      int red { 0 };
      int green { 0 };
      int blue { 0 };

      //^ Get user data
      cin >> red >> green >> blue;

      //^ Create a pixel and insert it into the array
      Pixel pixel { red, green, blue, colors };
      pixels[i] = pixel;
   }

   Image image1, image2; //* Create two images without data
   //* Create a image with data
   Image image3 { width, height, colors, pixels };
   Image image4 { image3 }; //* Create a image with other image
   image2 = image4;         //* Receipt operator of image

   //* Show data
   cout << image1.toString() << "\n";
   cout << image2.toString() << "\n";
   cout << image3.toString() << "\n";
   cout << image4.toString() << "\n\n";
} //! End of main function
