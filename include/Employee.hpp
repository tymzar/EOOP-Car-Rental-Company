#ifndef Employee_HPP
#define Employee_HPP

#include <bits/stdc++.h>
#include "Utility.hpp"

class Employee{

    static int employeeAmount;
    static int totalCarsFueled;
    static Employee * mostCarsFueled;
    std::string name;
    std::string surname;
    std::string phoneNumber;
    int employeeID;
    int fueledCars;
    Localization currentLocalization;

    public:
        Employee(std::string name, std::string surname, std::string phoneNumber, int fueledCars, Localization currentLocalization);
        ~Employee();
        std::string getName();
        std::string getSurname();
        std::string getPhoneNumber()const;
        int getEmployeeID();
        int getFueledCars();
        Localization getCurrentLocalization();
        void updateName(std::string x);
        void updateSurname(std::string x);
        void updatePhoneNumber(std::string x);
        void updateFueledCars(int x);
        void updateCurrentLocalization(Localization x);

        bool operator==(const Employee& x);
        friend std::ostream& operator<<(std::ostream& out, const Employee& x);
};

#endif