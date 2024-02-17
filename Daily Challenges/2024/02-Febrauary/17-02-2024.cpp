#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        queue<int> qp;
        qp.push(arr[0]);
        for(int i = 1; i<n; i++){
            
            auto root = qp.front();
            qp.pop();
            
            if(arr[i]>root) return 0;
            qp.push(arr[i]);
            
            if( i+1 < n ){
                if(arr[i+1]>root)  return 0;
                qp.push(arr[i+1]);
                i++;
            }
            
        }
        return 1;
    }
};

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}
