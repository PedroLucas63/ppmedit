/**
 * @file Editor.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Editor settings.
 * @version 1.1
 * @date 2023-06-20
 *
 * Portable pixmap image editor (ppm) with several methods to modify images.
 *
 * @copyright Copyright (c) 2023
 */

#include <string.h>
#include "./Image.hpp"

#define MASK_SIZE 3 /**< Mask width and height */

/**
 * @class Editor class.
 * @brief Editor definition with attributes and methods.
 */
class Editor {
public:
   /**
    * @brief Construct a new Editor object with no data.
    */
   Editor() { }

   /**
    * @brief Construct a new Editor object with full data.
    *
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @param pixels Image pixels.
    * @see setImage()
    */
   Editor(int width, int height, int colors, 
      std::vector<std::vector<Pixel>> pixels) 
   {
      setImage(width, height, colors, pixels);
   }

   /**
    * @brief Construct a new Editor object with an image.
    *
    * @param image An image.
    * @see setImage()
    */
   Editor(Image const& image) { setImage(image); }

   /**
    * @brief Construct a new Editor object with another editor (copy).
    *
    * @param rhs A editor to copy.
    * @see setImage()
    * @see getImage()
    */
   Editor(Editor const& rhs) {
      setImage(rhs.getImage());
   }

   /**
    * @brief Operator to receive a editor (copy).
    *
    * @param rhs A editor to receive.
    * @see setImage()
    * @see getImage()
    */
   void operator=(Editor const& rhs) {
      setImage(rhs.getImage());
   }

   /**
    * @brief Destroy the Editor object
    */
   ~Editor() { }

   /**
    * @brief Set image with full data.
    * 
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @param pixels Image pixels.
    */
   void setImage(int width, int height, int colors, 
      std::vector<std::vector<Pixel>> pixels) 
   {
      image = Image{ width, height, colors, pixels };
   }

   /**
    * @brief Set image with other image.
    * 
    * @param image An image.
    */
   void setImage(Image const& copy_image) 
   {
      image = copy_image ;
   }

   /**
    * @brief Get image.
    *
    * @return An image with the last modification.
    */
   Image getImage() const { return image; }

