/*
Problem : Problem : Array Pair Sum Divisibility Problem
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        unordered_map<int,int> mp;

        for(auto i:nums){

            int current=i%k;
            int need=(k-current)%k;

            if(mp.count(need)){
                mp[need]--;
                if(mp[need]==0){
                    mp.erase(need);
                }
            }
            else{
                mp[current]++;
            }

        }

        return mp.size()==0; 
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}