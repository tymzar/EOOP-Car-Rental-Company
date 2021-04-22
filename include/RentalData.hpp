#ifndef RentalData_HPP
#define RentalData_HPP

using namespace std;

#include <bits/stdc++.h>
#include "utility.hpp"
#include "Customer.hpp"
#include "Car.hpp"
#include "RentalReport.hpp"


class RentalData{

    int rentalDataID;
    Car * rentedCar;
    Customer * rentee;
    STATUS rentalStatus;
    RentalReport * rentalDetails;

    public:
        RentalData();
        ~RentalData();
        Car * getRentedCar();
        Customer * getRentee();
        STATUS getRentalStatus();
        RentalReport * getRentalDetails();
        void updateRentedCar(Car * x);
        void updateRentee(Customer* x);
        void updateRentalDetails(RentalReport *);
        void toggleRentalStatus();
        void notifyNearestEmployee();
        void notifyCustomer();

        friend ostream& operator<<(std::ostream& out, const RentalReport& x);


};

#endif