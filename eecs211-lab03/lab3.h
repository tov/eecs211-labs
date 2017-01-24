#pragma once
#include <vector>
#include <string>

using namespace std;
struct Dog
{
    string name;
    double age;
    double happiness; // happiness level from 1 to 5
    string owner;
};
Dog youngestDog(vector<Dog>);

Dog happiestDog(vector<Dog>);

string findOwner(vector<Dog>, string);
