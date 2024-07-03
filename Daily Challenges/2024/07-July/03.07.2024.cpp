#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        vector<int> nums,res;
        Node* temp = head;
        while(temp!=nullptr){
            nums.push_back(temp->data);
            temp = temp->next;
        }
        int size = nums.size();
        for(int i=0;i<size;){
            int data = nums[i];
            int cnt = 0;
            while(data==nums[i]){
                cnt++;
                i++;
            }
            // cout<<i<<" ";
            if(cnt==1){
                res.push_back(data);
            }
        }
        int n = res.size();
        int ind = 1;
        temp = head;
        temp->data = res[0];
        while(ind<n){
            temp = temp->next;
            temp->data = res[ind++];
        }
        temp->next = nullptr;
        return head;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
