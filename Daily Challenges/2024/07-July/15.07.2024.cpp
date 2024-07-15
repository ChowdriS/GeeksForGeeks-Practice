#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestNumber(int s, int d) {
        if((d*9)<s)     return "-1";
        string res = "";
        int temp = d;
        while(temp--){
            if((temp*9)>=s and temp!=(d-1)){
                res += string(1,'0');
            }
            else if(d==0 and s<=9){
                res += to_string(s);
            }
            else{
                for(int i = 1; i<=9; i++) {
                    if((temp*9)>=(s-i)){
                        res += to_string(i);
                        s-=i;
                        break;
                    }
                }
            }
        }
        return res;
    }
};


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
