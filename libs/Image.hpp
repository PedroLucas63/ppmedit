/**
 * @file Image.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Images settings.
 * @version 1.0
 * @date 2023-05-31
 *
 * Portable pixmap image (ppm) definition with rules and functions for
 * comparisons and editing the data in an editor.
 *
 * @copyright Copyright (c) 2023
 */

#include "Pixel.hpp"

#define ASCII_TYPE "P3" /**< Ascii type for the ppm image */
#define MIN_WIDTH 1     /**< Minimum width for a ppm image */
#define MIN_HEIGHT 1    /**< Minimum height for a ppm image */

/**
 * @class Image class.
 * @brief Image definition with attributes and methods.
 */
class Image {
public:
   /**
    * @brief Construct a new Image object with no data.
    */
   Image() { }

   /**
    * @brief Construct a new Image object with data but not with pixels.
    *
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @see setWidth()
    * @see setHeight()
    * @see setColors()
    * @see getSize()
    */
   Image(int width, int height, int colors) {
      setWidth(width);
      setHeight(height);
      setColors(colors);

      /*
       * Set the pixel array to the image size.
       */
      pixels = new Pixel[getSize()];
   }

   /**
    * @brief Construct a new Image object with full data.
    *
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @param pixels_array Image pixels.
    * @see setWidth()
    * @see setHeight()
    * @see setColors()
    * @see getSize()
    * @see setPixels()
    */
   Image(int width, int height, int colors, Pixel* pixels_array) {
      setWidth(width);
      setHeight(height);
      setColors(colors);

      /*
       * Set the pixel array to the image size.
       */
      pixels = new Pixel[getSize()];

      setPixels(pixels_array);
   }

   /**
    * @brief Construct a new Image object with another image (copy).
    *
    * @param rhs A image to copy.
    * @see getWidth()
    * @see setWidth()
    * @see getHeight()
    * @see setHeight()
    * @see getColors()
    * @see setColors()
    * @see getSize()
    * @see getPixels()
    * @see setPixels()
    */
   Image(Image const& rhs) {
      setWidth(rhs.getWidth());
      setHeight(rhs.getHeight());
      setColors(rhs.getColors());

      /**
       * @brief Set the pixel array to the image size.
       */
      pixels = new Pixel[getSize()];

      setPixels(rhs.getPixels());
   }

   /**
    * @brief Operator to receive a image (copy).
    *
    * @param rhs A image to receive.
    * @see getWidth()
    * @see setWidth()
    * @see getHeight()
    * @see setHeight()
    * @see getColors()
    * @see setColors()
    * @see getSize()
    * @see getPixels()
    * @see setPixels()
    */
   void operator=(Image const& rhs) {
      setWidth(rhs.getWidth());
      setHeight(rhs.getHeight());
      setColors(rhs.getColors());

      /*
       * Set the pixel array to the image size.
       */
      pixels = new Pixel[getSize()];

      setPixels(rhs.getPixels());
   }

   /**
    * @brief Destroy the Image object.
    */
   ~Image() { }

   /**
    * @brief Operator to check equality of two images.
    *
    * @param rhs A image to check equality.
    * @return True if the images are equal or false if they are not equal.
    */
   bool operator==(Image const& rhs) {
      bool equal { true };
      
      if (getType() == rhs.getType() && getWidth() == rhs.getWidth()
         && getHeight() == rhs.getHeight() && getColors() == rhs.getColors()) {
         int width { getWidth() };
         int height { getHeight() };

         for (int row { 0 }; row < height; row++) {
            for (int column { 0 }; column < width; column++) {
               Pixel lhs_pixel { getPixel(row, column) };
               Pixel rhs_pixel { rhs.getPixel(row, column) };

               if (lhs_pixel != rhs_pixel) {
                  equal = false;
               }
            }
         }
      } else {
         equal = false;
      }

      return equal;
   }

   /**
    * @brief Operator to check inequality of two images.
    *
    * @param rhs A image to check inequality.
    * @return True if the images are different or false if they are not
    * different.
    * @see operator==()
    */
   bool operator!=(Image const& rhs) { return !((*this) == rhs); }

   /**
    * @brief Get the image type.
    *
    * @return A string.
    */
   std::string getType() const { return type; }

   /**
    * @brief Get the image width.
    *
    * @return An integer.
    */
   int getWidth() const { return width; }

