/*
Problem : Largest Sum Subarray of Size at least K
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            dp[i] = a[i] + dp[i + 1];
            dp[i] = max(dp[i], 0LL);
        }
            
        long long ans = -1e18;
        
        long long cur_sum = 0;
        for(int i = 0; i < k; i++)
            cur_sum += a[i];
        
        for(int i = k; i < n; i++){
            long long sum = cur_sum + dp[i];
            ans = max(ans, sum);
            
            cur_sum += a[i];
            cur_sum -= a[i - k]; 
        }
        
        return max(ans, cur_sum);
    }
};

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
