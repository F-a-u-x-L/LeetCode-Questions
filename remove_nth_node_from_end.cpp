#include<iostream>
#include<vector>
using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}   
};

// Brute force solution

class Solution {

    public:

    ListNode* removeNthFromEnd(ListNode *head, int n) {

        ListNode *temp = head;
        int l = 0;

        // Getting the length of the list
        while(head != NULL) {
            l++;
            head = head->next;
        }

        // In case the first node is to be removed
        if(l-n == 0) return temp->next;

        head = temp;

        // Move the head before the node that is need to be removed
        for(int i=0; i<l-n-1; i++) {
            head = head->next;
        }

        // Remove the element by skipping it
        head->next = head->next->next;
        
        return temp;
    }
};


// Two pointer solution

class Solution {

    public:

    ListNode* removeNthFromEnd(ListNode *head, int n) {
        
        ListNode *fast = head;
        ListNode *slow = head;

        // Suppose we want to remove the 2nd last element, n = 2
        // fast     -   O   O   O   O   O   O   O
        // slow     -           O   O   O   O   O   O   O
        // Giving a head start to fast, so that when fast reaches end, the slow will reach the node to be removed;
        while(n != 0)
        {
            fast = fast->next;
            n--;
        }

        if(!fast) return head->next;

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};