#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "ostream"

/// @file

/// \brief
/// vector operator
/// \details
/// this library contains a c++ and a h++ file, it defines and declares some operator,
/// used with a vector. it also contains a constructor for a vector
class vector {
public:
   int x;
   int y; 
   
   vector( int x = 0, int y = 0 );
   vector operator+() const;
   vector operator+( const vector & rhs ) const;
   vector &operator+=(const vector & rhs );
   bool operator==( const vector & rhs ) const;
   
   vector operator*(const int rhs) const;
   vector operator*(const vector & rhs ) const;
   vector &operator*=(const vector & rhs );
   friend std::ostream& operator<<(std::ostream& lhs, const vector& rhs);
};


#endif // VECTOR_HPP
