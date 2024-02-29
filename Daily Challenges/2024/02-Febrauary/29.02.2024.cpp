#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0;
	    for(int i=31;i>=0;i--){
	        long long cnt = 0;
	        for(int j=0;j<n;j++){
	            if((arr[j]&(1<<i))) {
	                cnt++;
	            }
	        }
	        ans+=(cnt)*(n-cnt);
	    }
	    return ans*2;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}