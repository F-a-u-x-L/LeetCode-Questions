#include<iostream>
#include<vector>
using namespace std;

// The following method is correct but has a time complexity of O(N^2) and leads to TLE

class Solution {

    public:

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int n = gas.size();

        // We get the difference between the cost and gas at each station
        for(int i=0; i<n; i++) {
            cost[i] = gas[i] - cost[i];
        }

        // We start from each index and check the sum
        // If the sum is negative it means that there is not enough fuel to move to next station, so we make the start from next index
        // If the sum >= 0, it means that there is enough fuel to make a circular trip
        for(int i=0; i<n; i++) {
            int sum = 0;
            int k = 0;

            while(k<n) {
                sum += cost[(i+k)%n];
                if(sum<0) {
                    break;
                }
                k++;
            }

            if(sum>=0) {
                return i;
            }
        }

        return -1;
    }
};




// Greedy Solution

class Solution {

    public:

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int n = gas.size();
        int curr_fuel = 0;
        int start = 0;
        int total_gas = 0;
        int total_cost = 0;

        // We calculate the total cost and total gas
        for(int i=0; i<n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        // If the total cost exceeds the total gas, it means we cannot complete the circular trip
        if(total_gas < total_cost) {
            return -1;
        }

        // If the current fuel becomes negative it means that we cannot go to the next gas station
        // Thus we discard the previous gas station as starting point and appoint a new one
        for(int i=0; i<n; i++) {
            
            if(curr_fuel < 0) {
                start = i;
                curr_fuel = 0;
            }

            curr_fuel += gas[i] - cost[i];
        }

        return start;
    }
};




// A little optimized code

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

    int n = gas.size();
    int total = 0;
    int curr_fuel = 0;
    int start = 0;

    // If the current fuel becomes negative it means that we cannot go to the next gas station
    // Thus we discard the previous gas station as starting point and appoint a new one
    for(int i=0; i<n; i++) {
        
        if(curr_fuel < 0) {
            start = i;
            curr_fuel = 0;
        }

        curr_fuel += gas[i] - cost[i];
        total += gas[i] - cost[i];
    }

    return total<0 ? -1 : start;
}