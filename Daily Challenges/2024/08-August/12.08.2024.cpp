#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        
        vector<int> temp(arr1.begin(),arr1.end());
        temp.insert(temp.begin(),arr2.begin(),arr2.end());
        sort(temp.begin(),temp.end());
        int m = temp.size();
        return m%2==0 ? (temp[m/2] + temp[m/2-1]) : temp[m/2];
        
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
