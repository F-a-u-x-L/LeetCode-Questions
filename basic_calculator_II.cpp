#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {

    public:

    int calculate(string s) {

        stack<string> calc;
        int res;

        for(int i=0; i<s.length(); i++) {

            string str;
            if(s[i]>='0' && s[i]<='9') {
                while(i<s.length() && s[i]>='0' && s[i]<='9') {
                    str += s[i];
                    i++;
                }
                calc.push(str);
                i--;
            }
            else if(s[i]=='*' || s[i]=='/') {
                char sign = s[i];
                i++;
                while(i<s.length() && s[i]!='*' && s[i]!='+' && s[i]!='/' && s[i]!='-') {
                    if(s[i]==' ') {
                        i++;
                        continue;
                    }
                    str += s[i];
                    i++;
                }
                i--;
                int c = sign=='*' ? stoi(calc.top())*stoi(str) : stoi(calc.top())/stoi(str);
                calc.pop();
                calc.push(to_string(c));
            }
            else if(s[i]=='+' || s[i]=='-') {
                calc.push(to_string('+'));
                if(s[i] == '-') {
                    i++;
                    while(i<s.length() && s[i]>='0' && s[i]<='9') {
                        str += s[i];
                        i++;
                    }
                    i--;
                    int num = stoi(str) * (-1);
                    calc.push(to_string(num));
                }
            }
        }

        while(!calc.empty()) {
            int b = stoi(calc.top());
            calc.pop();
            if(calc.empty()) {
                res = b;
                break;
            }
            string sign = calc.top();
            calc.pop();
            int a = stoi(calc.top());
            calc.pop();
            int ans = a+b;
            calc.push(to_string(ans));
        }

        return res;
    }
};


class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk; 
        
        long long int ans = 0, curr = 0;
        char sign = '+'; //to store the previously encountered sign
        
        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0'); //keep forming the number, until you encounter an operator
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                
                if(sign == '+') stk.push(curr); //'Cause it has to added to the ans
            
                else if(sign == '-') stk.push(curr*(-1)); //'Cause it has to be subtracted from ans
                
                else if(sign == '*'){
                    int num = stk.top(); 
                    stk.pop();  //Pop the top of the stack
                    stk.push(num*curr); //Multiply it with the current value & push the result into stack
                }
                
                else if(sign == '/'){
                    int num = stk.top();
                    stk.pop(); 
                    stk.push(num/curr);  //Divide it with curr value & push it into the stack
                }
                
                curr = 0; 
                sign = s[i]; 
            }
            
        }
        
        while(stk.size()) {
            ans += stk.top(); 
            stk.pop();
        }
            
        return ans;    
    }
};