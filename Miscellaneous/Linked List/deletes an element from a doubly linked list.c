#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
    struct node* prev;
};
struct node *root = NULL;
struct node *end = NULL;
struct node *cur = NULL;

void push()
{

    int x;
    printf("\nEnter value: ");
    scanf("%d",&x);

    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> val = x;

    temp ->prev = NULL;

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
    end = temp;
    temp ->prev = cur;

}


void search()
{

    int cnt = 0,y;
    printf("\nWhich node would you like to remove?\n=>");
    scanf("%d",&y);
    y = y-1;
    if(root == NULL)
    {
        printf("\nNO DATA!!!\n");
        return;
    }

    if(y==cnt)
    {
        if(root->next != NULL)
        {
            root -> next ->prev = NULL;
            root = root -> next;
            return;
        }
        else
        {
            root = NULL;
            printf("\nLIST is now empty!!!\n");
            return;
        }
    }
    else if(y!=cnt && root->next == NULL)
    {
        printf("\ncouldn't find the value!!!\n");
        return;
    }


    cur = root;
    struct node *p;
    while(cur->next != NULL && y!=cnt)
    {
        p = cur;
        cur = cur->next;
        cnt++;
    }
    if(y==cnt)
    {
        p->next = p->next->next;


        if(p->next != NULL)
        {
            p -> next ->prev = p;
        }
        else
        {
            end = p;
        }

        free(cur);

    }
    else
    {
        printf("\n404 not found!!!\n");
    }

}


void show()
{
    struct node *shw = root;
    while(shw != NULL)
    {
        printf("%d ",shw->val);
        shw = shw->next;
    }
    printf("\n");

}

int main()
{

    int k;
    do
    {
        printf("\nEnter choice : 1.PUSH   2.DELETE NODE    3.SHOW      4.TERMINATE\n");
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
            show();
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
