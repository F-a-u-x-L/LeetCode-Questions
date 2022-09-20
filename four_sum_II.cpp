#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;



// Brute Force Method   ->   TLE

class Solution {

    public:

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        
        int n = nums1.size();
        vector<int> arr1;
        vector<int> arr2;
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr1.push_back(nums1[i] + nums2[j]);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr2.push_back(nums3[i] + nums4[j]);
            }
        }

        for(int i=0; i<arr1.size(); i++) {
            for(int j=0; j<arr2.size(); j++) {
                if(arr1[i] + arr2[j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};



class Solution {

    public:

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        
        unordered_map<int, int> track;
        int count = 0;
        int n = nums1.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                track[nums1[i] + nums2[j]]++;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(track[0-(nums3[i] + nums4[j])]) {
                    count += track[0-(nums3[i] + nums4[j])];
                }
            }
        }

        return count;
    }
};