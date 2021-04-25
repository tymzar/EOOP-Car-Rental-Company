#include "../include/Employee.hpp"

        int Employee::employeeAmount = 0;
        int Employee::totalCarsFueled = 0;
        Employee * Employee::mostCarsFueled = nullptr;

        Employee::Employee(){}
        Employee::~Employee(){}
        
        std::string Employee::getName(){
                return name;
        }
        std::string Employee::getSurname(){
                return surname;
        }
        std::string Employee::getPhoneNumber(){
                return phoneNumber;
        }
        int Employee::getFueledCars(){
                return fueledCars;
        }
        Localization Employee::getCurrentLocalization(){}
        void Employee::updateName(std::string x){
                this->name = x;
        }
        void Employee::updateSurname(std::string x){
                this->surname = x;
        }
        void Employee::updatePhoneNumber(std::string x){
                this->phoneNumber = x;
        }
        void Employee::updateFueledCars(int x){
                this->fueledCars += x;
                totalCarsFueled += x;
        }
        void Employee::updateCurrentLocalization(Localization x){
                this->currentLocalization = x;
        }

        std::ostream& operator<<(std::ostream& out, const Employee& x){}
