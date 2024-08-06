#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int check(string it){
        if(it=="" or it.size()>3)  return 0;
        bool temp = any_of(it.begin(),it.end(),[](char ch){
           return (ch>='a' and ch<='z') or (ch>='A' and ch<='Z'); 
        });
        if(temp)    return 0;
        int val = stoi(it);
        if(val<=9 and it.size()!=1)     return 0;
        if(val<0 or val>255)   return 0;
        return 1;
    }
  public:
    int isValid(string str) {
        string ans= "";
        int cnt = 0;
        for(auto it : str){
            if(it=='.'){
                cnt++;
                if(!check(ans)) return 0;
                ans = "";
            }
            else {
                ans += it;
            }
        }
        if(++cnt!=4)    return 0;
        if(!check(ans)) return 0;
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
