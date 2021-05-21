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
#include <fstream>
class CarRentalCompany{
    int carsAmount = 0;
    int customersAmount = 0;

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

        void inputCar();
        void inputCustomer();
        void inputEmployee();
        void inputRentalData();

        void removeCar(std::string VINnumber = "");
        void removeCustomer(std::string username = "");
        void removeEmployee(std::string phoneNumber = "");

        Car getCar(std::string VINnumber);
        Customer getCustomer(std::string username);
        Employee getEmployee(std::string phoneNumber);

        void updateCar(std::string VINnumber, Car& car );
        void updateCustomer(std::string username , Customer& customer);
        void updateEmployee(std::string phoneNumber , Employee& employee);

        // Function overload
        void updateCar();
        void updateCustomer();
        void updateEmployee();

        void addData();
        void removeData();
        void updateData();
        
        void saveData(std::string path);
        void loadData(DATA_TYPE type, std::string path);

        void findData(DATA_TYPE type, int memberDBID);

        void outData(std::ostream& out);

        void exportStatisticsToCSV();
        void getStatistics();
        int returnNumberOfCars();
        int returnNumberOfCustomers();

        void displayMenu();

        void printData();
        };

        void testing();

#endif