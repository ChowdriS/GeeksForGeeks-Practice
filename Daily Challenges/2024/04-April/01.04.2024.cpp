#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
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



/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/
class Solution {
private:
    int cnt = 0;

    void merge(vector<int>& ans, int low, int mid, int high) {
        vector<int> result(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            if (ans[i] <= ans[j]) {
                result[k++] = ans[i++];
            } else {
                cnt += mid - i + 1;
                result[k++] = ans[j++];
            }
        }
        while (i <= mid) {
            result[k++] = ans[i++];
        }
        while (j <= high) {
            result[k++] = ans[j++];
        }
        for (int idx = low; idx <= high; ++idx) {
            ans[idx] = result[idx - low];
        }
    }

    void mergeSort(vector<int>& ans, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(ans, low, mid);
            mergeSort(ans, mid + 1, high);
            merge(ans, low, mid, high);
        }
    }

    void inorder(Node* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

public:
    int pairsViolatingBST(int n, Node* root) {
        vector<int> ans;
        inorder(root, ans);
        mergeSort(ans, 0, ans.size() - 1);
        return cnt;
    }
};



int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}