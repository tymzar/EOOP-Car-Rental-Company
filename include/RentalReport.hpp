#ifndef RentalReport_HPP
#define RentalReport_HPP

using namespace std;

#include <bits/stdc++.h>
#include "utility.hpp"
#include "RentalReport.hpp"




class RentalReport{

    static int totalUserCharge;
    static int avgTravelledDistance;
    static int avgRentalTime;
    double travelledDistance;
    double userCharge;
    double usedFuel;
    Localization startPoint;
    Localization endPoint;
    time_t startTime;
    time_t endTime;

    public:
        RentalReport();
        ~RentalReport();
        double getTravelledDistance();
        double getUsedFuel();
        double getUserCharge();
        Localization getStartPoint();
        Localization getEndPoint();
        time_t getStartTime();
        time_t getEndTime();
        void updateTravelledDistance(double x);
        void updateUsedFuel(double x);
        void updateUserCharge(double x);
        void updateStartPoint(Localization x);
        void updateEndPoint(Localization x);
        void updateStartTime(time_t x);
        void updateEndTime(time_t x);
        void avgTravelledDistance(time_t x);

        friend ostream& operator<<(std::ostream& out, const RentalReport& x);

};


#endif