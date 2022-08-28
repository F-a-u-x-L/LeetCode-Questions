#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    vector<int> spiralOrder(vector<vector<int>> &matrix) {  
        int startrow = 0;
        int startcol = 0;
        int endrow = matrix.size();
        int endcol = matrix[0].size();
        int i = 0, j = 0;
        vector<int> ans;

        while(true) {
            while(j<endcol) {
                ans.push_back(matrix[i][j]);
                j++;
            }
            startrow++;
            j--;
            i++;
            if(startrow == endrow) break;

            while(i<endrow) {
                ans.push_back(matrix[i][j]);
                i++;
            }
            endcol--;
            i--;
            j--;
            if(endcol == startcol) break;

            while(j>=startcol) {
                ans.push_back(matrix[i][j]);
                j--;
            }
            endrow--;
            j++;
            i--;
            if(startrow == endrow) break;

            while(i>=startrow) {
                ans.push_back(matrix[i][j]);
                i--;
            }
            startcol++;
            i++;
            j++;
            if(startcol == endcol) break;
        }

        return ans;
    }
};