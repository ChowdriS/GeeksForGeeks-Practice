#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& arr, bool flag, int prev){
        int cnt = 1;
        for(auto it : arr) {
            if(flag){
                if(prev < it){
                    cnt++;
                    flag = !flag;
                }
                prev = it;
            }
            else{
                if(prev > it){
                    cnt++;
                    flag = !flag;
                }
                prev = it;
            }
        }
        return cnt;
    }
  public:
    int alternatingMaxLength(vector<int>& arr) {
        return max(solve(arr,false,INT_MIN),solve(arr,true,INT_MAX));
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
