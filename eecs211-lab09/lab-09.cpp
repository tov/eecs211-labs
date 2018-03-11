#include <iostream>
#include <vector>
#include <list>

using namespace std;

//function template
template <typename T>
T square(T num) {
    return num * num;
}

// struct template

template <typename T>
struct ListNode {
    T value;
    ListNode<T>* next;
};

template <typename Fwd_iter>
void print_container(Fwd_iter start, Fwd_iter limit) {
    for(Fwd_iter i = start; i != limit; i++) {
        cout << *i <<"\n";
}
}

// Review Practice


void rawPtrCode() {
    int* rawPtr = new int();
    *rawPtr = 211;
    cout<<"Raw ptr: "<<*rawPtr<<"\n";
}

template <typename T>
void removeHalf(ListNode<T>& front) {
    // Insert code here
}

void ptrMath() {
    double dubArr[5] = {1.0, 2.5, 4.0, 5.5, 7.0};
    double* testPtr;
    for(testPtr = dubArr; *testPtr != 7.0; testPtr++) {
        cout<<*testPtr<<"\n";
    }

}

template <typename T, typename Fwd_iter>
T add(Fwd_iter beg, Fwd_iter end) {
    // Sum up all of the elements within the iterator range
};

int main() {
    //Using a function template
    double x = 5.4545;
    int y = 4;
    float z = 2.35;
    cout<<"The square of double x is: "<<square(x)<<"\n";
    cout<<"The square of int y is: "<<square(y)<<"\n";
    cout<<"The square of float z is: "<<square(z)<<"\n";

    //Using the struct template
    ListNode<int> intNode;
    intNode.value = 211;
    ListNode<string> stringNode;
    stringNode.value = "EECS 211";
    cout<<"Int node: "<<intNode.value <<"\nString node: "<<stringNode.value<<" \n";

    // Using a generic iterator
    vector<int> vecInts = {1, 2, 3, 4};
    list<string> lstStrings = {"EECS 111", "EECS 211", "EECS 214"};
    print_container(vecInts.begin(), vecInts.end());
    print_container(lstStrings.begin(), lstStrings.end());
    ptrMath();

    return 0;
}