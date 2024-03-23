#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int mod = 1e9+7;
  public:
    vector<int> Series(int n) {
        if(n==0)    return {0};
        if(n==1)    return {0,1};
        vector<int> ans(n+1);
        ans[1] = 1;
        for(int i = 2; i<=n; i++) {
            ans[i] = (ans[i-1] + ans[i-2])%mod;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}