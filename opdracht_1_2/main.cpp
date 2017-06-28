// example:
// a rectangle object that is contains four line objects

#include <iostream>
#include "window.hpp"
#include "filled_rectangle.hpp"


int main(int argc, char **argv){
    window w( 128, 128, 2);
    filled_rectangle square( w, 20, 20, 40, 40 );
    filled_rectangle square2( w, 40, 40, 80, 80);
    filled_rectangle square3( w, 100, 20, 120, 60);
    square.print();
    square2.print();
    square3.print();
    return 0;
}
