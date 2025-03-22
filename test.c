#include<stdio.h>
struct node{
int value;
struct node *link;
};
print(struct node *head){
struct node *ptr=NULL;
ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->value);
    ptr=ptr->link;
}
}

insertatbeg(struct node* head, int val){
struct node *new_node=NULL;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->value=val;
new_node->link=head;
return new_node;
}
insertatend(struct node *head,int val){
struct node *ptr=NULL;
struct node *new_node=NULL;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->value=val;
new_node->link=NULL;
ptr=head;
while(ptr->link!=NULL){
    ptr=ptr->link;
}
ptr->link=new_node;
return head;
}
insertanypos(struct node* head, int pos, int val){
struct node *new_node=NULL;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->value=val;
new_node->link=NULL;
struct node *temp=NULL;
temp=head;
int i=1;
while(i<pos-1){
    temp=temp->link;
    i++;
}
new_node->link=temp->link;
temp->link=new_node;

return head;
}
int main(){
struct node *head=NULL,*current=NULL,*temp=NULL;
int n,val;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&val);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value=val;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        current=temp;
    }else{
    current->link=temp;
    current=temp;
    }
}
printf("Original List: ");
print(head);
printf("\nEnter the value to insert at beg: ");
int val1;
scanf("%d",&val1);
head=insertatbeg(head,val1);
printf("After insertion: ");
print(head);
printf("\nEnter the value to insert at end: ");
int val2;
scanf("%d",&val2);
head=insertatend(head,val2);
printf("After insertion: ");
print(head);
int val3;
int pos;
printf("\nEnter value to insert: ");
scanf("%d",&val3);
printf("Enter postion to be inserted: ");
scanf("%d",&pos);
head=insertanypos(head,pos,val3);
print(head);

return 0;
}
