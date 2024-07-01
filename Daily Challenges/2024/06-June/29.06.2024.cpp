#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool areIdentical(struct Node *head1, struct Node *head2);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, tmp, d1, d2;
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n1;
        cin >> d1;
        head1 = new Node(d1);
        tail1 = head1;
        while (n1-- > 1) {
            cin >> tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin >> n2;
        cin >> d2;
        head2 = new Node(d2);
        tail2 = head2;
        while (n2-- > 1) {
            cin >> tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }

        areIdentical(head1, head2) ? cout << "true" << endl : cout << "false" << endl;
    }
    return 0;
}
/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

bool areIdentical(struct Node *head1, struct Node *head2) {
    vector<int> nums;
    while(head1!=nullptr) {
        nums.push_back(head1->data);
        head1 = head1->next;
    }
    int i = 0;
    int n = nums.size();
    while(head2!=nullptr and i<n){
        if(head2->data!=nums[i++]){
            return false;
        }
        head2 = head2->next;
    }
    if(head2==nullptr and i==n){
        return true;
    }
    return false;
}