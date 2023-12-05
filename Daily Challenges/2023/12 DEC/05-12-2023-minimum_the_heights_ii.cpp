#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int nums[], int n, int k) {
        
        sort(nums,nums+n);
        
        int ans=nums[n-1]-nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]<k)   continue;
            
            int minimum=min(nums[0]+k,nums[i]-k);
            int maximum=max(nums[n-1]-k,nums[i-1]+k);
            
            ans=min(ans,maximum-minimum);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}