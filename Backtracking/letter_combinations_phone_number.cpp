#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;

// Mapping all of the numbers and their alphabets to access them instantly
unordered_map<char, string> mapper({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

class Solution {

    public:

    vector<string> letterCombinations(string digits) {
        int length = digits.size();
        vector<string> ans;
        if(!length) return ans;

        dfs(0, length, "", ans, digits);

        return ans;
    }

    void dfs(int pos, int &length, string str, vector<string> &ans, string &digits) {
        if(pos == length) {
            ans.push_back(str);
        } else {
            // Get the letters for that particular digit
            string letters = mapper[digits[pos]];


            // Iterate over all the letters of a particular digit and call the fuction after adding one letters from 
            // a particular digit anf increase the position so that next digit can be accessed
            for(int i=0; i<letters.size(); i++) {
                dfs(pos+1, length, str+letters[i], ans, digits);
            }
        }
    }
};