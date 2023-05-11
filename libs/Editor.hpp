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

      Pixel* pixels = image.getPixels();  //~ Get image output pixel's

      int const quant_colors{3};  //~ Colors quantify in a pixel

      for (int i{0}; i < image.getSize(); i++) {  //~ Repeat "image size" times
         Pixel pixel = pixels[i];                 //? Get pixel
         //? Calculate the grayscale of the colors in the pixel
         int grayscale{(pixel.getRed() + pixel.getGreen() + pixel.getBlue())
                       / quant_colors};
         //? Create a new pixel with grayscale in all colors
         Pixel new_pixel{grayscale, grayscale, grayscale, image.getColors()};
         //? Sets the new pixel in place of the old pixel
         pixels[i] = new_pixel;
      }

      image.setPixels(pixels);  //? Set pixels in image

      setImageOutput(image);  //? Set image output to gray image
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
