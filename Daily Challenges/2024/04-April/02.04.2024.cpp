#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}
Node *buildTree(string str)
{
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  Node *root = newNode(stoi(ip[0]));

  queue<Node *> queue;
  queue.push(root);

  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    Node *currNode = queue.front();
    queue.pop();

    string currVal = ip[i];

    if (currVal != "N")
    {

      currNode->left = newNode(stoi(currVal));

      queue.push(currNode->left);
    }

    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    if (currVal != "N")
    {

      currNode->right = newNode(stoi(currVal));

      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}


/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    private:
    void inorder(Node* root,vector<int>& ans){
        if(!root)   return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    public:
    int absolute_diff(Node *root)
    {
        vector<int> ans;
        inorder(root,ans);
        int n = ans.size();
        int result = INT_MAX;
        for(int i =1;i<n;i++) {
            result = min(ans[i]-ans[i-1],result);
        }
        return result;
    }
};


int main()
{

  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    if (root == NULL)
      continue;
    if (root->left == NULL and root->right == NULL)
      continue;
      Solution ob;
    cout << ob.absolute_diff(root) << '\n';
  }
  return 1;
}