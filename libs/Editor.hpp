#include <iostream>

#include "./Image.hpp"  //! Include Image header

//! Editor class start
class Editor {
   //* Public elements
public:
   //^ Editor constructor without data
   Editor() {}

   //^ Editor constructor with data
   Editor(std::string type_image, int width_image, int height_image,
          int colors_image, Pixel* pixels_image) {
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
   void open(std::string type_image, int width_image, int height_image,
             int colors_image, Pixel* pixels_image) {
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
      Image image{getImageOutput()};  //~ Get the output image to transform

      int const quant_colors{3};  //~ Colors quantify in a pixel

      //~ Repeat "image height" times
      for (int i{0}; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{0}; j < image.getWidth(); j++) {
            Pixel pixel = image.getPixel(i, j);  //? Get original pixel
            //? Calculate the grayscale and create a gray pixel
            int grayscale{(pixel.getRed() + pixel.getGreen() + pixel.getBlue())
                          / quant_colors};
            Pixel new_pixel{grayscale, grayscale, grayscale, image.getColors()};
            image.setPixel(new_pixel, i, j);
         }
      }

      setImageOutput(image);  //~ Set image output to gray image
   }

   //^ Rotate the image
   void rotate(char side = 'R') {
      side = std::toupper(side);  //~ Convert side character to upper

      if (side == 'R') {  //~ Check if side is "right"
         rotateRight();
      } else if (side == 'L') {  //~ Check if side is "left"
         rotateLeft();
      }
   }

   //^ Rotate the image to the right
   void rotateRight() {
      Image image{getImageOutput()};  //~ Get the output image to auxiliary
      //~ Get the output image to transform
      Image image_rotate{image.getType(), image.getHeight(), image.getWidth(),
                         image.getColors(), image.getPixels()};

      //~ Repeat "image height" times
      for (int i{0}; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{0}; j < image.getWidth(); j++) {
            image_rotate.setPixel(image.getPixel(i, j), j,
                                  image.getHeight() - 1 - i);
         }
      }

      setImageOutput(image_rotate);  //~ Set image output to rotation image
   }

   //^ Rotate the image to the left
   void rotateLeft() {
      Image image{getImageOutput()};  //~ Get the output image to auxiliary
      //~ Get the output image to transform
      Image image_rotate{image.getType(), image.getHeight(), image.getWidth(),
                         image.getColors(), image.getPixels()};

      //~ Repeat "image height" times
      for (int i{0}; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j{0}; j < image.getWidth(); j++) {
            image_rotate.setPixel(image.getPixel(i, j),
                                  image.getWidth() - 1 - j, i);
         }
      }

      setImageOutput(image_rotate);  //~ Set image output to rotation image
   }

   //* Private elements
private:
   Image image_in;   //^ Image input (unedited)
   Image image_out;  //^ Image output (edited)

   //^ Set image input with data
   void setImageInput(std::string type_image, int width_image, int height_image,
                      int colors_image, Pixel* pixels_image) {
      image_in = Image{type_image, width_image, height_image, colors_image,
                       pixels_image};
   }

   //^ Set image input with image
   void setImageInput(Image const& image) { image_in = image; }

   //^ Set image output with data
   void setImageOutput(std::string type_image, int width_image,
                       int height_image, int colors_image,
                       Pixel* pixels_image) {
      image_out = Image{type_image, width_image, height_image, colors_image,
                        pixels_image};
   }

   //^ Set image output with image
   void setImageOutput(Image const& image) { image_out = image; }
};
//! End of editor class
