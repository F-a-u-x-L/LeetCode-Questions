#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {

    public:

    string longestPalindrome(string s) {
        
        int n = s.size();

        // table[i][j] will be false if s[i.....j] is not a palindrome
        // otherwise table[i][j] will be true
        bool table[n][n];
        memset(table, 0, sizeof(table));


        // Making all diagonal elements true as substrings of length 1 will always be palindrome
        for(int i=0; i<n; i++) {
            table[i][i] = true;
        }

        // Checking if substrings of length 2 are palindrome or not
        int start = 0;
        int end = 1;

        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true;
                start = i;
                end = 2;
            }
        }

        // Checking for substrings with length greater tham 2
        for(int j=2; j<n; j++) {

            for(int i=0; i<n-j; i++) {

                int left = i;
                int right = i+j;

                if(table[left+1][right-1] && s[left]==s[right]) {
                    table[left][right] = true;
                    start = i;
                    end = j+1;
                }
            }
        }

        return s.substr(start, end);
    }
};