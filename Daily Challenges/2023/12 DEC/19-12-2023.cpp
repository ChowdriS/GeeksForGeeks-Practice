/*
Problem : Rightmost different bit
*/



#include <bits/stdc++.h>
using namespace std;
 

class Solution
{
    public:
    int posOfRightMostDiffBit(int m, int n)
    {
        for(int i = 0; i < 32; i++){
            int x = (m >> i) & 1;
            int y = (n >> i) & 1;
            
            if(x != y)
                return i + 1;
        }
        
        return -1;
    }
};

int main()
{   
    int t;
    cin>>t; 
    while(t--)
    {
         int m,n;
         cin>>m>>n;
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 