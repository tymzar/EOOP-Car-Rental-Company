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

        std::ostream& operator<<(std::ostream& out, const RentalRecord& x){}