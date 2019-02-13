#pragma once

#include <iostream>

class Person
{
private:
    std::string name_;
    int ssn_;
    double bank_balance_;

public:
    Person(const std::string& n, int s);
    Person(const std::string& n, int s, double b);

    bool canIBuyThis(double itemCost) const;
    bool canIBuyThis(int itemCost) const;
    double withdrawFromBank(double amount);

    const std::string& name() const;
    int ssn() const;
    double bank_balance() const;
};

