#pragma once
#ifndef Car_HPP
#define Car_HPP

#include <string>
#include <iostream>
#include "Utility.hpp"
#include "Customer.hpp"

class Car{

    static int carsRented;

    int carID;

    MANUFACTURER manufacturer;
    string model;
    string VINnumber;
    STATUS isRented;
    time_t technicalReview;
    time_t lastRented;
    Customer * lastRentee;
    int productionYear;
    double averageFuelConsumption;

    public:

        Car();
        ~Car();

        int getCarID();
        MANUFACTURER getManufacturer();
        string getModel();
        STATUS getIsRented();
        time_t getTechnicalReview();
        time_t getLastRented();
        Customer * getLastRentee();
        int getProductionYear();
        double getAverageFuelConsumption();
        double getCarRange();

        void updateCarID(int x);
        void updateManufacturer(MANUFACTURER x);
        void updateModel(string x);
        void updateTechnicalReview(time_t x);
        void updateLastRented(time_t x);
        void updateLastRentee(Customer x);
        void updateProductionYear(int x);
        void updateAverageFuelConsumption(double x);
       
        void toggleIsRented();
        void printData();    

        friend ostream& operator<<(std::ostream& out, const Car& x);

};


#endif