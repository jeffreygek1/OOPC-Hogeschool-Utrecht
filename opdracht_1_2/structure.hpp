#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>
#include "window.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"

class structure
{
private:
    int row;
    int column;
    window & w;
    
public:
    structure( window & w, int row, int column):
    row( row ),
    column( column ),
    w( w )
    {}
    
    void print();
};

#endif // STRUCTURE_HPP
