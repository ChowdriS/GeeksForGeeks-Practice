#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
    
    
    private:
    int dfs(struct Node* root,int target,vector<int> &temp){
        if(!root){
            return 0;
        }
        if(root->data==target){
            return 1;
        }
        int left = dfs(root->left,target,temp);
        int right = dfs(root->right,target,temp);
        if(left || right){
            temp.push_back(root->data);
            return 1;
        }
        return 0;
    }
    
    
  public:
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> temp;
        dfs(root,target,temp);
        return temp;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);

        int target;
        cin >> target;
        getchar();

        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root, target);
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
