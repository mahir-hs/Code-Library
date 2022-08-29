#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};
struct node *root = NULL;
struct node *cur = NULL;

void push()
{

    int x;
    printf("\nEnter value: ");
    scanf("%d",&x);

    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> val = x;

    temp ->next = NULL;

    if(root == NULL)
    {
        root = temp;
        return;
    }

        cur = root;

        while(cur->next != NULL)
        {
            cur = cur ->next;
        }

        cur ->next = temp;

}


void search()
{

    root->next->next = root;   ///creating loop demo for finding the loop
    struct node *one,*two;
    one = root;
    two = root;
    int x = 0;

    while(one!=NULL && two!=NULL && two->next!=NULL)
    {
        one = one->next;
        two = two->next->next;
        if(one==two)
        {
            x = 1;
            printf("\nfound");
            return;
        }
    }
    if(x==0)
    {
       printf("\nnot found");
    }

}


int main()
{

    int k;
    do
    {
        printf("\nEnter choice : 1.PUSH   2.detect loop or not    3.TERMINATE\n");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            push();
            break;
        case 2:
            search();
            break;
        case 3:
            return 0 ;
            break;
        default:
            printf("Error Choice\n");
        }
    }
    while(k != 3);

    return 0;
}
