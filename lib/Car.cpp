#include "../include/Car.hpp"




        Car::Car(){cout << "Car works!"<<endl;}
        Car::~Car(){}

        int Car::getCarID(){ return carID;}
        MANUFACTURER Car::getManufacturer(){return manufacturer;}
        string Car::getModel(){return model;}
        STATUS Car::getIsRented(){return isRented;}
        time_t Car::getTechnicalReview(){return technicalReview;}
        time_t Car::getLastRented(){ return lastRented;}
        Customer * Car::getLastRentee(){ return lastRentee;}
        int Car::getProductionYear(){return productionYear;}
        double Car::getAverageFuelConsumption(){return averageFuelConsumption;}
        double Car::getCarRange(){}

        void Car::updateCarID(int x){}
        void Car::updateManufacturer(MANUFACTURER x){}
        void Car::updateModel(string x){}
        void Car::updateTechnicalReview(time_t x){}
        void Car::updateLastRented(time_t x){}
        void Car::updateLastRentee(Customer x){}
        void Car::updateProductionYear(int x){}
        void Car::updateAverageFuelConsumption(double x){}
       
        void Car::toggleIsRented(){}
        void Car::printData(){}    

        ostream& operator<<(std::ostream& out, const Car& x){}
