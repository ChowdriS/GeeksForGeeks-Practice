#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long maximumSumSubarray(int size, vector<int> &nums , int n){
        
        long long  sum=0;
        for(int i=0;i<size;i++){
            sum+=nums[i];
        }
        
        long long ans=sum;
        
        for(int i=size;i<n;i++){
            sum-=nums[i-size];
            sum+=nums[i];
            ans=max(sum,ans);
        }
        
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 