#pragma once
#ifndef Customer_HPP
#define Customer_HPP

using namespace std;

#include <list>
#include <string>
#include <iostream>
#include "RentalData.hpp"
#include "Utility.hpp"

class Customer{

    static int activeCustomersAmount;
    int userID;
    string usename;
    string name;
    string surname;
    double accountBalace;
    list<RentalData> userRentalHistory;
    STATUS isAnyRenalActive;
    STATUS isAccountActive;

    public:
        Customer();
        ~Customer();
        int getUserID();
        string getUsername();
        string getName();
        string getSurname();
        double getAccountBalace();
        list<RentalData> getUserRentalHistory();
        STATUS getIsAnyRenalActive();
        STATUS getIsAccountActive();
        void updateUserID(int x);
        void updateUsername(string x);
        void updateName(string x);
        void updateSurname(string x);
        void updateAccountBalace(double x);
        void updateUserRentalHistory(RentalData& x);
        void toggleIsAnyRenalActive();
        void toggleIsAccountActive();
        void addUserRentalHistory(RentalData* rentalData);
        void printAllCustomerData(); // all data + last rental
        void printUserRentalHistory();
        void printData(OUT_CUSTOMER type);
        void outData(ostream& out);
        
        friend ostream& operator<<(ostream& out, const Customer& x);
};

#endif