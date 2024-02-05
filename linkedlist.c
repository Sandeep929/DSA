#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    
    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1,IN,opsn,pos,i=1,count=1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Memory Allocated\n");
        
        printf("Enter the Data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
         head = temp = newnode;   
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1)\n");
        scanf("%d",&choice);
    }
    //traversing
        temp = head;
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
		count++;
        }
        printf("Do you want to insert any node(0/1)\n");
        scanf("%d",&IN);
        if(IN==1)
        {
          printf("Where do you want to Insert\n");
          printf("1.Beginning\t 2.End\t 3.At specific Pos\n");
          scanf("%d",&opsn);
          if(opsn!=1 && opsn!=2 && opsn!=3)
          {
            printf("invalid option-\t");
            printf("Enter between 1 to 3");
          }
          else
          {
            if(opsn!=2 && opsn!=3)
            {
              newnode = (struct node*)malloc(sizeof(struct node));
              printf("Enter the data\n");
              scanf("%d",&newnode->data);
              newnode->next = head;
              head = newnode;
            }
            else
            {
              if(opsn!=1 && opsn!=3)
              {
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data\n");
                scanf("%d",&newnode->data);
                temp = head;
                while(temp->next!=0)
                {
                  temp = temp->next;
                }
                temp->next = newnode;
              }
              else
              {
                if(opsn!=1 && opsn!= 2)
                {
                  printf("Enter the position after which you want to insert\n");
		  scanf("%d",&pos);
			if(pos<1 || pos>count)
			{
			   printf("invalid position");
			}
			else
			{
			    newnode = (struct node*)malloc(sizeof(struct node));
              		   printf("Enter the data\n");
               		   scanf("%d",&newnode->data);
              		   temp = head;
			   while(i<pos)
			   {
				temp = temp->next;
				i++;
			   }
				newnode->next = temp->next;
				temp->next = newnode;
			}
                }
		else
		{
		   exit(0);
		}

              }
            }
          }
        }
        else
        {
          exit(0);
        }
	temp = head;
	while(temp!=0)
	{
	   printf("%d\n",temp->data);
	   temp = temp->next;
	}
    return 0;
}