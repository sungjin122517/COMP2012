#include <string>
#include <iostream>
#include "Vehicle.h"
#include "ParkingLot.h"
using namespace std;

//TODO: complete declaration of Truck

/*
capacity
constructor(string plate no, int capacity)
leave() and print()
*/

class Truck : public Vehicle
{
    private:
        int capacity;

    public:
        Truck(const string& plate_no, int capacity);
        void leave(ParkingLot *parking_lot);
        void print() const;
};