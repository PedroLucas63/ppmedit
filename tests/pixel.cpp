#include <iostream>
#include "../libs/Pixel.hpp" //! Include Pixel header

using namespace std;

//! Main function start
int main() {
   //^ Informations 
   Pixel real { 192, 256, 178 }; //* Real
   Pixel expected { 192, 255, 178 }; //* Expected

   //^ Check equality
   if (real == expected) {
      cout << "✔ Test success!" << endl;
   } else {
      cout << " ✕ Test error!" << endl;
   }
} //! End of main function
