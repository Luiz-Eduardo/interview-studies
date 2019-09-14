#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int value){
    struct Node *temp = (Node *) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head;
    head = temp;
}

void printList(Node* head){
    if(head == NULL)
        return;

    cout << head->data << " ";
    printList(head->next);
}

void printReverseList(Node *head){
    if(head == NULL)
        return;
    
    printReverseList(head->next);
    cout << head->data << " ";
}

int main(){
    insert(2);
    insert(3);
    insert(4); 

    printReverseList(head);
    return 0;
}