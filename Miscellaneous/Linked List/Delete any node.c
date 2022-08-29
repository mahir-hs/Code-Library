#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int val;
    struct node* next;
};
struct node* root = NULL;

void push()
{

    int x;
    printf("\nEnter value: ");
    scanf("%d",&x);
    if(root==NULL)
    {
        root = (struct node*) malloc (sizeof (struct node) );
        root -> val = x;
        root->next=NULL;

    }
    else
    {
        struct node *temp = root;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        struct node *newnode = (struct node*) malloc (sizeof (struct node) );
        newnode -> val = x;
        newnode -> next = NULL;
        temp -> next = newnode;

    }
}


void search()
{
    int a,b,c=0,d=0,e=0;
    printf("\nEnter position: ");
    scanf("%d",&a);
    a=a-1;
    struct node *thead = root;
    struct node *the = root;

    if(a==c)
    {
        struct node *nn =(struct node*) malloc(sizeof(struct node));
        nn = root->next;
        root = nn;
        e=1;

    }

    else if(a>c)
    {
        thead = thead->next;
        while(thead->next!=NULL)
        {
            c++;

            if(a==c)
            {
                e=1;
                the->next = thead->next;
                free(thead);
                break;
            }

            thead = thead->next;
            the = the->next;

        }
        if(e==0)
        {
            struct node *t = root;
            struct node *tt = root;
            while(t->next!=NULL)
            {
                tt = t;
                t = t->next;
            }
            if(t == root)
            {
                root = NULL;
            }
            else
            {
                tt->next = NULL;
            }
            free(t);

        }

    }





}


void show()
{
    struct node *tt = root;
    while(tt!=NULL)
    {
        printf("%d ",tt->val);
        tt = tt->next;
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
