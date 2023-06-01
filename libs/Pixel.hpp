/**
 * @file Pixel.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Pixels settings.
 * @version 1.0
 * @date 2023-05-31
 *
 * Pixel settings for portable pixmap images (ppm) with rules and functions for
 * figure construction and comparisons.
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>

#define MIN_COLOR 0                 /**< Minimum value for a color */
#define MIN_AMOUNT_COLORS 1         /**< Minimum number of colors */
#define MAX_AMOUNT_COLORS 65536     /**< Maximum number of colors */
#define STANDARD_COLOR_QUANTIFY 255 /**< Standard number of colors */
#define CHANNELS_PER_PIXEL 3        /**< Number of color channels per pixel */

/**
 * @class Pixel class.
 * @brief Pixel definition with attributes and methods.
 */
class Pixel {
public:
   /**
    * @brief Construct a new Pixel object with no data.
    */
   Pixel() { }

   /**
    * @brief Construct a new Pixel object with data.
    *
    * @param red_intensity Red intensity in the pixel.
    * @param green_intensity Green intensity in the pixel.
    * @param blue_intensity Blue intensity in the pixel.
    * @param maximum_colors Maximum of colors per channel in a pixel.
    * Default is #STANDARD_COLOR_QUANTIFY.
    * @see setMaxColors()
    * @see setRed()
    * @see setGreen()
    * @see setBlue()
    */
   Pixel(int red_intensity, int green_intensity, int blue_intensity,
      int maximum_colors = STANDARD_COLOR_QUANTIFY) {
      setMaxColors(maximum_colors);
      setRed(red_intensity);
      setGreen(green_intensity);
      setBlue(blue_intensity);
   }

   /**
    * @brief Construct a new Pixel object with another pixel (copy).
    *
    * @param rhs A pixel to copy.
    * @see setMaxColors()
    * @see setRed()
    * @see setGreen()
    * @see setBlue()
    */
   Pixel(Pixel const& rhs) {
      setMaxColors(rhs.getMaxColors());
      setRed(rhs.getRed());
      setGreen(rhs.getGreen());
      setBlue(rhs.getBlue());
   }

   /**
    * @brief Operator to receive a pixel (copy).
    *
    * @param rhs A pixel to receive.
    * @see setMaxColors()
    * @see setRed()
    * @see setGreen()
    * @see setBlue()
    */
   void operator=(Pixel const& rhs) {
      setMaxColors(rhs.getMaxColors());
      setRed(rhs.getRed());
      setGreen(rhs.getGreen());
      setBlue(rhs.getBlue());
   }

   /**
    * @brief Destroy the Pixel object.
    */
   ~Pixel() { }

   /**
    * @brief Operator to check the equality of two pixels.
    *
    * @param rhs A pixel to check equality.
    * @return True if the pixels are equal or false if they are not equal.
    */
   bool operator==(Pixel const& rhs) {
      if (getMaxColors() == rhs.getMaxColors() && getRed() == rhs.getRed()
         && getGreen() == rhs.getGreen() && getBlue() == rhs.getBlue()) {
         return true;
      }

      return false;
   }

   /**
    * @brief Operator to check the inequality of two pixels.
    *
    * @param rhs A pixel to check inequality.
    * @return True if the pixels are different or false if they are not
    * different.
    * @see operator==()
    */
   bool operator!=(Pixel const& rhs) { return !((*this) == rhs); }

   /**
    * @brief Get the minimum number of colors.
    *
    * @return An integer.
    */
   int getMinColors() const { return min_colors; }

   /**
    * @brief Get the maximum number of colors.
    *
    * @return An integer.
    */
   int getMaxColors() const { return max_colors; }

   /**
    * @brief This sets the red intensity in the pixel.
    *
    * @param red_intensity Red intensity in the pixel.
    */
   void setRed(int red_intensity) {
      int max_accepted { getMaxColors() };

      if (red_intensity >= getMinColors() && red_intensity <= max_accepted) {
         red = red_intensity;
      } else if (red_intensity < getMinColors()) {
         red = getMinColors();
      } else {
         red = max_accepted;
      }
   }

   /**
    * @brief Get the red intensity of the pixel.
    *
    * @return An integer.
    */
   int getRed() const { return red; }

   /**
    * @brief This sets the green intensity in the pixel.
    *
    * @param green_intensity Green intensity in the pixel.
    */
   void setGreen(int green_intensity) {
      int max_accepted { getMaxColors() };

      if (green_intensity >= getMinColors()
         && green_intensity <= max_accepted) {
         green = green_intensity;
      } else if (green_intensity < getMinColors()) {
         green = getMinColors();
      } else {
         green = max_accepted;
      }
   }

   /**
    * @brief Get the green intensity of the pixel.
    *
    * @return An integer.
    */
   int getGreen() const { return green; }

   /**
    * @brief This sets the blue intensity in the pixel.
    *
    * @param blue_intensity Blue intensity in the pixel.
    */
   void setBlue(int blue_intensity) {
      int max_accepted { getMaxColors() };

      if (blue_intensity >= getMinColors() && blue_intensity <= max_accepted) {
         blue = blue_intensity;
      } else if (blue_intensity < getMinColors()) {
         blue = getMinColors();
      } else {
         blue = max_accepted;
      }
   }

   /**
    * @brief Get the blue intensity of the pixel.
    *
    * @return An integer.
    */
   int getBlue() const { return blue; }

   /**
    * @brief Transform the pixel data into a string.
    *
    * @return A string with separated pixel informations.
    */
   std::string toString() const {
      std::string red { std::to_string(getRed()) };
      std::string green { std::to_string(getGreen()) };
      std::string blue { std::to_string(getBlue()) };

      std::string separator { " " };

      std::string buff { red + separator + green + separator + blue };

      return buff;
   }

private:
   int min_colors { MIN_COLOR }; /**< Minimum number of colors (included) */
   int max_colors { 0 };         /**< Maximum number of colors (included) */
   int red { 0 };                /**< Intensity of red in the pixel */
   int green { 0 };              /**< Intensity of green in the pixel */
   int blue { 0 };               /**< Intensity of blue in the pixel */

   /**
    * @public
    * @brief Sets the maximum colors for the pixel channels.
    * 
    * @param maximum_colors Maximum of colors per channel in a pixel.
    */
   void setMaxColors(int maximum_colors) {
      if (maximum_colors >= MIN_AMOUNT_COLORS
         && maximum_colors <= MAX_AMOUNT_COLORS) {
         max_colors = maximum_colors;
      } else if (maximum_colors < MIN_AMOUNT_COLORS) {
         max_colors = MIN_AMOUNT_COLORS;
      } else {
         max_colors = MAX_AMOUNT_COLORS;
      }
   }
};
