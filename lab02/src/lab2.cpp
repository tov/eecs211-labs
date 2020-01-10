#include <iostream>
#include <string>
using namespace std;

int sumNumbers(int num){
    // Write your loops in here
    return 0; // Make sure to change what you return!!
}


struct Apple{
    int weight; // in ounces
    string variety;
    string color;
};

// Your new struct goes here


// Your new function goes here

int main(){
    // Loop code:
    int numBound = 5; 
    int value = sumNumbers(numBound);
    cout<<"The sum with a numBound of "<<numBound<<" Is: "<<value<<'\n';
    // Structures Code:
    Apple redDelicious;
    redDelicious.weight = 10;
    redDelicious.variety = "Red Delicious";
    redDelicious.color = "Red";
    // cout<<redDelicious.variety<<" Apples weigh "<<redDelicious.weight<<" Ounces and are "<<redDelicious.color<<'\n';
    
    return 0;
}

    

