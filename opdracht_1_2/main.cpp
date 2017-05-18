// example:
// a rectangle object that is contains four line objects
#include "structure.hpp"


int main(int argc, char **argv){
    window w( 1024, 512, 1);
    int row = 2;
    int column = 4;
    structure car1(w, row, column);
    car1.print();

    
    return 0;
}
