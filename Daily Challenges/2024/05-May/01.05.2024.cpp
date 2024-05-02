#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        vector<char> vows,cons;
        Node* temp = head;
        while(temp){
            char ch = temp->data;
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
                vows.push_back(ch);
            }
            else {
                cons.push_back(ch);
            }
            temp = temp -> next;
        }
        temp = head;
        vector<char> nums = vows;
        nums.insert(nums.end(),cons.begin(),cons.end());
        int i = 0;
        while(temp){
            temp -> data = nums[i++];
            temp = temp -> next;
        }
        return head;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}
