/*
Problem : Candy
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> ans(N, 1);
        
        for(int i = 1; i < N; i++){
            if(ratings[i] > ratings[i - 1])
                ans[i] = max(ans[i], ans[i - 1] + 1);
        }
        
        for(int i = N - 2; i > -1; i--){
            if(ratings[i] > ratings[i + 1])
                ans[i] = max(ans[i], ans[i + 1] + 1);
        }
        
        return accumulate(ans.begin(), ans.end(), 0LL);
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}