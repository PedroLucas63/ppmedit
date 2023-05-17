#include <iostream>

#define MIN_COLOR 0                 //! Set minimum value for a color
#define MIN_AMOUNT_COLORS 1         //! Set minimum amount of colors
#define MAX_AMOUNT_COLORS 65536     //! Set maximum amount of colors
#define STANDARD_COLOR_QUANTIFY 255 //! Set standard color quantify

//! Pixel class start
class Pixel {
//* Public elements
public:
   //^ Pixel constructor without data
   Pixel() { }

   //^ Pixel constructor with data
   Pixel(int red_intensity, int green_intensity, int blue_intensity,
         int maximum_colors = STANDARD_COLOR_QUANTIFY) {
      //~ Set values in order
      setMaxColors(maximum_colors);
      setRed(red_intensity);
      setGreen(green_intensity);
      setBlue(blue_intensity);
   }

   //^ Pixel constructor with other pixel (copy constructor)
   Pixel(Pixel const& pixel) {
      //~ Set values in order
      setMaxColors(pixel.getMaxColors());
      setRed(pixel.getRed());
      setGreen(pixel.getGreen());
      setBlue(pixel.getBlue());
   }

   //^ Receipt operator
   void operator=(Pixel const& pixel) {
      //~ Set values in order
      setMaxColors(pixel.getMaxColors());
      setRed(pixel.getRed());
      setGreen(pixel.getGreen());
      setBlue(pixel.getBlue());
   }

   //^ Pixel destructor
   ~Pixel() { }

   //^ Get minimum colors
   int getMinColors() const { return min_colors; }

   //^ Get maximum colors
   int getMaxColors() const { return max_colors; }

   //^ Set intensity of red pixel
   void setRed(int red_intensity) {
      int max_accepted { getMaxColors() }; //~ Maximum value accepted

      //~ Is accepted
      if (red_intensity >= MIN_AMOUNT_COLORS && red_intensity <= max_accepted) {
         red = red_intensity;
      //~ It is less than accepted
      } else if (red_intensity < MIN_AMOUNT_COLORS) {
         red = MIN_AMOUNT_COLORS;
      } else { //~ It is greater than accepted
         red = max_accepted;
      }
   }

   //^ Get intensity of red pixel
   int getRed() const { return red; }

   //^ Set intensity of green pixel
   void setGreen(int green_intensity) {
      int max_accepted { getMaxColors() }; //~ Maximum value accepted

      //~ Is accepted
      if (green_intensity >= MIN_AMOUNT_COLORS
          && green_intensity <= max_accepted) {
         green = green_intensity;
      //~ It is less than accepted
      } else if (green_intensity < MIN_AMOUNT_COLORS) {
         green = MIN_AMOUNT_COLORS;
      } else { //~ It is greater than accepted
         green = max_accepted;
      }
   }

   //^ Get intensity of green pixel
   int getGreen() const { return green; }

   //^ Set intensity of blue pixel
   void setBlue(int blue_intensity) {
      int max_accepted { getMaxColors() }; //~ Maximum value accepted

      //~ Is accepted
      if (blue_intensity >= MIN_AMOUNT_COLORS
          && blue_intensity <= max_accepted) {
         blue = blue_intensity;
      //~ It is less than accepted
      } else if (blue_intensity < MIN_AMOUNT_COLORS) {
         blue = MIN_AMOUNT_COLORS;
      } else { //~ It is greater than accepted
         blue = max_accepted;
      }
   }

   //^ Get intensity of blue pixel
   int getBlue() const { return blue; }

   //^ Convert data to string
   std::string toString() const {
      //~ Receive intensity of colors and convert to string
      std::string red { std::to_string(getRed()) };
      std::string green { std::to_string(getGreen()) };
      std::string blue { std::to_string(getBlue()) };

      std::string separator { " " }; //~ Define separator of values

      //~ Create a buffer string with data
      std::string buff { red + separator + green + separator + blue };

      return buff;
   }

//* Private elements
private:
   int min_colors { MIN_COLOR }; //^ Minimum number of colors (included)
   int max_colors { 0 };         //^ Maximum number of colors (included)
   int red { 0 };                //^ Intensity of red in pixel
   int green { 0 };              //^ Intensity of green in pixel
   int blue { 0 };               //^ Intensity of blue in pixel

   //^ Set maximum colors
   void setMaxColors(int maximum_colors) {
      //~ Is accepted
      if (maximum_colors >= MIN_AMOUNT_COLORS
          && maximum_colors <= MAX_AMOUNT_COLORS) {
         max_colors = maximum_colors;
      //~ It is less than accepted
      } else if (maximum_colors < MIN_AMOUNT_COLORS) {
         max_colors = MIN_AMOUNT_COLORS;
      } else { //~ It is greater than accepted
         max_colors = MAX_AMOUNT_COLORS;
      }
   }
}; //! End of pixel class
