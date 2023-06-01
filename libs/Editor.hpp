/**
 * @file Editor.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Editor settings.
 * @version 1.0
 * @date 2023-05-31
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
    * @see importData()
    */
   Editor(int width, int height, int colors, Pixel* pixels) {
      importData(width, height, colors, pixels);
   }

   /**
    * @brief Construct a new Editor object with an image.
    *
    * @param image An image.
    * @see importData()
    */
   Editor(Image const& image) { importData(image); }

   /**
    * @brief Construct a new Editor object with another editor (copy).
    *
    * @param rhs A editor to copy.
    * @see setImageInput()
    * @see setImageOutput()
    */
   Editor(Editor const& rhs) {
      setImageInput(rhs.getImageInput());
      setImageOutput(rhs.getImageOutput());
   }

   /**
    * @brief Operator to receive a editor (copy).
    *
    * @param rhs A editor to receive.
    * @see setImageInput()
    * @see setImageOutput()
    */
   void operator=(Editor const& rhs) {
      setImageInput(rhs.getImageInput());
      setImageOutput(rhs.getImageOutput());
   }

   /**
    * @brief Destroy the Editor object
    */
   ~Editor() { }

   /**
    * @brief Get image input.
    *
    * @return An image without the last modification.
    */
   Image getImageInput() const { return image_in; }

   /**
    * @brief Get image output.
    *
    * @return An image with the last modification.
    */
   Image getImageOutput() const { return image_out; }

   /**
    * @brief Import the image input data.
    *
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @param pixels Image pixels.
    * @see setImageInput()
    * @see setImageOutput()
    */
   void importData(int width, int height, int colors, Pixel* pixels) {
      setImageInput(width, height, colors, pixels);
      setImageOutput(width, height, colors, pixels);
   }

   /**
    * @brief Import the input image.
    *
    * @param image import image.
    * @see setImageInput()
    * @see setImageOutput()
    */
   void importData(Image const& image) {
      setImageInput(image);
      setImageOutput(image);
   }

   /**
    * @brief Export the image output data.
    * @see getImageOutput()
    */
   void exportData() const { std::cout << getImageOutput().toString(); }

   /**
    * @brief Undoes the last change made to the output image.
    * @see getImageInput()
    * @see setImageOutput()
    */
   void undoImageChange() { setImageOutput(getImageInput()); }

   /**
    * @brief Transform the image into grayscale.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput()
    */
   void grayscaleImage() {
      Image grayscale { getImageOutput() };

      int width { grayscale.getWidth() };
      int height { grayscale.getHeight() };
      int colors { grayscale.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            Pixel pixel = grayscale.getPixel(row, column);

            /*
             * Calculate the average of the channels in the pixel.
             */
            int average { (pixel.getRed() + pixel.getGreen()
               + pixel.getBlue()) / CHANNELS_PER_PIXEL };

            Pixel grayscale_pixel { average, average, average, colors };
            grayscale.setPixel(grayscale_pixel, row, column);
         }
      }

      setImageInput(getImageOutput());
      setImageOutput(grayscale);
   }

   /**
    * @brief Transform the image into negative.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput()
    */
   void negativeImage() {
      Image negative { getImageOutput() };
      
      int width { negative.getWidth() };
      int height {negative.getHeight() };
      int colors { negative.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            Pixel pixel { negative.getPixel(row, column) };

            /*
             * It subtracts the maximum number of colors per channel by the
             * value of each one.
             */
            int new_red { colors - pixel.getRed() };
            int new_green { colors - pixel.getGreen() };
            int new_blue { colors - pixel.getBlue() };

            Pixel negative_pixel { new_red, new_green, new_blue, colors };
            negative.setPixel(negative_pixel, row, column);
         }
      }

      setImageInput(getImageOutput());
      setImageOutput(negative);
   }

   /**
    * @brief Rotate image to the right.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput
    */
   void rotateRight() {
      Image buff { getImageOutput() };

      int width { buff.getWidth() };
      int height { buff.getHeight() };

      Image rotate { height, width, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            /*
             * Sets the pixel of the rotation image with the pixel of the
             * buffer image, in the defined row and column, to the position
             * determined by (column, height - row - 1).
             * Relationship obtained from the observations.
             */
            rotate.setPixel(buff.getPixel(row, column), column, 
               height - row - 1);
         }
      }

      setImageInput(buff);
      setImageOutput(rotate);
   }

   /**
    * @brief Rotate image to the left.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput
    */
   void rotateLeft() {
      Image buff { getImageOutput() };

      int width { buff.getWidth() };
      int height { buff.getHeight() };

      Image rotate { height, width, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            /*
             * Sets the pixel of the rotation image with the pixel of the
             * buffer image, in the defined row and column, to the position
             * determined by (width - column - 1, row).
             * Relationship obtained from the observations.
             */
            rotate.setPixel(
               buff.getPixel(row, column), 
               width - column - 1, 
               row
            );
         }
      }

      setImageInput(buff);
      setImageOutput(rotate);
   }

   /**
    * @brief Invert the image.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput
    */
   void invertImage() {
      Image buff { getImageOutput() };

      int width { buff.getWidth() };
      int height { buff.getHeight() };

      Image invert { width, height, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            /*
             * Get the invert pixel of the buffer image.
             */
            Pixel pixel { buff.getPixel(row, width - column - 1) };
            invert.setPixel(pixel, row, column);
         }
      }

      setImageInput(buff);
      setImageOutput(invert);
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
    * @see getImageOutput()
    * @see getAveragePixelIntensity()
    * @see setImageInput()
    * @see setImageOutput()
    */
   void enlargeImage() {
      Image buff { getImageOutput() };

      int width { 2 * buff.getWidth() - 1 };
      int height { 2 * buff.getHeight() - 1 };

      Image enlarge { width, height, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            Pixel new_pixel;
            int quant_pixels { 2 };

            /*
             * Checks whether the pixel under analysis will be a pixel from the
             * original image, or a horizontally or vertically generated pixel.
             */
            if (row % 2 == 0 && column % 2 == 0) {
               new_pixel = buff.getPixel(row / 2, column / 2);
            } else if (row % 2 == 0) {
               Pixel pixels[quant_pixels] = { 
                  buff.getPixel(row / 2, (column - 1) / 2),
                  buff.getPixel(row / 2, (column + 1) / 2) 
               };

               new_pixel = getAveragePixelIntensity(pixels, quant_pixels);
            } else if (column % 2 == 0) {
               Pixel pixels[quant_pixels] = {
                  buff.getPixel((row - 1) / 2, column / 2),
                  buff.getPixel((row + 1) / 2, column / 2) 
               };

               new_pixel = getAveragePixelIntensity(pixels, quant_pixels);
            }

            enlarge.setPixel(new_pixel, row, column);
         }
      }

      /*
       * Scrolls through the pixels generated by two vertical pixels of the
       * previous repetition system
       */
      for (int row { 1 }; row < height; row += 2) {
         for (int column { 1 }; column < width; column += 2) {
            Pixel new_pixel;
            int quant_pixels { 2 };

            Pixel pixels[quant_pixels] = { 
               enlarge.getPixel(row - 1, column),
               enlarge.getPixel(row + 1, column) 
            };

            new_pixel = getAveragePixelIntensity(pixels, quant_pixels);

            enlarge.setPixel(new_pixel, row, column);
         }
      }

      setImageInput(buff);
      setImageOutput(enlarge);
   }

   /**
    * @brief Reduce image.
    * @see getImageOutput()
    * @see getAveragePixelIntensity()
    * @see setImageInput()
    * @see setImageOutput()
    */
   void reduceImage() {
      Image buff { getImageOutput() };

      int width { buff.getWidth() % 2 == 0 ? buff.getWidth() / 2
         : (buff.getWidth() - 1) / 2 };
      int height { buff.getHeight() % 2 == 0 ? buff.getHeight() / 2
         : (buff.getHeight() - 1) / 2 };

      Image reduce { width, height, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            /*
             * Calculate the average of the pixel and the three adjacent 
             * pixels.
             */
            int quant_pixels { 4 };
            Pixel pixels[quant_pixels] = { 
               buff.getPixel(row * 2, column * 2),
               buff.getPixel(row * 2, column * 2 + 1),
               buff.getPixel(row * 2 + 1, column * 2),
               buff.getPixel(row * 2 + 1, column * 2 + 1) 
            };

            Pixel pixel_average { 
               getAveragePixelIntensity(pixels, quant_pixels) 
            };

            reduce.setPixel(pixel_average, row, column);
         }
      }

      setImageInput(buff);
      setImageOutput(reduce);
   }

   /**
    * @brief Apply different filters to the image.
    * 
    * @param filter Filter to be apply. Accepts "sharpening", "blurring",
    * "edge-sharpening" and "embossing". Default is "sharpening".
    */
   void applyImageEffects(std::string filter = "sharpening") {
      float mask[MASK_SIZE][MASK_SIZE];

      if (filter == "sharpening") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { 0, -1, 0 }, 
            { -1, 5, -1 }, 
            { 0, -1, 0 } 
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
            { -1, 9, -1 },
            { -1, -1, -1 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == "embossing") {
         float buff_mask[MASK_SIZE][MASK_SIZE] = { 
            { -2, -1, 0 }, 
            { -1, 1, 1 }, 
            { 0, 1, 2 } 
         };

         memcpy(mask, buff_mask, sizeof(mask));
      }

      Image filtered { putOnMask(mask) };

      setImageInput(getImageOutput());
      setImageOutput(filtered);
   }

   /**
    * @brief Combine an image with a foreground image of equal size.
    * 
    * @param foreground foreground image.
    * @see getImageOutput()
    * @see setImageInput()
    * @see setImageOutput()
    */
   void combineImages(Image const& foreground) {
      Image image { getImageOutput() };

      int width { image.getWidth() };
      int height { image.getHeight() };

      if (width == foreground.getWidth() && height == foreground.getHeight()) {
         Pixel first_pixel { foreground.getPixel(0, 0) }; /* Pixel to ignore */

         for (int row { 0 }; row < height; row++) {
            for (int column { 0 }; column < width; column++) {
               /*
                * Set all pixels in the image other than the ignore pixel.
                */
               Pixel foreground_pixel { foreground.getPixel(row, column) };
               if (foreground_pixel != first_pixel) {
                  image.setPixel(foreground_pixel, row, column);
               }
            }
         }

         setImageInput(getImageOutput());
         setImageOutput(image);
      }
   }

