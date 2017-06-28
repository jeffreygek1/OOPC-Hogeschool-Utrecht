#include "hwlib.hpp"

namespace hwlib {

class pin_out_invert : public pin_out{
private:
	pin_out & a;
public:
	pin_out_invert(pin_out & a):
		a(a)
	{}
	
	void set(
		bool x,
		buffering buf = buffering::unbuffered 
	)override{
		a.set(!x, buf);
	}
	
}; //pin_out_invert

class pin_out_all : public pin_out {
private:
   pin_out * list[ 8 ];     
   
public:

   pin_out_all( 
      pin_out & p0, 
      pin_out & p1 = pin_out_dummy,  
      pin_out & p2 = pin_out_dummy, 
      pin_out & p3 = pin_out_dummy, 
	  pin_out & p4 = pin_out_dummy,  
      pin_out & p5 = pin_out_dummy, 
      pin_out & p6 = pin_out_dummy,
	  pin_out & p7 = pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7 }
   {}
   
   void set( bool v,  buffering buff = buffering::unbuffered ) override{
      for( auto p  : list ){
          p->set( v, buff );
      }
   }
};


}; //namespace hwlib

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d14 );
    auto led1 = hwlib::target::pin_out( hwlib::target::pins::d15 );
    auto led2 = hwlib::target::pin_out( hwlib::target::pins::d16 );
    auto led3 = hwlib::target::pin_out( hwlib::target::pins::d17 );
    
    auto ds = hwlib::target::pin_out(hwlib::target::pins::d9);
    auto shcp = hwlib::target::pin_out(hwlib::target::pins::d8);
    auto stcp = hwlib::target::pin_out(hwlib::target::pins::d7);

    auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
        stcp, 
        ds, 
        hwlib::pin_in_dummy
    );
    
    auto hc595 = hwlib::hc595(spi, shcp);
	
	auto led4_invert = hwlib::pin_out_invert(hc595.p0);
	auto led5_invert = hwlib::pin_out_invert(hc595.p1);
	auto led6_invert = hwlib::pin_out_invert(hc595.p2);
	auto led7_invert = hwlib::pin_out_invert(hc595.p3);
	
	auto leds = hwlib::pin_out_all( 
		led4_invert, 
		led5_invert, 
		led6_invert,
		led7_invert,
		led0, 
		led1, 
		led2, 
		led3 
	);
	

	hwlib::blink(leds);
	return 0;
}

