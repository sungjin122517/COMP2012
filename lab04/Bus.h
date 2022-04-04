#include "ParkingLot.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
using namespace std;

//TODO: complete declaration of Bus

/*
no of passengers
constructor(string plate no, int no of passengers)
leave() and print()
*/

class Bus : public Vehicle
{
    private:
        int passengers_bus;

    public:
        Bus(const string& plate_no, int passengers_bus);
        void leave(ParkingLot *parking_lot);
        void print() const;
};