#include "Bus.h"

//TODO: complete the constructor and all member functions of Bus
Bus::Bus(const string& plate_no, int passengers_num) : 
    Vehicle(plate_no), passengers_bus(passengers_num) {};


void Bus::leave(ParkingLot *parking_lot) {
    if (is_parking == false)
    {
        cout << this->get_plate_no() << " is not parking so it cannot leave!" << endl;
    }
    double fee = 0;
    fee = parking_lot->reclaim_space(this, BUS);
    is_parking = false;
    total_fee += fee;
}


void Bus::print() const {
    cout << "The bus is " << get_plate_no() << " with " << passengers_bus << " passengers. It has paid totally " 
    << total_fee << "." << endl;
}