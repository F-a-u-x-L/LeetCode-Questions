#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;



// SOLUTION USING SLIDING WINDOW CONCEPT

class Solution {

    public:

    int lengthOfLongestSubstring(string s) {
        
        int i=0, j=0;
        unordered_map<char, int> track;
        int res = INT_MIN;

        if(s.length() == 0) {
            return 0;
        }

        while(j < s.length()) {

            track[s[j]]++;

            // If the below condition satisfies it means that the substring has all uniwue elements
            if(track.size() == j-i+1) {
                res = max(res, j-i+1);
                j++;
            }
            // If track size is less, it means that there are repeating characters in the substring
            else if(track.size() < j-i+1) {
                // We remove the elements from the start till the tack size becaomes equal to the length of the substring
                while(track.size() < j-i+1) {
                    track[s[i]]--;
                    if(track[s[i]] == 0) {
                        track.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }

        return res;
    }
};