#include <iostream>
#include <vector>

using namespace std;

struct Dog{
    string name;
    double age;
    double happiness; //happiness level from 1 to 5
};


Dog youngestDog(vector<Dog> dogs){
    // Write your code here
    return dogs[0];
}

Dog happiestDog(vector<Dog> dogs){
    // Write your code here
    return dogs[0];
}

Dog searchForDog(vector<Dog> dogs, string name){
    // Write your code here
    return dogs[0];
}

int main(){
    cout<<"Thanks for doing Lab 3! \n";
    //Dog Initialization:
    Dog roger{"Roger", 5.0, 3.0};
    Dog angus{"Angus", 12.0, 2.4};
    Dog marie{"Marie", 0.5, 4.0 };
    Dog samuel{"Samuel", 7.5, 4.5};
    Dog pierre{"Pierre", 8.5, 3.5};
    Dog robert{"Robert", 15, 2.7};
    Dog forrester{"Forrester", 6.2, 1.5};
    //Vector creation:
    vector<Dog> dogs = {roger, angus, marie, samuel, pierre, robert, forrester};

    return 0;


}

    

