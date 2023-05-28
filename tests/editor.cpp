#include <iostream>
#include <string>
#include "../libs/Editor.hpp" //! Include Editor header

using namespace std;

//! Main function start
int main(int argc, char* argv[]) {
   //^ Informations 
   Pixel real_pixels[6] = { { 0, 0, 5 }, { 125, 9, 90 }, { 256, -2, 5 },
      { 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, -100 } }; //* Real pixels
   Image real_image { 3, 2, 255, real_pixels }; //* Real image
   Editor real { real_image }; //* Real

   Pixel expected_pixels[6] = { { 0, 0, 5 }, { 125, 9, 90 }, { 255, 0, 5 },
      { 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, 0 } }; //* Expected pixels
   Image expected_image { 3, 2, 255, expected_pixels }; //* Expected

   //^ Get the name of the test
   string full_name { argv[0] };
   std::size_t last_separator { full_name.find_last_of("/\\") };
   string program_name { full_name.substr(last_separator) };

   //^ Write program name
   cout << "." << program_name << " - ";

   //^ Check equality
   if (real.getImageOutput() == expected_image) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << "✕ Test error!" << endl;
   }
} //! End of main function
