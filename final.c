#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int array()
{
    void arrexecution();
    void arraydisplay(int A[],int n);
    int arrayinsert(int A[],int n);
    int arraydelete(int A[],int n);
    int arraytraverse(int A[], int n);
}  

void arraydisplay(int A[], int n)
    {
        int i;
        for(i=0;i<n;i++)
            printf("%d",A[i]);
    }


int arraytraverse(int A[],int n)
{
    {

        int i;
        printf("\n The elements of the array are : ");
        for(i=0;i<n;i++)
        {
            printf("%d",A[i]);
        }
    }
}

int arrayinsert(int A[],int n)
#define MAX 10
{
    {
        int loc,item,i;
        if(n==MAX)
        {
            printf("\n Array is full. Insertion is not possible");
            return n;
        }
        printf("\n Enter the location to insert an element : ");
        scanf("%d",&loc);
        if(loc>n+1 || loc<1)
        {
            printf("\n Invalid location - Insertion not possible");
            return n;
        }
        printf("\n Enter the value to insert : ");
        scanf("%d",&item);
        for(i=n-1;i>=loc-1;i--)
            A[i+1]=A[i];
        A[loc-1]=item;
        n=n+1;
        printf("\n The array after insertion : ");
        arraydisplay(A,n);
        return n;
    }
}


int arraydelete(int A[],int n)
#define MAX 10
{
    {
        int loc,item,i;
        if(n==0)
        {
            printf("\n Array is empty. Deletion is not possible");
            return n;
        }
        printf("\n Enter the location to delete the element : ");
        scanf("%d",&loc);
        if(loc>n || loc<1)
        {
            printf("\n Invalid location - deletion not possible");
            return n;
        }
        for(i=loc-1;i<n-1;i++)
            A[i]=A[i+1];
        n=n-1;
        printf("\n The array after deletion :");
        arraydisplay(A, n);
        return n;
    }

    
}

