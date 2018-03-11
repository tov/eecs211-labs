#include "TreeNode.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int getLength(const int* arr, size_t sizeOf){
    // note that sizeOf will give you the size of the elements in the array
    // but you don't actually need this, if you think about how de-referencing arrays works
    // Also note that the last element of the array is guaranteed to be 0, and no other element will be.
    // Make sure to include this element in your count.
    /// Write code to traverse the array keeping track of how many elements there are.
    /// And return the number of elements
    /// FILL IN YOUR CODE HERE
    int counter = 0;
    while (*(arr+counter) != 0) {
        counter++;
    }
    return counter+1;
    //arr[index]
}

void swapValues(int* ptr1, int* ptr2){
    /// Write the function here to swap the values at the ptr1 and ptr2
    /// FILL IN YOUR CODE HERE
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{

    int arr[]  = {5, 10, 15, 20, 25, 0};
    cout<<getLength(arr, sizeof(int))<<'\n';


}



