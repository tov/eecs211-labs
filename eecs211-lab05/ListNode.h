#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Dog.h"

struct ListNode{
    int idNumber;
    Dog dog;
    std::shared_ptr<ListNode> next;
};
using List = std::shared_ptr<ListNode>;
Dog& traverse(List& front, int desiredID);

