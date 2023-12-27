/*
Problem : Anti Diagonal Traversal of Matrix
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> nums) 
    {
        int row=nums.size();
        vector<int> result;
        
        // first part
        for(int i=0;i<row;i++){
            for(int j=0,ind=i;ind>=0 and j<row;ind--,j++){
                result.push_back(nums[j][ind]);        
            }
        }
        
        // second part
        for(int i=1;i<row;i++){
            for(int j=row-1,ind=i;ind<row and j>=0;j--,ind++){
                result.push_back(nums[ind][j]);
            }
        }
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}