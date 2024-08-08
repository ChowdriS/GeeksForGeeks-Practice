#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> temp;
        for(int i=0; i<n; i++) {
            temp.push_back({start[i],end[i]});
        }
        int cnt = 1;
        sort(temp.begin(),temp.end());
        pair<int,int> prev = temp[0];
        for(int i=1;i<n;i++) {
            if(temp[i].first>prev.second and prev.first<temp[i].first){
                cnt++;
                prev = temp[i];
            }
            else{
                if(temp[i].second < prev.second){
                    prev = temp[i];
                }
            }
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
