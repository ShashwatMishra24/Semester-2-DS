#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void length(struct node *ptr)
{int i=0;
    while(ptr!=NULL)
    { i++;
        ptr=ptr->next;
    }
    printf("%d",i);
}
void main()
{int i=1,n;
    printf("no of nodes");
    scanf("%d",&n);
    struct node *head ,*nnode,*temp;
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
    length(head);
}
