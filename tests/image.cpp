#include <iostream>
#include <vector>
#include "../libs/Image.hpp" //! Include Image header

using namespace std;

//! Main function start
int main(int argc, char* argv[]) {
   //^ Informations 
   vector<vector<Pixel>> real_pixels = { 
      { { 0, 0, 5 }, { 125, 9, 90 }, { 256, -2, 5 } }, 
      {{ 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, -100 } } 
   }; //* Real pixels
   Image real { 3, 2, 255, real_pixels }; //* Real image

   vector<vector<Pixel>> expected_pixels = { 
      { { 0, 0, 5 }, { 125, 9, 90 }, { 255, 0, 5 } }, 
      {{ 0, 0, 0 }, { 192, 78, 15 }, { 30, 0, 0 } } 
   }; //* Expected pixels
   Image expected { 3, 2, 255, expected_pixels }; //* Expected image
   
   //^ Get the name of the test
   string full_name { argv[0] };
   std::size_t last_separator { full_name.find_last_of("/\\") };
   string program_name { full_name.substr(last_separator) };

   //^ Write program name
   cout << "." << program_name << " - ";

   //^ Check equality
   if (real == expected) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << "✕ Test error!" << endl;
   }
} //! End of main function
