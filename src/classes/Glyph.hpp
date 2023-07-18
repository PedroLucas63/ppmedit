/**
 * @file Glyph.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Storage and bitmap properties of glyphs.
 * @version 2.0
 * @date 2023-07-18
 *
 * @copyright Copyright (c) 2023
 */

#ifndef GLYPH_HPP
#define GLYPH_HPP

#include <iostream>
#include <fstream>

/**
 * @class Glyph class.
 * @author André Maurício (andre@dimap.ufrn.br)
 * @brief Glyph definition with attributes and methods.
 */
class Glyph {
public:
   /**
    * @brief Construct a new Glyph object.
    */
   Glyph() : 
      encoding(0), 
      width(0), 
      height(0), 
      offset_x(0), 
      offset_y(0), 
      device_width_x(0), 
      device_width_y(0), 
      bitmap(nullptr) { }

   /**
    * @brief Destroy the Glyph object.
    */
   ~Glyph() {
      if (bitmap != nullptr) {
         delete[] this->bitmap;
      }
   }

   /**
    * @brief Operator to check equality of two glyphs.
    *
    * @param rhs A glyph to check equality.
    * @return True if the glyphs are equal or false if they are not equal.
    * @see getByte()
    */
   bool operator==(Glyph const& rhs) {
      if (encoding == rhs.getEncoding() && width == rhs.getWidth() &&
         height == rhs.getHeight() && offset_x == rhs.getXOffset() &&
         offset_y == rhs.getYOffset() &&
         device_width_x == rhs.getDeviceWidthX() &&
         device_width_y == rhs.getDeviceWidthY()) 
      {
         for (int row { 0 }; row < height; row++) {
            for (int column { 0 }; column < width; column++) {
               if (getBit(column, row) != rhs.getBit(column, row)) {
                  return false;
               }
            }
         }

         return true;
      }
      
      return false;
   }

   /**
    * @brief Operator to check inequality of two glyphs.
    *
    * @param rhs A glyph to check inequality.
    * @return True if the glyphs are different or false if they are not
    * different.
    * @see operator==()
    */
   bool operator!=(Glyph const& rhs) {
      return !((*this) == rhs);
   }

   /**
    * @brief Read a Glyph from the BDF file.
    *
    * @param file BDF file.
    */
   void read(std::istream& file) {
      int swx0, swy0;
      int xoff, yoff;

      std::string prop = "";
      file >> this->name;

      while (prop != "ENDCHAR") {
         if (prop == "ENCODING") {
            file >> encoding;
         } else if (prop == "SWIDTH" || prop == "SWIDTH1") {
            file >> swx0 >> swy0;
         } else if (prop == "DWIDTH" || prop == "DWIDTH1") {
            file >> device_width_x >> device_width_y;
         } else if (prop == "VVECTOR") {
            file >> xoff >> yoff;
         } else if (prop == "BBX") {
            file >> width >> height >> offset_x >> offset_y;
         } else if (prop == "BITMAP") {
            std::string line;
            int size = width > 8 ? 16 : 8;
            this->bitmap = new bool[width * height];

            file.ignore();

            for (int i = 0; i < height; i++) {
               unsigned int v;
               getline(file, line);
               sscanf(line.c_str(), "%x", &v);

               for (int j = 0; j < width; j++) {
                  unsigned long long mask = 1 << (size - j - 1);
                  bool isOn = (v & mask) != 0;
                  this->bitmap[i * width + j] = isOn;
               }
            }
         }

         file >> prop;
      }
   }

   /**
    * @brief Get the name of the glyph.
    * 
    * @return An string.
    */
   std::string getName() const { return name; }

   /**
    * @brief Get the encoding of the glyph.
    * 
    * @return An integer. 
    */
   int getEncoding() const { return encoding; }

   /**
    * @brief Get the width of the width.
    * 
    * @return An integer. 
    */
   int getWidth() const { return width; }

   /**
    * @brief Get the height of the glyph.
    * 
    * @return An integer. 
    */
   int getHeight() const { return height; }

   /**
    * @brief Get the x offset of the glyph.
    * 
    * @return An integer. 
    */
   int getXOffset() const { return offset_x; }

   /**
    * @brief Get the y offset of the glyph.
    * 
    * @return An integer. 
    */
   int getYOffset() const { return offset_y; }

   /**
    * @brief Get the device width x of the glyph.
    * 
    * @return An integer. 
    */
   int getDeviceWidthX() const { return device_width_x; }
   /**
    * @brief Get the device width y of the glyph.
    * 
    * @return An integer. 
    */
   int getDeviceWidthY() const { return device_width_y; }

   /**
    * @brief Checks if a glyph bit is on or off.
    * 
    * @param x X coordinate of the bit.
    * @param y Y coordinate of the bit
    * @return An boolean.
    */
   bool getBit(int x, int y) const { return bitmap[y * width + x]; }

private:
   std::string name;   /**< Name */
   int encoding;       /**< Encoding */
   int width;          /**< Bitmap width */
   int height;         /**< Bitmap height */
   int offset_x;       /**< Offset X */
   int offset_y;       /**< Offset Y */
   int device_width_x; /**< Device width X */
   int device_width_y; /**< Device width Y */
   bool* bitmap;       /**< Bitmap */
};

#endif // GLYPH_HPP
