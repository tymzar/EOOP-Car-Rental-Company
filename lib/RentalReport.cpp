#include "../include/RentalReport.hpp"

        /**
         * @brief Initialization of the static variables
         * 
         */
        double RentalReport::totalUserCharge = 0.0;
        double RentalReport::avgTravelledDistance = 0.0;
        int RentalReport::avgRentalTime = 0;
        int RentalReport::totalRentals = 0;

        /**
         * @brief Construct a new RentalReport which consists all the data
         * 
         * @param travelledDistance Car travelled distance 
         * @param userCharge Cost of the rental
         * @param usedFuel Fuel burned during the rental
         * @param startPoint Coordinates on the car at the beginning of the rental
         * @param endPoint Coordinates on the car at the finish of the rental
         * @param startTime Time when the rental started
         * @param endTime Time when the rental finished
         * 
         */
        RentalReport::RentalReport(double travelledDistance, double userCharge, double usedFuel, Localization startPoint, Localization endPoint, time_t startTime, time_t endTime): travelledDistance(travelledDistance), userCharge(userCharge), usedFuel(usedFuel), startPoint(startPoint), endPoint(endPoint), startTime(startTime), endTime(endTime) {
                totalRentals++;
                updateTotalUserCharge(userCharge);
                updateAvgTravelledDistance(travelledDistance);
                updateAvgRentalTime();
        }
        
        /**
         * @brief Destroy the RentalReport and updates all static variables
         * 
         */
        RentalReport::~RentalReport(){
                std::cout<< "Rental Report Removed!"<<std::endl;
                updateTotalUserCharge(0,userCharge);
                updateAvgTravelledDistance(0, travelledDistance);
                updateAvgRentalTime(startTime, endTime);
                totalRentals--;
        }

        /**
         * @brief Get method for travrlledDistance
         * 
         * @return travrlledDistance 
         */
        double RentalReport::getTravelledDistance(){return travelledDistance;}
        /**
         * @brief Get method for usedFuel
         * 
         * @return usedFuel 
         */
        double RentalReport::getUsedFuel(){return usedFuel;}
        /**
         * @brief Get method for userCharge
         * 
         * @return userCharge 
         */
        double RentalReport::getUserCharge(){return userCharge;}
        /**
         * @brief Get method for startPoint
         * 
         * @return startPoint 
         */
        Localization RentalReport::getStartPoint(){return startPoint;}
        /**
         * @brief Get method for endPoint
         * 
         * @return endPoint 
         */
        Localization RentalReport::getEndPoint(){return endPoint;}
        /**
         * @brief Get method for endTime
         * 
         * @return endTime 
         */
        time_t RentalReport::getStartTime(){return endTime;}
        /**
         * @brief Get method for endTime
         * 
         * @return endTime 
         */
        time_t RentalReport::getEndTime(){return endTime;}
        /**
         * @brief Get method for totalUserCharge
         * 
         * @return totalUserCharge 
         */
        double RentalReport::getTotalUserCharge(){return totalUserCharge;}
        /**
         * @brief Get method for avgTravelledDistance
         * 
         * @return avgTravelledDistance 
         */
        double RentalReport::getAvgTravelledDistance(){return avgTravelledDistance;}
        /**
         * @brief Get method for avgRentalTime
         * 
         * @return avgRentalTime 
         */
        int RentalReport::getAvgRentalTime(){return avgRentalTime;}
        /**
         * @brief Get method for totalRentals
         * 
         * @return totalRentals 
         */
        int RentalReport::getTotalRentals(){return totalRentals;}

        /**
         * @brief Method responsible for updating value of travelledDistance and static variable associated with it (avgTravelledDistance)
         * 
         * @param travelledDistance 
         */
        void RentalReport::updateTravelledDistance(double x){
                double temp = this->userCharge;
                this->travelledDistance = x;
                updateAvgTravelledDistance(x, temp);
        }

        /**
         * @brief Method responsible for updating value of usedFuel
         * 
         * @param usedFuel 
         */
        void RentalReport::updateUsedFuel(double x){
                this->usedFuel = x;
        }

        /**
         * @brief Method responsible for updating value of userCharge and static variable associated with it (totalUserCharge)
         * 
         * @param userCharge
         */
        void RentalReport::updateUserCharge(double x){
                double temp = this->userCharge;
                this->userCharge = x;
                updateTotalUserCharge(x, temp);
        }

        /**
         * @brief Method responsible for updating value of startPoint
         * 
         * @param startPoint
         */
        void RentalReport::updateStartPoint(Localization x){
                this->startPoint = x;
        }

        /**
         * @brief Method responsible for updating value of endPoint
         * 
         * @param endPoint
         */
        void RentalReport::updateEndPoint(Localization x){
                this->endPoint = x;
        }

        /**
         * @brief Method responsible for updating value of startTime and static variable associated with it (avgRentalTime)
         * 
         * @param startTime 
         */
        void RentalReport::updateStartTime(time_t x){
                time_t temp = this->startTime;
                this->startTime = x;
                updateAvgRentalTime(temp, endTime);
        }

        /**
         * @brief Method responsible for updating value of endTime and static variable associated with it (avgRentalTime)
         * 
         * @param endTime 
         */
        void RentalReport::updateEndTime(time_t x){
                time_t temp = this->endTime;
                this->endTime = x;
                updateAvgRentalTime(startTime, temp);
        }

        /**
         * @brief Method responsible for updating value of static totalUserCharge
         * 
         * @param customerCharge Charge for rental
         * @param oldcustomerCharge Old value in case of update
         */
        void RentalReport::updateTotalUserCharge(double customerCharge,double oldcustomerCharge){
                if(oldcustomerCharge != 0){
                        totalUserCharge -= oldcustomerCharge;    
                }
                if(travelledDistance != 0){
                        totalUserCharge += customerCharge;
                }
        }

        /**
         * @brief Method responsible for updating value of static avgTravelledDistance (two formulas for manipulating the average)
         * 
         * @param travelledDistance Travelled distanc form rental
         * @param oldtravelledDistance Old value in case of update
         */
        void RentalReport::updateAvgTravelledDistance(double travelledDistance,double oldtravelledDistance){
                if(oldtravelledDistance != 0){
                        avgTravelledDistance = ((avgTravelledDistance * totalRentals) - oldtravelledDistance) / (totalRentals - 1);
                }
                if(travelledDistance != 0){
                        avgTravelledDistance = (avgTravelledDistance*(totalRentals-1)+ travelledDistance)/totalRentals;   
                }         
        }

        /**
         * @brief Method responsible for updating value of static avgRentalTime (two formulas for manipulating the average)
         * 
         * @param oldTime_start Time of rental beginning
         * @param oldTime_end Time of rental finish
         */
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

        /**
         * @brief Overload of the operator<< used to clearly display report data
         * 
         * @param out ofstream variable to pass data
         * @param x poiner to the Rentalreport
         * @return ostream& 
         */
        std::ostream& operator<<(std::ostream& out, const RentalReport& x){
                const int nameWidth     = 25;
                
                out << std::left<< std::setw(nameWidth) << "Car travelled distace:" << x.travelledDistance << std::endl;
                out << std::left<< std::setw(nameWidth) << "Fuel burned:" << x.usedFuel << std::endl;
                out << std::left<< std::setw(nameWidth) << "Customer paid:" << x.userCharge << std::endl;
                out << std::left<< std::setw(nameWidth) << "Rental started at:" << timeStampToTime(x.startTime) << std::endl;
                out << std::left<< std::setw(nameWidth) << "Rental ended at:" << timeStampToTime(x.endTime) << std::endl;
                out << std::left<< std::setw(nameWidth) << "Car started form:" << x.startPoint.latitude << ", " <<x.startPoint.longitude << std::endl;
                out << std::left<< std::setw(nameWidth) << "Car ended at:"  << x.endPoint.latitude << ", " <<x.endPoint.longitude << std::endl;

                return out;
        }

