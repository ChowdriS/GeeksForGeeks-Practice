#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        vector<int> emp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++) {
            if(find(mat[i].begin(),mat[i].end(),1)==mat[i].end()){
                emp.push_back(i);
            }
        }
        int res = -1;
        for(auto i : emp){
            int val = 0;
            int ind = -1;
            for(int j = 0; j<m; j++){
                if(mat[j][i]==0){
                    if(val<=0){
                        val++;
                        ind = i;
                    }
                    else{
                        ind = -1;
                        break;
                    }
                }
            }
            if(ind!=-1){
                res = ind;
                break;
            }
        }
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}