void arrexecution()
#define MAX 10
    {
        
        int A[MAX],i,ch,n;
        printf("\n Enter the Number of Elements in Array :");
        scanf("%d",&n);
        printf("\n Enter %d Elements : ",n);
        for (i=0;i<n;i++)
            scanf("%d", &A[i]);
        while(1)
        {
            printf("\n Menu ");
            printf("\n*************************");
            printf("\n 1. Insert");
            printf("\n 2. Delete");
            printf("\n 3. Traverse");
            printf("\n 4. Exit");
            printf("\n Enter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: arrayinsert(A,n);
                        break;
                case 2: arraydelete(A,n);
                        break;
                case 3: arraytraverse(A,n);
                        break;
                case 4: 
                break;
                default: printf("\nInvalid option");
            }
            if(ch==4)
            {
                break;
            }
        }
    }


    struct node
    {
        int INFO;
        struct node *LINK;
    };
    typedef struct node NODE;
    NODE *start=NULL;
   
    

    void create()
    {
        char ch;
        int i=0;
        NODE *CURRPTR, *NEWNODE;
        CURRPTR=(NODE *) malloc(sizeof(NODE));
        start=CURRPTR;
        while(1)
        {
            printf("\n Enter the node %d :",i+1);
            scanf("%d",&CURRPTR->INFO);     
            printf("\n Do you wish to add one more node (Y/N) : ");
            ch=getchar();
            if(toupper(ch)=='Y')
            {
                NEWNODE=(NODE *) malloc(sizeof(NODE));
                CURRPTR->LINK=NEWNODE;
                CURRPTR=NEWNODE;
            }
            else 
            {
                CURRPTR->LINK=NULL;
                break;
            }    
            i++;
        }
    }

    void lldisplay()
    {
        NODE *CURRPTR=start;
        if(start==NULL)
            printf("\n The linked list is empty ");
        else
        {
            while(CURRPTR!=NULL)
            {
                printf("%d",CURRPTR->INFO);
                printf("->");
                CURRPTR=CURRPTR->LINK;
            }
            printf("NULL");
        }
    }

    int length()
    {
        int len=0;
        NODE *CURRPTR;
        if(start==NULL)
        {
            printf("The linked list is empty \n");
            return(len);
        }
        CURRPTR=start;
        while(CURRPTR!=NULL)
        {
            len++;
            CURRPTR=CURRPTR->LINK;
        }    
        return(len);
    }

    void insert_beg(int item)
    {
        NODE * NEWNODE;
        NEWNODE=(NODE*)malloc(sizeof(NODE));
        NEWNODE->INFO=item;
        NEWNODE->LINK=start;
        start=NEWNODE;
    }

    void insert_end(int item)
    {
        NODE *CURRPTR, *NEWNODE;
        if(start==NULL)
        {
            NEWNODE=(NODE *) malloc(sizeof(NODE));
            NEWNODE->INFO=item;
            NEWNODE->LINK=NULL;
            start=NEWNODE;
        }
        else
        {
            CURRPTR=start;
            while(CURRPTR->LINK!=NULL)
            {
                CURRPTR=CURRPTR->LINK;
            }
            NEWNODE=(NODE *) malloc(sizeof(NODE));
            NEWNODE->INFO=item;
            CURRPTR->LINK=NEWNODE;
            NEWNODE->LINK=NULL;
        }
    }

    void insert_pos(int item, int POS)
    {
        int i;
        NODE *CURRPTR=start, *NEWNODE;
        if(POS==1)
            insert_beg(item);
        else
        {
            for(i=0;i<POS-2;i++)
            {
                CURRPTR=CURRPTR->LINK;
            }
            NEWNODE=(NODE*) malloc(sizeof(NODE));
            NEWNODE->INFO=item;
            NEWNODE->LINK=CURRPTR->LINK;
            CURRPTR->LINK=NEWNODE;    
        }
    }

    void delete_beg()
    {
        NODE *CURRPTR;
        if(start==NULL)
        {
            printf("\n The linked list is empty \n");
            return;
        }
        else
        {
            CURRPTR=start;
            start=start->LINK;
            free(CURRPTR);
        }
    }

    void delete_end()
    {
        NODE *CURRPTR, *PREVPTR;
        if(start==NULL)
            printf("\n The linked list is empty \n");
        else if(start->LINK==NULL)
        {
            start=NULL;
            return;
        }
        else
        {
            CURRPTR=start;printf("\n 1. Create a linked list");
            PREVPTR=NULL;
            while(CURRPTR->LINK!=NULL)
            {
                PREVPTR=CURRPTR;
                CURRPTR=CURRPTR->LINK;
            }
            PREVPTR->LINK=NULL;
        }
    }

    void delete_pos(int POS)
    {
        int i;
        NODE *CURRPTR, *PREVPTR;
        if(POS==1)
            delete_beg();
        else
        {
            CURRPTR=start;
            PREVPTR=NULL;
            for(i=0;i<POS;i++)
            {
                PREVPTR=CURRPTR;
                CURRPTR=CURRPTR->LINK;
            }
            PREVPTR->LINK=CURRPTR->LINK;    
        }
    }

    void delete_item(int item)
    {
        NODE * CURRPTR=start, *PREVPTR=NULL;
        if(start==NULL)
        {
            printf("\n the linked list is empty");
            return;
        }
        else if(start->INFO==item)
        {
            start=start->LINK;
            free(CURRPTR);
            return;
        }
        else
        {
            while(CURRPTR!=NULL && CURRPTR->INFO!=item)
            {
                PREVPTR=CURRPTR;
                CURRPTR=CURRPTR->LINK;
            }
            if(CURRPTR==NULL)
                printf("\n The item is not found in the linked list \n");
            else
                PREVPTR->LINK=CURRPTR->LINK;
        }
    }

    void llexcecution()
    {
        {
        int ch,item,pos;
        while(1)
        {
            printf("\n 1. Create a linked list");
            printf("\n 2. Display");
            printf("\n 3. Insert First Node");
            printf("\n 4. Insert at the End");
            printf("\n 5. Insert at the Specified Position");
            printf("\n 6. Delete First Node");
            printf("\n 7. Delete Last Node");
            printf("\n 8. Delete at the Specified Position");
            printf("\n 9. Delete a Node When Item is Given");
            printf("\n 10. Exit");
            printf("\n Enter Your Choice :");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1: start=NULL;
                        create();
                        break;
                case 2: lldisplay();
                        break;
                case 3: printf("\n Enter the Item to insert at the Beginning : ");
                        scanf("%d", &item);
                        printf("\n Linked List before Insertion is : \n");
                        lldisplay();
                        insert_beg(item);
                        printf("\n Linked list after Insertion is : \n");
                        lldisplay();
                        break;
                case 4: printf("\n Enter the Item to insert at the End : ");
                        scanf("%d", &item);
                        printf("\n Linked List before Insertion is : \n");
                        lldisplay();
                        insert_end(item);
                        printf("\n Linked list after Insertion is : \n");
                        lldisplay();
                        break;
                case 5: printf("\n Enter an Item to Insert at Certain Position : ");
                        scanf("%d",&item);
                        printf("\n Enter a Valid Position : ");
                        scanf("%d",&pos);
                        if((pos==0) && (pos>length()+1))
                        {
                            printf("\n It is Invalid Position \n");
                            break;
                        }
                        else
                        {
                            printf("\n Linked list before Insertion is : ");
                            lldisplay();
                            insert_pos(item,pos);
                            printf("\n Linked List after Insertion is : \n");
                            lldisplay();
                            break;
                        }
                case 6: printf("\n Linked List before Deletion is : \n");
                        lldisplay();
                        delete_beg();
                        printf("\n Linked List after Deletion is : \n");
                        lldisplay();
                        break;
                case 7: printf("\n Linked Lisr before Deletion is : \n");
                        lldisplay();
                        delete_end();
                        printf("\n Linked List after Deletion is : \n");
                        lldisplay();
                        break;
                case 8: printf("\n Enter a Valid Position to Delete : \n");
                        scanf("%d",&pos);
                        if((pos==0) || (pos>length()))
                        {
                            printf("\n It is Invalid Position \n");
                            break;
                        }
                        else
                        {
                            printf("\n Linked list before Deletion is : ");
                            lldisplay();
                            delete_pos(pos);
                            printf("\n Linked List after Deletion is : \n");
                            lldisplay();
                            break;
                        }
                case 9: printf("\n Linked List before Deletion is: \n");
                        lldisplay();
                        printf("\n Enter an Item to be Deleted : \n");
                        scanf("%d",&item);
                        delete_item(item);
                        printf("\n Linked List after Deletion is : \n");
                        lldisplay();
                        break;
                case 10: exit(0);

            }
        }
    }
    }


