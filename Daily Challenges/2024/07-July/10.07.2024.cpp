#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSquare(int m, int n, vector<vector<int>> matrix) {
        for(int i=1;i<m;i++) {
            for(int j = 1;j<n;j++) {
                if(matrix[i][j]==1){
                    matrix[i][j] += min({matrix[i-1][j],
                        matrix[i][j-1],matrix[i-1][j-1]});
                }
            }
        }
        int maximum = INT_MIN;
        for(auto iter:matrix){
            for(auto it:iter){
                maximum = max(maximum,it);
            }
        }
        return maximum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}