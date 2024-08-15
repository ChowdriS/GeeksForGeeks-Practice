#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node *reverse(Node *root){
        if(root==NULL || root->next==NULL)return root;
        
        Node *New=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        
        return New;
    }
    
    Node* addOne(Node* head) {
        head=reverse(head);
        Node *curr=head;
        Node *prev=NULL;
        int carry=1;
        
        while(curr!=NULL && carry)
        {
            int newNum=curr->data+carry;
            curr->data=newNum%10;
            carry=newNum/10;
            prev=curr;
            curr=curr->next;
        }
        
        if(carry)
        {
            prev->next=new Node(carry);
        }
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
