#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head;
void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insebegin(struct node *u)
{
    u->next=head;
    head=u;
return head;
}
void main()
{int i=1,n;
    printf("no of nodes");
    scanf("%d",&n);
    struct node *nnode,*temp,*newn;
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
    newn=(struct node*)malloc(sizeof(struct node));
    printf("enter data of new node");
    scanf("%d",&newn->data);
    head=insebegin(newn);
    traverse(head);
}
