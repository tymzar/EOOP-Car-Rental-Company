#include "../include/Utility.hpp"

bool validateVINnumber(std::string VINnumber){

}

std::string timeStampToTime(const time_t rawtime)
{
        struct tm * dt;
        char buffer [30];
        dt = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", dt);
        return std::string(buffer);
}

long int timeToTimeStamp(const std::string &str)
{
    time_t rawtime;
    struct tm timeinfo;

    time ( &rawtime ); 
    timeinfo = *localtime ( &rawtime ); 

    timeinfo.tm_year   = stoi(str.substr(0, 4)) - 1900;
    timeinfo.tm_mon    = stoi(str.substr(4, 2)) - 1;
    timeinfo.tm_mday   = stoi(str.substr(6, 2));
    timeinfo.tm_hour   = stoi(str.substr(8, 2));
    timeinfo.tm_min    = stoi(str.substr(10, 2));
    timeinfo.tm_sec    = stoi(str.substr(12, 2));

    return mktime(&timeinfo);
}