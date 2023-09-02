# ppmedit - Command Line Image Editing Program :art:

[![Download](https://img.shields.io/badge/Download-ppmedit-blue.svg)](https://github.com/PedroLucas63/ppmedit/releases)

## Overview :rocket:
ppmedit is a command line image editing program written in C++. It provides various functionalities for image manipulation, including image resizing, filter application, rotation, and image composition. The program is designed and developed by Pedro Lucas and is licensed under the MIT License.

## Features :sparkles:
ppmedit offers the following features:

1. Support for both P3 and P6 PPM image formats.
2. Add borders to images to enhance their appearance.
3. Combine two images, background, and foreground, for creative compositions.
4. Convert images between P3 and P6 formats.
5. Apply various effects to images to achieve artistic enhancements.
6. Write text on images to add annotations or captions.

## Usage :wrench:
To use ppmedit, open a command prompt or terminal and navigate to the directory where the program executable is located. Then, use the following syntax:

```
ppmedit [OPTIONS]... -i [INPUT_FILES] -o [OUTPUT_FILE]
```

### Options :label:
ppmedit supports the following options:

| Directive       | Description                                        |
|-----------------|----------------------------------------------------|
| -b              | Add a border to the image.                         |
| -c              | Combine two images (background and foreground).   |
| --convert       | Convert an image to P3 or P6 format.              |
| -e              | Apply specific effects to the image.              |
| -h              | Display the program's manual and usage instructions. You can use `-h +[DIRECTIVE]` to get help specifically for a directive (e.g., `ppmedit -h +e`). Also, if you have any questions, suggestions, or need further assistance, you can post them on the GitHub [Issues](https://github.com/dimap-ufrn/processamento-de-imagens---p1-team-1/issues) section for this project. |
| -i              | Specify the input image (at least one image is required, two for the -c directive).|
| -o              | Define the output location of the image. The default is `./a.ppm` if not specified.|
| -t              | Write text on the image.                          |

## Building the Project :hammer:

To build the project, you can use the following make commands:

### `make all`

This command builds the project and saves the compilation in the `bin/` directory.

```bash
make all
```

Please ensure that you have `g++` with C++11 support installed on your system to successfully build the project.

### `make doc`

The `make doc` command generates automatic documentation for the project and saves it in the `doc/` directory.

```bash
make doc
```

To use this command, you need to have Doxyfile version 1.9.1 or higher installed on your system.

### `make test`

The `make test` command compiles and executes the test files.

```bash
make test
```

This command will help you run test cases and verify that the project is functioning correctly.

Please note that before using these commands, make sure you are in the root directory of the project where the necessary Makefile and source files are located. Additionally, ensure you have the required dependencies installed on your system to avoid any issues during the building process.

## License :page_facing_up:
ppmedit is distributed under the MIT License. You can find the full text of the license in the LICENSE file accompanying the program.

## Contributions :octocat:
Contributions to ppmedit are welcome. If you encounter any issues or have suggestions for improvements, please submit them to the project's GitHub repository.

## Contact :email:
If you have any questions or inquiries, you can reach out to Pedro Lucas at pedrolucas.jsrn@gmail.com.
