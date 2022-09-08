#include<iostream>
#include<vector>
using namespace std;


// Making a staircase - time complexity O(m+n)

class Solution {

    public:

    bool searchMatrix(vector<vector<int>> &matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;

        while(i>=0 && i<m && j>=0 && j<n) {

            if(matrix[i][j] == target) {
                return true;
            }

            // If target value is greater than the current value, we increment the row
            if(matrix[i][j] < target) {
                i++;
            }
            // If target value is less than the current value, we decrement the column
            else if(matrix[i][j] > target) {
                j--;
            }
        }

        return false;
    }
};