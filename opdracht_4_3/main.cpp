#include "hwlib.hpp"

void light_cycle( hwlib::pin_in_out & led0,hwlib::pin_in_out & led1,hwlib::pin_in_out & led2,hwlib::pin_in_out & led3 ){
   led0.direction_set_output();
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
   while(1){
      led0.set( 1 );
      led1.set( 1 );
      led2.set( 0 );
      led3.set( 0 );
      hwlib::wait_ms( 200 );
      led0.set( 0 );
      led1.set( 1 );
      led2.set( 1);
      led3.set( 0 );
      hwlib::wait_ms( 200 );  
      led0.set( 0 );
      led1.set( 0 );
      led2.set( 1);
      led3.set( 1 );
      hwlib::wait_ms( 200 );   
      led0.set( 0 );
      led1.set( 1 );
      led2.set( 1);
      led3.set( 0 );
      hwlib::wait_ms( 200 );      
   }
}

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d14 );
    auto led1 = hwlib::target::pin_out( hwlib::target::pins::d15 );
    auto led2 = hwlib::target::pin_out( hwlib::target::pins::d16 );
    auto led3 = hwlib::target::pin_out( hwlib::target::pins::d17 );
   light_cycle( led0,led1, led2 , led3);
}

         