#include <iostream>
#include "../../libs/Pixel.hpp" //! Include Pixel header

using namespace std;

//! Main function start
int main() {
   //* Definition of variables to create a pixel object
   int maximum_colors { 0 };
   int red_intensity { 0 };
   int green_intensity { 0 };
   int blue_intensity { 0 };

   int const QUANT { 5 }; //* Amount of pixels

   for (int i { 0 }; i < QUANT; i++) { //* Repeat five times
      //^ Get user data
      cin >> maximum_colors;
      cin >> red_intensity >> green_intensity >> blue_intensity;

      Pixel pixel1, pixel2; //^ Create two pixels without data
      Pixel pixel3 { red_intensity, green_intensity, blue_intensity,
                     maximum_colors }; //^ Create a pixel with data
      Pixel pixel4 { pixel3 };         //^ Create a pixel with other pixel
      pixel2 = pixel4;                 //^ Receipt operator of pixel

      //^ Show data
      cout << pixel1.toString() << "\n";
      cout << pixel2.toString() << "\n";
      cout << pixel3.toString() << "\n";
      cout << pixel4.toString() << "\n\n";
   }
} //! End of main function
