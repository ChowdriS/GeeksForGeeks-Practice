#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int zeros = 0, ones = 0;
        for(auto it : arr) {
            it ? ones++ : zeros++;
        }
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(zeros){
                arr[i] = 0;
                zeros--;
            }
            else {
                arr[i] = 1;
                ones--;
            }
        }
    }
};

int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
