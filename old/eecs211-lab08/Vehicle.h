#pragma once
#include <iostream>

#define DELTA_TIME 0.5 // (hours)

class Vehicle {

protected:
    std::string brand_;
    std::string color_;
    std:: string fuelType_;
    double position_;
public:
    Vehicle() : position_(0) {}
    virtual ~Vehicle(){}

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
    double position() {
        return position_;
    }
    virtual void Drive() = 0; // Our pure virtual function
    virtual std::string vehicleType() = 0; // Another pure virtual function

};
