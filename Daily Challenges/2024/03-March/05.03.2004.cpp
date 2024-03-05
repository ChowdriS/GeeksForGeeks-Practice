#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        
    int maxIndexDiff(int arr[], int n) 
    { 
        int i = 0, j = n-1, ans = 0;
        while(i<n){
            if(arr[i]>arr[j]){
                j--;
            }
            else{
                ans = max(ans,(j-i));
                i++;
                j=n-1;
            }
        }
        return ans;
    }
};

  
int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 