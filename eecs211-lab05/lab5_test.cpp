#include "Dog.h"
#include "ListNode.h"
#include "Practice.h"

#include <UnitTest++/UnitTest++.h>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

// Helper for creating a List to test on
List test_list() {
    List l = make_shared<ListNode>();
    l->idNumber = 1;
    l->dog = Dog{"Bandit", 3.0, "Greenies"};
    l->next = make_shared<ListNode>();
    l->next->idNumber = 2;
    l->next->dog = Dog{"Buster", 6.0, "Kibble"};
    l->next->next = nullptr;
    return l;
}

// Helper for reating a vector to test on
vector<Dog> test_dog_vector()
{
    Dog roger{"Roger", 5.0, "Greenies"};
    Dog angus{"Angus", 12.0, "Kibble"};
    Dog marie{"Marie", 7.0, "Peanut Butter"};

    // Vector creation:
    vector<Dog> dogs = {roger, angus, marie};
    return dogs;
}


TEST(FIND_DOG) {
    List front = test_list();
    //For our purposes, if the Dog returned has the same name, age, and favorite treat,
    // then it's the same dog
    Dog found = findDog(front, 1);
    CHECK_EQUAL("Bandit", found.name);
    CHECK_EQUAL(3.0, found.age);
    CHECK_EQUAL("Greenies", found.favoriteTreat);

    CHECK_THROW(findDog(front, 3), runtime_error);
}

TEST(REMOVE_HALF) {
    List front = test_list();
    removeHalf(front);
    CHECK(front->next == nullptr);
    List empty;
    CHECK_THROW(removeHalf(empty), runtime_error);
}

TEST(SQUARE_ID_NUMBERS) {
    List front = test_list();
    squareIDNumbers(front);
    CHECK_EQUAL(1, front->idNumber);
    CHECK_EQUAL(4, front->next->idNumber);

    List empty;
    CHECK_THROW(squareIDNumbers(empty), runtime_error);
}

TEST(TO_VECTOR) {
    List front = test_list();
    vector<Dog> ret = toVector(front);
    CHECK_EQUAL("Bandit", ret[0].name);
    CHECK_EQUAL(3.0, ret[0].age);
    CHECK_EQUAL("Greenies", ret[0].favoriteTreat);
    CHECK_EQUAL("Buster", ret[1].name);
    CHECK_EQUAL(6.0, ret[1].age);
    CHECK_EQUAL("Kibble", ret[1].favoriteTreat);

    List empty;
    CHECK_THROW(toVector(empty), runtime_error);
}

TEST(SWAP_DOGS) {
    List front = test_list();
    swapDogs(front, 0, 1);
    CHECK_EQUAL("Buster", front->dog.name);
    CHECK_EQUAL("Bandit", front->next->dog.name);

    List empty;
    CHECK_THROW(swapDogs(empty, 0, 1), runtime_error);
    CHECK_THROW(swapDogs(front, 1, 0), runtime_error);
    CHECK_THROW(swapDogs(front, 1, 2), runtime_error);
}

TEST(REVERSE_LIST) {
    List front = test_list();
    List reverse = reverseList(front);
    CHECK_EQUAL(1, reverse->idNumber);
    CHECK_EQUAL(2, reverse->next->idNumber);
    CHECK(reverse->next->next == nullptr);

    List empty;
    CHECK_THROW(reverseList(empty), runtime_error);
}

TEST(MEAN_AGE){
    vector<Dog> dogs = test_dog_vector();
    CHECK_EQUAL((5.0,+12.0+7.0)/3, meanAge(dogs));
}

TEST(SWAP_TREATS) {
    Dog roger{"Roger", 5.0, "Greenies"};
    Dog angus{"Angus", 12.0, "Kibble"};
    swapTreats(roger, angus);
    CHECK_EQUAL("Greenies", angus.favoriteTreat);
    CHECK_EQUAL("Kibble", roger.favoriteTreat);
}

TEST(DIVISIBLE_BY_ALL) {
    vector<int> nums = {10, 20, 30, 40};
    vector<int> divs = {2, 4, 5};
    vector<int> ret = divisibleByAll(nums, divs);
    CHECK_EQUAL(2, ret.size());
    CHECK_EQUAL(20, ret[0]);
    CHECK_EQUAL(40, ret[1]);
}

TEST(FACTORIAL) {
    CHECK_EQUAL(1, factorial(1));
    CHECK_EQUAL(120, factorial(5));
}

TEST(VECTORIZE_INT) {
    vector<int> test1 = vectorizeInt(108);
    CHECK_EQUAL(3, test1.size());
    CHECK_EQUAL(1, test1[0]);
    CHECK_EQUAL(0, test1[1]);
    CHECK_EQUAL(8, test1[2]);

    vector<int> test2 = vectorizeInt(3);
    CHECK_EQUAL(1, test2.size());
    CHECK_EQUAL(3, test2[0]);
}