   /**
    * @brief Get the image height.
    *
    * @return An integer.
    */
   int getHeight() const { return height; }

   /**
    * @brief Get the image size.
    *
    * @return An integer.
    * @see getWidth()
    * @see getHeight()
    */
   int getSize() const { return getWidth() * getHeight(); }

   /**
    * @brief Get the maximum colors per pixel channel.
    *
    * @return An integer.
    */
   int getColors() const { return colors; }

   /**
    * @brief Defines a pixel in the image.
    *
    * @param pixel Pixel to define in the image.
    * @param row Row of the pixel to define in the image.
    * @param column Column of the pixel to define in the image.
    * @see getWidth()
    */
   void setPixel(Pixel pixel, int row, int column) {
      /*
       * The image of set size has a one-dimensional matrix in which the rows
       * are followed one after the other. Thus, the reference of a pixel is
       * given by the row number multiplied by the image width plus its column
       * number.
       * It was implemented on the recommendation of Microsoft's artificial
       * intelligence.
       */
      pixels[row * getWidth() + column] = pixel;
   }

   /**
    * @brief Get an image pixel.
    *
    * @param row Row of the pixel.
    * @param column Column of the pixel.
    * @return An pixel.
    * @see getHeight()
    * @see getWidth()
    * @see getPixels()
    */
   Pixel getPixel(int row, int column) const {
      int width { getWidth() };
      int height { getHeight() };

      if (row < 0) {
         row = 0;
      } else if (row > height - 1) {
         row = height - 1;
      }

      if (column < 0) {
         column = 0;
      } else if (column > width - 1) {
         column = width - 1;
      }

      return getPixels()[row * width + column];
   }

   /**
    * @brief Get all image pixels.
    *
    * @return All pixels.
    */
   Pixel* getPixels() const { return pixels; }

   /**
    * @brief Set multiple pixels on the image.
    *
    * @param pixels_image Image pixels to define in the image.
    * @see getHeight()
    * @see getWidth()
    * @see setPixel()
    */
   void setPixels(Pixel* pixels_image) {
      int width { getWidth() };
      int height { getHeight() };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            setPixel(pixels_image[row * width + column], row, column);
         }
      }
   }

   /**
    * @brief Transform the image data into a string.
    *
    * @return A string with separated image informations.
    */
   std::string toString() const {
      int width { getWidth() };
      int height { getHeight() };

      std::string width_str { std::to_string(width) };
      std::string height_str { std::to_string(height) };
      std::string colors { std::to_string(getColors()) };

      std::string separator { " " };
      std::string endline { "\n" };

      std::string buff { getType() + endline };
      buff += width_str + separator + height_str + endline;
      buff += colors + endline;

      std::string buff_line { "" };

      for (int row { 0 }; row < height; row++) {
         for (int column { 0 }; column < width; column++) {
            buff += getPixel(row, column).toString() + separator;
         }
         buff += endline;
      }

      return buff;
   }

private:
   std::string type { ASCII_TYPE }; /**< Image type */
   int width { 0 };                 /**< Image width */
   int height { 0 };                /**< Image height */
   int colors { 0 };                /**< Number of colors in the image */
   Pixel* pixels;                   /**< Pixels pointer */

   /**
    * @public
    * @brief Set the image width.
    * 
    * @param width_image Image width.
    */
   void setWidth(int width_image) {
      if (width_image >= MIN_WIDTH) {
         width = width_image;
      } else {
         width = MIN_WIDTH;
      }
   }

   /**
    * @public
    * @brief Set the image height.
    * 
    * @param height_image Image height.
    */
   void setHeight(int height_image) {
      if (height_image >= MIN_HEIGHT) {
         height = height_image;
      } else {
         height = MIN_HEIGHT;
      }
   }
   
   /**
    * @public
    * @brief Set the number of colors in the image.
    * 
    * @param colors_image Maximum of colors per pixel channel.
    */
   void setColors(int colors_image) {
      if (colors_image >= MIN_AMOUNT_COLORS
         && colors_image <= MAX_AMOUNT_COLORS) {
         colors = colors_image;
      } else if (colors_image < MIN_AMOUNT_COLORS) {
         colors = MIN_AMOUNT_COLORS;
      } else {
         colors = MAX_AMOUNT_COLORS;
      }
   }
};
