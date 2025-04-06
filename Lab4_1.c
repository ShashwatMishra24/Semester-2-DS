#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *head ;
struct node *head2;
void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void concate()
{
    struct node *u=(struct node*)malloc(sizeof(struct node));
    u=head;
    while(u->next!=NULL)
    {
        u=u->next;
    }
    u->next=head2;
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
    i=1;
    printf("no of nodes");
    scanf("%d",&n);
    struct node *nnode2,*temp2;
    head2=NULL;
    while(i<=n)
    {
        nnode2=(struct node*)malloc(sizeof(struct node));
        if(head2==NULL)
        {
            head2=nnode2;
            temp2=nnode2;
            printf("enter data");
            scanf("%d",&nnode2->data);
        }
        else{
           
            temp2->next=nnode2;
            temp2=nnode2;
            scanf("%d",&nnode2->data);
        }
        i++;
    }
    temp2->next=NULL;
    concate();
    traverse(head);
}
