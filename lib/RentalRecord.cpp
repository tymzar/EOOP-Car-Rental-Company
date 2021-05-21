#include "../include/RentalRecord.hpp"

        RentalRecord::~RentalRecord(){
                delete rentedCar;
                delete rentee;
                std::cout << "Rental data removed!"<<std::endl;
        }
        Car * RentalRecord::getRentedCar()const{
                return rentedCar;
        }
        Customer * RentalRecord::getRentee()const{
                return rentee;
        }
        void RentalRecord::updateRentedCar(Car * x){
                this->rentedCar = x;
        }
        void RentalRecord::updateRentee(Customer * x){
                this->rentee = x;
        }

        std::ostream& operator<<(std::ostream& out, const RentalRecord& x){
                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'O' for Rental Data overview and 'R' for Rental Report: (O/R)";

                while((print_type = getchar()))
                {
                        
                        if( print_type == 'O' || print_type == 'o'){
                                out << std::left<< std::setw(nameWidth) << "Rental ID:" << x.getRentalDataID() << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Rental Status:" << x.getRentalStatus() << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Rental Details:" << x.getRentalDetails()->getUserCharge() << "EUR..." << std::endl;   
                                out << std::left<< std::setw(nameWidth) << "Rental Rentee:" << x.getRentee()->getName() << " " << x.getRentee()->getSurname() << std::endl;   
                                out << std::left<< std::setw(nameWidth) << "Rental Car:" <<  x.getRentedCar()->getModel() << std::endl;   
                                break;
                        }else if( print_type == 'R' || print_type == 'r'){
                                out << std::left<< std::setw(nameWidth) << "Rental Report:" << std::endl;
                                out << *x.getRentalDetails();
                                break;
                        }else{
                                std::cout << "Input proper character! "<<std::endl;
                                std::cout << "Enter 'O' for Rental Data overview and 'R' for Rental Report: (O/R)";
                        }
                }
                return out;
        }