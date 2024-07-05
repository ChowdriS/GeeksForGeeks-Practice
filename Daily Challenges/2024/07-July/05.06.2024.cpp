#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    int verticalWidth(Node* root) {
        if(root==nullptr)   return 0;
        unordered_map<int,Node*> mp;
        mp[0] = root;
        queue<pair<int,Node*>> qp;
        qp.push({0,root});
        while(!qp.empty()){
            auto val = qp.front();
            qp.pop();
            
            int width = val.first;
            Node* node = val.second;
            
            if(node->left){
                qp.push({width+1,node->left});
                mp[width+1] = node->left;
            }
            if(node->right){
                qp.push({width-1,node->right});
                mp[width-1] = node->right;
            }
        }
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        
        for(auto it : mp){
            maximum = max(it.first,maximum);
            minimum = min(it.first,minimum);
        }
        return maximum + abs(minimum)+1;
    }
};


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Solution obj;
        Node *root = buildTree(str);

        cout << obj.verticalWidth(root) << "\n";
    }

    return 0;
}
