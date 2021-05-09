#include "../include/Car.hpp"




        Car::Car(std::string model, std::string VINnumber, STATUS isRented, time_t lastRented, Customer * lastRentee, double averageFuelConsumption): manufacturer(manufacturer), isRented(isRented), lastRented(lastRented), lastRentee(lastRentee),fuelLevel(100.0), averageFuelConsumption(averageFuelConsumption) 
        {
                this->model = new std::string(model);
                this->VINnumber = new std::string(VINnumber);
        }
        
        Car::~Car()
        {
                delete model;
                delete VINnumber;
        }
        
        int Car::getCarID(){return carID;}
        MANUFACTURER Car::getManufacturer(){return manufacturer;}
        std::string Car::getModel(){return *model;}
        STATUS Car::getIsRented(){return isRented;}
        time_t Car::getTechnicalReview(){return technicalReview;}
        time_t Car::getLastRented(){ return lastRented;}
        Customer * Car::getLastRentee(){ return lastRentee;}
        int Car::getProductionYear(){return productionYear;}
        double Car::getAverageFuelConsumption(){return averageFuelConsumption;}
        double Car::getCarRange() const{
                return (this->fuelLevel / this->averageFuelConsumption) * 100;
        }

        void Car::updateCarID(int x){}
        void Car::updateManufacturer(MANUFACTURER x){
                this->manufacturer = x;
        }
        void Car::updateModel(std::string x){
                delete this->model;
                this->model = new std::string(x);
        }
        void Car::updateTechnicalReview(time_t x){
                this->technicalReview = x;
        }
        void Car::updateLastRented(time_t x){}
        void Car::updateLastRentee(Customer * x){
                this->lastRentee = x;
        }
        void Car::updateProductionYear(int x){
                this->productionYear = x;
        }
        void Car::updateAverageFuelConsumption(double x){
                this->averageFuelConsumption = x;
        }
        void Car::toggleIsRented(){
                if(this->isRented == 0){
                        this->isRented =  (STATUS)1;
                }else{
                        this->isRented = (STATUS)0;
                }
        }
        void Car::printData(std::ostream& out, const Car& x) const{

                const char separator    = ' ';
                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";

                while(print_type = getchar())
                {
                        if( print_type == 'D' || print_type == 'd'){
                        out << std::left<< std::setw(nameWidth) << "Car manufacturer:" << x.manufacturer << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Car model:" << x.model << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Car VIN number:" << x.VINnumber << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Car Production year:" << x.productionYear << std::endl;     
                        break;
                        }else if( print_type == 'S' || print_type == 's'){
                        out << std::left<< std::setw(nameWidth) << "Car rental status:" << (STATUS)x.isRented << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Next technical review:" << timeStampToTime(x.technicalReview) << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Car range:" << x.getCarRange() << std::endl;  
                        out << std::left<< std::setw(nameWidth) << "Last var rental time" <<  timeStampToTime(x.lastRented) << std::endl;
                        out << std::left<< std::setw(nameWidth) << "Last car rentee:" << x.lastRentee->getUsername() << std::endl;  
                        }else{
                                std::cout << "Input proper character! "<<std::endl;
                                std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";
                        }
                }

        }    

        std::ostream& operator<<(std::ostream& out, const Car& x){

                x.printData(out, x);

                return out;
        }
