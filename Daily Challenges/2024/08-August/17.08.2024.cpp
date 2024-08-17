#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        vector<long long int> left;
        left.push_back(1);
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            left.push_back(left.back()*nums[i]);
        }
        vector<long long int> right;
        right.push_back(1);
        for(int i=n-1;i>0;i--) {
            right.insert(right.begin(),(right.front()*nums[i]));
        }
        vector<long long int> res;
        for(int i=0;i<n;i++){
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};


int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
