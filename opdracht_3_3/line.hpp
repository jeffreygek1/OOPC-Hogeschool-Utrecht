#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
   vector end;
public:
   line( window & w, const vector & location, const vector & end, const vector & bounce):
      drawable( w, location, end - location, bounce ),
      end( end )
   {}
   void draw() override;
};

#endif // LINE_HPP
