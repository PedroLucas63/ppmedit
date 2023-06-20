/**
 * @file Test.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Test settings.
 * @version 1.1
 * @date 2023-06-20
 *
 * Tests for methods of the "Editor" class.
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <fstream>
#include "Editor.hpp"

/**
 * @enum Methods enumeration.
 * @brief Enumeration with all methods of the "Editor" class.
 */
enum Methods {
   Blurring,
   Combine,
   Edge_Sharpening,
   Embossing,
   Enlarge,
   Gray,
   Invert,
   Negative,
   Reduce,
   Rotate_Left,
   Rotate_Right,
   Sharpening
};

/**
 * @class Test class.
 * @brief Test definition with attributes and methods.
 */
class Test {
public:
   /**
    * @brief Construct a new Test object with no data.
    */
   Test() { }

   /**
    * @brief Construct a new Test object with image data.
    *
    * @param original_image Original image local.
    * @see openImage()
    */
   Test(std::string original_image) {
      image = openImage(original_image);
   }

   /**
    * @brief Destroy the Test object.
    */
   ~Test() { }

   /**
    * @brief Opens an image from the location.
    * 
    * @param local Image Location.
    * @return Image.
    */
   Image openImage(std::string local) {
      std::string type { "" };
      int width { 0 };
      int height { 0 };
      int colors { 0 };
      int red { 0 };
      int green { 0 };
      int blue { 0 };

      std::ifstream file(local);

      file >> type;
      file >> width;
      file >> height;
      file >> colors;

      Image image { width, height, colors };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            file >> red;
            file >> green;
            file >> blue;

            Pixel pixel { red, green, blue, colors };
            image.setPixel(pixel, row, column);
         }
      }

      file.close();

      return image;
   }

   /**
    * @brief Runs the method and checks for equality with expectation.
    * 
    * @param expected_image Expected image in the test.
    * @param method Method used in the test.
    * @see openImage()
    */
   void test(std::string expected_image, Methods method) {
      Editor editor { image };
      Image expected = openImage(expected_image);
      bool passed { false };

      switch(method) {
         case Blurring:
            std::cout << "Blurring:\n\t";
            editor.applyImageEffects("blurring");
            passed = editor.getImage() == expected;
            break;
         case Edge_Sharpening:
            std::cout << "Edge Sharpening:\n\t";
            editor.applyImageEffects("edge-sharpening");
            passed = editor.getImage() == expected;
            break;
         case Embossing:
            std::cout << "Embossing:\n\t";
            editor.applyImageEffects("embossing");
            passed = editor.getImage() == expected;
            break;
         case Enlarge:
            std::cout << "Enlarge:\n\t";
            editor.enlargeImage();
            passed = editor.getImage() == expected;
            break;
         case Gray:
            std::cout << "Grayscale:\n\t";
            editor.grayscaleImage();
            passed = editor.getImage() == expected;
            break;
         case Invert:
            std::cout << "Invert:\n\t";
            editor.rotateImage("invert");
            passed = editor.getImage() == expected;
            break;
         case Negative:
            std::cout << "Negative:\n\t";
            editor.negativeImage();
            passed = editor.getImage() == expected;
            break;
         case Reduce:
            std::cout << "Reduce:\n\t";
            editor.reduceImage();
            passed = editor.getImage() == expected;
            break;
         case Rotate_Left:
            std::cout << "Rotate Left:\n\t";
            editor.rotateImage("left");
            passed = editor.getImage() == expected;
            break;
         case Rotate_Right:
            std::cout << "Rotate Right:\n\t";
            editor.rotateImage("right");
            passed = editor.getImage() == expected;
            break;
         case Sharpening:
            std::cout << "Sharpening:\n\t";
            editor.applyImageEffects("sharpening");
            passed = editor.getImage() == expected;
            break;
      }

      if (passed) {
         std::cout << "✔ Test success!" << std::endl;
      } else {
         std::cout << "✕ Test error!" << std::endl;
      }
   }

   /**
    * @brief Runs the method and checks for equality with expectation.
    * 
    * @param additional_image Additional image for the method.
    * @param expected_image Expected image in the test.
    * @param method Method used in the test.
    * @see openImage()
    */
   void test(std::string additional_image, std::string expected_image,
      Methods method) 
   {
      Editor editor { image };
      Image additional = openImage(additional_image);
      Image expected = openImage(expected_image);
      bool passed { false };

      switch(method) {
         case Combine:
            std::cout << "Combine:\n\t";
            editor.combineImages(additional);
            passed = editor.getImage() == expected;
            break;
      }

      if (passed) {
         std::cout << "✔ Test success!" << std::endl;
      } else {
         std::cout << "✕ Test error!" << std::endl;
      }
   }

private:
   Image image; /**< Image */
};
