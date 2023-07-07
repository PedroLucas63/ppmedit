/**
 * @file Test.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Test settings.
 * @version 2.0
 * @date 2023-07-04
 *
 * Tests for methods of the "Editor" class.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <fstream>
#include "Manipulator.hpp"
#include "Editor.hpp"

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
    */
   Test(std::string original_image) {
      openImage(original_image, image);
   }

   /**
    * @brief Destroy the Test object.
    */
   ~Test() { }

   /**
    * @brief Get the quantify of tests.
    *
    * @return An integer.
    */
   int getTests() const {
      return tests;
   }

   /**
    * @brief Get the quantify of success tests.
    *
    * @return An integer.
    */
   int getSuccessTests() const {
      return success_tests;
   }

   /**
    * @brief Runs the method and checks for equality with expectation.
    * 
    * @param expected_image Expected image in the test.
    * @param effect Effect used in the test.
    */
   void testEffect(std::string expected_image, Effects effect) {
      Editor editor { image };
      Image expected;
      bool passed { false };

      openImage(expected_image, expected);

      switch(effect) {
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
         default:
            break;
      }

      if (passed) {
         std::cout << "✔ Test success!" << std::endl;
         success_tests++;
      } else {
         std::cout << "✕ Test error!" << std::endl;
      }

      tests++;
   }

private:
   Image image;             /**< Image */
   int tests { 0 };         /**< Quantify of tests */
   int success_tests { 0 }; /**< Quantify of success tests */
};

#endif // TEST_HPP
