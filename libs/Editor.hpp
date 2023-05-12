#include <iostream>

#include "./Image.hpp" //! Include Image header

//! Editor class start
class Editor {
//* Public elements
public:
   //^ Editor constructor without data
   Editor() {}

   //^ Editor constructor with data
   Editor(std::string type_image,
          int width_image,
          int height_image,
          int colors_image,
          Pixel* pixels_image) {
      //~ Open the image input in the editor
      open(type_image, width_image, height_image, colors_image, pixels_image);
   }

   //^ Editor constructor with image
   Editor(Image const& image) {
      //~ Open the image input in the editor
      open(image);
   }

   //^ Editor constructor with other editor
   Editor(Editor const& editor) {
      //~ Set images in the editor
      setImageInput(editor.getImageInput());
      setImageOutput(editor.getImageOutput());
   }

   //^ Receipt operator
   void operator=(Editor const& editor) {
      //~ Set images in the editor
      setImageInput(editor.getImageInput());
      setImageOutput(editor.getImageOutput());
   }

   //^ Editor destructor
   ~Editor() {}

   //^ Get image input
   Image getImageInput() const { return image_in; }

   //^ Get image output
   Image getImageOutput() const { return image_out; }

   //^ Open a image with full data
   void open(std::string type_image,
             int width_image,
             int height_image,
             int colors_image,
             Pixel* pixels_image) {
      setImageInput(type_image, width_image, height_image, colors_image,
                    pixels_image);
      setImageOutput(type_image, width_image, height_image, colors_image,
                     pixels_image);
   }

   //^ Open a image with image
   void open(Image const& image) {
      //~ Defines image input and output
      setImageInput(image);
      setImageOutput(image);
   }

   //^ Save image output
   void save() const { std::cout << getImageOutput().to_string(); }

   //^ Restore image output
   void restore() { setImageOutput(getImageInput()); }

   //^ Turn to gray
   void toGray() {
      Image image{ getImageOutput() }; //~ Get the output image to transform

      int const quant_colors{ 3 }; //~ Colors quantify in a pixel

      //~ Repeat "image height" times
      for (int i{ 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{ 0 }; j < image.getWidth(); j++) {
            Pixel pixel = image.getPixel(i, j); //? Get original pixel
            //? Calculate the grayscale and create a gray pixel
            int grayscale{ (pixel.getRed() + pixel.getGreen() + pixel.getBlue())
                           / quant_colors };
            Pixel new_pixel{ grayscale, grayscale, grayscale,
                             image.getColors() };
            image.setPixel(new_pixel, i, j);
         }
      }

      setImageOutput(image); //~ Set image output to gray image
   }

   //^ Rotate the image
   void rotate(char side = 'R') {
      side = std::toupper(side); //~ Convert side character to upper

      if (side == 'R') { //~ Check if side is "right"
         rotateRight();
      } else if (side == 'L') { //~ Check if side is "left"
         rotateLeft();
      }
   }

   //^ Rotate the image to the right
   void rotateRight() {
      Image image{ getImageOutput() }; //~ Get the output image to auxiliary
      //~ Get the output image to transform
      Image image_rotate{ image.getType(), image.getHeight(), image.getWidth(),
                          image.getColors(), image.getPixels() };

      //~ Repeat "image height" times
      for (int i{ 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{ 0 }; j < image.getWidth(); j++) {
            image_rotate.setPixel(image.getPixel(i, j), j,
                                  image.getHeight() - 1 - i);
         }
      }

      setImageOutput(image_rotate); //~ Set image output to rotation image
   }

   //^ Rotate the image to the left
   void rotateLeft() {
      Image image{ getImageOutput() }; //~ Get the output image to auxiliary
      //~ Get the output image to transform
      Image image_rotate{ image.getType(), image.getHeight(), image.getWidth(),
                          image.getColors(), image.getPixels() };

      //~ Repeat "image height" times
      for (int i{ 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{ 0 }; j < image.getWidth(); j++) {
            image_rotate.setPixel(image.getPixel(i, j),
                                  image.getWidth() - 1 - j, i);
         }
      }

      setImageOutput(image_rotate); //~ Set image output to rotation image
   }

