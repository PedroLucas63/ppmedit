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
extern const Pixel COLOR_WHITE { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global black pixel.
 */
extern const Pixel COLOR_BLACK { 
   MIN_COLOR,
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global red pixel.
 */
extern const Pixel COLOR_RED { 
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS
};

/**
 * @brief Global green pixel.
 */
extern const Pixel COLOR_GREEN { 
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global blue pixel.
 */
extern const Pixel COLOR_BLUE { 
   MIN_COLOR,
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global yellow pixel.
 */
extern const Pixel COLOR_YELLOW { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global purple pixel.
 */
extern const Pixel COLOR_PURPLE { 
   MAX_AMOUNT_COLORS,
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global cyan pixel.
 */
extern const Pixel COLOR_CYAN { 
   MIN_COLOR,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global pink pixel.
 */
extern const Pixel COLOR_PINK { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global orange pixel.
 */
extern const Pixel COLOR_ORANGE { 
   MAX_AMOUNT_COLORS,
   MAX_AMOUNT_COLORS / 2,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global brown pixel.
 */
extern const Pixel COLOR_BROWN { 
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 4,
   MIN_COLOR,
   MAX_AMOUNT_COLORS 
};

/**
 * @brief Global gray pixel.
 */
extern const Pixel COLOR_GRAY { 
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS / 2,
   MAX_AMOUNT_COLORS 
};

#endif // COLORS_HPP
