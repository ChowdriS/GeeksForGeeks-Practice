#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string printString(string s, char ch, int count) {
        int cnt = 0;
        auto ind = 0;
        while(cnt < count) {
            ind = s.find(ch, ind);
            if(ind == string::npos){
                return "";
            }
            cnt++;
            ind++;
        }
        return s.substr(ind);
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
