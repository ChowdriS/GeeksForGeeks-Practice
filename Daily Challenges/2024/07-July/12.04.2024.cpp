#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
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

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    private:
    bool dfs(Node* root,int target,int cnt){
        if(root->left == nullptr and root->right == nullptr) {
            cnt+=root->data;
            if(target==cnt)   return true;
            return false;
        }
        bool left =false, right = false;
        if(root->left){
            left = dfs(root->left,target,cnt+root->data);
        }
        if(root->right){
            right = dfs(root->right, target,cnt+root->data);
        }
        return (left or right);
    }
  public:
    bool hasPathSum(Node *root, int target) {
        return dfs(root,target,0);
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        Solution ob;
        bool r = ob.hasPathSum(root, sum);
        if (r)
            cout << "true"
                 << "\n";
        else
            cout << "false"
                 << "\n";
    }
    return 0;
}
