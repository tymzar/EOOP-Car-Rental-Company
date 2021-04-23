#pragma once
#ifndef RentalData_HPP
#define RentalData_HPP

using namespace std;

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "RentalReport.hpp"

class RentalData{

    int rentalDataID;
    STATUS rentalStatus;
    RentalReport * rentalDetails;

    public:
        RentalData();
        ~RentalData();
        int getRentalDataID();
        STATUS getRentalStatus();
        RentalReport * getRentalDetails();
        void updateRentalDetails(RentalReport *);
        void toggleRentalStatus();
        void notifyNearestEmployee();
        void notifyCustomer();

        friend ostream& operator<<(std::ostream& out, const RentalData& x);


};

#endif