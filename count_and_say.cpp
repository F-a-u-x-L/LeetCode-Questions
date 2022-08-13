#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {

    public:

    string countAndSay(int n) {

        // Base case
        if(n==1) {
            return "1";
        }

        // Recursion
        string str, ans;

        str = countAndSay(n-1);

        for(int i=0; i<str.length(); i++) {
            
            int count = 1;
            // example - if "21" is returned, we iterate over it and count the number of times a digit occurs in continuation
            // once we have the count, we convert the count to string and add the count string and the digit string
            while(str[i+1] && str[i] == str[i+1]) {
                count++;
                i++;
            }
            ans += to_string(count);
            ans += str[i];
        }

        return ans;
    }
};