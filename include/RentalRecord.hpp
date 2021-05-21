#ifndef RentalRecord_HPP
#define RentalRecord_HPP

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "RentalReport.hpp"
#include "Car.hpp"

class RentalRecord: public RentalData{

    Car * rentedCar;
    Customer * rentee;

    public:
        RentalRecord(Car * rentedCar, Customer * rentee,STATUS rentalStatus,double travelledDistance, double userCharge, double usedFuel, time_t startTime, time_t endTime): RentalData(rentalStatus,travelledDistance,  userCharge,  usedFuel, startTime,  endTime){
            this->rentedCar = rentedCar;
            this->rentee = rentee;
        }
        ~RentalRecord();
        Car * getRentedCar()const;
        Customer * getRentee()const;
        void updateRentedCar(Car * x);
        void updateRentee(Customer * x);

        friend std::ostream& operator<<(std::ostream& out, const RentalRecord& x);
};

#endif