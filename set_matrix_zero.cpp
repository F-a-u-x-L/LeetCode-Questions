#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Space Complexity - O(m+n)
class Solution {

    public:

    void setZeroes(vector<vector<int>> &matrix) {

        vector<int> rows(matrix.size(), 1);
        vector<int> cols(matrix[0].size(), 1);

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    // If the element is zero store its correnponding indices
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(rows[i]==0 || cols[j]==0) {
                    // If the idices of the current elementare marked 0, change the element to zero
                    matrix[i][j] = 0;
                }
            }
        }
    }
};




// Space Complexity - O(1)

class Solution {

    public:

    void setZeroes(vector<vector<int>> &matrix) {

        int m = matrix.size();
        int n =matrix[0].size();
        bool firstRow = false;      // To check if we need to set first row as zero
        bool firstCol = false;      // To check if  we need to set second row to zero

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    if(i==0) {
                        firstRow = true;
                    }
                    if(j==0) {
                        firstCol = true;
                    }

                    // Mark the first row and first column indices that are to be zero
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    // If the first row or first column of the corresponding element is 0, make that element 0
                    matrix[i][j] = 0;
                }
            }
        }

        // If first row and column are to be converted to zero
        if(firstRow) {
            for(int i=0; i<n; i++) {
                matrix[0][i] = 0;
            }
        }

        if(firstCol) {
            for(int j=0; j<m; j++) {
                matrix[j][0] = 0;
            }
        }
    }
};