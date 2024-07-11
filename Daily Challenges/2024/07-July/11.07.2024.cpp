#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, int> unmap;
        int dfs(int i, int j, vector<vector<int> >& grid,
                vector<vector<bool> >& visited, int key)
        {
            int n = grid.size();
            if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j]
                || grid[i][j] == 0) {
                return 0;
            }
            visited[i][j] = true;
            int count = 1 + dfs(i + 1, j, grid, visited, key)
                        + dfs(i - 1, j, grid, visited, key)
                        + dfs(i, j + 1, grid, visited, key)
                        + dfs(i, j - 1, grid, visited, key);
            grid[i][j] = key;
            return count;
        }
     public:
        int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int key = 2;
        vector<vector<bool> > visited(n,
                                    vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    int count = dfs(i, j, grid, visited, key);
                    unmap[key] = count;
                    key++;
                }
            }
        }
        int result = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int a = (i + 1 < n) ? grid[i + 1][j] : 0;
                    int b = (i - 1 >= 0) ? grid[i - 1][j] : 0;
                    int c = (j + 1 < n) ? grid[i][j + 1] : 0;
                    int d = (j - 1 >= 0) ? grid[i][j - 1] : 0;
                    set<int> st;
                    st.insert(a);
                    st.insert(b);
                    st.insert(c);
                    st.insert(d);
                    int res = 1;
                    for (auto it = st.begin(); it != st.end();
                        it++) {
                        res += unmap[*it];
                    }
                    result = max(result, res);
                }
            }
        }
        if (result == -1) {
            return n * n;
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}
