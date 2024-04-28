#include "bits/stdc++.h"
using namespace std;


class Solution{   
public:
    vector<int> frequency(int n, vector<int> &a){
        unordered_map<int,int> mp;
        for(auto iter : a) {
            mp[iter]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(mp[a[i]]--);
        }
        return res;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        vector<int>ans=ob.frequency(n, a);
        for(auto it:ans)
            cout<<it<<" ";
        cout<<endl;
    }
}