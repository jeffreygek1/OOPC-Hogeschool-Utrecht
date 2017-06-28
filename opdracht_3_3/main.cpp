#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main(){
    window w( vector( 128, 64 ), 2 );
    line top( w, vector(   0,  0 ), vector( 127,  0 ), vector(1,-1) );
    
    line right( w, vector( 127,  0 ), vector( 127, 63 ),vector(-1,1) );
    line bottom( w, vector(   0, 63 ), vector( 127, 63 ),vector(1,-1) );
    line left( w, vector(   0,  0 ), vector(   0, 63 ),vector(-1,1)  );
    victim r(w, vector(15, 20), vector(35,60));
//    wall q(w, vector(110, 50), vector(120,60), 0);
    ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   
    drawable * objects[] = { &b, &r, &top, &right, &bottom, &left};

    for(;;){
       w.clear();
       for( auto & p : objects ){
          p->draw();
       }
       wait_ms( 20 );
       for( auto & p : objects ){
           p->update();
       }
       for( auto & p : objects ){
          for( auto & other : objects ){
             p->interact( *other );
          } 
       }
    }
}

