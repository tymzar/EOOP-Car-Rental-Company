#include "../include/Employee.hpp"


        Employee::Employee(){}
        Employee::~Employee(){}
        string Employee::getName(){}
        string Employee::getSurname(){}
        int Employee::getPhoneNumber(){}
        int Employee::getFueledCars(){}
        Localization Employee::getCurrentLocalization(){}
        void Employee::updateName(string x){}
        void Employee::updateSurname(string x){}
        void Employee::updatePhoneNumber(int x){}
        void Employee::updateEmployeeID(int x){}
        void Employee::updateFueledCars(int x){}
        void Employee::updateCurrentLocalization(Localization x){}

        ostream& operator<<(std::ostream& out, const Employee& x){}
