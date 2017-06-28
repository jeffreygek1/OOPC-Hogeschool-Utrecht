#include "hwlib.hpp"

class vector{
public:
	int x;
	int y;
	/** 
	 * @name vector constructor
	 * @details a constructor of the class is created to initialize two integers, x and y. These two integers are the x and y coordinates of the vector. \n
	 * The default value of the operators wil become 0. This however will be modified once different values are being givin by the parameters.  
	 * @code 
	 * vector (int x = 0, int y = 0):
			x(x),y(y)
	 {}
	 * @endcode
	 * */
	vector (int x = 0, int y = 0):
		x(x),y(y)
	{}
	
	/** 
	 * @name == operator(vector,vector)
	 * @returns true or false
	 * @details this operator will check if the x and y coordinates of two vectors are equal. \n  
	 * This operator is only able to check two vectors. 
	 * @code 
	 * bool operator==( const vector & r ) const {
			return ( x == r.x ) && ( y == r.y );
	   }
	 * @endcode
	 * */
	bool operator==( const vector & r ) const {
		return ( x == r.x ) && ( y == r.y );
	}
	
	/** 
	 * @name + operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to add two vectors to each other. \n
	 * The x and y coordinates of the second vector will be added to the first. \n
	 * @warning this operator does NOT change the original value of the first vector
	 * @example add_subtract_two_vectors \n
	 * vector v(1,2), x(2,1); \n
	 * vector y = v + x; \n
	 * std::cout << y; \n
	 * \n
	 * \b output: \n
	 * |3| \n
	 * |3|
	 * @code 
	 * vector operator+(const vector & r) const{
		return vector(x+r.x, y+r.y);
	}
	 * @endcode
	 * */
	vector operator+(const vector & r) const{
		return vector(x+r.x, y+r.y);
	}
	
	/** 
	 * @name + operator(vector,NULL)
	 * @returns vector
	 * @details this operator can be used to add an empty vectors to another vector. \n
	 * No calculations will take place and a vector with the same x and y coordinates of the first vector will be returned \n
	 * This operator is used as an error prevention method so an user wont get an error message when an empty vector is added to another vector.
	 * @warning this operator does NOT change the original value of the first vector and a NEW vector (equal to the first) will be returned.
	 * @code 
	 * vector operator+() const{
		return vector(x,y);
	}
	 * @endcode 
	 * */
	vector operator+() const{
		return vector(x,y);
	}
	
	/** 
	 * @name += operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to increment an vector with another vector. \n
	 * The x and y coordinates of the second vector will be added to the first vector. \n
	 * @warning this operator changes the original value of the first vector.
	 * @example vector_incrementations \n
	 * vector v(1,2), x(4,3); \n
	 * int k = 2; \n
	 * \n
	 * v += x; \n
	 * std::cout << v << '/n'; \n
	 * \n
	 * v += vector(); \n
	 * std::cout << v << '/n'; \n
	 * \n
	 * v -= x; \n
	 * std::cout << v << '/n'; \n
	 * \n
	 * v *= x; \n
	 * std::cout << v << '/n'; \n 
	 * \n
	 * \b output: \n
	 * |5| \n
	 * |5|
	 * 
	 * |5|
	 * |5|
	 * 
	 * |1|
	 * |2|
	 * 
	 * |7|
	 * |14|
	 * @code 
	 * vector & operator+=(const vector & r){
		x = x + r.x;
		y = y + r.y;
		return *this;
	}
	 * @endcode
	 * */
	vector & operator+=(const vector & r){
		x = x + r.x;
		y = y + r.y;
		return *this;
	}
	
	/** 
	 * @name - operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to subtract an vector with another vector. \n
	 * The x and y coordinates of the second vector will be subtrated from the first vector. \n
	 * @warning this operator does NOT change the original value of the first vector.
	 * @code 
	 * vector operator-(const vector & r) const{
		return vector(x-r.x, y-r.y);
	}
	 * @endcode
	 * */
	vector operator-(const vector & r) const{
		return vector(x-r.x, y-r.y);
	}
	
