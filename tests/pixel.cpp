#include <iostream>
#include "../libs/Pixel.hpp" //! Include Pixel header

using namespace std;

//! Main function start
int main(int argc, char* argv[]) {
   //^ Informations 
   Pixel real { 192, 256, 178 }; //* Real
   Pixel expected { 192, 255, 178 }; //* Expected

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
