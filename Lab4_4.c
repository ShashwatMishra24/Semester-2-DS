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
struct node* delin(struct node *u, int pos)
{struct node * prev=(struct node*)malloc(sizeof(struct node));
    u=head;
    int i=1;
    while(i<pos)
    {prev=u;
        u=u->next;
        i++;
    }
    prev->next=u->next;
    free(u);
}
void main()
{int n,i=1,pos;
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
    printf("pos to delete");
    scanf("%d",&pos);
   delin(temp,pos);
    traverse(head);
}