	/** 
	 * @name - operator(vector,NULL)
	 * @returns vector
	 * @details this operator can be used to subtract an empty vectors from another vector. \n
	 * No calculations will take place and a vector with the same x and y coordinates of the first vector will be returned \n
	 * This operator is used as an error prevention method so an user wont get an error message when an empty vector is subtracted from another vector.
	 * @warning this operator does NOT change the original value of the first vector and a NEW vector (equal to the first) will be returned.
	 * @code 
	 * vector operator-() const{
		return vector(x,y);
	}
	 * @endcode
	 * */
	vector operator-() const{
		return vector(x,y);
	}
	
	/** 
	 * @name -= operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to deincrement a vector from another vector. \n
	 * The x and y coordinates of the second vector will be subtracted from the first vector. \n
	 * @warning this operator changes the original value of the first vector.
	 * @code 
	 * vector & operator-=(const vector & r){
		x = x - r.x;
		y = y - r.y;
		return *this;
	}
	 * @endcode 
	 * */
	vector & operator-=(const vector & r){
		x = x - r.x;
		y = y - r.y;
		return *this;
	}
	
	/** 
	 * @name * operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to multiply an vector with another vector. \n
	 * This is the principle of the operation: \n
	 * |a| . |c| -> |a*c + a*d| \n 
	 * |b| * |d| -> |b*c + b*d| \n
	 * Multiplications of vectors work differently from additions and subtraction.
	 * @warning this operator does NOT change the original value of the first vector.
	 * @example multiply_two_vectors \n
	 * vector v(1,2), x(4,3); \n
	 * vector y = v * x; \n
	 * std::cout << y; \n
	 * \n
	 * \b output: \n
	 * |7| \n
	 * |14|
	 * @code 
	 * vector operator*(const vector & r) const{
		return vector(
			x * r.x + x * r.y,
			y * r.x + y * r.y
		);
	}
	 * @endcode 
	 * */
	vector operator*(const vector & r) const{
		return vector(
			x * r.x + x * r.y,
			y * r.x + y * r.y
		);
	}
	
	/** 
	 * @name * operator(vector, int)
	 * @returns vector
	 * @details this operator can be used to multiply an vector with an scalar constant. \n
	 * This is the principle of the operation: \n
	 * |a| . . -> |a*2| \n 
	 * |b| * 2 -> |b*2| \n
	 * Multiplications of a vector with a scalar constant also works differently. \n
	 * This is the default operator where the scalar constant goes on the right. \n
	 * There is an override of this opperator which allows the scalar constant to be used from the left.
	 * @see * operator(int, vector)
	 * @warning this operator does NOT change the original value of the first vector.
	 * @code 
	 * vector operator*(const int r) const{
		return vector(
			x * r,
			y * r
		);
	}
	 * @endcode 
	 * */
	vector operator*(const int r) const{
		return vector(
			x * r,
			y * r
		);
	}
	
	/** 
	 * @name *= operator(vector, vector)
	 * @returns vector
	 * @details this operator can be used to increment (by multiplication) a vector with an another vector. \n
	 * This is the principle of the operation: \n
	 * |a| . |c| -> |a*c + a*d| \n 
	 * |b| * |d| -> |b*c + b*d| \n
	 * @warning this operator changes the original value of the first vector.
	 * @code 
	 * vector & operator*=(const vector & r){
		x = (x * r.x) + (x * r.y);
		y = (y * r.x) + (y * r.y);
		return *this;
	}
	 * @endcode
	 * */
	vector & operator*=(const vector & r){
		x = (x * r.x) + (x * r.y);
		y = (y * r.x) + (y * r.y);
		return *this;
	}
	
