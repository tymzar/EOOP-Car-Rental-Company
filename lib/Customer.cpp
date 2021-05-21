
#include "../include/Customer.hpp"

        int Customer::activeCustomersAmount = 0;

        Customer::Customer(std::string username,std::string name,std::string surname,double accountBalace): accountBalace(accountBalace), isAnyRenalActive(UNACTIVE){
                this->username = username;
                this->name = name;
                this->surname = surname;

                if(accountBalace >= 20){
                        this->isAccountActive = ACTIVE;
                }else{
                        this->isAccountActive = UNACTIVE;
                }
        }

        Customer::~Customer(){
        }
        std::string Customer::getUsername()const{return username;}
        std::string Customer::getName(){return name;}
        std::string Customer::getSurname(){return surname;}
        double Customer::getAccountBalace(){ return accountBalace;}
        std::list<RentalData> Customer::getUserRentalHistory(){return userRentalHistory;}
        STATUS Customer::getIsAnyRenalActive(){return isAnyRenalActive;}
        STATUS Customer::getIsAccountActive(){return isAccountActive;}

        void Customer::updateUsername(std::string x){
                this->username = x;
        }
        void Customer::updateName(std::string x){

                this->name = x;
        }

        int Customer::getactiveCustomersAmount(){
            return activeCustomersAmount;
        }

        void Customer::updateSurname(std::string x){

                this->surname = x;
        }
        void Customer::updateAccountBalace(double x){
                this-> accountBalace = x;
        }
        void Customer::toggleIsAnyRenalActive(){
                if(this->isAnyRenalActive == 0){
                        this->isAnyRenalActive =  (STATUS)1;
                }else{
                        this->isAnyRenalActive = (STATUS)0;
                }
        }
        void Customer::toggleIsAccountActive(){
                if(this->isAccountActive == 0){
                        this->isAccountActive =  (STATUS)1;
                }else{
                        this->isAccountActive = (STATUS)0;
                }
        }
        void Customer::addUserRentalHistory(RentalData rentalData){

                this->userRentalHistory.push_back(rentalData);
        }

        
        bool Customer::operator==(const Customer& x){
                if( username == x.username){
                        return true;
                }else{
                        return false;
                }
        }

        std::ostream& operator<<(std::ostream& out, const Customer& x){

                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'D' for User Deatils and 'H' for User rental history: (D/H)";

                while((print_type = getchar()))
                {
                        getchar();
                        
                        if( print_type == 'D' || print_type == 'd'){
                                out << std::left<< std::setw(nameWidth) << "Customer username:" << x.username << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Customer name:" << x.name << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Customer surname:" << x.surname << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Customer balance:" << x.accountBalace << std::endl;     
                                out << std::left<< std::setw(nameWidth) << "Customer active rental:" << x.isAnyRenalActive << std::endl;     
                                out << std::left<< std::setw(nameWidth) << "Customer account status:" << x.isAccountActive << std::endl;     
                                break;
                        }else if( print_type == 'H' || print_type == 'h'){
                                for (std::list<RentalData>::const_iterator iterator = x.userRentalHistory.begin(), end = x.userRentalHistory.end(); iterator != end; ++iterator) {
                                        out << *iterator;
                                }
                                break;
                        }else{
                                std::cout << "Input proper character! "<<std::endl;
                                std::cout << "Enter 'D' for User Deatils and 'H' for User rental history: (D/H)";
                        }
                }

                return out;
        }
