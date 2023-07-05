/**
 * @file Pixel.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Pixels settings.
 * @version 2.0
 * @date 2023-06-25
 *
 * Pixel settings for portable pixmap images (ppm) with rules and functions for
 * figure construction and comparisons.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <math.h>

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
    * @see setColors()
    * @see setRed()
    * @see setGreen()
    * @see setBlue()
    */
   Pixel(int red_intensity, int green_intensity, int blue_intensity,
      int maximum_colors = STANDARD_COLOR_QUANTIFY) 
   {
      setColors(maximum_colors);
      setRed(red_intensity);
      setGreen(green_intensity);
      setBlue(blue_intensity);
   }

   /**
    * @brief Construct a new Pixel object with another pixel (copy).
    *
    * @param rhs A pixel to copy.
    * @see getMaxColors()
    * @see setColors()
    * @see getRed()
    * @see setRed()
    * @see getGreen()
    * @see setGreen()
    * @see getBlue()
    * @see setBlue()
    */
   Pixel(Pixel const& rhs) {
      setColors(rhs.getMaxColors());
      setRed(rhs.getRed());
      setGreen(rhs.getGreen());
      setBlue(rhs.getBlue());
   }

   /**
    * @brief Operator to receive a pixel (copy).
    *
    * @param rhs A pixel to receive.
    * @see getMaxColors()
    * @see setColors()
    * @see getRed()
    * @see setRed()
    * @see getGreen()
    * @see setGreen()
    * @see getBlue()
    * @see setBlue()
    */
   void operator=(Pixel const& rhs) {
      setColors(rhs.getMaxColors());
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
    * @see getMaxColors()
    * @see getRed()
    * @see getGreen()
    * @see getBlue()
    */
   bool operator==(Pixel const& rhs) const {
      if (getMaxColors() == rhs.getMaxColors() && getRed() == rhs.getRed() &&
         getGreen() == rhs.getGreen() && getBlue() == rhs.getBlue()) 
      {
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
   bool operator!=(Pixel const& rhs) const { return !((*this) == rhs); }

   /**
    * @brief Get the minimum number of colors.
    *
    * @return An integer.
    */
   int getMinColors() const { return MIN_COLOR; }

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
    * @see getMaxColors()
    * @see getMinColors()
    */
   void setRed(int red_intensity) {
      int max_accepted { getMaxColors() };
      int min_accepted { getMinColors() };

      if (red_intensity >= min_accepted && red_intensity <= max_accepted) {
         red = red_intensity;
      } else if (red_intensity < min_accepted) {
         red = min_accepted;
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
    * @see getMaxColors()
    * @see getMinColors()
    */
   void setGreen(int green_intensity) {
      int max_accepted { getMaxColors() };
      int min_accepted { getMinColors() };

      if (green_intensity >= min_accepted && green_intensity <= max_accepted) {
         green = green_intensity;
      } else if (green_intensity < min_accepted) {
         green = min_accepted;
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
    * @see getMaxColors()
    * @see getMinColors()
    */
   void setBlue(int blue_intensity) {
      int max_accepted { getMaxColors() };
      int min_accepted { getMinColors() };

      if (blue_intensity >= min_accepted && blue_intensity <= max_accepted) {
         blue = blue_intensity;
      } else if (blue_intensity < min_accepted) {
         blue = min_accepted;
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
    * Sets the maximum colors for the pixel channels and the value of each 
    * channel.
    * 
    * @param maximum_colors Maximum of colors per channel in a pixel.
    * @param red_intensity Red intensity in the pixel. Default is 0.
    * @param green_intensity Green intensity in the pixel. Default is 0.
    * @param blue_intensity Blue intensity in the pixel. Default is 0.
    */
   void setColors(int maximum_colors) {
      int new_red { 
         (int) round(
            ((float) red /  max_colors) * maximum_colors
         ) 
      };
      int new_green { 
         (int) round(
            ((float) green /  max_colors) * maximum_colors
         ) 
      };
      int new_blue { 
         (int) round(
            ((float) blue /  max_colors) * maximum_colors
         ) 
      };

      if (maximum_colors >= MIN_AMOUNT_COLORS
         && maximum_colors <= MAX_AMOUNT_COLORS) {
         max_colors = maximum_colors;
      } else if (maximum_colors < MIN_AMOUNT_COLORS) {
         max_colors = MIN_AMOUNT_COLORS;
      } else {
         max_colors = MAX_AMOUNT_COLORS;
      }

      

      setRed(new_red);
      setGreen(new_green);
      setBlue(new_blue);
   }

   /**
    * @brief Transform the pixel data into a string.
    *
    * @return A string with separated pixel informations.
    * @see getRed()
    * @see getGreen()
    * @see getBlue()
    */
   std::string toString() const {
      std::string red { std::to_string(getRed()) };
      std::string green { std::to_string(getGreen()) };
      std::string blue { std::to_string(getBlue()) };

      std::string init { "rgb(" };
      std::string separator { ", " };
      std::string end { ")" };

      std::string buff { init + red + separator + green + separator + blue + 
         end };

      return buff;
   }

private:
   int max_colors { 0 };         /**< Maximum number of colors (included) */
   int red { 0 };                /**< Intensity of red in the pixel */
   int green { 0 };              /**< Intensity of green in the pixel */
   int blue { 0 };               /**< Intensity of blue in the pixel */
};

#endif // PIXEL_HPP
