#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printlist(struct Node *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    cout << endl;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        cout << "Prevous node can not be null" << endl;
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node;
}

void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node -> data = new_data;
    new_node -> next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last -> next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int position){
   if (*head_ref == NULL)
      return;
   struct Node* temp = *head_ref;
    if (position == 0){
        *head_ref = temp->next;   
        free(temp);
        return;
    }
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
    if (temp == NULL || temp->next == NULL)
         return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteNodeKey(struct Node **head_ref, int key){
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;   
        free(temp);              
        return;
    }
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = NULL;
    
    push(&head, 5);
    insertAfter(head->next, 88);
    append(&head, 90);
    printlist(head);
    deleteNode(&head, 4);
    printlist(head);
    deleteNodeKey(&head, 88);
    printlist(head);
    
}
