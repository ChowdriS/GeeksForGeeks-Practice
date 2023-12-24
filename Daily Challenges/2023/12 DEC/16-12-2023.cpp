/*
Problem : String's Count
*/


#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}


long long int countStr(long long int n){
    long long ans = 0;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(i + j > n)
                continue;
                
            long long curans = 1;
                
            long long total = n;
            if(j == 2){
                curans = (total * (total - 1)) / 2;
                total -= 2;
            }
            else if(j){
                curans = total;
                --total;
            }
            
            if(i)
                curans *= total;
                
            ans += curans;    
        }
    }
    
    return ans;
}