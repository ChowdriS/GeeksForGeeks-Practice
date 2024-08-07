#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        int i = 0, j = 0;
        int val = 0;
        int ind = 0;
        while(i<m and j<n){
            if(arr1[i]<arr2[j]){
                val = arr1[i++];
                ind++;
            }
            else{
                val = arr2[j++];
                ind++;
            }
            if(ind==k)  return val;
        }
        if(i<m){
            while(i<m){
                ind++;
                if(ind==k)  return arr1[i];
                i++;
            }
        }
        else{
            while(j<n){
                ind++;
                if(ind==k)  return arr2[j];
                j++;
            }
        }
        return 0;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
