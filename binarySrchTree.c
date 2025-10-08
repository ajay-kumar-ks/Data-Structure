#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
    struct node *left;
	struct node *right;
}node;

node *root = NULL;
void insertNode(node* root,node * newNode){
        if(root->data > newNode->data){
            if(root->left == NULL)
              root->left = newNode;
            else
              insertNode(root->left,newNode);
        }else if(root->data < newNode->data){
            if(root->right == NULL)
              root->right = newNode;
            else
              insertNode(root->right,newNode);
        }else{
            printf("This number is already exist!!\n");
        }
    }
void createNode(int val){
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        if(!root){
            root = newNode;
            return;
        }
        insertNode(root,newNode);
    }
   void traverseIn(node* root)
        {
            if(root != NULL){
                traverseIn(root->left);
                printf("%d ",root->data);
                traverseIn(root->right);
            }
        }
    void display(node* root){
           node *temp = root;
           while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->left;
           }
        }
    node *minimum(node * root){
        if(root->left != NULL){
            minimum(root->left);
        }
        return root;
    }
    node* deleteNode(node* root,int val){
        if (root == NULL) return root;

       if(root && root->data == val){
          if(root->right == NULL && root->left == NULL){

          }
       }else if(root->data > val){
         deleteNode(root->left,val);
       }else if(root->data < val){
         deleteNode(root->left,val);
       }
    }

    int main(){

        int ch,data,value;
        while(1)
        {
            printf("\n Binary search tree \n ------------------\n  1.create \n  2.inorder \n 3.display \n \n cmd--> ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    printf("enter the value ");
                    scanf("%d",&data);
                    createNode(data);
                    break;
                case 2:
                    traverseIn(root);
                case 3:
                    display(root);
                case 4:
                    printf("enter the value to delete ");
                    scanf("%d",&value);
                    deleteNode(root,value);
            }
            
        }
    }