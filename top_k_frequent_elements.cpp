#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;



// Solution using map and extra array   :   Time complexity - O(NlogN)

class Solution {

    public:

    vector<int> topFrequent(vector<int> &nums, int k) {

        vector<int> ans;
        vector<vector<int>> arr;
        unordered_map<int, int> freq;

        // We use map to store the frequency of each element occuring in the array
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }

        // We iterate over the map and push the pairs in an array such that the frequency acts as the first element of the pair
        for(auto x : freq) {
            arr.push_back({x.second, x.first});
        }

        // Sorting the array according to their frequncies
        sort(arr.begin(), arr.end());

        // Pushing the top k frequent elements into the ans array
        int i=1;
        int n = arr.size();
        while(k!=0) {
            ans.push_back(arr[n-i][1]);
            i++;
            k--;
        }

        return ans;
    }
};




// Solution using map and priority queue    :   Time complexity - O(NlogN)

class Solution {

    public:

    vector<int> topFrequent(vector<int> &nums, int k) {

        vector<int> ans;
        unordered_map<int, int> track;
        priority_queue<pair<int, int>> q;

        // We use map to store the frequency of each element occuring in the array
        for(int i=0;  i<nums.size(); i++) {
            track[nums[i]]++;
        }

        // In the priority queue we insert the pair such that, the frequency acts as the first element of pair
        // This ensures that the priority queue is implemented on the basis of the frequencies
        for(auto x : track) {
            q.push({x.second, x.first});
        }

        // Selecting the top k elements from the queue
        while(k != 0) {
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }

        return ans;
    }
};




// Solution using bucket sort   :   Time complexity - O(N)

class Solution {

    public:

    vector<int> topFrequent(vector<int> &nums, int k) {

        vector<int> ans;
        unordered_map<int, int> track;
        vector<vector<int>> bucket(nums.size() + 1);

        // We use map to store the frequency of each element occuring in the array
        for(int i=0;  i<nums.size(); i++) {
            track[nums[i]]++;
        }

        // We now use another 2d-array, and use it's indices as frequency
        // Each index stores an array that contains all the elements of a particular frequency
        for(auto x : track) {
            bucket[x.second].push_back(x.first);
        }

        // We now iterate over the bucket array and pull out the numbers that are most frequent
        for(int i=nums.size(); k; i--) {
            for(auto num : bucket[i]) {
                ans.push_back(num);
                k--;
            }
        }
        
        return ans;
    }
};