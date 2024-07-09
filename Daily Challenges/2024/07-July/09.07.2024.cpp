#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int ans = 0;
        int diff = INT_MAX;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int j = i+1; 
            int k = n-1;
            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(abs(sum-target)<=diff){
                    if(diff==abs(sum-target)){
                        ans = max(sum,ans);    
                    }
                    else{
                        diff = abs(sum-target);
                        ans = sum;
                    }
                }
                if(sum==target){
                    return sum;
                }
                if(sum>target){
                    k--;
                }
                if(sum<target){
                    j++;
                }
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
