/*
Problem : Game of XOR
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            if(((i + 1) & 1) and ((N - i) & 1)){
                ans ^= A[i];
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}