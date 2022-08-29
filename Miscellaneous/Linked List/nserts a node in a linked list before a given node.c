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
    int a,b,c=1,d=0,e=0;
    printf("\nEnter position: ");
    scanf("%d",&a);
    printf("\nEnter value: ");
    scanf("%d",&b);
    struct node *thead = root;
    struct node *the = root;

    if(a>c)
    {
        while(thead->next!=NULL)
        {
            c++;
            thead = thead ->next;
            if(a==c)
            {
                struct node *nn =(struct node*) malloc(sizeof(struct node));
                nn ->val  = b;
                nn->next = thead->next;
                thead ->next = nn;
            }


        }

    }
    else if(a==c)
    {
        struct node *nn =(struct node*) malloc(sizeof(struct node));
        nn ->val  = b;
        nn->next = root;
        root = nn;
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
        printf("Enter choice : 1.PUSH   2.GIVING A NODE FOR INSERTING IN-BETWEEN    3.SHOW      4.TERMINATE\n");
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
