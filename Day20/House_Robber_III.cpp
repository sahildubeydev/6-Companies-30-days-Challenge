// 337. House Robber III

#include  <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode*, int> lookup; // create a lookup table to store the results of subproblems
    int rob(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode* node) {
        if (!node) // if the input node is null, return 0
            return 0;
        if (lookup.count(node)) // if the result is already in the lookup table, return the value stored in the lookup table
            return lookup[node];
        int left = helper(node->left); // calculate the maximum amount of money that can be robbed from the left subtree
        int right = helper(node->right); // calculate the maximum amount of money that can be robbed from the right subtree
        int left_grandchild = helper(node->left ? node->left->left : nullptr) + helper(node->left ? node->left->right : nullptr);
        // calculate the maximum amount of money that can be robbed from the left subtree's grandchild
        int right_grandchild = helper(node->right ? node->right->left : nullptr) + helper(node->right ? node->right->right : nullptr);
        // calculate the maximum amount of money that can be robbed from the right subtree's grandchild
        int result = max(node->val + left_grandchild + right_grandchild, left + right);
        // To avoid alerting the police, the thief cannot rob both the current node and its immediate children.
        // Therefore, the maximum amount of money that can be robbed from the current node is the maximum of the following two options:
        // 1. The maximum amount of money that can be robbed from the left subtree + the maximum amount of money that can be robbed from the right subtree.
        // 2. The value of the current node + the maximum amount of money that can be robbed from the left subtree's grandchild + the maximum amount of money that can be robbed from the right subtree's grandchild.
        lookup[node] = result; // store the result in the lookup table
        return result;
    }
};