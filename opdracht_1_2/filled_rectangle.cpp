#include "filled_rectangle.hpp"

/// \brief
/// a print function of a filled_rectangle
/// \details
/// this function makes a filled rectangle made out of a start_x and y pos and a end_x and y pos
void filled_rectangle::print(){

   int x0 = start_x;
   int y0 = start_y;
   int x1 = end_x;
   int y1 = end_y;
    for( int x = x0; x < (x1 +1); x++ ){
        for( int y = y0; y < (y1 + 1); y++){
            w.draw(x, y);
        }
    }
}