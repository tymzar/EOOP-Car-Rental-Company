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
    std::string* model;
    std::string* VINnumber;
    STATUS isRented;
    time_t technicalReview;
    time_t lastRented;
    Customer * lastRentee;
    int productionYear;
    double fuelLevel;
    double averageFuelConsumption;

    public:

        Car(std::string model, std::string VINnumber, STATUS isRented, time_t lastRented, Customer * lastRentee, double averageFuelConsumption);
        ~Car();

        int getCarID();
        MANUFACTURER getManufacturer();
        std::string getModel();
        STATUS getIsRented();
        time_t getTechnicalReview();
        time_t getLastRented();
        Customer * getLastRentee();
        int getProductionYear();
        double getAverageFuelConsumption();
        double getCarRange() const;

        void updateCarID(int x);
        void updateManufacturer(MANUFACTURER x);
        void updateModel(std::string x);
        void updateTechnicalReview(time_t x);
        void updateLastRented(time_t x);
        void updateLastRentee(Customer * x);
        void updateProductionYear(int x);
        void updateAverageFuelConsumption(double x);
        void toggleIsRented();

        friend std::ostream& operator<<(std::ostream& out, const Car& x);

};


#endif