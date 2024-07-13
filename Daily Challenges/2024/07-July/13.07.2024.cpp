#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int weight = edge[2];
            adj[a].push_back({b, weight});
            adj[b].push_back({a, weight});
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int source = 1;
        dist[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            auto node = pq.top().second;
            auto distance = pq.top().first;
            pq.pop();
            if (distance > dist[node]) continue;
            for(auto it : adj[node]){
                auto neighbour = it.first;
                auto w = it.second;
                if(w + distance < dist[neighbour]){
                    dist[neighbour] = w + distance;
                    parent[neighbour] = node;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        if (dist[n] == INT_MAX) {{}
            return {-1};
        }
        vector<int> path;
        for (int at = n; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};

int main() {
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}