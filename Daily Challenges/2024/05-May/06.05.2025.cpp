#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
        
    queue<Node*> queue;
    queue.push(root);
        
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        Node* currNode = queue.front();
        queue.pop();
            
        string currVal = ip[i];
            
        if(currVal != "N") {
                
            currNode->left = newNode(stoi(currVal));
                
            queue.push(currNode->left);
        }
            
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
                
            currNode->right = newNode(stoi(currVal));
                
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
vector<int> noSibling(Node *root);

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
  }
  return 0;
}


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
void solve(Node* &root,unordered_map<int,int>&par){
    
    
    if(root==nullptr){
        return ;
    }
    
    
    if(root->left){
        
        par[root->left->data]=root->data;
    }
       
    if(root->right){
        
        par[root->right->data]=root->data;
    }
    
    solve(root->left,par);
    solve(root->right,par);
    

}


void solution(Node* &root,unordered_map<int,int>&par,vector<int>&ans){
    
    
    if(root==nullptr){
        return;
    }
    
  if(root->right && !root->left){
      ans.push_back(root->right->data);
      
  }
    if(root->left && !root->right){
      ans.push_back(root->left->data);
  }
  
 
    solution(root->left,par,ans);
    solution(root->right,par,ans);
}


vector<int> noSibling(Node* node)
{
    
    
    unordered_map<int,int>par;
    
    if(node==nullptr){
        return {-1};
    }
    
    par[node->data]=-1;
    
    solve(node,par);
    
    
    vector<int>ans;
    
    solution(node,par,ans);
    
    if(ans.empty()){
        return {-1};
    }
    
    else
    sort(ans.begin(),ans.end());
    return ans;
 
}