#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{

public:
    Node *copyRandomList(Node *head)
    {
        // We need a map to keep the track of all the nodes and the addreses from where they came from
        // Since we need to assign for two pointers, next and random, with random being any node not in order
        // We need all the nodes to be created first with a way of keep a track of their origin address for connections
        unordered_map<Node *, Node *> track;
        Node *ptr = head;

        // Populatng the map with the ponters and their corresponding new nodes
        while (ptr)
        {
            track[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;

        // Now we connect the newly generated nodessuch that the next pointer and random pointer point to the correct node
        // Since we have a track of all the nodes, we don't have to care about which node is to be created frist and in which order
        while (ptr)
        {
            track[ptr]->next = track[ptr->next];
            track[ptr]->random = track[ptr->random];
            ptr = ptr->next;
        }

        return track[head];
    }
};