#include<iostream>
#include<vector>
using namespace std;

// For 90deg    :   Transpose -> Swap columns
// For 180deg   :   Swap columns -> Swap rows
// For 270deg   :   Transpose -> Swap rows

class Solution {

    public:

    void rotate(vector<vector<int>> &matrix) {

        int n = matrix.size();

        // Transpose the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i<j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // Swap the elements
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }

    }
};



// Alternate method to transpose

class Solution {

    public:

    void rotate(vector<vector<int>> &matrix) {

        int n = matrix.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }

};