#include<iostream>

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(0), left(left), right(right) {}
};

class Solution {

    public:

    bool isValid(TreeNode *root, TreeNode *min, TreeNode *max) {

        // BASE CASE
        if(root == NULL) {
            return true;
        }

        if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val))
        {
            return isValid(root->left, min, root) && isValid(root->right, root, max);
        }

        return false;
    }

    bool isValidBST(TreeNode *root) {

        return isValid(root, NULL, NULL);
    }
};