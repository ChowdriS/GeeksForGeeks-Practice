#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long helper(long long n) {
        if (n < 0) return 0; 
        if (n == 0) return 1; 
        
        long long cnt = 0;
        for (long long i = 1; i <= 2; i++) { 
            cnt += helper(n - i);
        }
        return cnt;
    }

public:
    long long countWays(int n) {
       vector<int> dp(n+1);
       dp[0] = 1;
       dp[1] = 1;
       for(int i = 2; i<= n; i++){
           dp[i] = dp[i-1] + dp[i-2];
       }
    //   return dp[n];
       return n/2+1;
    }
};



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; 
    }
    return 0;
}