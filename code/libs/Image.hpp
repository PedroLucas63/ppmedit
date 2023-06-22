/**
 * @file Image.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Images settings.
 * @version 1.1
 * @date 2023-06-20
 *
 * Portable pixmap image (ppm) definition with rules and functions for
 * comparisons and editing the data in an editor.
 *
 * @copyright Copyright (c) 2023
 */

#include <vector>
#include "Pixel.hpp"

#define ASCII_TYPE "P3"         /**< Ascii type for the ppm image */
#define BINARY_TYPE "P6"        /**< Binary type for the ppm image */
#define MIN_WIDTH 1             /**< Minimum width for a ppm image */
#define MIN_HEIGHT 1            /**< Minimum height for a ppm image */
#define MAX_COLUMNS_PER_LINE 70 /**< Maximum columns per line */

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
    * @param type Type image.
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @see setSize()
    * @see setColors()
    */
   Image(std::string type, int width, int height, int colors) {
      setType(type);
      setSize(width, height);
      setColors(colors);
   }

   /**
    * @brief Construct a new Image object with full data.
    *
    * @param type Type image.
    * @param width Image width.
    * @param height Image height.
    * @param colors Maximum of colors per pixel channel.
    * @param pixels Image pixels.
    * @see setSize()
    * @see setColors()
    * @see setPixels()
    */
   Image(std::string type, int width, int height, int colors, 
      std::vector<std::vector<Pixel>> pixels) 
   {
      setType(type);
      setSize(width, height);
      setColors(colors);
      setPixels(pixels);
   }

   /**
    * @brief Construct a new Image object with another image (copy).
    *
    * @param rhs A image to copy.
    * @see getType()
    * @see setType()
    * @see getWidth()
    * @see getHeight()
    * @see setSize()
    * @see getColors()
    * @see setColors()
    * @see getPixels()
    * @see setPixels()
    */
   Image(Image const& rhs) {
      setType(rhs.getType());
      setSize(rhs.getWidth(), rhs.getHeight());
      setColors(rhs.getColors());
      setPixels(rhs.getPixels());
   }

   /**
    * @brief Operator to receive a image (copy).
    *
    * @param rhs A image to receive.
    * @see getType()
    * @see setType()
    * @see getWidth()
    * @see getHeight()
    * @see setSize()
    * @see getColors()
    * @see setColors()
    * @see getPixels()
    * @see setPixels()
    */
   void operator=(Image const& rhs) {
      setType(rhs.getType());
      setSize(rhs.getWidth(), rhs.getHeight());
      setColors(rhs.getColors());
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
    * @see getType()
    * @see getWidth()
    * @see getHeight()
    * @see getColors()
    * @see getPixels()
    */
   bool operator==(Image const& rhs) const {
      if (type == rhs.getType() && width == rhs.getWidth() &&
         height == rhs.getHeight() && colors == rhs.getColors()) 
      {
         for (int row { 1 }; row <= height; row++) {
            for (int column { 1 }; column <= width; column++) {
               if (getPixel(row, column) != rhs.getPixel(row, column)) {
                  return false;
               }
            }
         }

         return true;
      }

      return false;
   }

   /**
    * @brief Operator to check inequality of two images.
    *
    * @param rhs A image to check inequality.
    * @return True if the images are different or false if they are not
    * different.
    * @see operator==()
    */
   bool operator!=(Image const& rhs) const { return !((*this) == rhs); }

   /**
    * @brief Set the image type.
    *
    * @param type_image Type image.
    */
   void setType(std::string type_image) {
      if (type_image == ASCII_TYPE || type_image == BINARY_TYPE) {
         type = type_image;
      } else {
         type = ASCII_TYPE;
      }
   }
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
    * @brief Set the image size.
    * 
    * @param width Image width
    * @param height Image height.
    */
   void setSize(int width, int height) {
      setWidth(width);
      setHeight(height);
      pixels.resize(height, std::vector<Pixel>(width));
   }

   /**
    * @brief Get the image size.
    *
    * @return An integer.
    */
   int getSize() const { return width * height; }

   /**
    * @brief Set the number of colors in the image.
    * 
    * @param colors_image Maximum of colors per pixel channel.
    */
   void setColors(int colors_image) {
      int max_colors { 0 };

      if (type == ASCII_TYPE) {
         max_colors = MAX_AMOUNT_COLORS;
      } else {
         max_colors = STANDARD_COLOR_QUANTIFY;
      }

      if (colors_image >= MIN_AMOUNT_COLORS &&
         colors_image <= max_colors) 
      {
         colors = colors_image;
      } else if (colors_image < MIN_AMOUNT_COLORS) {
         colors = MIN_AMOUNT_COLORS;
      } else {
         colors = max_colors;
      }
   }

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
    */
   void setPixel(Pixel pixel, int row, int column) {
      row--;
      column--;

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

      pixels.at(row).at(column) = pixel;
   }

   /**
    * @brief Get an image pixel.
    *
    * @param row Row of the pixel.
    * @param column Column of the pixel.
    * @return An pixel.
    * @see getWidth()
    * @see getHeight()
    * @see getPixels()
    */
   Pixel getPixel(int row, int column) const {
      row--;
      column--;

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

      return pixels.at(row).at(column);
   }

   /**
    * @brief Get all image pixels.
    *
    * @return All pixels.
    */
   std::vector<std::vector<Pixel>> getPixels() const { return pixels; }

   /**
    * @brief Set multiple pixels on the image.
    *
    * @param pixels_image Image pixels to define in the image.
    */
   void setPixels(std::vector<std::vector<Pixel>> image_pixels) {
      pixels = image_pixels;
   }

   /**
    * @brief Transform the image data into a string.
    *
    * @return A string with separated image informations.
    */
   std::string toString() const {
      std::string width_str { std::to_string(width) };
      std::string height_str { std::to_string(height) };
      std::string colors_str { std::to_string(colors) };

      std::string separator { " " };
      std::string endline { "\n" };

      std::string buff { type + endline };
      buff += width_str + separator + height_str + endline;
      buff += colors_str + endline;

      std::string buff_line { "" };

      for (auto row : pixels) {
         for (auto pixel : row) {
            std::string pixel_str { };

            if (type == BINARY_TYPE) {
               pixel_str += (char) pixel.getRed();
               pixel_str += (char) pixel.getGreen();
               pixel_str += (char) pixel.getBlue();
            } else {
               pixel_str = std::to_string(pixel.getRed()) + separator +
                  std::to_string(pixel.getGreen()) + separator +
                  std::to_string(pixel.getBlue()) + separator;
            }

            if ((buff_line + pixel_str).size() <= MAX_COLUMNS_PER_LINE) {
               buff_line += pixel_str;
            } else {
               buff += buff_line + endline;
               buff_line = pixel_str;
            }
         }
      }

      buff += buff_line;

      return buff;
   }

private:
   std::string type;                       /**< Image type */
   int width { 0 };                        /**< Image width */
   int height { 0 };                       /**< Image height */
   int colors { 0 };                       /**< Number of colors in image */
   std::vector<std::vector<Pixel>> pixels; /**< Pixels vector */

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
};
