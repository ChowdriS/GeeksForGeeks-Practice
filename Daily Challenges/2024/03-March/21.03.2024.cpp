#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {


            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
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
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> zigzag;
        queue<Node*> qp;
        qp.push(root);
        int level = 0;
        while(!qp.empty()) {
            int n = qp.size();
            vector<int> temp;
            while(n--){
                Node* root = qp.front();
                qp.pop();
                temp.push_back(root->data);
                if(root->right)    qp.push(root->right);
                if(root->left)    qp.push(root->left);
            }
            if(level%2==0) {
                reverse(temp.begin(),temp.end());
            }
            zigzag.insert(zigzag.end(),temp.begin(),temp.end());
            level++;
        }
        return zigzag;
    }
};
  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}