   /**
    * @brief Transform the image into grayscale.
    */
   void grayscaleImage() {
      int width { image.getWidth() };
      int height { image.getHeight() };
      int colors { image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            Pixel pixel = image.getPixel(row, column);

            /*
             * Calculate the average of the channels in the pixel.
             */
            int average { (pixel.getRed() + pixel.getGreen()
               + pixel.getBlue()) / CHANNELS_PER_PIXEL };

            Pixel grayscale_pixel { average, average, average, colors };
            image.setPixel(grayscale_pixel, row, column);
         }
      }
   }

   /**
    * @brief Transform the image into negative.
    */
   void negativeImage() {
      int width { image.getWidth() };
      int height {image.getHeight() };
      int colors { image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            Pixel pixel { image.getPixel(row, column) };

            /*
             * It subtracts the maximum number of colors per channel by the
             * value of each one.
             */
            int new_red { colors - pixel.getRed() };
            int new_green { colors - pixel.getGreen() };
            int new_blue { colors - pixel.getBlue() };

            Pixel negative_pixel { new_red, new_green, new_blue, colors };
            image.setPixel(negative_pixel, row, column);
         }
      }
   }

   /**
    * @brief Rotate image to the right.
    * @see setImage()
    */
   void rotateRight() {
      int width { image.getWidth() };
      int height { image.getHeight() };

      Image rotate { height, width, image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            /*
             * Sets the pixel of the rotation image with the pixel of the
             * buffer image, in the defined row and column, to the position
             * determined by (column, height - row + 1).
             * Relationship obtained from the observations.
             */
            rotate.setPixel(image.getPixel(row, column), column, 
               height - row + 1);
         }
      }

      setImage(rotate);
   }

   /**
    * @brief Rotate image to the left.
    * @see setImage()
    */
   void rotateLeft() {
      int width { image.getWidth() };
      int height { image.getHeight() };

      Image rotate { height, width, image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            /*
             * Sets the pixel of the rotation image with the pixel of the
             * buffer image, in the defined row and column, to the position
             * determined by (width - column + 1, row).
             * Relationship obtained from the observations.
             */
            rotate.setPixel(
               image.getPixel(row, column), 
               width - column + 1, 
               row
            );
         }
      }

      setImage(rotate);
   }

   /**
    * @brief Invert the image.
    * @see setImage()
    */
   void invertImage() {
      int width { image.getWidth() };
      int height { image.getHeight() };

      Image invert { width, height, image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            /*
             * Get the invert pixel of the buffer image.
             */
            Pixel pixel { image.getPixel(row, width - column + 1) };
            invert.setPixel(pixel, row, column);
         }
      }

      setImage(invert);
   }

   /**
    * @brief Rotate the image.
    * 
    * @param side Side of rotation. Accepts "right", "left" and "invert".
    * Default is "right".
    * @see rotateRight()
    * @see rotateLeft()
    * @see flipImage()
    */
   void rotateImage(std::string side = "right") {
      if (side == "right") {
         rotateRight();
      } else if (side == "left") {
         rotateLeft();
      } else if (side == "invert") {
         invertImage();
      }
   }

   /**
    * @brief Enlarge image.
    * @see getAveragePixelIntensity()
    * @see setImage()
    */
   void enlargeImage() {
      int width { 2 * image.getWidth() - 1 };
      int height { 2 * image.getHeight() - 1 };

      Image enlarge { width, height, image.getColors() };

      /*
       * Fills in the original pixels, the pixels immediately below and the 
       * pixels immediately to the sides of the original
       */
      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            Pixel enlarge_pixel;

            if (row % 2 == 1 && column % 2 == 1) {
               enlarge_pixel = image.getPixel((row / 2) + 1, (column / 2) + 1);
            } else if (row % 2 == 1) {
               Pixel pixels_auxiliary[2] = {
                  image.getPixel((row / 2) + 1, column / 2),
                  image.getPixel((row / 2) + 1, (column / 2) + 1)
               };
               enlarge_pixel = getAveragePixelIntensity(pixels_auxiliary, 2);
            } else if (column % 2 == 1) {
               Pixel pixels_auxiliary[2] = {
                  image.getPixel(row / 2, (column / 2) + 1),
                  image.getPixel((row / 2) + 1, (column / 2) + 1)
               };
               enlarge_pixel = getAveragePixelIntensity(pixels_auxiliary, 2);
            }

            enlarge.setPixel(enlarge_pixel, row, column);
         }
      }
      
      /*
       * Fills in the pixels on the diagonals of the original pixels based on
       * the pixels below and above them generated in the previous loop.
       */
      for (int row { 2 }; row <= height; row += 2) {
         for (int column { 2 }; column <= width; column += 2) {
            Pixel enlarge_pixel;

            Pixel pixels_auxiliary[2] = {
               enlarge.getPixel(row - 1, column),
               enlarge.getPixel(row + 1, column)
            };
            enlarge_pixel = getAveragePixelIntensity(pixels_auxiliary, 2);

            enlarge.setPixel(enlarge_pixel, row, column);
         }
      }

      setImage(enlarge);
   }

   /**
    * @brief Reduce image.
    * @see getAveragePixelIntensity()
    * @see setImage()
    */
   void reduceImage() {
      int width { image.getWidth() % 2 == 0 ? image.getWidth() / 2
         : (image.getWidth() - 1) / 2 };
      int height { image.getHeight() % 2 == 0 ? image.getHeight() / 2
         : (image.getHeight() - 1) / 2 };

      Image reduce { width, height, image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            /*
             * Calculate the average of the pixel and the three adjacent 
             * pixels.
             */
            int quant_pixels { 4 };
            Pixel pixels[quant_pixels] = { 
               image.getPixel((row * 2) - 1, (column * 2) - 1),
               image.getPixel((row * 2) - 1, column * 2),
               image.getPixel((row * 2), (column * 2) - 1),
               image.getPixel((row * 2), column * 2) 
            };

            Pixel pixel_average { 
               getAveragePixelIntensity(pixels, quant_pixels) 
            };

            reduce.setPixel(pixel_average, row, column);
         }
      }

      setImage(reduce);
   }

   /**
    * @brief Apply different filters to the image.
    * 
    * @param filter Filter to be apply. Accepts "sharpening", "blurring",
    * "edge-sharpening" and "embossing". Default is "sharpening".
    * @see putOnMask()
    */
   void applyImageEffects(std::string filter = "sharpening") {
      float mask[MASK_SIZE][MASK_SIZE];

      if (filter == "sharpening") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { 0, -1,  0 }, 
            { -1, 5, -1 }, 
            { 0, -1,  0 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == "blurring") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { 1.0 / 9, 1.0 / 9, 1.0 / 9 }, 
            { 1.0 / 9, 1.0 / 9, 1.0 / 9 },
            { 1.0 / 9, 1.0 / 9, 1.0 / 9 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == "edge-sharpening") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { -1, -1, -1 },
            { -1,  9, -1 },
            { -1, -1, -1 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == "embossing") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { -2, -1, 0 }, 
            { -1,  1, 1 }, 
            {  0,  1, 2 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      }

      putOnMask(mask);
   }

   /**
    * @brief Combine an image with a foreground image of equal size.
    * 
    * @param foreground foreground image.
    * @see getImage()
    * @see setImage()
    */
   void combineImages(Image const& foreground) {
      int width { image.getWidth() };
      int height { image.getHeight() };

      if (width == foreground.getWidth() && height == foreground.getHeight()) {
         Pixel first_pixel { foreground.getPixel(0, 0) }; /* Pixel to ignore */

         for (int row { 1 }; row <= height; row++) {
            for (int column { 1 }; column <= width; column++) {
               /*
                * Set all pixels in the image other than the ignore pixel.
                */
               Pixel foreground_pixel { foreground.getPixel(row, column) };
               if (foreground_pixel != first_pixel) {
                  image.setPixel(foreground_pixel, row, column);
               }
            }
         }
      }
   }

