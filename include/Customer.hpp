#pragma once
#ifndef Customer_HPP
#define Customer_HPP

#include <list>
#include <string>
#include <iostream>
#include "RentalData.hpp"
#include "Utility.hpp"

class Customer{

    static int activeCustomersAmount;

    std::string username;
    std::string name;
    std::string surname;
    double accountBalace;
    std::list<RentalData> userRentalHistory;
    STATUS isAnyRenalActive;
    STATUS isAccountActive;

    public:
        Customer(std::string username,std::string name,std::string surname,double accountBalace);
        ~Customer();
        std::string getUsername()const;
        std::string getName();
        std::string getSurname();
        double getAccountBalace();
        std::list<RentalData> getUserRentalHistory();
        STATUS getIsAnyRenalActive();
        STATUS getIsAccountActive();
        int getactiveCustomersAmount();
        void updateUsername(std::string x);
        void updateName(std::string x);
        void updateSurname(std::string x);
        void updateAccountBalace(double x);
        void toggleIsAnyRenalActive();
        void toggleIsAccountActive();
        void addUserRentalHistory(RentalData rentalData);
        void printAllCustomerData(); // all data + last rental
        void printUserRentalHistory();
        void printData(OUT_CUSTOMER type);
        void outData(std::ostream& out);
        
        bool operator==(const Customer& x);
        friend std::ostream& operator<<(std::ostream& out, const Customer& x);
};

#endif