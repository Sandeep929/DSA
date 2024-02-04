#include<stdio.h>
#include<stdlib.h>

int main()
{
  struct node
  {
    int data;
    struct node *next;
  };
  int choice=1;
  struct node *head,*newnode,*temp;
  head = 0;
  
     while(choice)
     {
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("User defined Datatype Declared\n");

  printf("Enter the data\n");
  scanf("%d",&newnode->data);
  newnode->next = 0;
    if(head==0)
  {
  head = temp = newnode;
  }
  else
  {
    temp->next = newnode;
    temp = newnode;
  }
    printf("Do you want to coontiue(o,1)\n");
    scanf("%d",&choice);
    }
    temp=head;
      while(temp!=0)
      {
        printf("%d\n",temp->data);
        temp = temp->next;
      }
  return 0;
}