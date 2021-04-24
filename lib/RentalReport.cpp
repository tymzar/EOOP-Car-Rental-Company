#include "../include/RentalReport.hpp"

        

        double RentalReport::totalUserCharge = 0.0;
        double RentalReport::avgTravelledDistance = 0.0;
        int RentalReport::avgRentalTime = 0;
        int RentalReport::totalRentals = 0;

        RentalReport::RentalReport(double travelledDistance, double userCharge, double usedFuel, Localization startPoint, Localization endPoint, time_t startTime, time_t endTime): travelledDistance(travelledDistance), userCharge(userCharge), usedFuel(usedFuel), startPoint(startPoint), endPoint(endPoint), startTime(startTime), endTime(endTime) {
                totalRentals++;
                // updateTotalUserCharge(userCharge);
                updateAvgTravelledDistance(travelledDistance);
                // updateAvgRentalTime();
        }
        RentalReport::~RentalReport(){
                std::cout<< "Rental Report Removed!"<<std::endl;
                updateTotalUserCharge(0,userCharge);
                updateAvgTravelledDistance(0, travelledDistance);
                updateAvgRentalTime(startTime, endTime);
                totalRentals--;
        }
        double RentalReport::getTravelledDistance(){return travelledDistance;}
        double RentalReport::getUsedFuel(){return usedFuel;}
        double RentalReport::getUserCharge(){return userCharge;}
        Localization RentalReport::getStartPoint(){return startPoint;}
        Localization RentalReport::getEndPoint(){return endPoint;}
        time_t RentalReport::getStartTime(){return endTime;}
        time_t RentalReport::getEndTime(){return endTime;}
        double RentalReport::getTotalUserCharge(){return totalUserCharge;}
        double RentalReport::getAvgTravelledDistance(){return avgTravelledDistance;}
        int RentalReport::getAvgRentalTime(){return avgRentalTime;}
        int RentalReport::getTotalRentals(){return totalRentals;}

        void RentalReport::updateTravelledDistance(double x){
                double temp = this->userCharge;
                this->travelledDistance = x;
                updateAvgTravelledDistance(x, temp);
        }
        void RentalReport::updateUsedFuel(double x){
                this->usedFuel = x;
        }
        void RentalReport::updateUserCharge(double x){
                double temp = this->userCharge;
                this->userCharge = x;
                updateTotalUserCharge(x, temp);
        }
        void RentalReport::updateStartPoint(Localization x){
                this->startPoint = x;
        }
        void RentalReport::updateEndPoint(Localization x){
                this->endPoint = x;
        }
        void RentalReport::updateStartTime(time_t x){
                time_t temp = this->startTime;
                this->startTime = x;
                updateAvgRentalTime(temp, endTime);
        }
        void RentalReport::updateEndTime(time_t x){
                time_t temp = this->endTime;
                this->endTime = x;
                updateAvgRentalTime(startTime, temp);
        }

        void RentalReport::updateTotalUserCharge(double customerCharge,double oldcustomerCharge){
                if(oldcustomerCharge != 0){
                        totalUserCharge -= oldcustomerCharge;    
                }
                if(travelledDistance != 0){
                        totalUserCharge += customerCharge;
                }
        }
        void RentalReport::updateAvgTravelledDistance(double travelledDistance,double oldtravelledDistance){
                if(oldtravelledDistance != 0){
                        avgTravelledDistance = ((avgTravelledDistance * totalRentals) - oldtravelledDistance) / (totalRentals - 1);
                }
                if(travelledDistance != 0){
                        avgTravelledDistance = (avgTravelledDistance*(totalRentals-1)+ travelledDistance)/totalRentals;   
                }         
        }
        void RentalReport::updateAvgRentalTime(time_t oldTime_start, time_t oldTime_end){

                if(oldTime_start != 0 || oldTime_end != 0){
                    int timeDiff = oldTime_end - oldTime_start;
                    avgRentalTime = ((avgRentalTime * totalRentals) - timeDiff) / (totalRentals - 1);
                }
                if(startTime != oldTime_start && endTime != oldTime_end){
                        int timeDiff = endTime - startTime;
                        avgRentalTime = (avgRentalTime*(totalRentals-1)+ timeDiff)/totalRentals; 
                }           
        }

        std::ostream& operator<<(std::ostream& out, const RentalReport& x){}

