#include "../include/Employee.hpp"

        int Employee::employeeAmount = 0;
        Employee * Employee::mostCarsFueled = nullptr;

        Employee::Employee(){}
        Employee::~Employee(){}
        std::string Employee::getName(){}
        std::string Employee::getSurname(){}
        int Employee::getPhoneNumber(){}
        int Employee::getFueledCars(){}
        Localization Employee::getCurrentLocalization(){}
        void Employee::updateName(std::string x){}
        void Employee::updateSurname(std::string x){}
        void Employee::updatePhoneNumber(int x){}
        void Employee::updateEmployeeID(int x){}
        void Employee::updateFueledCars(int x){}
        void Employee::updateCurrentLocalization(Localization x){}

        std::ostream& operator<<(std::ostream& out, const Employee& x){}
