#include "../include/Employee.hpp"
        /**
         * @brief Initialization of the static variables
         * 
         */
        int Employee::employeeAmount = 0;
        int Employee::totalCarsFueled = 0;
        Employee * Employee::mostCarsFueled = nullptr;

        /**
         * @brief Construct a new Empl0yee which consists all the data
         * 
         * @param name Emplyee name
         * @param surname Employee surname
         * @param phoneNumber Employee phone number
         * @param fueledCars Cars fueled by employee
         * @param currentLocalization 
         */
        Employee::Employee(std::string name, std::string surname, std::string phoneNumber, int fueledCars, Localization currentLocalization): name(name), surname(surname), phoneNumber(phoneNumber), employeeID(employeeAmount+1), fueledCars(fueledCars), currentLocalization(currentLocalization) {
                employeeAmount++;
                std::cout << "Employee hired!" <<std::endl;

        }

        /**
         * @brief Destroy the RentalReport and update static variable
         * 
         */
        Employee::~Employee(){
                employeeAmount--;
                std::cout << "Employee fired!" <<std::endl;
        }

        /**
         * @brief Get method for name
         * 
         * @return string name
         */
        std::string Employee::getName(){
                return name;
        }

        /**
         * @brief Get method for surname
         * 
         * @return string surname
         */
        std::string Employee::getSurname(){
                return surname;
        }

        /**
         * @brief Get method for phoneNumber
         * 
         * @return string phoneNumber
         */
        std::string Employee::getPhoneNumber(){
                return phoneNumber;
        }

        /**
         * @brief Get method for fueledCars
         * 
         * @return int fueledCars
         */
        int Employee::getFueledCars(){
                return fueledCars;
        }
        
        /**
         * @brief Get method for currentLocalization
         * 
         * @return Localization currentLocalization
         */
        Localization Employee::getCurrentLocalization(){
                return currentLocalization;
        }
        
        /**
         * @brief Method responsible for updating value of name
         * 
         * @param name new value 
         */
        void Employee::updateName(std::string x){
                this->name = x;
        }

        /**
         * @brief Method responsible for updating value of usedFuel
         * 
         * @param surname new value 
         */
        void Employee::updateSurname(std::string x){
                this->surname = x;
        }

        /**
         * @brief Method responsible for updating value of usedFuel
         * 
         * @param phoneNumber new value
         */
        void Employee::updatePhoneNumber(std::string x){
                this->phoneNumber = x;
        }

        /**
         * @brief Method responsible for updating value of fueledCars and static variable associated with it (totalCarsFueled)
         * 
         * @param new value
         */
        void Employee::updateFueledCars(int x){
                int temp = this->fueledCars;
                totalCarsFueled -= temp;
                this->fueledCars += x;
                totalCarsFueled += x;
        }

        /**
         * @brief Method responsible for updating value of usedFuel
         * 
         * @param new value
         */
        void Employee::updateCurrentLocalization(Localization x){
                this->currentLocalization = x;
        }

        /**
         * @brief Overload of the operator<< used to clearly display report data
         * 
         * @param out ofstream variable to pass data
         * @param x poiner to the Employee
         * @return ostream& 
         */
        std::ostream& operator<<(std::ostream& out, const Employee& x){
                const char separator    = ' ';
                const int nameWidth     = 25;
                
                out << std::left<< std::setw(nameWidth) << "Employee name:" << x.name << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee surname:" << x.surname << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee phone number:" << x.phoneNumber << std::endl;
                out << std::left<< std::setw(nameWidth) << "Cars employee fueled:" << x.fueledCars << std::endl;
                out << std::left<< std::setw(nameWidth) << "Employee localization:" << x.currentLocalization.latitude << ", " <<x.currentLocalization.longitude << std::endl;


                return out;
        }
