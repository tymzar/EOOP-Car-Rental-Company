#include "../include/RentalData.hpp"

        int RentalData::totalRentals = 0;

        RentalData::RentalData(STATUS rentalStatus,double travelledDistance, double userCharge, double usedFuel, Localization startPoint, Localization endPoint, time_t startTime, time_t endTime):rentalStatus(rentalStatus), rentalDataID(++totalRentals)  {
                this->rentalDetails = new RentalReport(travelledDistance, userCharge, usedFuel, startPoint, endPoint, startTime, endTime );
                notifyCustomer();
                notifyNearestEmployee();
        }
        RentalData::~RentalData(){
                totalRentals--;
                delete rentalDetails;
                std::cout << "Rental data removed!"<<std::endl;
        }

        int RentalData::getRentalDataID(){ 
                return rentalDataID;
        }
        STATUS RentalData::getRentalStatus(){
                return rentalStatus;
        }
        RentalReport * RentalData::getRentalDetails(){
                return rentalDetails;
        }

        void RentalData::updateRentalDetails(RentalReport * x){
                this->rentalDetails = x;
        }

        void RentalData::toggleRentalStatus(){
               if(rentalStatus == (STATUS)1){
                       rentalStatus = (STATUS)0;
               }else{
                       std::cerr<<"Finished rental cannot be reopened!"<< std::endl;
               }
        }
        void RentalData::notifyNearestEmployee(){

                // CarRentalCompany find customers
                // findNearestEmployee(this->rentalDetails->getEndPoint().longitude, this->rentalDetails->getEndPoint().latitude);

        }

        void RentalData::notifyCustomer(){}

        std::ostream& operator<<(std::ostream& out, const RentalData& x){}

