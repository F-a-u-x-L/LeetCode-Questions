#include<iostream>
#include<vector>
using namespace std;


// Using counting sort

class Solution {

    public:

    void sortColors(vector<int> &nums) {

        vector<int> count(3,0);

        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }

        int k = 0;

        for(int i=0; i<count.size(); i++) {
            while(count[i] != 0) {
                nums[k] = i;
                count[i]--;
                k++;
            }
        }
    }
};


// O(1) Space Complexity

class Solution {

    public:

    void sortColors(vector<int> &nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        // The algorithm ensures that at any point, 
        // every element before low is 0, every element after high is 2, every element in between are either 0, 1 or 2 i.e. unprocessed.

        while( mid <= high ) {

            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};