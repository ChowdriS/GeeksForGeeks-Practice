/*
Problem : Count More than n/k Occurences
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> f;
        
        for(int i = 0; i < n; i++){
            ++f[arr[i]];
        }
        
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > (n / k);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

