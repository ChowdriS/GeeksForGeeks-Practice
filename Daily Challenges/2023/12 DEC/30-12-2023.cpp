/*
Problem : Winner of an election
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


class Solution{
  public:
  
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> votes;
        
        for(int i = 0; i < n; i++)
            ++votes[arr[i]];
            
        int best = 0;
        vector<string> ans(2);
        
        for(auto i : votes){
            if(i.second > best){
                best = i.second;
                ans[0] = i.first;
                ans[1] = to_string(best);
            }
            else if(i.second == best and i.first < ans[0]){
                ans[0] = i.first;
            }
        }
        
        return ans;
    }
};


int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
