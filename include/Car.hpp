#pragma once
#ifndef Car_HPP
#define Car_HPP

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "Customer.hpp"
class Car{

    static int carsRented;

    std::string model;
    std::string VINnumber;
    STATUS isRented;
    time_t lastRented;
    Customer * lastRentee;
    int productionYear;
    double fuelLevel;
    double averageFuelConsumption;

    public:

        Car(std::string model, std::string VINnumber, STATUS isRented, time_t lastRented, Customer * lastRentee, double averageFuelConsumption);
        ~Car();

        std::string getModel()const;
        std::string getVIN()const;
        STATUS getIsRented();
        time_t getLastRented();
        Customer * getLastRentee();
        int getProductionYear();
        int getCarsRented(){
            return carsRented;
        }
        double getAverageFuelConsumption();
        double getCarRange() const;

        void updateModel(std::string x);
        void updateLastRented(time_t x);
        void updateLastRentee(Customer * x);
        void updateProductionYear(int x);
        void updateAverageFuelConsumption(double x);
        void toggleIsRented();

        bool operator==(const Car& x);
        friend std::ostream& operator<<(std::ostream& out, const Car& x);

};


#endif