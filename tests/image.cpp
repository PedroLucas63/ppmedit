#include <iostream>
#include "../libs/Image.hpp" //! Include Image header

using namespace std;

//! Main function start
int main() {
   //^ Informations 
   Pixel real_pixels[6] = { { 0, 0, 5 }, { 125, 9, 90 }, { 256, -2, 5 },
      { 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, -100 } }; //* Real pixels
   Image real { 3, 2, 255, real_pixels }; //* Real

   Pixel expected_pixels[6] = { { 0, 0, 5 }, { 125, 9, 90 }, { 255, 0, 5 },
      { 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, 0 } }; //* Expected pixels
   Image expected { 3, 2, 255, expected_pixels }; //* Expected

   //^ Check equality
   if (real == expected) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << " ✕ Test error!" << endl;
   }
} //! End of main function
