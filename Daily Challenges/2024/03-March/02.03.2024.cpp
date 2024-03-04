#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]>=k)    return a[i];
        }
        // for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
        // int ans = INT_MAX;
        // for(auto it:mp){
        // }
        // if(ans==INT_MAX) return -1;
        return -1;
    }
};


int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}