#define MAXSTK 5
void stcexecution();

int TOP=-1;
int S[MAXSTK];

int push()
{
    int item;
    if(TOP==(MAXSTK-1))
        printf("Stack overflow\n");
    else
    {
        printf("Enter the item to be pushed in stack : ");
        scanf("%d",&item);
        TOP=TOP+1;
        S[TOP]=item;
    }
}

int pop()
{
    if(TOP==-1)
        printf("Stack Underflow\n");
    else
    {
        printf("Popped element is : %d\n",S[TOP]);
        TOP=TOP-1;
    }
}

void display()
{
    int i;
    if(TOP==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements :\n");
        for(i=TOP;i>=0;i--)
            printf("%d\n",S[i]);
    }
}

void stcexecution()
    {
        int choice;
        while(1)
        {
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: push();
                        break;
                case 2: pop();
                        break;
                case 3: display();
                        break;
                case 4: exit(1);
                default: printf("Wrong choice\n");
            }
        }
    }




int main()
{
    int opch;
    printf("\nOn which of the data structures do you want to perform the operation on :");
    printf("\n 1. Array");
    printf("\n 2. Linked List");
    printf("\n 3. Stack");
    printf("\n 4. Exit");
    scanf("%d",&opch);
    switch(opch)
    {
        case 1: array();
                break;
        case 2: llexcecution();
                break;
        case 3: stcexecution();
                break;
        case 4: exit(0);
        default: printf("\n Invalid option");
    }
    return 0;
}