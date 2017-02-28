#pragma once
#include <iostream>

#define DELTA_TIME .05

class Vehicle {

protected:
    std::string brand_;
    std::string color_;
    std:: string fuelType_;
public:
    void setBrand(std::string brand){
        brand_ = brand;
    }
    void setColor(std::string color){
        color_ = color;
    }
    void setFuelType(std::string fuelType){
        fuelType_ = fuelType;
    }
    string brand(){
        return brand_;
    }
    string color(){
        return color_;
    }
    string fuelType(){
        return fuelType_;
    }
    virtual void Drive() = 0; // Our pure virtual function

};
