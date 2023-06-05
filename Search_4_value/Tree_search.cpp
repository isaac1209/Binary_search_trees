#include "all_functions.h"


// Recursive function to build a balanced binary tree from a sorted vector
TreeNode* buildBalancedBST(int_vector & nums, int start, int end) {
    // Base case
    if (start > end) {
        return nullptr;
    }

    // Calculate the mid index of the vector
    int mid = (start + end) / 2;

    // Create a new node with the value at the mid index
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedBST(nums, start, mid - 1);
    root->right = buildBalancedBST(nums, mid + 1, end);

    return root;
}

// Recursive function to search for a value in the binary tree
bool searchBST(TreeNode* root, int val) {
    // Base case: the node is null or the value matches
    if (root == nullptr || root->val == val) {
        return root != nullptr;
    }

    // Recursively search the left or right subtree based on the value
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

// Function to print the inorder traversal of a binary tree
void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

