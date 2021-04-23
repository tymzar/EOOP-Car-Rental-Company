#include "../include/RentalReport.hpp"

        RentalReport::RentalReport(){}
        RentalReport::~RentalReport(){}
        double RentalReport::getTravelledDistance(){}
        double RentalReport::getUsedFuel(){}
        double RentalReport::getUserCharge(){}
        Localization RentalReport::getStartPoint(){}
        Localization RentalReport::getEndPoint(){}
        time_t RentalReport::getStartTime(){}
        time_t RentalReport::getEndTime(){}
        void RentalReport::updateTravelledDistance(double x){}
        void RentalReport::updateUsedFuel(double x){}
        void RentalReport::updateUserCharge(double x){}
        void RentalReport::updateStartPoint(Localization x){}
        void RentalReport::updateEndPoint(Localization x){}
        void RentalReport::updateStartTime(time_t x){}
        void RentalReport::updateEndTime(time_t x){}

        ostream& operator<<(std::ostream& out, const RentalReport& x){}