private:
   Image image; /**< Image */

   /**
    * @public
    * @brief Get the average pixel among several pixels.
    * 
    * @param pixels Multiple pixels.
    * @param size Number of pixels.
    * @return A pixel.
    */
   Pixel getAveragePixelIntensity(Pixel* pixels, int size) {
      int colors { pixels[0].getMaxColors() };

      int red_sum { 0 };
      int green_sum { 0 };
      int blue_sum { 0 };

      for (int index { 0 }; index < size; index++) {
         red_sum += pixels[index].getRed();
         green_sum += pixels[index].getGreen();
         blue_sum += pixels[index].getBlue();
      }

      /*
       * Divide the sums of the channels of the various pixels by the number of
       * pixels.
       */
      int red_average { red_sum / size };
      int green_average { green_sum / size };
      int blue_average { blue_sum / size };

      Pixel pixel_average { red_average, green_average, blue_average, colors };

      return pixel_average;
   }

   /**
    * @public
    * @brief Put a defined filter on a pixel.
    * 
    * @param pixels Pixels for Analysis. The center is the filter pixel.
    * @param mask Filter mask with the size defined by #MASK_SIZE x #MASK_SIZE.
    * @return A pixel. 
    */
   Pixel putFilterOnPixel(Pixel pixels[MASK_SIZE][MASK_SIZE],
      float mask[MASK_SIZE][MASK_SIZE]) {
      int colors { pixels[0][0].getMaxColors() };

      float sum_red { 0 };
      float sum_green { 0 };
      float sum_blue { 0 };

      for (int row { 0 }; row < MASK_SIZE; row++) {
         for (int column { 0 }; column < MASK_SIZE; column++) {
            /*
             * Sums the pixel channels multiplied by their weight in the mask.
             */
            sum_red += pixels[row][column].getRed() * mask[row][column];
            sum_green += pixels[row][column].getGreen() * mask[row][column];
            sum_blue += pixels[row][column].getBlue() * mask[row][column];
         }
      }

      Pixel filter_pixel { 
         int(sum_red), 
         int(sum_green), 
         int(sum_blue), 
         colors 
      };

      return filter_pixel;
   }

   /**
    * @public
    * @brief Put a defined filter on the whole image.
    * 
    * @param mask Filter mask with the size defined by #MASK_SIZE x #MASK_SIZE.
    * @see setImage() 
    */
   void putOnMask(float mask[MASK_SIZE][MASK_SIZE]) {
      int width { image.getWidth() };
      int height { image.getHeight() };

      Image mask_image { width, height, image.getColors() };

      for (int row { 1 }; row <= height; row++) {
         for (int column { 1 }; column <= width; column++) {
            /*
             * Put the filter on all pixels of the image through it with its 
             * neighbors.
             */
            Pixel pixels[MASK_SIZE][MASK_SIZE] = { 
               { 
                  image.getPixel(row - 1, column - 1), 
                  image.getPixel(row - 1, column),
                  image.getPixel(row - 1, column + 1) 
               },
               { 
                  image.getPixel(row, column - 1), 
                  image.getPixel(row, column),
                  image.getPixel(row, column + 1) 
               },
               { 
                  image.getPixel(row + 1, column - 1), 
                  image.getPixel(row + 1, column),
                  image.getPixel(row + 1, column + 1) 
               } 
            };

            mask_image.setPixel(putFilterOnPixel(pixels, mask), row, column);
         }
      }

      setImage(mask_image);
   }
};
