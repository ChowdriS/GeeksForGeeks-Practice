#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> found;
        found[0] = 1;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(found.count(sum))
                return 1;
                
            found[sum]++;
        }
        
        return 0;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
