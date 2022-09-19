#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node {

    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next): val(0), left(left), right(right), next(next) {}
};



// Using Iterative Process

class Solution {

    public:

    Node *connect(Node *root) {

        if(!root) {
            return root;
        }

        queue<Node *> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();

            for(int i=0; i<len; i++) {
                Node *item = q.front();
                q.pop();

                if(len - 1 == i){
                    item->next = NULL;
                }

                if(len - 1 != i) {
                    item->next = q.front();
                }

                if(item->left) {
                    q.push(item->left);
                }
                if(item->right) {
                    q.push(item->right);
                }
            }
        }

        return root;
    }
};




// Using Recursion

class Solution {

    public:

    Node *connect(Node *root) {

        if(!root) {
            return NULL;
        }

        // Connecting the left node with the right node
        if(root->left != NULL) {
            root->left->next = root->right;
        }

        // Connection the right node to the next subtree left node
        if(root->right != NULL && root->next != NULL) {
            root->right->next = root->next->left;
        }

        // Doing the same job for subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};