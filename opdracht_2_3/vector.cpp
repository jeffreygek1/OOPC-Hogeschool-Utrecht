#include "vector.hpp"

/// \brief
/// The constructor of an Vector
/// \details
/// This is a constructor that makes a vector from two parameters
/// a x pos and a y pos, with a default value of 0 for both pos

vector::vector( int x, int y ):
    x( x ), y( y ){}
    
/// \brief
/// returns himself vector
/// \details
/// This operatotor return himself
vector vector::operator +() const{
    return *this;
}

/// \brief
/// Adds 2 vector into a new vector
/// \details
/// This operator return a vector made from adding the x_pos and the y_pos of both vector
vector vector::operator+( const vector & rhs ) const{
    return vector( x + rhs.x, y + rhs.y);
}
/// \brief
/// Adds a vector into another vector
/// \details
/// This operator adds a vector into another vector
/// Thereby it changes the first vector and returns himself
vector &vector::operator+=( const vector & rhs){
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}

/// \brief
/// Compares 2 vectors
/// \details
/// This operator compares 2 vectors there x_pos and y_pos and returns a boo value
bool vector::operator==(const vector & rhs) const{
    return( x == rhs.x) && ( y == rhs.y);
}

/// \brief
/// multiplies a vector with an integer
/// \details
/// This operator multiplies a vector with an integer into a new vector,
/// the new vector is returned
vector vector::operator*(const int rhs) const{
    return vector( x*rhs, y*rhs);
}

/// \brief
/// multiplies 2 vectors
/// \details
/// This operator multiplies 2 vector into a new vector,
/// the new vector is returned
vector vector::operator*(const vector & rhs) const{
    return vector( x*rhs.x, y*rhs.y);
}

/// \brief
/// multiplies a vector into a vector
/// \details
/// This operator multiplies a vector into a vector, thereby it changes the first vector
/// the first vector is returned
vector &vector::operator*=( const vector & rhs){
    x*=rhs.x;
    y*=rhs.y;
    return *this;
}

/// \brief
/// prints a vector in the command line
/// \details
/// This operator prints a into the command line
std::ostream &operator<<(std::ostream& lhs, const vector& rhs)
{
    return lhs << std::showbase << std::hex << "[" << rhs.x << "/" << rhs.y << "]";
}