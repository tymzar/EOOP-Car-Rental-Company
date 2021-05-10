#include "../include/RentalRecord.hpp"

        RentalRecord::~RentalRecord(){
                delete rentedCar;
                delete rentee;
                std::cout << "Rental data removed!"<<std::endl;
        }
        Car * RentalRecord::getRentedCar(){
                return rentedCar;
        }
        Customer * RentalRecord::getRentee(){
                return rentee;
        }
        void RentalRecord::updateRentedCar(Car * x){
                this->rentedCar = x;
        }
        void RentalRecord::updateRentee(Customer * x){
                this->rentee = x;
        }

        std::ostream& operator<<(std::ostream& out, RentalRecord& x){

                const char separator    = ' ';
                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'O' for Rental Data overview and 'R' for Rental Report: (O/R)";

                while(print_type = getchar())
                {
                        // getchar();
                        
                        // if( print_type == 'D' || print_type == 'd'){
                        //         out << std::left<< std::setw(nameWidth) << "Rental ID:" << x.getRentalDataID() << std::endl;
                        //         out << std::left<< std::setw(nameWidth) << "Rental Status:" << x.get << std::endl;
                        //         out << std::left<< std::setw(nameWidth) << "Rental Details:" << x.rentalDetails->getUserCharge() << "EUR..." << std::endl;   
                        //         break;
                        // }else if( print_type == 'S' || print_type == 's'){
                        //         out << std::left<< std::setw(nameWidth) << "Rental Report:" << std::endl;
                        //         out << x.rentalDetails;
                        //         break;
                        // }else{
                        //         std::cout << "Input proper character! "<<std::endl;
                        //         std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";
                        // }
                }
                return out;
        }