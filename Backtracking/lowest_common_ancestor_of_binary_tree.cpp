#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    public:

    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if(!root) {
            return root;
        }

        // Since the numbers p and q are unique, if the value of the root matches any of these numbers, we return it
        if(root==p || root==q) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If we found that each of the elements lie o either side of the root, we return root
        if(left && right) {
            return root;
        }

        return left ? left : right;
    }
};