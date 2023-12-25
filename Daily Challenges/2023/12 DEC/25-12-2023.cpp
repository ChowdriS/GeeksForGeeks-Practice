/*
Problem : Determinant of a Matrix
*/


#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if(n == 1)
            return matrix[0][0];
            
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            vector<vector<int>> second(n - 1, vector<int> (n - 1));
        
            for(int j = 1; j < n; j++){
                int x = 0;
                for(int k = 0; k < n; k++){
                    if(k == i)
                        continue;
                        
                    second[j - 1][x++] = matrix[j][k];
                }
            }
            
            ans += matrix[0][i] * determinantOfMatrix(second, n - 1) * ((i & 1) ? -1 : 1);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}