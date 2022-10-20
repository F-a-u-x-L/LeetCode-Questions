#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {

    public:

    bool helper(vector<vector<int>> &prerequisites, unordered_set<int> &courseToBeTaken, int i, int current) {
        // Base Case
        if(i >= prerequisites.size()) {
            return true;
        }

        if(prerequisites[i][0]==current && (courseToBeTaken.find(prerequisites[i][1]) == courseToBeTaken.end())) {
            courseToBeTaken.insert(prerequisites[i][0]);
            return helper(prerequisites, courseToBeTaken, 0, prerequisites[i][1]) && helper(prerequisites, courseToBeTaken, i+1, current);
        }
        else if(prerequisites[i][0]==current && (courseToBeTaken.find(prerequisites[i][1]) != courseToBeTaken.end())) {
            return false;
        }
        else if(prerequisites[i][0] != current) {
            return helper(prerequisites, courseToBeTaken, i+1, current);
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        unordered_set<int> courseToBeTaken;

        for(int i=0; i<prerequisites.size(); i++) {

            courseToBeTaken.insert(prerequisites[i][0]);
            if(!helper(prerequisites, courseToBeTaken, 0, prerequisites[i][1])) {
                return false;
            }
            courseToBeTaken.clear();
        }

        return true;
    }
};


class Solution {

    public:

    bool helper(vector<vector<int>> &prerequisites, unordered_set<int> &courseToBeTaken, int current) {
        
        for(int i=0; i<prerequisites.size(); i++) {

            if(current == prerequisites[i][1]) {
                if(courseToBeTaken.find(prerequisites[i][0]) != courseToBeTaken.end()) {
                    return false;
                }
                else {
                    courseToBeTaken.insert(prerequisites[i][0]);
                    helper(prerequisites, courseToBeTaken, prerequisites[i][1]);
                }
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        unordered_set<int> courseToBeTaken;

        for(int i=0; i<prerequisites.size(); i++) {

            courseToBeTaken.insert(prerequisites[i][0]);
            if(!helper(prerequisites, courseToBeTaken, prerequisites[i][1])) {
                return false;
            }
            courseToBeTaken.clear();
        }

        return true;
    }
};



// Correct answer

class Solution {
public:
    int WHITE = 0;  // Unvisited
    int GREY = 1;   // Explore incomplete
    int BLACK = 2;  // Fully explored
    
    // return true if no cycle otherwise return false
    bool dfs(int node, vector<vector<int>>&graph,vector<int>&visited)
    {
        visited[node] = GREY;
        
        // go thourgh all parent nodes i.e., prerequisites courses
        for(int j=0;j<graph[node].size();j++)
        {
            // If end up in an unexplored node then it is a cycle and return false
            if(visited[graph[node][j]]==GREY) return false;
            
            // Explore all unvisited parent node
            if(visited[graph[node][j]]==WHITE)
                if(!dfs(graph[node][j],graph,visited)) return false;    // return false if find cycle
        }
        
        visited[node] = BLACK;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // create graph for each course to prerequisites Adjacency List
        vector<vector<int>>graph(numCourses);
        
        // Visited track of each node
        vector<int>visited(numCourses,WHITE);
        
        // Populate graph 
        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        // Run DFS on each unvisited node
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==WHITE)
                if(!dfs(i,graph,visited))return false;  // return false if detect cycle
        }
            
        return true;
    }
};