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
    int userID;
    std::string usename;
    std::string name;
    std::string surname;
    double accountBalace;
    std::list<RentalData> userRentalHistory;
    STATUS isAnyRenalActive;
    STATUS isAccountActive;

    public:
        Customer();
        ~Customer();
        int getUserID();
        std::string getUsername();
        std::string getName();
        std::string getSurname();
        double getAccountBalace();
        std::list<RentalData> getUserRentalHistory();
        STATUS getIsAnyRenalActive();
        STATUS getIsAccountActive();
        void updateUserID(int x);
        void updateUsername(std::string x);
        void updateName(std::string x);
        void updateSurname(std::string x);
        void updateAccountBalace(double x);
        void updateUserRentalHistory(RentalData& x);
        void toggleIsAnyRenalActive();
        void toggleIsAccountActive();
        void addUserRentalHistory(RentalData* rentalData);
        void printAllCustomerData(); // all data + last rental
        void printUserRentalHistory();
        void printData(OUT_CUSTOMER type);
        void outData(std::ostream& out);
        
        friend std::ostream& operator<<(std::ostream& out, const Customer& x);
};

#endif