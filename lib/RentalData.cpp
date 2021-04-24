#include "../include/RentalData.hpp"

        RentalData::RentalData(){}
        RentalData::~RentalData(){}
        int RentalData::getRentalDataID(){ return rentalDataID;}

        STATUS RentalData::getRentalStatus(){return rentalStatus;}
        RentalReport * RentalData::getRentalDetails(){return rentalDetails;}
        void RentalData::updateRentalDetails(RentalReport *){}
        void RentalData::toggleRentalStatus(){}
        void RentalData::notifyNearestEmployee(){}
        void RentalData::notifyCustomer(){}

        std::ostream& operator<<(std::ostream& out, const RentalData& x){}

