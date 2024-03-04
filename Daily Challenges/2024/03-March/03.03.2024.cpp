#include <bits/stdc++.h>

using namespace std;


class Solution{
public:

	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(),arr.end(),[](auto& x,auto& y){
	       string xy = x,yx = y;
	       xy+=y;yx+=x;
	       return xy>yx ? 1: 0;
	    });
	    string ans = "";
	    for(auto it : arr){
	        ans += it;
	    }
	    return ans;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}