#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        sort(arr.begin(),arr.end());
        string first = arr[0];
        string last = arr.back();
        int n = min(first.size(),last.size());
        int i;
        for(i = 0; i<n ; i++) {
            if(first[i]!=last[i]){
                break;
            }    
        }
        if(i==0)    return "-1";
        return arr[0].substr(0,i);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}
