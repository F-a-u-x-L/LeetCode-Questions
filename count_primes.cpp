#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


// Brute Force Solution - results in TLE O(N^2)

class Solution {

    public:

    int countPrimes(int n){

        if(n==0 || n==1 || n==2) {
            return 0;
        }

        int count = 1;
        int i=3;
        unordered_set<int> primes;
        primes.insert(2);

        while(i<n) {
            bool flag = true;

            for(auto x : primes) {
                if(i % x == 0) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                primes.insert(i);
                count++;
            }

            i += 2;
        }

        return count;
    }
};


// Optimized solution - using Sieve of Eratosthenes 

class Solution {

    public:

    int countPrimes(int n) {
        vector<bool> sieve(n+1, true);
        sieve[0] = false;
        sieve[1] = false;

        for(int i=2; i*i<=n; i++) {
            if(sieve[i]) {
                for(int j=i*i; j<=n; j+=i) {
                    sieve[j] = false;
                }
            }
        }

        int count = 0;
        for(int i=2; i<n; i++) {
            if(sieve[i]) {
                count++;
            }
        }

        return count;
    }

};