#include<iostream>
#include<vector>
#include<queue>
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

    vector<vector<int>> levelOrder(TreeNode *root) {

        vector<vector<int>> res;
        vector<TreeNode*> tracker;

        if(root == NULL) {
            return {};
        }

        tracker.push_back(root);
        tracker.push_back(NULL);

        for(int i=0; i<tracker.size(); i++) {
            if(tracker[i]!=NULL && tracker[i]->left!=NULL){
                tracker.push_back(tracker[i]->left);
            }
            else if (tracker[i]!=NULL && tracker[i]->left==NULL) {
                tracker.push_back(NULL);
            }

            if(tracker[i]!=NULL && tracker[i]->right!=NULL) {
                tracker.push_back(tracker[i]->right);
            }
            else if (tracker[i]!=NULL && tracker[i]->right==NULL) {
                tracker.push_back(NULL);
            }
        }

        for(int i=0; i<tracker.size(); i++) {
            vector<int> ans;
            while(tracker[i]!=NULL) {
                ans.push_back(tracker[i]->val);
                i++;
            }
            res.push_back(ans);

            if(tracker[i] == NULL) {
                while(tracker[i] == NULL) {
                    i++;
                } 
            }

            i--;
        }

        return res;

    }
};


// ALTERNTE SOLUTION

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

            res.push_back(track);
        }

        return res;
    }
};