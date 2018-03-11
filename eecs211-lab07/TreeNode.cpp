#include "TreeNode.h"

using namespace std;


TreeNode::TreeNode(){
    left_ = nullptr;
    right_ = nullptr;
    data_ = 0;
}

TreeNode::TreeNode(int data){
    left_ = nullptr;
    right_ = nullptr;
    data_ = data;
}

TreeNode::TreeNode(TreeNode* left, TreeNode* right, int data){
    left_ = left;
    right_ = right;
    data_ = data;
}

TreeNode* TreeNode::left() const{
    return left_;
}

TreeNode* TreeNode::right() const{
    return right_;
}

int TreeNode::data() const {
    return data_;
}

TreeNode* TreeNode::findLargest(){
    /// FILL ME IN
    TreeNode* result = this;
    while (result->right() != nullptr) {
        result = right();
    }
    return result;
}

TreeNode* TreeNode::largestLessThan(int bound){
    /// FILL ME IN
    /// if there is no TreeNode less than bound, throw an error
    TreeNode* result = this;
    if (this->data() > bound) {
        while(result->data() > bound) {

            result = result->left();
            if (result == nullptr) {
                throw runtime_error("There is no TreeNode less than bound");
            }
        }
        while (result->right() != nullptr && result->right()->data() < bound) {
            result = result->right();
        }
        // left of bound
    } else {
        // right of bound
        while (result->right() != nullptr && result->right()->data() < bound) {
            result = result->right();

        }
    }
    return result;
}

TreeNode* TreeNode::largestBetween(int lowerBound, int upperBound){
    /// FILL ME IN
    /// if there is no treeNode between the bounds, throw an erorr
}

void TreeNode::insertNode(int data){
    /// FILL ME IN
}

TreeNode::~TreeNode(){
    /// Make this destructor
    delete left();
    delete right();
}

void TreeNode::removeNode(int data) {
    /// FILL ME IN
    /// Make sure to de-allocate the removed node's memory.
    /// this is a challenge function
}

// main.cpp

int main() {
    TreeNode* tn = new TreeNode();
    // ....
    delete tn;
}

