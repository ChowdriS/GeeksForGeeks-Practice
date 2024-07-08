#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int search(vector<int>& arr, int key) {
        auto it = find(arr.begin(),arr.end(),key);
        if(it==arr.end()){
            return -1;
        }
        else{
            return distance(arr.begin(),it);
        }
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
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
