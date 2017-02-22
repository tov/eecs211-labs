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
