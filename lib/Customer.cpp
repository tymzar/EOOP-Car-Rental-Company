
#include "../include/Customer.hpp"


        Customer::Customer(){}
        Customer::~Customer(){}
        int Customer::getUserID(){ return userID;}
        std::string Customer::getUsername(){return usename;}
        std::string Customer::getName(){return name;}
        std::string Customer::getSurname(){return surname;}
        double Customer::getAccountBalace(){ return accountBalace;}
        std::list<RentalData> Customer::getUserRentalHistory(){return userRentalHistory;}
        STATUS Customer::getIsAnyRenalActive(){return isAnyRenalActive;}
        STATUS Customer::getIsAccountActive(){return isAccountActive;}
        void Customer::updateUserID(int x){}
        void Customer::updateUsername(std::string x){}
        void Customer::updateName(std::string x){}
        void Customer::updateSurname(std::string x){}
        void Customer::updateAccountBalace(double x){}
        void Customer::updateUserRentalHistory(RentalData& x){}
        void Customer::toggleIsAnyRenalActive(){}
        void Customer::toggleIsAccountActive(){}
        void Customer::addUserRentalHistory(RentalData* rentalData){}
        void Customer::printAllCustomerData(){} // all data + last rental
        void Customer::printUserRentalHistory(){}
        void Customer::printData(OUT_CUSTOMER type){}
        void Customer::outData(std::ostream& out){}
        
        // ostream& operator<<(ostream& out, const Customer& x){}
