/*
Problem : Buy Maximum Stocks if i stocks can be bought on i-th day
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>> info(n);
        
        for(int i = 0; i < n; i++){
            info[i].first = price[i];
            info[i].second = i + 1;
        }
        
        sort(info.begin(), info.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int qty = k / info[i].first;
            qty = min(qty, info[i].second);
            
            ans += qty;
            k -= qty * info[i].first;
        }
        
        return ans;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
