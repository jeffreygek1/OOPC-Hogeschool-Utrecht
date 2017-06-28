#include "hwlib.hpp"

class two_input_AND : public hwlib::pin_in {
private:
	hwlib::target::pin_in pin1;
    hwlib::target::pin_in pin2;
	hwlib::buffering buffer;
public:

	two_input_AND(hwlib::target::pin_in & pin1, hwlib::target::pin_in & pin2, hwlib::buffering buffer):
		pin1(pin1),
        pin2(pin2)
	{}
	
	bool get(hwlib::buffering buffer) override{
        return(pin1.get()&& pin2.get());
	}

};

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto led0 = hwlib::target::pin_out( hwlib::target::pins::d14 );
	
	auto button1 = hwlib::target::pin_in( hwlib::target::pins::d6 );
	auto button2 = hwlib::target::pin_in( hwlib::target::pins::d5 );
	hwlib::buffering buffer = hwlib::buffering::unbuffered;
	two_input_AND buttons(button1, button2, buffer);
	
	for(;;){
		led0.set(buttons.get(buffer));
		hwlib::wait_ms(10);
	}
	return 0;
}

