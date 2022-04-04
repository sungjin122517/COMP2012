#include "ParkingLot.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
using namespace std;

//TODO: complete declaration of PrivateCar

/*
no of passengers
constructor(string plate no, string brand)
leave() and print()
*/

class PrivateCar : public Vehicle
{
    private:
        // int passengers_car;
        string brand;

    public:
        PrivateCar(const string& plate_no, const string& brand);
        void leave(ParkingLot *parking_lot);
        void print() const;
};