#ifndef RentalReport_HPP
#define RentalReport_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Utility.hpp"
#include "RentalReport.hpp"

class RentalReport{

    static double totalUserCharge;
    static double avgTravelledDistance;
    static int avgRentalTime;
    static int totalRentals;
    
    double travelledDistance;
    double userCharge;
    double usedFuel;
    time_t startTime;
    time_t endTime;

    public:
        RentalReport(double travelledDistance, double userCharge, double usedFuel, time_t startTime, time_t endTime);
        ~RentalReport();
        double getTravelledDistance();
        double getAvgTravelledDistance();
        int getAvgRentalTime();
        int getTotalRentals();
        double getUsedFuel();
        double getUserCharge();
        double getTotalUserCharge();
        time_t getStartTime();
        time_t getEndTime();
        void updateTravelledDistance(double x);
        void updateUsedFuel(double x);
        void updateUserCharge(double x);
        void updateStartTime(time_t x);
        void updateEndTime(time_t x);
        void updateTotalUserCharge(double customerCharge, double oldcustomerCharge = 0);
        void updateAvgTravelledDistance(double travelledDistance,double oldtravelledDistance = 0);
        void updateAvgRentalTime(time_t oldTime_start = 0, time_t oldTime_end = 0);

        friend std::ostream& operator<<(std::ostream& out, const RentalReport& x);

};


#endif