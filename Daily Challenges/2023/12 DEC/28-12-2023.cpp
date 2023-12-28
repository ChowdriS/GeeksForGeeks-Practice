/*
Problem : Wildcard string matching
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int n = wild.size();
        int m = pattern.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        dp[n][m] = 1;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = m - 1; j > -1; j--){
                if(wild[i] == '?')  
                    dp[i][j] = dp[i + 1][j + 1];
                else if(wild[i] == '*'){
                    if(i == n - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
                }
                else{
                    if(wild[i] == pattern[j])
                        dp[i][j] = dp[i + 1][j + 1];
                    else
                        dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][0];
    }
};

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}