#ifndef Employee_HPP
#define Employee_HPP

using namespace std;

#include <bits/stdc++.h>
#include "utility.hpp"

class Employee{

    static Employee * mostCarsFueled;
    string name;
    string surname;
    int phoneNumber;
    int employeeID;
    int fueledCars;
    Localization currentLocalization;

    public:
        Employee();
        ~Employee();
        string getName();
        string getSurname();
        int getPhoneNumber();
        int getEmployeeID();
        int getFueledCars();
        Localization getCurrentLocalization();
        void updateName(string x);
        void updateSurname(string x);
        void updatePhoneNumber(int x);
        void updateEmployeeID(int x);
        void updateFueledCars(int x);
        void updateCurrentLocalization(Localization x);

        friend ostream& operator<<(std::ostream& out, const Employee& x);
};

#endif