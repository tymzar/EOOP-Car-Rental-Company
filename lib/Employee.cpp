#include "../include/Employee.hpp"

        int Employee::employeeAmount = 0;
        int Employee::totalCarsFueled = 0;
        Employee * Employee::mostCarsFueled = nullptr;

        Employee::Employee(std::string name, std::string surname, std::string phoneNumber, int fueledCars, Localization currentLocalization): name(name), surname(surname), phoneNumber(phoneNumber), employeeID(employeeAmount+1), fueledCars(fueledCars), currentLocalization(currentLocalization) {
                employeeAmount++;
        }
        Employee::~Employee(){
                employeeAmount--;
        }

        std::string Employee::getName(){
                return name;
        }
        std::string Employee::getSurname(){
                return surname;
        }
        std::string Employee::getPhoneNumber()const{
                return phoneNumber;
        }
        int Employee::getFueledCars(){
                return fueledCars;
        }
        Localization Employee::getCurrentLocalization(){
                return currentLocalization;
        }
        void Employee::updateName(std::string x){
                this->name = x;
        }
        void Employee::updateSurname(std::string x){
                this->surname = x;
        }
        void Employee::updatePhoneNumber(std::string x){
                this->phoneNumber = x;
        }
        void Employee::updateFueledCars(int x){
                int temp = this->fueledCars;
                totalCarsFueled -= temp;
                this->fueledCars += x;
                totalCarsFueled += x;
        }
        void Employee::updateCurrentLocalization(Localization x){
                this->currentLocalization = x;
        }

        bool Employee::operator==(const Employee& x){
                if( phoneNumber == x.phoneNumber){
                        return true;
                }else{
                        return false;
                }
        }

        std::ostream& operator<<(std::ostream& out, const Employee& x){
                const int nameWidth     = 25;
                
                out << std::left<< std::setw(nameWidth) << "Employee name:" << x.name << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee surname:" << x.surname << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee phone number:" << x.phoneNumber << std::endl;
                out << std::left<< std::setw(nameWidth) << "Cars employee fueled:" << x.fueledCars << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee localization:" << x.currentLocalization.latitude << ", " <<x.currentLocalization.longitude << std::endl;


                return out;
        }
