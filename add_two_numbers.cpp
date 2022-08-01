#include<iostream>
#include<vector>
using namespace std;

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    public: 

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        // Initialize the ListNode
        ListNode *head = new ListNode(0);
        // Assigning a node to keep adding nodes
        ListNode *curr = head;
        int carry = 0;

        // We loop until both l1 and l2 are not null and carry is equal to 1
        while(l1!=NULL || l2!=NULL || carry==1) {
            int sum = 0;

            // If l1 is not null, then add it to sum
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If l2 is not null, then add it to sum
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry to sum and update carry
            sum += carry;
            carry = sum / 10;

            // Create new node and link curr to it
            ListNode *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
        }

        // Increment head and return the ListNode
        head = head->next;
        return head;
    }
};