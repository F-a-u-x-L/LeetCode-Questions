#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    int m, n;
    vector<vector<bool>> visited;

    bool search(vector<vector<char>> &board, int i, int j, int index, string &word) {

        if(board[i][j] == word[index]) {

            visited[i][j] = true;

            if(index == word.length() - 1) {
                return true;
            }

            if( i-1 >= 0 && visited[i-1][j] == false) {
                if(search(board, i-1, j, index+1, word)) {
                    return true;
                }
            }

            if( i+1 < m && visited[i+1][j] == false) {
                if(search(board, i+1, j, index+1, word)) {
                    return true;
                }
            }

            if( j-1 >= 0 && visited[i][j-1] == false) {
                if(search(board, i, j-1, index+1, word)) {
                    return true;
                }
            }

            if( j+1 < n && visited[i][j+1] == false) {
                if(search(board, i, j+1, index+1, word)) {
                    return true;
                }
            }

            visited[i][j] = false;
            return false;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {

        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==word[0] && search(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};



// Alternate Solution

class Solution {

    public:

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index) {

        if(index==word.size()) {
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index]) {
            return false;
        }

        board[i][j] = '0';

        bool status =   dfs(board, word, i-1, j, index+1) ||
                        dfs(board, word, i+1, j, index+1) ||
                        dfs(board, word, i, j-1, index+1) ||
                        dfs(board, word, i, j+1, index+1) ;

        board[i][j] = word[index];

        return status;
    }

    bool exist(vector<vector<char>> board, string word) {

        if(word == "") {
            return false;
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};