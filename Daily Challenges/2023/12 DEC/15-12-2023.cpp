/*
Problem : Reach the Nth point
*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int nthPoint(int n){
		    long long a, b;
		    a = b = 1;
		    
		    const long long mod = 1e9 + 7;
		    
		    for(int i = 1; i < n; i++){
		        long long c = (a + b) % mod;
		        a = b;
		        b = c;
		    }
		    
		    return b;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}