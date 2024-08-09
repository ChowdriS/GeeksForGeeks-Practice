#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int Maximize(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        // int res = accumulate(arr.begin(),arr.end(),0,[](int it1, int it2){
        //   static int index = 0;
        //   int mod = 1e9 + 7;
        // //   cout<<it1<<" "<<it2<<'-';
        //   int cal = (it1 + it2*index)%mod;
        // //   cout<<cal<<endl;
        //   index++;
        //   return cal;
        // });
        int n = arr.size();
        int mod = 1e9 + 7;
        int res = 0;
        for(int i = 0; i<n; i++){
            res = (res + 1ll*arr[i]*i)%mod;
        }
        return res;
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
