#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {

    public:

    ListNode *sortList(ListNode *head) {

        vector<int> res;

        // We insert all the values into a vector and sort it
        // Alternatively a priority queue can be used as well
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }

        sort(res.begin(), res.end());
        ListNode *root = new ListNode(0);
        head = root;

        // Iterate over the vector an created a new list
        for(int i=0; i<res.size(); i++) {
            ListNode *temp = new ListNode(res[i]);
            root->next = temp;
            root = root->next;
        }

        root->next = NULL;

        return head->next;
    }
};




// The following solution has a time complexity of O(N log N) ans space complexity of O(N)
// We make use of merge sort in the solution

class Solution {

    public:

    ListNode *getMid(ListNode *head) {

        ListNode *midPrev = nullptr;
        while(head && head->next) {

            midPrev = (midPrev==nullptr) ? head : midPrev->next;
            head = head->next->next;
        }

        ListNode *mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }

    ListNode *mergeList(ListNode *list1, ListNode *list2) {

        ListNode *dummy = new ListNode(0);
        ListNode *ptr = dummy;

        while(list1 && list2) {

            if(list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                list2 = list2->next;
            }

            ptr = ptr->next;
        }

        if(list1) {
            ptr->next = list1;
        }
        else {
            ptr->next = list2;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        if(!head || !head->next) {
            return head;
        }

        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return mergeList(left, right);
    }
};