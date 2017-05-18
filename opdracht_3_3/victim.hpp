#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "rectangle.hpp"

class victim : public rectangle {
protected:
    bool destroyed;
    int size_shrink;
public:
    victim( window & w, const vector & start, const vector & end);
    void draw() override;
    void update() override;
    void interact( drawable & other ) override;
    

//    void update() override;
};


#endif // VICTIM_HPP
