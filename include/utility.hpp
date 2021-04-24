#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

enum MANUFACTURER{
    AUDI,
    BMW,
    SKODA,
    TOYOTA,
    FORD,
    HONDA,
    VOLKSWAGEN,

};

enum STATUS{
    INACTIVE,
    ACTIVE,    
};

enum DATA_TYPE{
    ALL,
    CAR,
    CUSTOMER,
    EMPLOYEE,
    RENTAL_HISTORY,    
};

enum OUT_CUSTOMER{
    WHOLE,
    USER_RENTAL_HISTORY,
};

typedef struct{
    double longitude;
    double latitude;
} Localization;

    bool validateVINnumber(std::string VINnumber);

    std::string timeStampToTime(const time_t rawtime);
    long int timeToTimeStamp(const std::string &str);


#endif