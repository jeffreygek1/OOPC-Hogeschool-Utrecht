// example:
// definition of the functions of a rectangle object

#include "wall.hpp"
/// \brief
/// a update function of a wall
/// \details
/// this count towards the update counts, if meeted it inverts the state of filled
void wall::update(){
    update_count+=1;
    if(update_count == update_interval){
        filled = !filled;
        update_count=0;
    }
}

/// \brief
/// The constructor of a wall
/// \details
/// This is a constructor that makes a wall from four parameters
/// it has a start and an end pos also an update interval
wall::wall( window & w, const vector & start, const vector & end, int update_interval):
    rectangle(w, start, end),
    filled(true),
    update_interval(update_interval),
    update_count(0)
    {}
    
/// \brief
/// a draw function of a wall
/// \details
/// if filled this function makes a wall using 4 rectangles, each an pixel thick
void wall::draw(){
    vector lb = start;
    vector ro = end;
    if(filled){
        for(int i = 0; i<4; i++){
            rectangle(w, lb, ro).draw();
            lb+=vector(1,1);
            ro+=vector(-1,-1);
        }
    } else {
        rectangle(w, start, end).draw();
        rectangle(w, (start+vector(3,3)), (end+vector(-3,-3))).draw();
    }
}



