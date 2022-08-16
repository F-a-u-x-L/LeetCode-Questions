#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// BRUTE FORCE SOLUTION - this leads to TLE

class Solution {

    public:

    bool isAnagram(string s1, string s2) {
        vector<int> test(26,0);

        if(s1.length() != s2.length()) {
            return false;
        }

        for(int i=0; i<s1.length(); i++) {
            test[s1[i] - 'a']++;
            test[s2[i] - 'a']--;
        }

        for(int i=0; i<test.size(); i++) {
            if(test[i] != 0) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // To store the result
        vector<vector<string>> res;
        // Map to keep a track of whether the element has been added to the result or not
        unordered_map<int, int> tracker;

        for(int i=0; i<strs.size(); i++) {

            vector<string> store;

            // To check if the element has already been added to result or not, if added skip the element now
            if(tracker[i] != 0) {
                continue;
            }

            // If not already visited, we first mark it in the map and then push it to a vector
            tracker[i]++;
            store.push_back(strs[i]);

            // We iterate from the next element as the previous elements would have already been visited
            for(int j=i+1; j<strs.size(); j++) {
                // If already visited, skip the element
                if(tracker[j] != 0) {
                    continue;
                }

                // Compare it with the initial element on the ith loop and if it is anagram, mark it on the map and push to store
                if(isAnagram(strs[i], strs[j])) {
                    tracker[j]++;
                    store.push_back(strs[j]);
                }
            }

            // Push the store to the result vector
            res.push_back(store);
        }

        return res;
    }
};



// Solution with time complexity O(N)

class Solution {

    public:

    vector<vector<string>> groupAnagrams(vector<string> strs) {

        // Base Case
        if(strs.size() == 1) {
            return {{strs[0]}};
        }

        vector<vector<string>> res;
        unordered_map<string, vector<string>> tracker;

        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];

            // We sort the element - this leads to the element getting alphabetically sorted
            // This makes it easier to store elements that are anagram
            sort(strs[i].begin(), strs[i].end());
            tracker[strs[i]].push_back(str);
        }

        // Then we iterate over the map and push the vector of strings to result
        for(auto x : tracker) {
            res.push_back(x.second);
        }

        return res;
    }
};