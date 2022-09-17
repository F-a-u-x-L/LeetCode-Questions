#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<list>
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

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {

        if(root==NULL) {
            return {};
        }

        vector<vector<int>> res;
        // queue<TreeNode *> qt;
        list<TreeNode*> q;
        TreeNode *temp;
        q.push_front(root);
        int len;
        bool direction = true;          // 0 for right to left and 1 for left to right

        while(!q.empty()) {
            len = q.size();
            vector<int> track;

            if(direction) {
                for(int i=0; i<len; i++) {
                    temp = q.front();
                    q.pop_front();
                    track.push_back(temp->val);

                    if(temp->left) {
                        q.push_back(temp->left);
                    }

                    if(temp->right) {
                        q.push_back(temp->right);
                    }
                }
            }

            if(!direction) {
                for(int i=0; i<len; i++) {
                    temp = q.back();
                    q.pop_back();
                    track.push_back(temp->val);

                    if(temp->right) {
                        q.push_front(temp->right);
                    }

                    if(temp->left) {
                        q.push_front(temp->left);
                    }
                }
            }

            res.push_back(track);
            direction = !direction;
        }

        return res;
    }
};




// Alternate Approach for a bit cleaner code

class Solution {

    public:

    vector<vector<int>> levelOrder(TreeNode *root) {

        if(root == NULL) {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        int len;
        bool flag = true;

        while(!q.empty()) {

            len = q.size();
            vector<int> track;

            for(int i=0; i<len; i++) {
                temp = q.front();
                q.pop();
                track.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right) {
                    q.push(temp->right);
                }
            }

            if(flag) {
                res.push_back(track);
            }
            else {
                reverse(track.begin(), track.end());
                res.push_back(track);
            }

            flag = !flag;

        }

        return res;
    }
};