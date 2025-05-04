#pragma once
#include<string>
#include<iostream>

struct EGTSensor{
    float egt_temp = 770;

};

std::string read_EGT(void *self){
   EGTSensor *egt = static_cast<EGTSensor*>(self);
   return "Exhaust Egnine Temperature is : " + std::to_string(egt->egt_temp);
}

std::string status_EGT(void *self){
    return "EGT Sensor is OK";
}

struct Altimeter{
    float altitude = 3000;
};


std::string read_Altitude(void *self){
    Altimeter* altitude_atp = static_cast<Altimeter*>(self);
    return "Altitude at pressure is : " + std::to_string(altitude_atp->altitude);
}

std::string status_Altitudde(void *self){
    return "Altimeter sensor status is okay";
}

struct BleedValve{
    float bleed_valve_deg = 36.5;
};

std::string read_BleedValve(void *self){
    BleedValve* bvp = static_cast<BleedValve*>(self);
    return "Bleed valve position is : " + std::to_string(bvp->bleed_valve_deg);
}

std::string status_bleedValve(void *self){
    return "Bleed valve status is okay";
}

struct RPMSensor{
    int rpm = 3000;
};

std::string read_rpm(void *self){
    RPMSensor* rpmp = static_cast<RPMSensor*>(self);
    return "rpm speed is : "+ std::to_string(rpmp->rpm);
}

std::string status_rpm(void *self){
    return "rpm sensor status is Okay";
}
