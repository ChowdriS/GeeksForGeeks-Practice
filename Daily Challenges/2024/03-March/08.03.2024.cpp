#include <bits/stdc++.h>
using namespace std;

#define N 26
class Solution{
private:
    bool allSame(vector<int>& alpha,int n){
        int same = 0;
        for(int i = 0;i<n;i++){
            if(alpha[i]>0){
                same = alpha[i];
                break;
            }  
        }
        for(int i =0;i<n;i++){
            if(alpha[i]>0 and same!=alpha[i]){
                return false;
            }
        }
        return true;
    }
public:	
	bool sameFreq(string s)
	{
	   vector<int> alpha(N,0);
	   for(auto iter : s){
	       alpha[iter-'a']++;
	   }
	   if(allSame(alpha,N)){
	       return true;
	   }
	   for(int i = 0;i<N;i++){
	       if(alpha[i]>0){
	           alpha[i]--;
	           if(allSame(alpha,N)){
	               return true;
	           }
	           alpha[i]++;
	       }
	   }
	   return false;
	}
};


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


