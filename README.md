# ppmedit - Command Line Image Editing Program

## Overview
ppmedit is a command line image editing program written in C++. It provides various functionalities for image manipulation, including image resizing, filter application, rotation, and image composition. The program is designed and developed by Pedro Lucas and is licensed under the MIT License.

## Features
ppmedit offers the following features:

1. Image resizing: The program can resize images, allowing users to decrease or increase their dimensions while maintaining the aspect ratio.

2. Filter application: Users can apply various filters to images, enhancing or modifying their appearance.

3. Rotation: ppmedit allows users to rotate images by left and right, enabling them to change the orientation of the image.

4. Image composition: The program supports combining two images, a background image, and a foreground image, to create a composite image. This feature is useful for overlaying one image onto another.

## Usage
To use ppmedit, open a command prompt or terminal and navigate to the directory where the program executable is located. Then, use the following syntax:

```
ppmedit [options] input_file output_file
```

### Options
ppmedit supports the following options:

| Option        | Description                                           |
|---------------|-------------------------------------------------------|
| gray          | Transform the image into grayscale.                   |
| negative      | Transform the image into negative.                    |
| rotate        | Rotate the image 90 degrees to the right.             |
| rotate-l      | Rotate the image 90 degrees to the left.              |
| invert        | Invert the image.                                     |
| enlarge       | Enlarge the image by 2x.                              |
| reduce        | Reduce the image by 2x.                               |
| sharp         | Apply the sharpening filter to the image.             |
| sharp-e       | Apply the edge sharpening filter to the image.        |
| blur          | Apply the blurring filter to the image.               |
| embossing     | Apply the embossing filter to the image.              |
| combine       | Combine first image (background) with the secund image (foreground). |

## License
ppmedit is distributed under the MIT License. You can find the full text of the license in the LICENSE file accompanying the program.

## Contributions
Contributions to ppmedit are welcome. If you encounter any issues or have suggestions for improvements, please submit them to the project's GitHub repository.

## Contact
If you have any questions or inquiries, you can reach out to Pedro Lucas at pedrolucas.jsrn@gmail.com.
