#ifndef CarRentalCompany_HPP
#define CarRentalCompany_HPP

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

    std::list<Car> Cars;
    std::list<Customer> Customers;
    std::list<Employee> Employees;
    std::list<RentalRecord> RentalHistory;

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
        
        void saveData(std::string path);
        void loadData(DATA_TYPE type, std::string path);

        void findData(DATA_TYPE type, int memberDBID);




        void outData(std::ostream& out);

        void exportStatisticsToXLSX();
        void getStatistics();
        int returnNumberOfCars();
        int returnNumberOfCustomers();


        void printData(DATA_TYPE type, int memberDBID);
        friend std::ostream& operator<<(std::ostream& out, const CarRentalCompany& x);
};

#endif