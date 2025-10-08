#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
    struct node *prev;
	struct node *next;
}node;

node *head = NULL;

void create(int data,int flg)
{
	node *newNode = (node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->prev=NULL;
	newNode->next=NULL;
    if(!head){
        head = newNode;
        return;
    }
    node *temp = head;
    if(flg){
        while(temp ->next == NULL)
           temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }else{
        head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
    }
}


void delete(int flg)
{
    if(!head){
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    if(flg){
        while(temp ->next->next == NULL)
           temp = temp->next;
        printf("element %d deleted\n",temp->data);
        free(temp);
        temp->next = NULL;
    }else{
        temp = head->next->next;
        temp->prev = head;
        printf("element %d deleted\n",head->next->data);
        free(head->next);
        head->next = temp;
    }
}

void Traverse(int flg)
{
	if(!head){
        printf("List is empty!\n");
        return;
    }
    node *temp = head;
    node *t;
    if(flg)
        printf("Forward Traversing !\n");
	while(temp!=NULL)
	{
        if(flg)
		  printf("%d ",temp->data);
        t = temp;
		temp=temp->next;
	}
    if(!flg){
        printf("Backward Traversing !\n");
        while(t != NULL)
        {
            printf("%d ",t->data);
            t=t->prev;
        }
    }
}

int countNode()
{
	int count =0;
	node *temp=head;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
		
	}
	return count;
}
void main()
{
	int ch,flg,data;
	while(1)
	{
		printf("\n Doubly Linked list \n ------------------\n  1.insert Beginning \n  2.Insert at end\n  3.Delete From Beginning \n  4.Delete From end\n  5.Traverse From Beginning \n  6.Traverse From end \n  7.Count Nodes\n  8.exit\n \n cmd--> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			       printf("Enter the data :");
				   scanf("%d",&data);
				   create(data,0);
				   break;
				   
			case 2:printf("Enter the data :");
                   scanf("%d",&data);
                   create(data,1);
                   break;
				   
		    case 3:delete(0);
		    	   break;
		    	   
		    case 4:delete(1);
		    	   break;
            case 5:Traverse(1);
                   break;
		    	   
		    case 6:Traverse(0);
		    	   break;
            case 7:printf("Number of Nodes is %d\n",countNode());
                   break;	   	   
		    case 8:exit(0);
		}
	}
	
}
