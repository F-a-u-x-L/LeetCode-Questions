#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Brute Force Solution

class Solution
{

    public:

        void helper(TreeNode *root, vector<int> &res) {

            if(root == NULL) {
                return;
            }

            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }

        int kthSmallest(TreeNode *root, int k) {

            vector<int> res;
            helper(root, res);

            return res[k-1];
        }
};