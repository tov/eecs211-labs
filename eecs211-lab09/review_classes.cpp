#include <string>

class Animal
{
protected:
    std::string name_;
    int age_;
public:
    Animal() {}
    Animal(std::string name, int age) : name_(name), age_(age) {}
    std::string name() {return name_;}
    int age() {return age_;}
};

class Dog:public Animal
{
private:
    Dog* friends_;
    int num_friends_;
    std::string breed_;
public:
    Dog() {}
    Dog(std::string breed, int num_friends) : breed_(breed), num_friends_(num_friends)
    {
        friends_ = new Dog[num_friends_];
    }
    ~Dog(){delete[] friends_;}
};

class Complex
{
    double real_, imaginary_;
public:
    //Insert constructor code here
    Complex operator+ (const Complex& c) const
    {
        //insert code here
    }
};