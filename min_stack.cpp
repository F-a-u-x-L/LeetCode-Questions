#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {

    public:

    // The first value stores the latest number inserted and the second number stores the minimum number till now
    stack<pair<int, int>> rack;

    MinStack() {

    }

    void push(int val) {
        if(rack.empty()) {
            rack.push({val, val});
        }
        else {
            // If the stack is not empty, we calculate the minimum value till now and push the pair of current number and the minimum value in the stack
            int mini = min(rack.top().second, val);
            rack.push({val, mini});
        }
    }

    void pop() {
        rack.pop();
    }

    int top() {
        // To get the top element we return the first value of the pair
        return rack.top().first;
    }

    int getMin() {
        // To get the top element we return the second value of the pair
        return rack.top().second;
    }
};