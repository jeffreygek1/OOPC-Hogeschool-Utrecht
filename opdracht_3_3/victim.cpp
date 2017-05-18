// example:
// definition of the functions of a rectangle object

#include "victim.hpp"
void victim::update(){
    if( destroyed){
        size_shrink++;
    }
}
void victim::interact( drawable & other ){
    if( this != & other){
        if( overlaps( other )){
            destroyed = true;
        }
    }
}
    
victim::victim( window & w, const vector & start, const vector & end):
    rectangle(w, start, end),
    destroyed(false),
    size_shrink(0)
    {}
    
void victim::draw(){
    if( ((start.x + size_shrink)-(end.x - size_shrink) == 0) || ((start.y + size_shrink)-(end.y - size_shrink) == 0)){
        destroyed = false;
    }
    else{
    rectangle(w, start + vector(size_shrink,size_shrink), end + vector(-size_shrink,-size_shrink)).draw();
    }
}