	/** 
	 * @name *= operator(vector, int)
	 * @returns vector
	 * @details this operator can be used to increment (by multiplication) a vector with a scalar constant. \n
	 * This is the principle of the operation: \n
	 * |a| . . -> |a*2| \n 
	 * |b| * 2 -> |b*2| \n
	 * @warning this operator changes the original value of the first vector.
	 * @code 
	 * vector & operator*=(const int r){
		x *= r;
		y *= r;
		return *this;
	}
	 * @endcode 
	 * */
	vector & operator*=(const int r){
		x *= r;
		y *= r;
		return *this;
	}
};

class display{
private:
	hwlib::pin_oc & scl;
	hwlib::pin_oc & sda;
	hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus;
	hwlib::glcd_oled & screen;
public:
	int screen_width;
	int screen_height;
	display(hwlib::pin_oc & scl, hwlib::pin_oc & sda, hwlib::i2c_bus_bit_banged_scl_sda & i2c_bus, hwlib::glcd_oled & screen):
		scl(scl), 
		sda(sda),
		i2c_bus(i2c_bus),
		screen(screen),
		screen_width(127),
		screen_height(63)
	{screen.clear();}
	
	void clear(){
		screen.clear();
	}
	
	void draw(const vector & pos){
		screen.write(hwlib::location(pos.x,pos.y), hwlib::black);
	}

};
	

class object{
protected:
	display w;
	vector speed;
public:
	object(display & w, const vector & speed):
		w(w),
		speed(speed)
	{}
	virtual void print() = 0;
	virtual void collision(){};
	virtual void update(){};
	
};//class object

class ball : public object{
private: 
	vector midpoint;
	int radius;
public:
	ball(display & w, const vector & speed = vector(0,0), const vector & midpoint = vector(0,0), int radius = 0):
		object(w,speed),
		midpoint(midpoint),
		radius(radius)
	{}
		
	void print() override{
		//Pitteway algoritme
		int x0 = midpoint.x;
		int y0 = midpoint.y;
		
		int x = radius;
		int y = 0;
		int error = 0;

		while(x >= y){
			w.draw(vector(x0 + x, y0 + y));
			w.draw(vector(x0 + y, y0 + x));
			w.draw(vector(x0 - y, y0 + x));
			w.draw(vector(x0 - x, y0 + y));
			
			w.draw(vector(x0 - x, y0 - y));
			w.draw(vector(x0 - y, y0 - x));
			w.draw(vector(x0 + y, y0 - x));
			w.draw(vector(x0 + x, y0 - y));
			
			++y;
			if (error <= 0){
				error+= 2*y + 1;
			}
			if (error > 0){
				--x;
				error -= 2*x + 1;
			}
			
		}
	}

	void collision() override{
		//dit voorkoomt verwijning van de bal als die uit het scherm gaat
		if ((midpoint.y+radius) >= w.screen_height || midpoint.y-radius<=0){
			speed.x*=1;
			speed.y*=-1;
		}
		if ((midpoint.x+radius) >=w.screen_width || midpoint.x-radius<=0){
			speed.x*=-1;
			speed.y*=1;
		}
	}
	
	void update() override{
		midpoint+=speed;
	}

	
};//class circle

 
int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
	auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
	auto screen = hwlib::glcd_oled( i2c_bus, 0x3c ); 
	
	display w(scl,sda,i2c_bus,screen);
	
	ball a(w, vector(2,2) ,vector(10,10) , 5);
	ball b(w, vector(-2,2) ,vector(40,10) , 5);
	ball c(w, vector(2,-2) ,vector(40,50) , 5);
	ball d(w, vector(-2,-2) ,vector(30,30) , 5);
	object * objects[] = {&a,&b,&c,&d};
	
	for(;;){
		w.clear();
		for( auto & p : objects ){
			p->print();
		}
		for( auto & p : objects ){
			p->collision();
			p->update();
		}
   }
	
	return 0;
}