private:
   Image image_in; /**< Image input (without the last edition) */
   Image image_out; /**< Image output (with the last edition) */ 

   /**
    * @public
    * @brief Set image input with all data. 
    *
    * @param width_image Image width.
    * @param height_image Image height.
    * @param colors_image Maximum of colors per pixel channel.
    * @param pixels_image Image pixels.
    */
   void setImageInput(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      image_in = Image { 
         width_image, 
         height_image, 
         colors_image, 
         pixels_image 
      };
   }

   /**
    * @public
    * @brief Set the image input with an image.
    * 
    * @param image An image.
    */
   void setImageInput(Image const& image) { image_in = image; }

   /**
    * @public
    * @brief Set image output with all data. 
    *
    * @param width_image Image width.
    * @param height_image Image height.
    * @param colors_image Maximum of colors per pixel channel.
    * @param pixels_image Image pixels.
    */
   void setImageOutput(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      image_out = Image { 
         width_image, 
         height_image, 
         colors_image, 
         pixels_image
      };
   }

   /**
    * @public
    * @brief Set the image output with an image.
    * 
    * @param image An image.
    */
   void setImageOutput(Image const& image) { image_out = image; }

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
    * @return A image. 
    */
   Image putOnMask(float mask[MASK_SIZE][MASK_SIZE]) {
      Image buff { getImageOutput() };

      int width { buff.getWidth() };
      int height { buff.getHeight() };

      Image mask_image { width, height, buff.getColors() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            /*
             * Put the filter on all pixels of the image through it with its 
             * neighbors.
             */
            Pixel pixels[MASK_SIZE][MASK_SIZE] = { 
               { 
                  buff.getPixel(row - 1, column - 1), 
                  buff.getPixel(row - 1, column),
                  buff.getPixel(row - 1, column + 1) 
               },
               { 
                  buff.getPixel(row, column - 1), 
                  buff.getPixel(row, column),
                  buff.getPixel(row, column + 1) 
               },
               { 
                  buff.getPixel(row + 1, column - 1), 
                  buff.getPixel(row + 1, column),
                  buff.getPixel(row + 1, column + 1) 
               } 
            };

            mask_image.setPixel(putFilterOnPixel(pixels, mask), row, column);
         }
      }

      return mask_image;
   }
};
