// example:
// declaration of a line class that stores its window

#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"
// example:
// declaration of a line class that stores its window

#include "filled_rectangle.hpp"

/// @file

/// \brief
/// filled_rectangle
/// \details
/// this library contains a c++ and a h++ file, it contains a constructor and a print function 
/// for a filled_rectangle made out of 4 coordinates and a window

class filled_rectangle {
private:
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
   window & w;
public:
/// \brief
/// The constructor of a filled_rectangle
/// \details
/// This is a constructor that makes a strucure from five parameters
   filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
      start_x( start_x ),
      start_y( start_y ),
      end_x( end_x ),
      end_y( end_y ),
      w( w )
   {}
   void print();
};

#endif // LINE_HPP
