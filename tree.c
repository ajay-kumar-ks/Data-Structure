#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
    struct node *left;
	struct node *right;
}node;

node *root = NULL;

node* createNode()
{
    int val;
    printf("\nEnter value (-1 for no node)");
    scanf("%d",&val);
    if(val == -1){
      return NULL;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    printf("enter left child of %d",val);
    newNode->left = createNode();
    printf("enter right child of %d",val);
    newNode->right = createNode();
    return newNode;
}


// void delete(int flg)
// {
//     if(!head){
//         printf("List is empty!\n");
//         return;
//     }
//     node *temp = head;
//     if(flg){
//         while(temp ->next->next == NULL)
//            temp = temp->next;
//         printf("element %d deleted\n",temp->data);
//         free(temp);
//         temp->next = NULL;
//     }else{
//         temp = head->next->next;
//         temp->prev = head;
//         printf("element %d deleted\n",head->next->data);
//         free(head->next);
//         head->next = temp;
//     }
// }

void traverseIn(node* root)
{
	if(root != NULL){
        traverseIn(root->left);
        printf("%d ",root->data);
        traverseIn(root->right);
    }
}
void traversePre(node* root)
{
	if(root != NULL){
        traverseIn(root->left);
        printf("%d ",root->data);
        traverseIn(root->right);
    }
}
void traversePost(node* root)
{
	if(root != NULL){
        traverseIn(root->left);
        printf("%d ",root->data);
        traverseIn(root->right);
    }
}

// trverse(node* root){
    
// }

// int countNode()
// {
// 	int count =0;
// 	node *temp=head;
// 	while(temp->next!=NULL)
// 	{
// 		count++;
// 		temp=temp->next;
		
// 	}
// 	return count;
// }
void main()
{
	int ch,flg,data;
	while(1)
	{
		printf("\n Doubly Linked list \n ------------------\n  1.createTree \n  2.inorder traverse\n  3.Pre order traverse \n  4.post order traverse\n  5.Traverse From Beginning \n  6.Traverse From end \n  7.Count Nodes\n  8.exit\n \n cmd--> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			       root = createNode();
				   break;
				   
			case 2:
                   printf("inorder traversal  \n");
                   traverseIn(root);
                   break;
            case 3:
                    printf("inorder traversal  \n");
                    traversePre(root);
                    break;
            case 4:
                   printf("inorder traversal  \n");
                   traversePost(root);
                   break;
				   
		    // case 3:delete(0);
		    // 	   break;
		    	   
		    // case 4:delete(1);
		    // 	   break;
            // case 5:Traverse(1);
            //        break;
		    	   
		    // case 6:Traverse(0);
		    // 	   break;
            // case 7:printf("Number of Nodes is %d\n",countNode());
            //        break;	   	   
		    // case 8:exit(0);
		}
	}
	
}
