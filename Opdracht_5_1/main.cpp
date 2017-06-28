#include "hwlib.hpp"


int power(int value, int power) {
    int result = 1;

    for (int i = 0; i < power; ++i) {
        result *= value;
    }
    result -= 1;
    return (result);
}

void meer_of_minder_hwlib(hwlib::port_out & leds, auto & button_add, auto & button_del){
    unsigned int max = 0; 
    for(;;){
        if(button_add.get() == 0 && max < 9){
            ++max;
            hwlib::wait_ms(200);
        }
        
        if(button_del.get() == 0 && max > 0){
            --max;
            hwlib::wait_ms(200);
        }
        
        int binary_code = power(2, max);
        hwlib::cout << "binary:" << binary_code << "\n";
        leds.set(binary_code);
    }
    
    
}

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
    
    auto shift_reg = hwlib::hc595(spi, shcp);
    
    auto leds = hwlib::port_out_from_pins(
        led0,
        led1,
        led2,
        led3,
        shift_reg.p0,
        shift_reg.p1,
        shift_reg.p2,
        shift_reg.p3
    );
    
    auto button_add = hwlib::target::pin_in( hwlib::target::pins::d6 );
    auto button_del = hwlib::target::pin_in( hwlib::target::pins::d5 );
    //shift_reg.p4.set(0);
    meer_of_minder_hwlib(leds, button_add, button_del);
    return 0;
}

