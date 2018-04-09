/// An example of 2D sort using vector pair // Problem : Burglar & Matches ///

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main(){
    int n, m, res = 0, i, a, b;
	vector< pair <int, int> >pr;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> a >> b;
        pr.push_back(make_pair(a, b));
    }
    
    sort(pr.begin(), pr.end(), comp);
    
    vector< pair<int, int> > :: const_iterator it;
    
    for(it = pr.begin(); it != pr.end(); it++){
        int p = it->first;
        int q = it->second;
        if(n == 0)
            break;
        if(n >= p){
            res += p * q;
            n -= p;
        }
        else if(n < p){
            res += n * q;
            n = 0;
        }
    }

/// efficient is prime ///

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
    
    
    
/// Maximum Flow ///
    
#include <stdio.h>

#define SIZE 8

void merge(int * array_of_integers, int p, int q, int r){
   int n1 = q - p + 1;
   int n2 = r - q; 
   int i, j, k;
   int left_array[n1+1];
   int right_array[n2+1];

   left_array[n1] = 123456798;
   right_array[n2] = 123456798;

   for(i = 0; i < n1; i++)
     left_array[i] = array_of_integers[p + i];
   for(j = 0; j < n2; j++)
     right_array[j] = array_of_integers[q + j + 1];

   i = 0;
   j = 0;

   for(k = p; k <= r; k++){
     if(left_array[i] <= right_array[j]){
       array_of_integers[k] = left_array[i];
       i++;
     } else {
       array_of_integers[k] = right_array[j];
       j++;
     }
   }
 }

 void merge_sort(int * array_of_integers, int p, int r){
   if(p < r){
     int q = (p+r)/2;
     merge_sort(array_of_integers, p, q);
     merge_sort(array_of_integers, q + 1, r);
     merge(array_of_integers, p, q, r);
   }
 }


void print_array(int * array_of_integers, int amout_of_integers){
  int i;
  for(i = 0; i < amout_of_integers; i++)
    printf("%d ",array_of_integers[i]);
  puts("");
}

int main(void){
  int dataset[] = {2, 4, 5, 7, 1, 2, 3, 6};

  print_array(dataset, SIZE);
  merge_sort(dataset, 0, SIZE - 1);
  print_array(dataset, SIZE);

  return 0;
}


#include<iostream>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

int main(){
    int input;

    cout<< "Enter length of desired array";
    cin>>input;

    cout<<"\n";

    int A[input];

    for(int i = 0 ;i <input ; i++)
    {
        A[i] = rand() % 100;   
        cout<<A[i] << "\t";
    }

    cout<<"\n";

    for(int j =1; j<input ; j++)
    {   int i;
        int key = A[j];
        i = j-1;
        while( i >=0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i-1;
            
        }
     A[i+1] = key;
    }

    for(int i = 0 ;i <input ; i++)
    {
        cout<<A[i] << "\t";
    }
}
    

    
/// The ultimate tree ///
    
#include <stdio.h>
#include <stdlib.h>

struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = NULL;
    newNode=(struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    //(*newNode).data = data;
    //(*newNode).left = (*newNode).right = NULL;
    return newNode;

}
struct BstNode* Insert(struct BstNode* rootPtr, int data){
    if(rootPtr == NULL){
    rootPtr = GetNewNode(data);

    }
    else if(data <= rootPtr->data) {
    rootPtr->left = Insert(rootPtr->left, data);

    }
    else {
    rootPtr->right = Insert(rootPtr->right, data);

    }
    return rootPtr;
}

int Search(struct BstNode* rootPtr, int data) {
    if(rootPtr == NULL) {
    return 0;
    }
    else if(rootPtr->data == data) {
    return 1;
    }
    else if(data <= rootPtr->data) {
    return Search(rootPtr->left, data);
    }
    else {
    return Search(rootPtr->right, data);
    }
}

void showtree(struct BstNode *root){
    if (root){
         printf("\t%d\n ",root->data);

    if(root->left){
        printf("Left Subtree of %d",root->data);
    printf("\n");
    showtree(root->left);

    }
    if(root->right){
        printf("Right Subtree of %d",root->data);
        printf("\n");
        showtree(root->right);


        }
    }
}

int main(void){
    struct BstNode* rootPtr;
    rootPtr = NULL;
    rootPtr = Insert(rootPtr, 15);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 60);
    rootPtr = Insert(rootPtr, 05);
    rootPtr = Insert(rootPtr, 30);
    rootPtr = Insert(rootPtr, 2);
    rootPtr = Insert(rootPtr, 50);
    rootPtr = Insert(rootPtr, 8);
    rootPtr = Insert(rootPtr, 20);
    rootPtr = Insert(rootPtr, 25);
    rootPtr = Insert(rootPtr, 45);
    showtree(rootPtr);
    int n;
    printf("Enter number to be searched: \n");
    scanf("%d",&n);
    if(Search(rootPtr, n) == 1) {
    printf("Found\n");
    }
    else {
    printf("Not Found\n");
    }
    return 0;
}
