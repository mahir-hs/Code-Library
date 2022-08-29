
#include<stdio.h>
#include<stdlib.h>
int i=0,arr[1001];
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


void push2(int y)
{

    struct node1 *temp1 = (struct node1*) malloc(sizeof(struct node1));

    temp1 -> val1 = y;

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


void ans()
{

    struct node *a;
    a = root;

    int o=0;
    while(a  != NULL)
    {

        if(o%2==0)
        {
            push2(a->val);
        }
        o++;
        a = a->next;
    }


}

void ser()
{
    ans();
    struct node1 *nn = root1;
    struct node1 *nnn;
    while(nn!=NULL)
    {
        printf("%d ",nn->val1);
        nn = nn->next1;
    }
    printf("\n");
    while(root1!=NULL)
    {
        nnn = root1;
        root1 =  root1->next1;
        free(nnn);
    }

}


int main()
{

    int k;
    do
    {
        printf("\nEnter choice : 1.PUSH Values    2.result    3.TERMINATE\n");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            push1();
            break;
        case 2:
            ser();
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
