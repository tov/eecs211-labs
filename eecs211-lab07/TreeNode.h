#pragma once

#include <iostream>

class TreeNode
{
private:
    TreeNode* left_;
    TreeNode* right_;
    int data_;

public:
    TreeNode(TreeNode* left, TreeNode* right, int data);
    TreeNode(int data);
    TreeNode();
    TreeNode* left() const;
    TreeNode* right() const;
    int data() const;


};

