#include "../include/CarRentalCompany.hpp"



        CarRentalCompany::CarRentalCompany(){ std::cout << "CRC created!"<<std::endl;}
        CarRentalCompany::~CarRentalCompany(){
              std::cout << "CRC shutdown!"<<std::endl;  
        }

        struct carUnique {
                bool operator() (Car first, Car second)
                { return (first.getVIN() == second.getVIN()); }
        };

        struct employeeUnique {
                bool operator() (Employee first, Employee second)
                { return (first.getPhoneNumber() == second.getPhoneNumber()); }
        };

        void CarRentalCompany::addCar(Car& car){
                this->Cars.push_back(car);
                this->Cars.unique(carUnique());
        }
        void CarRentalCompany::addCustomer(Customer& customer){
                this->Customers.push_back(customer);
        }
        void CarRentalCompany::addEmployee(Employee& employee){
                this->Employees.push_back(employee);
                this->Employees.unique(employeeUnique());
        }
        void CarRentalCompany::addRentalData(RentalRecord& rentalData){
                this->RentalHistory.push_back(rentalData);

        }

        void CarRentalCompany::removeCar(std::string VINnumber){
                std::list<Car>::const_iterator res;
                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == VINnumber){
                                res = iterator;
                        }
                }
                Cars.erase(res);
        }
        void CarRentalCompany::removeCustomer(std::string username){
                std::list<Customer>::const_iterator res;
                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == username){
                                res = iterator;
                        }
                }
                Customers.erase(res);
        }
        void CarRentalCompany::removeEmployee(std::string phoneNumber){
                std::list<Employee>::const_iterator res;
                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                        if( iterator->getPhoneNumber() == phoneNumber){
                                res = iterator;
                        }
                }
                Employees.erase(res);
        }

        Car CarRentalCompany::getCar(std::string VINnumber){
                std::list<Car>::const_iterator res = Cars.begin();
                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == VINnumber){
                                res = iterator;
                                return *res;
                        }
                }
                return *res;
        }
        Customer CarRentalCompany::getCustomer(std::string username){
                std::list<Customer>::const_iterator res;
                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == username){
                                res = iterator;
                                return *res;
                        }
                }   
                return *res;       
        }
        Employee CarRentalCompany::getEmployee(std::string phoneNumber){
                std::list<Employee>::const_iterator res;
                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                        if( iterator->getPhoneNumber() == phoneNumber){
                                res = iterator;
                                return *res;
                        }
                }   
                return *res;   
        }

        void CarRentalCompany::updateCar(std::string VINnumber, Car& car){
                removeCar(VINnumber);
                addCar(car);
        }
        void CarRentalCompany::updateCustomer(std::string username, Customer& customer){
                removeCustomer(username);
                addCustomer(customer);
        }
        void CarRentalCompany::updateEmployee(std::string phoneNumber, Employee& emplyee){
                removeEmployee(phoneNumber);
                addEmployee(emplyee);
        }

        void CarRentalCompany::addData(DATA_TYPE type){}
        void CarRentalCompany::removeData(DATA_TYPE type, int memberDBID){}
        void CarRentalCompany::updateData(DATA_TYPE type, int memberDBID){}
        
        void CarRentalCompany::saveData(std::string path){}
        void CarRentalCompany::loadData(DATA_TYPE type, std::string path){}

        void CarRentalCompany::findData(DATA_TYPE type, int memberDBID){}
        void CarRentalCompany::outData(std::ostream& out){}

        // void CarRentalCompany::exportStatisticsToXLSX(){}
        // void CarRentalCompany::getStatistics(){}
        int CarRentalCompany::returnNumberOfCars(){ return carsAmount;}
        int CarRentalCompany::returnNumberOfCustomers(){ return customersAmount;}


        void CarRentalCompany::printData(DATA_TYPE type, int memberDBID){}



