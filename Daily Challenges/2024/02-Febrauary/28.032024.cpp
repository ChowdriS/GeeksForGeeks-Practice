#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        if(n<=3){
            if(stoi(s)%8==0)    return 1;
            // else return -1;
        }
        else{
            string last_three = "";
            last_three = last_three+s[n-3]+s[n-2]+s[n-1];
            if(stoi(last_three)%8==0)   return 1;
            // else return -1
        }
        return -1;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}