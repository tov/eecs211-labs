#pragma once
#include <iostream>

#define DELTA_TIME .05

class Vehicle {

protected:
    std::string brand_;
    std::string color_;
    std:: string fuelType_;
    double position_;
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
    void setPosition(double position){
        position_ = position;
    }
    std::string brand(){
        return brand_;
    }
    std::string color(){
        return color_;
    }
    std::string fuelType(){
        return fuelType_;
    }
    virtual void Drive() = 0; // Our pure virtual function

};
