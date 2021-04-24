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

        //
        void RentalReport::updateUsedFuel(double x){
                this->usedFuel = x;
        }
        void RentalReport::updateUserCharge(double x){
                this->userCharge = x;
                totalUserCharge +=x;
        }
        void RentalReport::updateStartPoint(Localization x){
                this->startPoint = x;
        }
        void RentalReport::updateEndPoint(Localization x){
                this->endPoint = x;
        }
        void RentalReport::updateStartTime(time_t x){
                this->startTime = x;
        }
        void RentalReport::updateEndTime(time_t x){
                this->endTime = x;
        }

        std::ostream& operator<<(std::ostream& out, const RentalReport& x){}

