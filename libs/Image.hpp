#include "Pixel.hpp" //! Include Pixel header

#define ASCII_TYPE "P3" //! Set ascii type for a ppm image
#define MIN_WIDTH 1     //! Set minimum width for a ppm image
#define MIN_HEIGHT 1    //! Set minimum height for a ppm image

//! Image class start
class Image {
//* Public elements
public:
   //^ Image constructor without data
   Image() { }

   //^ Image constructor without pixels
   Image(int width, int height, int colors) {
      //~ Set values in order
      setWidth(width);
      setHeight(height);
      setColors(colors);

      pixels = new Pixel[getSize()]; //? Defines array of pixels with size
   }

   //^ Image constructor with data
   Image(int width, int height, int colors, Pixel* pixels_array) {
      //~ Set values in order
      setWidth(width);
      setHeight(height);
      setColors(colors);

      pixels = new Pixel[getSize()]; //? Defines array of pixels with size

      setPixels(pixels_array);
   }

   //^ Image constructor with other image
   Image(Image const& image) {
      //~ Set values in order
      setWidth(image.getWidth());
      setHeight(image.getHeight());
      setColors(image.getColors());

      pixels = new Pixel[getSize()]; //? Defines array of pixels with size

      setPixels(image.getPixels());
   }

   //^ Receipt operator
   void operator=(Image const& image) {
      //~ Set values in order
      setWidth(image.getWidth());
      setHeight(image.getHeight());
      setColors(image.getColors());

      pixels = new Pixel[getSize()]; //? Defines array of pixels with size

      setPixels(image.getPixels());
   }

   //^ Image destructor
   ~Image() { }

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
      if (row < 0) { //~ Row is less than 0
         row = 0;
      } else if (row > getHeight() - 1) { //~ Row is greater than height
         row = getHeight() - 1;
      }

      if (column < 0) { //~ Column is less than 0
         column = 0;
      } else if (column > getWidth() - 1) { //~ Column is greater than width
         column = getWidth() - 1;
      }

      return getPixels()[row * getWidth() + column];
   }

   //^ Set image pixels
   void setPixels(Pixel* pixels_image) {
      for (int i { 0 }; i < getHeight(); i++) { //~ Repeat "image height" times
         for (int j { 0 }; j < getWidth(); j++) { //? Repeat "image width" times
            setPixel(pixels_image[i * getWidth() + j], i, j);
         }
      }
   }

   //^ Convert data to string
   std::string toString() const {
      //~ Receive width, height and colors and convert to string
      std::string width { std::to_string(getWidth()) };
      std::string height { std::to_string(getHeight()) };
      std::string colors { std::to_string(getColors()) };

      std::string separator { " " }; //~ Define separator of values
      std::string endline { "\n" };  //~ Define end line

      //~ Create a buffer string with data
      std::string buff { getType() + endline };
      buff += width + separator + height + endline;
      buff += colors + endline;

      std::string buff_line { "" }; //~ Buffer line with pixels

      int max_line_size { 70 }; //~ Max line size

      for (int i { 0 }; i < getHeight(); i++) { //~ Repeat "image height" times
         //? Repeat "image width" times
         for (int j { 0 }; j < getWidth(); j++) {
            //? Length of buff line and pixel to string
            long unsigned int buff_line_length { buff_line.length() };
            long unsigned int pixel_length { getPixel(i, j).toString().length() };

            //? Buffer line length is accepted
            if (buff_line_length + pixel_length <= max_line_size) {
               buff_line += getPixel(i, j).toString() + separator;
            } else { //? Buffer line length is not accepted
               buff += buff_line + endline;
               buff_line = getPixel(i, j).toString() + separator;
            }
         }
      }

      buff += buff_line; //? Buffer gets the last line

      return buff;
   }

//* Private elements
private:
   std::string type { ASCII_TYPE }; //^ Image type
   int width { 0 };                 //^ Image width
   int height { 0 };                //^ Image height
   int colors { 0 };                //^ Number of colors in the image
   Pixel* pixels;                   //^ Pixel's pointer

   //^ Set image width
   void setWidth(int width_image) {
      //~ The image width is accepted
      if (width_image >= MIN_WIDTH) {
         width = width_image;
      } else { //~ The image width is not accepted
         width = MIN_WIDTH;
      }
   }

   //^ Set image height
   void setHeight(int height_image) {
      //~ The image height is accepted
      if (height_image >= MIN_HEIGHT) {
         height = height_image;
      } else { //~ The image height is not accepted
         height = MIN_HEIGHT;
      }
   }

   //^ Set image colors
   void setColors(int colors_image) {
      //~ Number of colors is accepted
      if (colors_image >= MIN_AMOUNT_COLORS
         && colors_image <= MAX_AMOUNT_COLORS) {
         colors = colors_image;
         //~ Number of colors is less than accepted
      } else if (colors_image < MIN_AMOUNT_COLORS) {
         colors = MIN_AMOUNT_COLORS;
      } else { //~ Number of colors is greater than accepted
         colors = MAX_AMOUNT_COLORS;
      }
   }
}; //! End of image class
