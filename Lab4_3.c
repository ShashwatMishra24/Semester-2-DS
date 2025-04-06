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
struct node* delend(struct node *u)
{struct node * prev=(struct node*)malloc(sizeof(struct node));
    u=head;
    while(u->next!=NULL)
    {prev=u;
        u=u->next;
    }
    prev->next=NULL;
    free(u);
}
void main()
{int n,i=1;
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
   delend(temp);
    traverse(head);
}
