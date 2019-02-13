#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Dog.h"
#include <vector>

struct ListNode{
    int idNumber;
    Dog dog;
    std::shared_ptr<ListNode> next;
};
using List = std::shared_ptr<ListNode>;
Dog& findDog(List& front, int desiredID);
void removeHalf(List& front);
void squareIDNumbers(List& front);
std::vector<Dog> toVector(List& front);
void swapDogs(List& front, int index1, int index2);
List reverseList(List front);