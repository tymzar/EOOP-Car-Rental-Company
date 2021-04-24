#include "../include/CarRentalCompany.hpp"


int main(){
    CarRentalCompany test = CarRentalCompany();

    time_t now = time(0);

    std::cout<< timeStampToTime(now)<< std::endl;


}