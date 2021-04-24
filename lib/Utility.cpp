#include "../include/Utility.hpp"

bool validateVINnumber(std::string VINnumber){

}

std::string timeStampToTime(const time_t rawtime)
{
        struct tm * dt;
        char buffer [30];
        dt = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%m.%d.%Y %H:%M ", dt);
        return std::string(buffer);
}