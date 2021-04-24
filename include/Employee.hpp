#ifndef Employee_HPP
#define Employee_HPP

#include <bits/stdc++.h>
#include "Utility.hpp"

class Employee{

    static int employeeAmount;
    static Employee * mostCarsFueled;
    std::string name;
    std::string surname;
    int phoneNumber;
    int employeeID;
    int fueledCars;
    Localization currentLocalization;

    public:
        Employee();
        ~Employee();
        std::string getName();
        std::string getSurname();
        int getPhoneNumber();
        int getEmployeeID();
        int getFueledCars();
        Localization getCurrentLocalization();
        void updateName(std::string x);
        void updateSurname(std::string x);
        void updatePhoneNumber(int x);
        void updateEmployeeID(int x);
        void updateFueledCars(int x);
        void updateCurrentLocalization(Localization x);

        friend std::ostream& operator<<(std::ostream& out, const Employee& x);
};

#endif