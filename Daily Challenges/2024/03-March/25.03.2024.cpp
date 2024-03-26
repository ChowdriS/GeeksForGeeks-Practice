#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	
    void solve(vector<string> &result, string &temp, int n, int count)
    {
        if(n == 0)
        {
            result.push_back(temp);
            return ;
        }
        temp += '1';
        solve(result, temp, n - 1, count + 1);
        temp.pop_back();
        if(count > 0)
        {    
            temp += '0';
            solve(result, temp, n - 1, count - 1);
            temp.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> result;
	    string temp = "";
	    solve(result, temp, n, 0);
	    return result;
	}
};

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}