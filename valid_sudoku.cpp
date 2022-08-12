#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {

    public:

    bool isValidMap(unordered_map<char, int> &tracker) {

        for(auto x : tracker) {
            if(x.second > 1) {
                return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board) {

        unordered_map<char, int> tracker;


        // Checking the rows
        for(int i=0; i<9; i++) {

            for(int j=0; j<9; j++) {

                if(board[i][j]>'0' && board[i][j]<='9') {
                    tracker[board[i][j]]++;
                }
            }

            if(!isValidMap(tracker)) {
                return false;
            }

            tracker.clear();
        }


        // Checking the columns
        for(int i=0; i<9; i++) {

            for(int j=0; j<9; j++) {

                if(board[j][i]>'0' && board[j][i]<='9') {
                    tracker[board[j][i]]++;
                }
            }

            if(!isValidMap(tracker)) {
                return false;
            }

            tracker.clear();
        }


        // Checking the blocks
        int row=0, col=0;

        while(row<9) {

            while(col<9) {

                for(int i=row; i<row+3; i++) {

                    for(int j=col; j<col+3; j++) {

                        if(board[i][j]>'0' && board[i][j]<='9') {
                            tracker[board[i][j]]++;
                        }
                    }
                }

                if(!isValidMap(tracker)) {
                    return false;
                }

                tracker.clear();

                col +=3;
            }

            col = 0;
            row += 3;
        }

        return true;
    }
};