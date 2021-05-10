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
        RentalData(STATUS rentalStatus,double travelledDistance, double userCharge, double usedFuel, Localization startPoint, Localization endPoint, time_t startTime, time_t endTime);
        ~RentalData();
        int getRentalDataID();
        STATUS getRentalStatus();
        RentalReport * getRentalDetails();
        void updateRentalDetails(RentalReport * x);
        void toggleRentalStatus();
        void notifyCustomer();

        friend std::ostream& operator<<(std::ostream& out, const RentalData& x);


};

#endif