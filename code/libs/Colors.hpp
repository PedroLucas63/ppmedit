/**
 * @file Colors.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Color pixel standards.
 * @version 2.0
 * @date 2023-06-25
 * 
 * Setting default color pixels based on the maximum color (#MAX_AMOUNT_COLORS)
 * and minimum color (#MIN_COLOR) values.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef COLORS_HPP
#define COLORS_HPP

#include "Pixel.hpp"

/**
 * @brief Global white pixel.
 */
extern Pixel const WHITE { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global black pixel.
 */
extern Pixel const BLACK { 
   MIN_COLOR,
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global red pixel.
 */
extern Pixel const RED { 
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global green pixel.
 */
extern Pixel const GREEN { 
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global blue pixel.
 */
extern Pixel const BLUE { 
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global yellow pixel.
 */
extern Pixel const YELLOW { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global purple pixel.
 */
extern Pixel const PURPLE { 
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global cyan pixel.
 */
extern Pixel const CYAN { 
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global pink pixel.
 */
extern Pixel const PINK { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global orange pixel.
 */
extern Pixel const ORANGE { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS / 2,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global brown pixel.
 */
extern Pixel const BROWN { 
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 4,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global gray pixel.
 */
extern Pixel const GRAY { 
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Get the global pixel color by color name.
 * 
 * @param color_name Color name.
 * @return An global pixel color.
 */
Pixel const getColorByName(std::string color_name) {
   if (color_name == "white") {
      return WHITE;
   } else if (color_name == "red") {
      return RED;
   } else if (color_name == "green") {
      return GREEN;
   } else if (color_name == "blue") {
      return BLUE;
   } else if (color_name == "yellow") {
      return YELLOW;
   } else if (color_name == "purple") {
      return PURPLE;
   } else if (color_name == "cyan") {
      return CYAN;
   } else if (color_name == "pink") {
      return PINK;
   } else if (color_name == "orange") {
      return ORANGE;
   } else if (color_name == "brown") {
      return BROWN;
   } else if (color_name == "gray") {
      return GRAY;
   }

   return BLACK;
}

#endif // COLORS_HPP
