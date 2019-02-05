#include "ListNode.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>
using namespace std;

/// Write a function to return the dog from the linked list,
/// whose linked list node's idNumber matches the desiredID
/// If no idNumber matches, throw a runtime_error!
Dog& findDog(List &front, int desiredID){

    // [YOUR CODE HERE]

}

/// Now write a function to remove every other element of the linked list.
/// For example, consider this sample input and output:
/// Input:: 1 -> 2 -> 3 -> 4 -> nullptr
/// Output:: 1 -> 3 -> nullptr
/// Remember to check that a ListNode exists before accessing its data members
/// If the list is empty (i.e. front is nullptr), throw a runtime error.
void removeHalf(List &front){

    // [YOUR CODE HERE]

}

/// Write a function square idNumbers to go through a linked list,
/// and square each identification number.
/// If the list is empty, (i.e. front is nullptr), throw a runtime error.
void squareIDNumbers(List &front){

    // [YOUR CODE HERE]

}

/// Write a function that goes through a linked list, adds the dogs
/// to a vector, and then returns that vector of Dogs.
/// If the list is emtpy, throw a runtime error.
vector<Dog> toVector(List &front){

    // [YOUR CODE HERE]

}

/// Write a function that takes in a linked list and two indices,
/// and swaps the dogs located at the Nodes for those two indices.
/// Assume that index1 < index2. If index1 >= index2, throw a runtime error.
/// If the list is empty, throw a runtime error.
/// If either of the indices weren't found, throw a runtime error.
void swapDogs(List &front, int index1, int index2){

    // [YOUR CODE HERE]

}

/// Write a function to return a new list that is a reversed version
/// of the first list.  For example:
/// Input: 1 -> 2 -> 3 -> nullptr
/// Output: 3 -> 2 -> 1 -> nullptr
/// If the list is empty, throw a runtime error.
List reverseList(List front){

    // [YOUR CODE HERE]

}
