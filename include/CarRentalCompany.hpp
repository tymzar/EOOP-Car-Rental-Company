#ifndef CarRentalCompany_HPP
#define CarRentalCompany_HPP

using namespace std;

#include <list>
#include <string>
#include <iostream>
#include "Utility.hpp"
#include "Employee.hpp"
#include "Customer.hpp"
#include "Car.hpp"
#include "RentalRecord.hpp"


class CarRentalCompany{
    int carsAmount;
    int customersAmount;

    list<Car> Cars;
    list<Customer> Customers;
    list<Employee> Employees;
    list<RentalRecord> RentalHistory;

    public:

        CarRentalCompany();
        ~CarRentalCompany();

        void addCar(Car& car);
        void addCustomer(Customer& customer);
        void addEmployee(Employee& employee);
        void addRentalData(RentalRecord& rentalData);

        void removeCar(int carDBID);
        void removeCustomer(int customerDBID);
        void removeEmployee(int employeeDBID);

        Car* getCar(int carDBID);
        Customer* getCustomer(int customerDBID);
        Employee* getEmployee(int employeeDBID);
        RentalRecord* getRentalData(int rentalDataDBID);

        void updateCar(int carDBID);
        void updateCustomer(int customerDBID);
        void updateEmployee(int employeeDBID);
        void updateRentalData(int rentalDataDBID);

        void addData(DATA_TYPE type);
        void removeData(DATA_TYPE type, int memberDBID);
        void updateData(DATA_TYPE type, int memberDBID);
        
        void saveData(string path);
        void loadData(DATA_TYPE type, string path);

        void findData(DATA_TYPE type, int memberDBID);




        void outData(ostream& out);

        void exportStatisticsToXLSX();
        void getStatistics();
        int returnNumberOfCars();
        int returnNumberOfCustomers();


        void printData(DATA_TYPE type, int memberDBID);
        friend ostream& operator<<(ostream& out, const CarRentalCompany& x);
};

#endif