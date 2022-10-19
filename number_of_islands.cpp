#include<iostream>
#include<vector>
using namespace std;

class Solution {

    public:

    void DFS(vector<vector<char>> &grid, int i,  int j) {

        // Boundary check
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) {
            return;
        }
        // Return if current position is of water or is already visited
        if(grid[i][j]=='2' || grid[i][j]=='0') {
            return;
        }

        // Mark the current positon as visited
        grid[i][j] = '2';

        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }

    int numIslands(vector<vector<char>> &grid) {

        int islands = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {

                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};