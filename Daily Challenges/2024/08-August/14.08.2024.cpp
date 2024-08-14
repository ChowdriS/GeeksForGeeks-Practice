#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int ans = 0;
        vector<vector<int>> dp(m+n,vector<int>(n+1,0));
        for(int i= 1; i<=m; i++){
            for(int j =1; j<=n; j++) {
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                // else dp[i][j] = 0;
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
