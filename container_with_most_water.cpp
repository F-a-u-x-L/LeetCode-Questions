#include<iostream>
#include<vector>
using namespace std;

// A brute force method would be to grab one element and gop through the remaining element calculating the vol.
// This results in a time complexity of O(N^2)

// The following method uses greedy algorithm to solve the problem in O(N) time

// We take two pointers, start and end
// Calculate the area between that and compare it with previous area to get the maximum
// Depending upon whether the start value or end value is greater we make the adjustment
// The pointer with the greater value is kept as it is and the other pointer is incremented or decremented

class Solution {

    public:

    int maxArea(vector<int> &height) {
        int area = 0;
        int start = 0;
        int end = height.size() - 1;

        while(start < end) {
            int currArea;
            currArea = (end - start) * min(height[start], height[end]);

            area = max(area, currArea);

            if(height[start] > height[end]) {
                end--;
            }
            else if(height[start] < height[end]) {
                start++;
            }
            else {
                start++;
                end--;
            }
        }

        return area;
    }
};