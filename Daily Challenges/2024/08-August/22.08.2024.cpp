#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int> temp[k];
        vector<int> indegree(k);
        for(int i = 0; i<n-1 ;i++){
            string a = dict[i];
            string b = dict[i+1];
            int mini = min(a.size(),b.size()); 
            for(int j = 0;j<mini;j++){
                if(a[j]!=b[j]){
                    temp[a[j]-'a'].push_back(b[j]-'a');
                    indegree[b[j]-'a']++;
                    break;
                }
            }
        }
        vector<int> topo;
        queue<int> qp;
        for(int i =0 ;i<k ; i++){
            if(indegree[i]==0){
                qp.push(i);
            }
        }
        while(!qp.empty()){
            auto node = qp.front();
            qp.pop();
            topo.push_back(node);
            for(auto it : temp[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    qp.push(it);
                }
            }
        }
        string ans = "";
        for(auto it : topo){
            ans+=string(1,it+'a');
        }
        return ans;
    }
};


string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

