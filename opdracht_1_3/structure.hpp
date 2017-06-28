#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>
#include "window.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"
/// @file

/// \brief
/// structure
/// \details
/// this library contains a c++ and a h++ file, it contains a constructor and a print function for a structure
/// made out of rows and columns
class structure
{
private:
    int row;
    int column;
    window & w;
    
public:
/// \brief
/// The constructor of a structure
/// \details
/// This is a constructor that makes a strucure from two parameters
/// it the rows and columns determine how many times the structure is printed
    structure( window & w, int row, int column):
    row( row ),
    column( column ),
    w( w )
    {}
    void print();
};

#endif // STRUCTURE_HPP
