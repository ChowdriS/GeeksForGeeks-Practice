#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.size();
		    vector<string> result;
		    int pow_n = pow(2,n);
		    for(int i = 1;i<pow_n;i++){
		        string temp = "";
		        for(int j=0;j<n;j++){
		            if((1<<j) & i)    temp+=s[j];
		        }
		        if(temp!="") {
		            result.push_back(temp);
		        }
		    }
		    sort(result.begin(),result.end());
		    return result;
		}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}