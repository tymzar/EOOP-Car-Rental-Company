#ifndef UTILITY_HPP
#define UTILITY_HPP
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <cmath>

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
    UNACTIVE,
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
    // Employee * findNearestEmployee(double x, double y);
    double coordinatesDistanceCalculator(double x, double y, double Ex, double Ey);
    

#endif