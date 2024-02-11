#include<stdio.h>
#include<stdlib.h>

 struct node
    {
        int data;
        struct node *next;
    };
void delnode(struct node**,struct node**);
void insertion(int,int,struct node**,struct node**,struct node**);
void traversing(struct node**,struct node**,struct node**);
void createlist(struct node**,struct node**,struct node**);

int main()
{
    	struct node *head,*newnode,*temp;
	head = 0;
          
    int IN,count=1,p1,i=1,del;
    
    again:
	printf("Firstly you have to create list\nTo create press one\n");
    	scanf("%d",&p1);
	
	if(p1==1)
	{
		createlist(&head,&newnode,&temp);
	}
	
	else
	{
	   printf("You did not create the list\n");
	   goto again;
   	}  	
   	printf("Here is your created linked list\n");
   	    traversing(&head,&newnode,&temp);
	
	while(i==1)
	{
        printf("Do you want to insert any node(0/1)\n");
        scanf("%d",&IN);
        if(IN==1)
        {
        insertion(IN,count,&head,&newnode,&temp);
        }
        else
        {
            goto there;
        }
       there:
        printf("\nDo you want to insert more nodes\n1.Yes\t2.No\n");
        scanf("%d",&i);
	}
	here:
	printf("Do you want to delete any node\n");
	printf("1.Yes\t2.No\t\n");
	scanf("%d",&del);
	switch(del)
	{
	case 1:
		delnode(&head,&temp);
	break;
	case 2:
		exit(0);
	break;
	default:
		printf("Invalid input");
	goto here;
	}
	printf("Here is your final list\n");
      	temp = head;
	while(temp!=0)
	{
	   printf("%d\n",temp->data);
	   temp = temp->next;
	}
	
    return 0;
}
void createlist(struct node** head, struct node** newnode, struct node** temp) {
    int choice = 1;
    int count = 0; // Initialize count to 0
    while (choice == 1) {
        *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Memory Allocated\n");
        printf("Enter the Data\n");
        scanf("%d", &(*newnode)->data);
        (*newnode)->next = NULL;
        if (*head == NULL) {
            *head = *temp = *newnode;
        } else {
            (*temp)->next = *newnode;
            *temp = *newnode;
        }
        count++; // Increment count for each node added
        printf("Do you want to continue(0,1)\n");
        scanf("%d", &choice);
    }
}

void traversing(struct node** head, struct node** newnode, struct node** temp) {
    int count = 0; // Initialize count to 0
   
    *temp = *head;
    while (*temp != NULL) {
        printf("%d\n", (*temp)->data);
        *temp = (*temp)->next;
        count++; // Increment count for each node traversed
    }
    printf("Total nodes: %d\n", count);
}
void insertion(int b, int c, struct node** head, struct node** newnode, struct node** temp)
{
    int count;
    int IN;
    IN = b;
    count = c;

    int opsn, pos, i = 1;
    if (IN == 1) {
        printf("Where do you want to Insert\n");
        printf("1.Beginning\t 2.End\t 3.At specific Pos\n");
        scanf("%d", &opsn);
        if (opsn != 1 && opsn != 2 && opsn != 3) {
            printf("Invalid option-\t");
            printf("Enter between 1 to 3");
        } else {
            if (opsn != 2 && opsn != 3) {
                *newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data\n");
                scanf("%d", &(*newnode)->data);
                (*newnode)->next = *head;
                *head = *newnode;
            } else {
                if (opsn != 1 && opsn != 3) {
                    *newnode = (struct node*)malloc(sizeof(struct node));
                    printf("Enter the data\n");
                    scanf("%d", &(*newnode)->data);
                    *temp = *head;
                    while ((*temp)->next != NULL) {
                        *temp = (*temp)->next;
                    }
                    (*temp)->next = *newnode;
                } else {
                    if (opsn != 1 && opsn != 2) {
                        printf("Enter the position after which you want to insert\n");
                        scanf("%d", &pos);
                        if (pos < 1 & pos > count) {
                            printf("Invalid position");
                        } 
                        else {
              *newnode = (struct node*)malloc(sizeof(struct node));
                            printf("Enter the data\n");
                            scanf("%d", &(*newnode)->data);
                            *temp = *head;
                            while (i < pos) {
                                *temp = (*temp)->next;
                                i++;
                            }
                            (*newnode)->next = (*temp)->next;
                            (*temp)->next = *newnode;
                        }
                    } else {
                        exit(0);
                    }
                }
            }
        }
    } else {
        exit(0);
    }
}
void delnode(struct node**head,struct node**temp)
{
struct node **currentnode;
int pos,pos1,i=1,e=1;
while(e==1)
{
begin:
printf("From where do you want to delete\n");
printf("1.Begining\t2.End\t3.From Specific Position\n");
scanf("%d",&pos1);
switch(pos1)
{
case 1:
	*temp = *head;
	*head = (*head)->next;
	free(*temp);
	break;
case 2:
	*temp = *head;
	while((*temp)->next!=0)
		{
		*temp = (*temp)->next;
		}
	free((*temp)->next);
	break;
case 3:
	printf("Enter the postion from which do you want to delete\n");
	scanf("%d",&pos);
	*temp = *head;
	while(i<pos-1)
		{
		*temp = (*temp)->next;
		i++;
		}
	currentnode = (struct node**)malloc(sizeof(struct node*));
	*currentnode = (*temp)->next;
	(*temp)->next = (*currentnode)->next;
	free(*currentnode);
	break;
default:
	printf("Invalid Input");
	goto begin;
}
    printf("Do you want to delete more nodes\n");
    printf("1.Yes\t2.No\n");
    scanf("%d",&e);
}
}