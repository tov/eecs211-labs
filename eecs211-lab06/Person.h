#pragma once

#include <iostream>

class Person {
private:
    std::string name_;
    int SSN_;
    double bank_balance_;


public:
    Person(std::string n, int s);
    Person(std::string n, int s, double b);
    bool canIBuyThis(double itemCost);
    bool canIBuyThis(int itemCost);
    double withdrawFromBank(double amount);

    std::string name();
    int SSN();
    double bank_balance();
};

