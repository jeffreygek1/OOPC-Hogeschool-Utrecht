#include "hwlib.hpp"
#include <stdio.h>

int power(int value, int power) {
    int result = 1;

    for (int i = 0; i < power; ++i) {
        result *= value;
    }
    result -= 1;
    return (result);
}

void add_del(hwlib::port_out & leds, auto & add, auto & del){
    int count = 0;
    while(1){
        if(del.get() && count > 0){
            count--;
            hwlib::wait_ms(200);
            
        }
        if(add.get() && count < 5){
            count++;
            hwlib::wait_ms(200);
        }
        
        int binary_code = power(2, count);
        hwlib::cout << "binary:" << (binary_code) << "\n";
        leds.set(binary_code);
        hwlib::wait_ms(200);

    }
}

int main( void ){
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
	auto led0 = hwlib::target::pin_out( hwlib::target::pins::d14 );
	auto led1 = hwlib::target::pin_out( hwlib::target::pins::d15 );
	auto led2 = hwlib::target::pin_out( hwlib::target::pins::d16 );
	auto led3 = hwlib::target::pin_out( hwlib::target::pins::d17 );
    
	auto add = hwlib::target::pin_in( hwlib::target::pins::d6 );
	auto del = hwlib::target::pin_in( hwlib::target::pins::d5 );
    
    auto leds = hwlib::port_out_from_pins(led0,led1,led2,led3);

    
    add_del(leds, add, del);
}
