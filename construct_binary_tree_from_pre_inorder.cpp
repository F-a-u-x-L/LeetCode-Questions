#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

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

    TreeNode *splitTree(vector<int> &preorder, unordered_map<int,int> &M, int pix, int ileft, int iright) {
        int val = preorder[pix];
        int imid = M[val];
        TreeNode *root = new TreeNode(val);

        if(imid > ileft) {
            root->left = splitTree(preorder, M, pix+1, ileft, imid-1);
        }

        if(imid < iright) {
            root->right = splitTree(preorder, M, pix+imid-ileft+1, imid+1, iright);
        }

        return root;
    }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {

        unordered_map<int, int> M;
        for(int i=0; i<inorder.size(); i++) {
            M[inorder[i]] = i;
        }

        return splitTree(preorder, M, 0, 0, inorder.size() - 1);
    }

};







class Solution {

    public:

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        unordered_map<int, int> track;
        
        for(int i=0; i<inorder.size(); i++) {
            track[inorder[i]] = i;
        }

        TreeNode *root = construct(preorder ,0 , preorder.size()-1, inorder, 0, inorder.size()-1, track);

        return root;
    }

    TreeNode *construct(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &track) {

        if(preStart>preEnd || inStart>inEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = track[root->val];
        int numsLeft = inRoot - inStart;

        root->left = construct(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inEnd-1, track);
        root->right = construct(preorder, preStart+1+numsLeft, preEnd, inorder, inRoot+1, inEnd, track);

        return root;
    }
};