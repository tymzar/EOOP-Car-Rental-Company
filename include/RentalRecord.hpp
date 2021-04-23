#pragma once
#ifndef RentalRecord_HPP
#define RentalRecord_HPP

using namespace std;

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "RentalReport.hpp"
#include "Car.hpp"

class RentalRecord: public RentalData{

    Car * rentedCar;
    Customer * rentee;

    public:
        RentalRecord(){}
        ~RentalRecord(){}
        Car * getRentedCar(){}
        Customer * getRentee(){}
        void updateRentedCar(Car * x){}
        void updateRentee(Customer * x){}

        friend ostream& operator<<(std::ostream& out, const RentalRecord& x){}
};

#endif