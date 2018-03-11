#pragma once

#include "Person.h"
#include <iostream>
#include <vector>

class Bank
{
private:
    std::vector<Person> accounts_;

public:
    Bank();
    double convertToFaraneheit(double);
    const std::vector<Person>& accounts() const;
    double stealMoney();
};
