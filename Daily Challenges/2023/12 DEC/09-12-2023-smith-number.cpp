#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int sum_digit(int num){  // sum of the digits of a number
        int sum=0;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
  
    int smithNum(int n) {
        
        vector<int> sieve (n+1,1e5);  // to find the minimum prime factor of a number
        
        for(int i=2;i<n+1;i++){
            if(sieve[i]==1e5){
                sieve[i]=i;
                for(int j=i+i;j<n+1;j+=i){
                    sieve[j]=min(sieve[j],i);
                }
            }
        }
        
        
        if(sieve[n]==n){   // if the number itself a prime number
            return 0;
        }
        
        int sumA=0,sumB=0;
        
        sumA=sum_digit(n);
        
        while(n>1){
            sumB+=sum_digit(sieve[n]);  // to make the sum for factors too eg: 11 => 2
            n/=sieve[n];
        }
        
        return sumA==sumB;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
