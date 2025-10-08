#include<stdio.h>
#include<stdlib.h>

#define SIZE 5 

int queue[SIZE];
int rear = -1,front = -1;

void insert(int val){
    if(rear == SIZE-1 && front == 0 || rear+1 == front){
        printf("queue is full! \n");
        return;
    }
    if(front == -1)
      front = 0;
    if(rear == SIZE-1)
      rear = -1;
    queue[++rear] = val;
}
void delete(){
    if(front == -1){
        printf("queue is empty! \n");
        return;
    }
    printf("%d is deleted \n",queue[front]);
    if(front == rear){
        front = rear = -1;
        return;
    }
    if(front+1 == SIZE)
      front = -1;
    front++;
}
void display(){
    int i = front-1;
    if(rear == -1){
        printf("queue is empty!\n");
        return;
    }
    printf("queue is \n");
    while(i!=rear){
        if(i == SIZE)
         i = -1;
        i++;
        printf("%d ",queue[i]);
    }
    printf("%d ",queue[i]);
}
int count(){
    return 5;
}

void main()
{
	int ch,data;
	while(1)
	{
		printf("\n Circular Queue \n -------------\n  1.insert  \n  2.Delete  \n  3.Display\n  4.Count \n  5.exit\n \n cmd--> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			       printf("Enter the data :");
				   scanf("%d",&data);
				   insert(data);
				   break;
				   
			case 2:delete();
                   break;
				   
		    case 3:display(0);
		    	   break;
            case 4:printf("Number of elements is %d\n",count());
                   break;	   	   
		    case 5:exit(0);
		}
	}
	
}