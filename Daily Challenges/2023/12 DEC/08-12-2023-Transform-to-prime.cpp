#include <bits/stdc++.h>
using namespace std;

bool flag=0;
vector<int> primes;

class Solution
{
    private:
    long long mod = 1e6+10;
    public:
    int minNumber(int arr[],int N)
    {
        if(!flag){
            vector<int> erato(mod,1);
            erato[0] = erato[1] = 0;
            
            for(int i=2;i*i<mod;i++){
                if(erato[i]){
                    for(int j=i+i;j<mod;j+=i){
                        erato[j]=0;
                    }
                }
            }
            
            for(int i=0;i<mod;i++){
                if(erato[i]){
                    primes.push_back(i);
                }
            }
            flag=1;
        }
        
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        auto ans=lower_bound(primes.begin(),primes.end(),sum);
        
        return *ans-sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}