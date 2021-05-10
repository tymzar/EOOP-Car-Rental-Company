#include "../include/RentalData.hpp"

        int RentalData::totalRentals = 0;

        RentalData::RentalData(STATUS rentalStatus,double travelledDistance, double userCharge, double usedFuel, Localization startPoint, Localization endPoint, time_t startTime, time_t endTime):rentalStatus(rentalStatus), rentalDataID(++totalRentals)  {
                this->rentalDetails = new RentalReport(travelledDistance, userCharge, usedFuel, startPoint, endPoint, startTime, endTime );
                notifyCustomer();
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

        void RentalData::notifyCustomer(){}

        std::ostream& operator<<(std::ostream& out, const RentalData& x){

                const char separator    = ' ';
                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'O' for Rental Data overview and 'R' for Rental Report: (O/R)";

                while(print_type = getchar())
                {
                        getchar();
                        
                        if( print_type == 'D' || print_type == 'd'){
                                out << std::left<< std::setw(nameWidth) << "Rental ID:" << x.rentalDataID << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Rental Status:" << x.rentalStatus << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Rental Details:" << x.rentalDetails->getUserCharge() << "EUR..." << std::endl;   
                                break;
                        }else if( print_type == 'S' || print_type == 's'){
                                out << std::left<< std::setw(nameWidth) << "Rental Report:" << std::endl;
                                out << x.rentalDetails;
                                break;
                        }else{
                                std::cout << "Input proper character! "<<std::endl;
                                std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";
                        }
                }
                return out;

        }

