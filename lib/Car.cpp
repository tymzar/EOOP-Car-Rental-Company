#include "../include/Car.hpp"

        int Car::carsRented = 0;


        Car::Car(std::string model, std::string VINnumber, STATUS isRented, time_t lastRented, Customer * lastRentee, double averageFuelConsumption): isRented(isRented), lastRented(lastRented), lastRentee(lastRentee),fuelLevel(100.0), averageFuelConsumption(averageFuelConsumption) 
        {
                this->model = model;
                this->VINnumber = VINnumber;
        }
        
        Car::~Car(){}
        
        std::string Car::getModel()const{return model;}
        std::string Car::getVIN()const{return VINnumber;}
        STATUS Car::getIsRented(){return isRented;}
        time_t Car::getLastRented(){ return lastRented;}
        Customer * Car::getLastRentee(){ return lastRentee;}
        int Car::getProductionYear(){return productionYear;}
        double Car::getAverageFuelConsumption(){return averageFuelConsumption;}
        double Car::getCarRange() const{
                return (this->fuelLevel / this->averageFuelConsumption) * 100;
        }

        void Car::updateModel(std::string x){
                this->model = x;
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
 
        bool Car::operator==(const Car& x){
                if( VINnumber == x.VINnumber){
                        return true;
                }else{
                        return false;
                }
        }

        std::ostream& operator<<(std::ostream& out, const Car& x){
                const int nameWidth     = 25;
                
                char print_type = '\0';

                std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";

                while((print_type = getchar()))
                {
                        getchar();                        
                        if( print_type == 'D' || print_type == 'd'){
                                out << std::left<< std::setw(nameWidth) << "Car model:" << x.model << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Car VIN number:" << x.VINnumber << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Car Production year:" << x.productionYear << std::endl;     
                                break;
                        }else if( print_type == 'S' || print_type == 's'){
                                std::string status = "";
                                std::string lastRentedTime = timeStampToTime(x.lastRented);
                                if(x.isRented == UNACTIVE){
                                        status = "unactive";
                                }else{
                                        status = "active";
                                }

                                out << std::left<< std::setw(nameWidth) << "Car rental status:" << status << std::endl;
                                out << std::left<< std::setw(nameWidth) << "Car range:" << x.getCarRange() << "km" << std::endl;  
                                out << std::left<< std::setw(nameWidth) << "Last var rental time" << lastRentedTime << std::endl;                                break;
                                break;
                        }else{
                                std::cout << "Input proper character! "<<std::endl;
                                std::cout << "Enter 'D' for Car Deatils and 'S' for Car Status: (D/S)";
                        }
                }

                return out;
        }
