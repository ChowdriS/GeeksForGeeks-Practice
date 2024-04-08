#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < m; i++){
            dp[n][i] = INT_MIN;
        }
        for (int i = n-1; i >=0 ; i--) {
            for (int j = m-1; j >= 0; j--) {
                dp[i][j] = max(dp[i+1][j], dp[i + 1][j + 1] + (a[i] * b[j]));
            }
        }
        return dp[0][0];
    } 
};



int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}