   //^ Enlarge image
   void enlarge() {
      Image image{ getImageOutput() }; //~ Get the output image to auxiliary
      //~ Get maximum pixel color intensity value
      int colors{ image.getColors() };

      //~ Get width and height from enlarged image
      int width{ 2 * image.getWidth() - 1 };
      int height{ 2 * image.getHeight() - 1 };
      int size{ width * height };

      Pixel pixels_enlarge[size]; //~ Pixels of the enlarged image

      //~ Repeat "height" times
      for (int i{ 0 }; i < height; i++) {
         //? Repeat "width" times
         for (int j{ 0 }; j < width; j++) {
            Pixel new_pixel;            // Create the new pixel
            int quant_pixels{ 2 };      // Quantify of pixels to average

            if (i == j && i % 2 == 0) { // Make sure it's the original pixels
               new_pixel = image.getPixel(i / 2, j / 2);
            } else if (i == j) { // Checks if it's pixels diagonally
               Pixel pixels[quant_pixels]
                  = { image.getPixel((i - 1) / 2, (j - 1) / 2),
                      image.getPixel((i + 1) / 2, (j + 1) / 2) };
               new_pixel
                  = getAveragePixelIntensity(quant_pixels, pixels, colors);
            } else if (i % 2 == 0) { //  Checks if the pixels are horizontal
               Pixel pixels[quant_pixels]
                  = { image.getPixel(i / 2, (j - 1) / 2),
                      image.getPixel(i / 2, (j + 1) / 2) };
               new_pixel
                  = getAveragePixelIntensity(quant_pixels, pixels, colors);
            } else { // Are the pixels vertically
               Pixel pixels[quant_pixels]
                  = { image.getPixel((i - 1) / 2, j / 2),
                      image.getPixel((i + 1) / 2, j / 2) };
               new_pixel
                  = getAveragePixelIntensity(quant_pixels, pixels, colors);
            }
            //? Define new pixel in pixels array
            pixels_enlarge[i * width + j] = new_pixel;
         }
      }

      //~ Create a image enlarge object
      Image image_enlarge{ image.getType(), width, height, colors,
                           pixels_enlarge };

      setImageOutput(image_enlarge); //~ Set image output to enlarge image
   }

   //^ Reduce image
   void reduce() {
      Image image{ getImageOutput() }; //~ Get the output image to auxiliary

      //~ Define width and height from reduce image
      int width{ image.getWidth() % 2 == 0 ? image.getWidth() / 2
                                           : (image.getWidth() - 1) % 2 };
      int height{ image.getHeight() % 2 == 0 ? image.getHeight() / 2
                                             : (image.getHeight() - 1) % 2 };
      int size{ width * height };

      Pixel pixels_reduce[size]; //~ Define pixels reduce array

      for (int i{ 0 }; i < height; i++) {   //~ Repeat "height" times
         for (int j{ 0 }; j < width; j++) { //?  Repeat "width" times
            int quant_pixels{ 2 };          // Quantify of pixels to average
            //  Array of pixels to average
            Pixel pixels[quant_pixels]
               = { image.getPixel(i * 2, j * 2),
                   image.getPixel(i * 2, j * 2 + 1),
                   image.getPixel(i * 2 + 1, j * 2),
                   image.getPixel(i * 2 + 1, j * 2 + 1) };

            Pixel pixel_average{
               getAveragePixelIntensity(quant_pixels, pixels, image.getColors())
            }; // Create a pixel average

            pixels_reduce[i * width + j] = pixel_average;
         }
      }

      //~ Create a image reduce object
      Image image_reduce{ image.getType(), width, height, image.getColors(),
                          pixels_reduce };

      setImageOutput(image_reduce); //~ Set image output to reduce image
   }

//* Private elements
private:
   Image image_in;  //^ Image input (unedited)
   Image image_out; //^ Image output (edited)

   //^ Set image input with data
   void setImageInput(std::string type_image,
                      int width_image,
                      int height_image,
                      int colors_image,
                      Pixel* pixels_image) {
      image_in = Image{ type_image, width_image, height_image, colors_image,
                        pixels_image };
   }

   //^ Set image input with image
   void setImageInput(Image const& image) { image_in = image; }

   //^ Set image output with data
   void setImageOutput(std::string type_image,
                       int width_image,
                       int height_image,
                       int colors_image,
                       Pixel* pixels_image) {
      image_out = Image{ type_image, width_image, height_image, colors_image,
                         pixels_image };
   }

   //^ Set image output with image
   void setImageOutput(Image const& image) { image_out = image; }

   //~ Get average pixels intensity
   Pixel getAveragePixelIntensity(int size, Pixel* pixels, int colors) {
      //~ Define sum of colors
      int red_sum{ 0 };
      int green_sum{ 0 };
      int blue_sum{ 0 };

      for (int i{ 0 }; i < size; i++) { //~ Repeat size times
         //? Sum colors
         red_sum += pixels[i].getRed();
         green_sum += pixels[i].getGreen();
         blue_sum += pixels[i].getBlue();
      }

      //~ Define average of colors
      int red_average{ red_sum / size };
      int green_average{ green_sum / size };
      int blue_average{ blue_sum / size };

      //~ Create a pixel average
      Pixel pixel_average{ red_average, green_average, blue_average, colors };

      return pixel_average;
   }
};
//! End of editor class
