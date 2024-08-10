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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        int n = 0;
        Node* temp = head;
        for(;temp;){
            n++;
            temp = temp->next;
        }
        k = k%n;
        if(k==0)    return head;
        temp = head;
        for(int i = 1;i<k;i++){
            temp = temp->next;
        }
        
        Node* last = temp->next;
        temp->next = nullptr;
        if(last){
            Node* prev = last;
            for(;last->next;){
                last = last->next;
            }
            last->next = head;
            head = prev;
        }
        return head;
        
        
    }
};


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

        Node* head = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

