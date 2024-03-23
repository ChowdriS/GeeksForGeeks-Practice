#include <bits/stdc++.h>
using namespace std;


// s : given string to search
// dictionary : vector of available strings

class Solution
{
    private:
    unordered_map<string,bool> dp;
    bool solve(string s,unordered_set<string> &sp){
        if(s.size()==0)     return true;
        if(dp.find(s)!=dp.end())    return dp[s];
        for(int i =0;i<s.size();i++){
            string temp = s.substr(0,i+1);
            if(sp.count(temp)){
                if(solve(s.substr(i+1),sp)){
                    return dp[s]=true;
                }
            }
        }
        return dp[s]=false;
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_set<string> sp;
        for(auto iter : dictionary){
            sp.insert(iter);
        }
        return solve(s,sp);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}
