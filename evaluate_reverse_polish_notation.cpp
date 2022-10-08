#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {

    public:

    int evalRPN(vector<string> &tokens) {

        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        stack<int> s;
        int ans;
        int a, b;

        for(int i=0; i<tokens.size(); i++) {

            if(tokens[i]=="/" || tokens[i]=="*" || tokens[i]=="+" || tokens[i]=="-") {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                if(tokens[i] == "/") {
                    ans = a / b;
                }
                else if(tokens[i] == "*") {
                    ans = a * b;
                }
                else if(tokens[i] == "+") {
                    ans = a + b;
                }
                else {
                    ans = a - b; 
                }

                s.push(ans);
            }
            else {
                s.push(stoi(tokens[i]));
            }
        }

        return ans;
    }
};



// Solving in O(1) space complexity

class Solution {

    public:

    int evalRPN(vector<string> &tokens) {

        int top = 0;

        for(int i=0; i<tokens.size(); i++) {

            if(tokens[i]=="/" || tokens[i]=="*" || tokens[i]=="+" || tokens[i]=="-") {
                int b = stoi(tokens[--top]);
                int a = stoi(tokens[--top]);

                if(tokens[i] == "/") {
                    a = a / b;
                }
                else if(tokens[i] == "*") {
                    a = a * b;
                }
                else if(tokens[i] == "+") {
                    a = a + b;
                }
                else {
                    a = a - b; 
                }

                tokens[top++] = to_string(a);
            }
            else {
                tokens[top++] = tokens[i];
            }
        }

        return stoi(tokens[0]);
    }
};