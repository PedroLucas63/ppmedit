#include <iostream>

#include "Pixel.hpp"  //! Include Pixel header

//! Image class start
class Image {
   //* Public elements
public:
   //^ Image constructor without data
   Image() {}

   //^ Image constructor with data
   Image(std::string type_image, int width_image, int height_image,
         int colors_image, Pixel* pixels_image) {
      //~ Set values in order
      setType(type_image);
      setWidth(width_image);
      setHeight(height_image);
      setColors(colors_image);
      pixels = new Pixel[getSize()];  //~ Defines array of pixels with size
      setPixels(pixels_image);
   }

   //^ Image constructor with other image
   Image(Image const& image) {
      //~ Set values in order
      setType(image.getType());
      setWidth(image.getWidth());
      setHeight(image.getHeight());
      setColors(image.getColors());
      pixels = new Pixel[getSize()];  //~ Defines array of pixels with size
      setPixels(image.getPixels());
   }

   //^ Receipt operator
   void operator=(Image const& image) {
      //~ Set values in order
      setType(image.getType());
      setWidth(image.getWidth());
      setHeight(image.getHeight());
      setColors(image.getColors());
      pixels = new Pixel[getSize()];  //~ Defines array of pixels with size
      setPixels(image.getPixels());
   }

   //^ Image destructor
   ~Image() {}

   //^ Get image type
   std::string getType() const { return type; }

   //^ Get image width
   int getWidth() const { return width; }

   //^ Get image height
   int getHeight() const { return height; }

   //^ Gey image size
   int getSize() const { return getWidth() * getHeight(); }

   //^ Get image colors
   int getColors() const { return colors; }

   //^ Get image pixels
   Pixel* getPixels() const { return pixels; }

   //^ Set an image pixel
   void setPixel(Pixel pixel, int row, int column) {
      pixels[row * getWidth() + column] = pixel;
   }

   //^ Get an image pixel
   Pixel getPixel(int row, int column) const {
      return getPixels()[row * getWidth() + column];
   }

   //^ Set image pixels
   void setPixels(Pixel* pixels_image) {
      for (int i{0}; i < getHeight(); i++) {    //~ Repeat "image height" times
         for (int j{0}; j < getWidth(); j++) {  //? Repeat "image width" times
            setPixel(pixels_image[i * getWidth() + j], i, j);
         }
      }
   }

   //^ Convert data to string
   std::string to_string() const {
      //~ Receive width, height and colors and convert to string
      std::string width{std::to_string(getWidth())};
      std::string height{std::to_string(getHeight())};
      std::string colors{std::to_string(getColors())};

      std::string separator{" "};  //~ Define separator of values
      std::string endline{"\n"};   //~ Define end line

      //~ Create a buffer string with data
      std::string buff{getType() + endline};
      buff += width + separator + height + endline;
      buff += colors + endline;

      for (int i{0}; i < getHeight(); i++) {    //~ Repeat "image height" times
         for (int j{0}; j < getWidth(); j++) {  //? Repeat "image width" times
            buff += getPixel(i, j).to_string() + endline;
         }
      }

      return buff;
   }

   //* Private elements
private:
   std::string type{""};  //^ Image type
   int width{0};          //^ Image width
   int height{0};         //^ Image height
   int colors{0};         //^ Number of colors in the image
   Pixel* pixels;         //^ Pixel's pointer

   //^ Set image type
   void setType(std::string type_image) {
      //~ Types accepted
      std::string ascii_type{"P3"};
      std::string binary_type{"P6"};

      //~ Check if image type is accepted
      if (type_image == ascii_type || type_image == binary_type) {
         type = type_image;
      } else {  //~ Image type is not accepted
         type = ascii_type;
      }
   }

   //^ Set image width
   void setWidth(int width_image) {
      int min_width{1};  //~ Minimum value accepted

      //~ Check if image width is accepted
      if (width_image >= min_width) {
         width = width_image;
      } else {  //~ Image width is not accepted
         width = min_width;
      }
   }

   //^ Set image height
   void setHeight(int height_image) {
      int min_height{1};  //~ Minimum value accepted

      //~ Check if image height is accepted
      if (height_image >= min_height) {
         height = height_image;
      } else {  //~ Image height is not accepted
         height = min_height;
      }
   }

   //^ Set image colors
   void setColors(int colors_image) {
      int min_accepted{1};  //~ Minimum value accepted

      //~ Check if image colors is accepted
      if (colors_image >= min_accepted) {
         colors = colors_image;
      } else {  //~ Image colors is not accepted
         colors = min_accepted;
      }
   }
};
//! End of image class