// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end):

   drawable( w, start+vector(1,1), (end - start) + vector(-1,1), vector(1,1)),
   
   end( end ),
   start(start),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ), vector(-1, 1)),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y+1   ), vector(-1, 1) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ), vector(1, -1) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ), vector(1,-1) )
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}

