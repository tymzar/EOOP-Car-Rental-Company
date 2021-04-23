#include "../include/CarRentalCompany.hpp"



        CarRentalCompany::CarRentalCompany(){ cout << "CRC works!"<<endl;}
        CarRentalCompany::~CarRentalCompany(){}

        void CarRentalCompany::addCar(Car& car){}
        void CarRentalCompany::addCustomer(Customer& customer){}
        void CarRentalCompany::addEmployee(Employee& employee){}
        void CarRentalCompany::addRentalData(RentalRecord& rentalData){}

        void CarRentalCompany::removeCar(int carDBID){}
        void CarRentalCompany::removeCustomer(int customerDBID){}
        void CarRentalCompany::removeEmployee(int employeeDBID){}

        // Car* CarRentalCompany::getCar(int carDBID){}
        // Customer* CarRentalCompany::getCustomer(int customerDBID){}
        // Employee* CarRentalCompany::getEmployee(int employeeDBID){}
        // RentalData*CarRentalCompany:: getRentalData(int rentalDataDBID){}

        void CarRentalCompany::updateCar(int carDBID){}
        void CarRentalCompany::updateCustomer(int customerDBID){}
        void CarRentalCompany::updateEmployee(int employeeDBID){}
        void CarRentalCompany::updateRentalData(int rentalDataDBID){}

        void CarRentalCompany::addData(DATA_TYPE type){}
        void CarRentalCompany::removeData(DATA_TYPE type, int memberDBID){}
        void CarRentalCompany::updateData(DATA_TYPE type, int memberDBID){}
        
        void CarRentalCompany::saveData(string path){}
        void CarRentalCompany::loadData(DATA_TYPE type, string path){}

        void CarRentalCompany::findData(DATA_TYPE type, int memberDBID){}
        void CarRentalCompany::outData(ostream& out){}

        void CarRentalCompany::exportStatisticsToXLSX(){}
        void CarRentalCompany::getStatistics(){}
        int CarRentalCompany::returnNumberOfCars(){ return carsAmount;}
        int CarRentalCompany::returnNumberOfCustomers(){ return customersAmount;}


        void CarRentalCompany::printData(DATA_TYPE type, int memberDBID){}

        // ostream& operator<<(ostream& out, const CarRentalCompany& x){}


