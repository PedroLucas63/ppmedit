#include <string.h>
#include "./Image.hpp" //! Include Image header

#define MASK_SIZE 3 //! Set mask size for filters

//! Editor class start
class Editor {
//* Public elements
public:
   //^ Editor constructor without data
   Editor() { }

   //^ Editor constructor with data
   Editor(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      //~ Import the image input in the editor
      importData(width_image, height_image, colors_image, pixels_image);
   }

   //^ Editor constructor with image
   Editor(Image const& image) {
      //~ Import the image input in the editor
      importData(image);
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
   ~Editor() { }

   //^ Get image input
   Image getImageInput() const { return image_in; }

   //^ Get image output
   Image getImageOutput() const { return image_out; }

   //^ Import a image with full data
   void importData(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      setImageInput(width_image, height_image, colors_image, pixels_image);
      setImageOutput(width_image, height_image, colors_image, pixels_image);
   }

   //^ Import a image with image
   void importData(Image const& image) {
      //~ Defines image input and output
      setImageInput(image);
      setImageOutput(image);
   }

   //^ Export image output
   void exportData() const { std::cout << getImageOutput().toString(); }

   //^ Undo image change
   void undoImageChange() { setImageOutput(getImageInput()); }

   //^ Turn to gray
   void grayscaleImage() {
      Image image { getImageOutput() }; //~ Get the output image to transform

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            Pixel pixel = image.getPixel(i, j); //? Get original pixel

            //? Calculate the grayscale
            int grayscale { (pixel.getRed() + pixel.getGreen()
                               + pixel.getBlue())
               / CHANNELS_PER_PIXEL };

            //?  Create a gray pixel and set in the image
            Pixel new_pixel { grayscale, grayscale, grayscale,
               image.getColors() };
            image.setPixel(new_pixel, i, j);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(image); //~ Set image output to gray image
   }

   //^ Rotate the image
   void rotateImage(char side = 'R') {
      side = std::toupper(side); //~ Convert side character to upper

      if (side == 'R') { //~ Check if side is "right"
         rotateRight();
      } else if (side == 'L') { //~ Check if side is "left"
         rotateLeft();
      }
   }

   //^ Rotate the image to the right
   void rotateRight() {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Define rotate image to transform
      Image rotate_image { image.getHeight(), image.getWidth(),
         image.getColors() };

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            //? Set pixel rotation in new image
            rotate_image.setPixel(image.getPixel(i, j), j,
               image.getHeight() - 1 - i);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(rotate_image); //~ Set image output to rotation image
   }

   //^ Rotate the image to the left
   void rotateLeft() {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Define rotate image to transform
      Image rotate_image { image.getHeight(), image.getWidth(),
         image.getColors() };

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            //? Set pixel rotation in new image
            rotate_image.setPixel(image.getPixel(i, j),
               image.getWidth() - 1 - j, i);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(rotate_image); //~ Set image output to rotation image
   }

   //^ Flip image
   void flipImage() {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Mirror image with image output
      Image mirror_image(image.getWidth(), image.getHeight(),
         image.getColors());

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            //? Get and set current pixel mirror
            Pixel pixel { image.getPixel(i, image.getWidth() - 1 - j) };
            mirror_image.setPixel(pixel, i, j);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(mirror_image); //~ Set image output to enlarge image
   }

   //^ Enlarge image
   void enlargeImage() {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Get width and height from enlarged image
      int width { 2 * image.getWidth() - 1 };
      int height { 2 * image.getHeight() - 1 };

      //~ Enlarge image with image output
      Image enlarge_image { width, height, image.getColors() };

      for (int i { 0 }; i < height; i++) {   //~ Repeat "image height" times
         for (int j { 0 }; j < width; j++) { //? Repeat "image width" times
            Pixel new_pixel;                 //? Create the new pixel
            int quant_pixels { 2 };          //? Quantify of pixels to average

            if (i == j && i % 2 == 0) { //? Make sure it's the original pixels
               new_pixel = image.getPixel(i / 2, j / 2);
            } else if (i == j) { //? Checks if it's pixels diagonally
               Pixel pixels[quant_pixels]
                  = { image.getPixel((i - 1) / 2, (j - 1) / 2),
                       image.getPixel((i + 1) / 2, (j + 1) / 2) };

               new_pixel = getAveragePixelIntensity(pixels, quant_pixels);
            } else if (i % 2 == 0) { //?  Checks if the pixels are horizontal
               Pixel pixels[quant_pixels]
                  = { image.getPixel(i / 2, (j - 1) / 2),
                       image.getPixel(i / 2, (j + 1) / 2) };

               new_pixel = getAveragePixelIntensity(pixels, quant_pixels);
            } else { //? Are the pixels vertically
               Pixel pixels[quant_pixels]
                  = { image.getPixel((i - 1) / 2, j / 2),
                       image.getPixel((i + 1) / 2, j / 2) };

               new_pixel = getAveragePixelIntensity(pixels, quant_pixels);
            }

            //? Define new pixel in enlarge image
            enlarge_image.setPixel(new_pixel, i, j);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(enlarge_image); //~ Set image output to enlarge image
   }

   //^ Shrink image
   void shrinkImage() {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Define width and height from reduce image
      int width { image.getWidth() % 2 == 0 ? image.getWidth() / 2
                                            : (image.getWidth() - 1) / 2 };
      int height { image.getHeight() % 2 == 0 ? image.getHeight() / 2
                                              : (image.getHeight() - 1) / 2 };

      //~ Reduce image with image output
      Image reduce_image { width, height, image.getColors() };

      for (int i { 0 }; i < height; i++) {   //~ Repeat "image height" times
         for (int j { 0 }; j < width; j++) { //?  Repeat "image width" times
            int quant_pixels { 4 };          //? Quantify of pixels to average

            //?  Array of pixels to average
            Pixel pixels[quant_pixels] = { image.getPixel(i * 2, j * 2),
               image.getPixel(i * 2, j * 2 + 1),
               image.getPixel(i * 2 + 1, j * 2),
               image.getPixel(i * 2 + 1, j * 2 + 1) };

            Pixel pixel_average { getAveragePixelIntensity(pixels,
               quant_pixels) }; //? Create a pixel average

            //? Define new pixel in reduce image
            reduce_image.setPixel(pixel_average, i, j);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(reduce_image); //~ Set image output to reduce image
   }

   //^ Apply image effects
   void applyImageEffects(char filter = 'S') {
      filter = std::toupper(filter); //~ Convert filter character to upper

      float mask[MASK_SIZE][MASK_SIZE]; //~ Create a mask without data

      if (filter == 'B') { //~ Filter is blurring
         float buff_mask[MASK_SIZE][MASK_SIZE]
            = { { 1.0 / 9, 1.0 / 9, 1.0 / 9 }, { 1.0 / 9, 1.0 / 9, 1.0 / 9 },
                 { 1.0 / 9, 1.0 / 9, 1.0 / 9 } };
         //? Copy buffer mask to mask
         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == 'D') { //~ Filter is edge enhancement
         float buff_mask[MASK_SIZE][MASK_SIZE]
            = { { -1, -1, -1 }, { -1, 9, -1 }, { -1, -1, -1 } };
         //? Copy buffer mask to mask
         memcpy(mask, buff_mask, sizeof(mask));
      } else if (filter == 'E') { //~ Filter is embossing
         float buff_mask[MASK_SIZE][MASK_SIZE]
            = { { -2, -1, 0 }, { -1, 1, 1 }, { 0, 1, 2 } };
         //? Copy buffer mask to mask
         memcpy(mask, buff_mask, sizeof(mask));
      } else { //~ Filter is sharpening
         float buff_mask[MASK_SIZE][MASK_SIZE]
            = { { 0, -1, 0 }, { -1, 5, -1 }, { 0, -1, 0 } };
         //? Copy buffer mask to mask
         memcpy(mask, buff_mask, sizeof(mask));
      }

      Image filter_image { putOnMask(mask) }; //~ Put selected mask

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(filter_image); //~ Set image output to filter image
   }

   //^ Negative image
   void negativeImage() {
      Image image { getImageOutput() }; //~ Get the output image to transform
      int colors {image.getColors()}; //~ Get colors of the image

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            Pixel pixel {image.getPixel(i, j)}; //? Get original pixel

            //? Get negative channels  
            int new_red {colors - pixel.getRed()};
            int new_green {colors - pixel.getGreen()};
            int new_blue {colors - pixel.getBlue()};

            //?  Create a negative pixel and set in the image
            Pixel new_pixel { new_red, new_green, new_blue,
               colors };
            image.setPixel(new_pixel, i, j);
         }
      }

      //~ Set image input to output image without modifiers
      setImageInput(getImageOutput());
      setImageOutput(image); //~ Set image output to gray image
   }

   //^ Combine two images
   void combineImages(Image const& foreground) {
      Image image { getImageOutput() }; //~ Get the output image to transform

      //~ Images are the same size
      if (image.getWidth() == foreground.getWidth() && image.getHeight() == foreground.getHeight()) {
         Pixel first_pixel {foreground.getPixel(0, 0)}; //? get the first pixel

         //? Scroll through the pixels
         for (int i { 0 }; i < image.getHeight(); i++) {
            for (int j { 0 }; j < image.getWidth(); j++) {
               Pixel foreground_pixel {foreground.getPixel(i, j)};

               //? Foreground pixel is added to background image when it is 
               //? different
               if (foreground.getPixel(i, j) != first_pixel) {
                  image.setPixel(foreground_pixel, i, j);
               }
            }
         }

         //~ Set image input to output image without modifiers
         setImageInput(getImageOutput());
         setImageOutput(image); //~ Set image output to combine image
      }
   }

//* Private elements
private:
   Image image_in;  //^ Image input (without the latest edition)
   Image image_out; //^ Image output (with the last edition)

   //^ Set image input with data
   void setImageInput(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      image_in
         = Image { width_image, height_image, colors_image, pixels_image };
   }

   //^ Set image input with image
   void setImageInput(Image const& image) { image_in = image; }

   //^ Set image output with data
   void setImageOutput(int width_image, int height_image, int colors_image,
      Pixel* pixels_image) {
      image_out
         = Image { width_image, height_image, colors_image, pixels_image };
   }

   //^ Set image output with image
   void setImageOutput(Image const& image) { image_out = image; }

   //^ Get average pixels intensity
   Pixel getAveragePixelIntensity(Pixel* pixels, int size) {
      //~ Define sum of colors
      int red_sum { 0 };
      int green_sum { 0 };
      int blue_sum { 0 };

      for (int i { 0 }; i < size; i++) { //~ Repeat size times
         //? Sum colors
         red_sum += pixels[i].getRed();
         green_sum += pixels[i].getGreen();
         blue_sum += pixels[i].getBlue();
      }

      //~ Define average of colors
      int red_average { red_sum / size };
      int green_average { green_sum / size };
      int blue_average { blue_sum / size };

      //~ Create a pixel average
      Pixel pixel_average { red_average, green_average, blue_average,
         pixels[0].getMaxColors() };

      return pixel_average;
   }

   //^ Put filter on pixel
   Pixel putFilterOnPixel(Pixel pixels[MASK_SIZE][MASK_SIZE],
      float mask[MASK_SIZE][MASK_SIZE]) {
      //~ Define sum of colors intensity
      float sum_red { 0 };
      float sum_green { 0 };
      float sum_blue { 0 };

      for (int i { 0 }; i < MASK_SIZE; i++) {    //~ Repeat "mask size" times
         for (int j { 0 }; j < MASK_SIZE; j++) { //? Repeat "mask size" times
            //? Sum colors with mask
            sum_red += pixels[i][j].getRed() * mask[i][j];
            sum_green += pixels[i][j].getGreen() * mask[i][j];
            sum_blue += pixels[i][j].getBlue() * mask[i][j];
         }
      }

      //~ Filter pixel with round results
      Pixel filter_pixel { (int) round(sum_red), (int) round(sum_green), (int) round(sum_blue),
         pixels[0][0].getMaxColors() };

      return filter_pixel;
   }

   //^ Put mask on image
   Image putOnMask(float mask[MASK_SIZE][MASK_SIZE]) {
      Image image { getImageOutput() }; //~ Get the output image to auxiliary

      //~ Mask image with image output
      Image mask_image { image.getWidth(), image.getHeight(),
         image.getColors() };

      //~ Repeat "image height" times
      for (int i { 0 }; i < image.getHeight(); i++) {
         //? Repeat "image width" times
         for (int j { 0 }; j < image.getWidth(); j++) {
            //? Grab adjacent pixels
            Pixel pixels[MASK_SIZE][MASK_SIZE]
               = { { image.getPixel(i - 1, j - 1), image.getPixel(i - 1, j),
                      image.getPixel(i - 1, j + 1) },
                    {
                       image.getPixel(i, j - 1),
                       image.getPixel(i, j),
                       image.getPixel(i, j + 1),
                    },
                    {
                       image.getPixel(i + 1, j - 1),
                       image.getPixel(i + 1, j),
                       image.getPixel(i + 1, j + 1),
                    } };

            mask_image.setPixel(putFilterOnPixel(pixels, mask), i, j);
         }
      }

      return mask_image;
   }
}; //! End of editor class
