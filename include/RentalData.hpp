#pragma once
#ifndef RentalData_HPP
#define RentalData_HPP

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "RentalReport.hpp"

class RentalData{

    static int totalRentals;
    int rentalDataID;
    STATUS rentalStatus;
    RentalReport * rentalDetails;

    public:
        RentalData(STATUS rentalStatus,double travelledDistance, double userCharge, double usedFuel, time_t startTime, time_t endTime);
        ~RentalData();
        int getRentalDataID()const;
        STATUS getRentalStatus()const;
        RentalReport * getRentalDetails()const;
        void updateRentalDetails(RentalReport * x);
        void toggleRentalStatus();

        friend std::ostream& operator<<(std::ostream& out, const RentalData& x);


};

#endif