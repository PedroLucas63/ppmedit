#include <iostream>

//! Pixel class start
class Pixel {
//* Public elements
public:
   //^ Pixel constructor without data
   Pixel() {}

   //^ Pixel constructor with data
   Pixel(int red_intensity,
         int green_intensity,
         int blue_intensity,
         int maximum_colors = 255) {
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
   ~Pixel() {}

   //^ Get minimum colors
   int getMinColors() const { return min_colors; }

   //^ Get maximum colors
   int getMaxColors() const { return max_colors; }

   //^ Set intensity of red pixel
   void setRed(int red_intensity) {
      int min_accepted{ getMinColors() }; //~ Minimum value accepted
      int max_accepted{ getMaxColors() }; //~ Maximum value accepted

      //~ Check if red intensity is accepted
      if (red_intensity >= min_accepted && red_intensity <= max_accepted) {
         red = red_intensity;
      } else { //~ red intensity is not accepted
         red = min_accepted;
      }
   }

   //^ Get intensity of red pixel
   int getRed() const { return red; }

   //^ Set intensity of green pixel
   void setGreen(int green_intensity) {
      int min_accepted{ getMinColors() }; //~ Minimum value accepted
      int max_accepted{ getMaxColors() }; //~ Maximum value accepted

      //~ Check if green intensity is accepted
      if (green_intensity >= min_accepted && green_intensity <= max_accepted) {
         green = green_intensity;
      } else { //~ green intensity is not accepted
         green = min_accepted;
      }
   }

   //^ Get intensity of green pixel
   int getGreen() const { return green; }

   //^ Set intensity of blue pixel
   void setBlue(int blue_intensity) {
      int min_accepted{ getMinColors() }; //~ Minimum value accepted
      int max_accepted{ getMaxColors() }; //~ Maximum value accepted

      //~ Check if blue intensity is accepted
      if (blue_intensity >= min_accepted && blue_intensity <= max_accepted) {
         blue = blue_intensity;
      } else { //~ blue intensity is not accepted
         blue = min_accepted;
      }
   }

   //^ Get intensity of blue pixel
   int getBlue() const { return blue; }

   //^ Convert data to string
   std::string to_string() const {
      //~ Receive intensity of colors and convert to string
      std::string red{ std::to_string(getRed()) };
      std::string green{ std::to_string(getGreen()) };
      std::string blue{ std::to_string(getBlue()) };

      std::string separator{ " " }; //~ Define separator of values

      //~ Create a buffer string with data
      std::string buff{ red + separator + green + separator + blue };

      return buff;
   }

//* Private elements
private:
   int min_colors{ 0 }; //^ Minimum number of colors (included)
   int max_colors{ 0 }; //^ Maximum number of colors (included)
   int red{ 0 };        //^ Intensity of red in pixel
   int green{ 0 };      //^ Intensity of green in pixel
   int blue{ 0 };       //^ Intensity of blue in pixel

   //^ Set maximum colors
   void setMaxColors(int maximum_colors) {
      int min_accepted{ getMinColors() + 1 }; //~ Minimum value accepted

      //~ Check if maximum colors is accepted
      if (maximum_colors >= min_accepted) {
         max_colors = maximum_colors;
      } else { //~ maximum colors is not accepted
         max_colors = min_accepted;
      }
   }
};
//! End of pixel class
