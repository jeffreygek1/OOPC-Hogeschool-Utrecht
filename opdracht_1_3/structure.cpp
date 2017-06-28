#include "structure.hpp"

/// \brief
/// a print function of a structure
/// \details
/// this function makes a structure of rectangles, lines and circles and prints this structure
/// the column and row determine how many times it is printed
void structure::print(){
    int rows = row;
    int columns = column;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int placement_row = (200*j);
            int placement_column = (100*i);
            filled_rectangle car_body( w, 0 + placement_row, 50 + placement_column, 175 + placement_row, 70+ placement_column);
            filled_rectangle car_hood( w, 3 + placement_row, 35 + placement_column, 40 + placement_row, 50+ placement_column);
            filled_rectangle car_trunk( w, 140 + placement_row, 35+ placement_column, 173 + placement_row, 50+ placement_column);
            filled_rectangle mid_pillar(w, 90 + placement_row, 5+ placement_column, 100 + placement_row, 50+ placement_column);
            
            line front_window( w, 40 + placement_row, 35+ placement_column, 80 + placement_row, 5+ placement_column);
            line roof(w, 80 + placement_row, 5+ placement_column, 120 + placement_row, 5+ placement_column);
            line rear_window(w, 120 + placement_row, 5+ placement_column, 140 + placement_row, 35+ placement_column);

            circle tire_left( w, 150 + placement_row, 80+ placement_column, 25);
            circle tire_right( w, 25 + placement_row, 80+ placement_column, 25);
            
            car_body.print();
            car_hood.print();
            car_trunk.print();
            mid_pillar.print();
            
            front_window.print();
            roof.print();
            rear_window.print();
            
            tire_left.print();
            tire_right.print();
        
        }
    }
}
