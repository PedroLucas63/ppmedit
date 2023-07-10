/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief ppm file manipulation program.
 * @version 2.0
 * @date 2023-06-25
 * 
 * Execution of various methods for the transformation of ppm (portable pixmap)
 * images with guaranteed execution according to the expected parameters.
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Manipulator.hpp"

using namespace std;

/**
 * @brief Main function of the program (starting point). 
 * 
 * @param argc Number of arguments.
 * @param argv Arguments values.
 * @return An integer. 
 */
int main(int argc, char* argv[]) {
   performEditing(argc, argv);
   
   return 0;
}
