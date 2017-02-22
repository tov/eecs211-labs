#pragma once

#include <iostream>

class TreeNode
{
private:
    TreeNode* left_;
    TreeNode* right_;
    int data_;

public:
    TreeNode(TreeNode left, TreeNode right, int data);
    TreeNode(int data);
    TreeNode();
    TreeNode* left() const;
    TreeNode* right() const;
    int data() const;
    TreeNode* findLargest();
    TreeNode* largestLessThan(int bound);
    TreeNode* largestBetween(int lowerBound, int upperBound);
    void insertNode(int data);
    ~TreeNode();
    void removeNode(TreeNode* removeMe);
};

