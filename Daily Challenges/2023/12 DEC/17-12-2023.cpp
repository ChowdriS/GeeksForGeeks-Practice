/*
Problem : Max Sum without Adjacents
*/


#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    int next_0, next_1;
	    next_0 = next_1 = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        int cur_0 = max(arr[i] + next_1, next_0);
	        int cur_1 = next_0;
	        
	        next_0 = cur_0;
	        next_1 = cur_1;
	    }
	    
	    return next_0;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}