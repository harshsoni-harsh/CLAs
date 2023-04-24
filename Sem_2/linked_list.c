#include<stdio.h>

struct node{

    int data;
    struct node* next
};

struct node* createList(){
    struct node* head= (struct node* )malloc(sizeof(struct node));
    return head;
}

void addnode(struct node* head, int value){
    struct node* currNode=head;
    for(int i=0;currNode->next!=NULL;i++);
    currNode->next= (struct node* )malloc(sizeof(struct node ));
    currNode->next=currNode->next->next;
    currNode->next=NULL;
    currNode->data=value;
}

deleteNode(struct node*head,int position){

}
insertNode(struct node* head,int position,int value){

}

printList(struct node* head){
   int i=0;
    struct node* currNode=head;
    for(i=0;currNode->next!=NULL;i++)
      printf("\n%d",currNode->data);

}



int numElements(struct node* head){
    int i=0;
    struct node* currNode=head;
    for(i=0;currNode->next!=NULL;i++);
    return i;
}

void main(){
    struct node* myList;
    myList=createList();
    addnode(myList,45);
    printList(myList);


}



