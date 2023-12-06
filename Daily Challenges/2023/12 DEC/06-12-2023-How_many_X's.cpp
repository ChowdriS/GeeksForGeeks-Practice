#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countX(int l, int r, int X) {
        int res=0;

        for(int i=l+1;i<r;i++){
            int temp=i;
            while(temp){
                res+=( (temp%10)==X )?1:0;
                temp/=10;
            }
            
        }
        
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}