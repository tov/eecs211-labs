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

TreeNode::TreeNode(TreeNode left, TreeNode right, int data){
    left_ = new TreeNode(left);
    right_ = new TreeNode(right);
    data_ = data;
}

TreeNode::findLargest(){
    /// FILL ME IN
}

TreeNode::largestLessThan(int bound){
    /// FILL ME IN
    /// if there is no TreeNode less than bound, throw an error
}