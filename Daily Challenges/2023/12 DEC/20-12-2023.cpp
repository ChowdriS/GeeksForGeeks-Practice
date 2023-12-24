/*
Problem : Modified Game of Nim
*/



#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int findWinner(int n, int A[]){
        int val = 0;
        
        for(int i = 0; i < n; i++)
            val ^= A[i];
        
        return ((n & 1) and val > 0) ? 2 : 1;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}