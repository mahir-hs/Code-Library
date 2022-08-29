#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};
struct node *root = NULL;
struct node *cur = NULL;
struct node1
{
    int val1;
    struct node1* next1;
};
struct node1 *root1 = NULL;
struct node1 *cur1 = NULL;
void push1()
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


void push2()
{

    int x;
    printf("\nEnter value: ");
    scanf("%d",&x);

    struct node1 *temp1 = (struct node1*) malloc(sizeof(struct node1));

    temp1 -> val1 = x;

    temp1 ->next1 = NULL;

    if(root1 == NULL)
    {
        root1 = temp1;
        return;
    }

    cur1 = root1;

    while(cur1->next1 != NULL)
    {
        cur1 = cur1 ->next1;
    }

    cur1 ->next1 = temp1;

}


void search()
{

    struct node *a;
    struct node1 *b;
    a = root;
    b = root1;
    int o=0,p=0;
    while(a->next!= NULL)
    {
        o++;
        a = a->next;
    }
    while(b->next1!= NULL)
    {
        p++;
        b = b->next1;
    }
    if(o>p)
    {
        printf("\n1\n");
    }
    else if(o<p)
    {
        printf("\n-1\n");
    }
    else
    {
        printf("\n0\n");
    }

}


int main()
{

    int k;
    do
    {
        printf("\nEnter choice : 1.PUSH List 1 Values    2.PUSH List 2 Values    3.result    4.TERMINATE\n");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            push1();
            break;
        case 2:
            push2();
            break;
        case 3:
            search();
            break;
        case 4:
            return 0 ;
            break;
        default:
            printf("Error Choice\n");
        }
    }
    while(k != 4);

    return 0;
}
