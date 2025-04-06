#include<stdio.h>
#include<stdlib.h>
struct node *head;
struct node{
    int data;
    struct node* next;
};
void reverse(struct node *ptr)
{struct node *temp,*prev=head;
while(temp->next!=NULL)
    {temp=ptr->next;
    ptr->next=prev;
    prev=ptr;
    ptr=temp;}
    temp->next=prev;
    head->next=NULL;
    head=temp;
}
void print(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void main()
{int i=1,n;
    printf("no of nodes");
    scanf("%d",&n);
    struct node *nnode,*temp;
    head=NULL;
    while(i<=n)
    {
        nnode=(struct node*)malloc(sizeof(struct node));
        if(head==NULL)
        {
            head=nnode;
            temp=nnode;
            printf("enter data");
            scanf("%d",&nnode->data);
        }
        else{
           
            temp->next=nnode;
            temp=nnode;
            scanf("%d",&nnode->data);
        }
        i++;
    }
    temp->next=NULL;
   reverse(head->next);
   print(head);
}
