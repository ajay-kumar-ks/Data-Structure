#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,queue[100],G[100][2],v;
void insert(int x){
    if(front==-1 && rear ==-1)
        front=rear=0;
    else{
        rear++;
    }
    queue[rear]=x;
}
void delete(){
    if(front==v-1)
        front=-1;
    else
        front++;
    
}
void main(){
    int e,i,j,k,n,visit[100],T[100][2];
    printf("\nEnter the number of vertex & edges:");
    scanf("%d%d",&v,&e);
    printf("\nEnter the edges:");
    for(i=0,j=1;i<e*2;i=i+2,j++){
        printf("\nedge %d:",j);
        scanf("%d%d",&G[i][1],&G[i][2]);
        G[i+1][1]=G[i][2];
        G[i+1][2]=G[i][1];
    }
    for(i=1;i<=v;i++)
      visit[i]=0;
    printf("\nEnter the starting vertex:");
    scanf("%d",&n);
    insert(n);
    visit[n]=1;
    j=0;
    printf("\nvisited vertexs:");
    while(front!=-1){
        k=queue[front];
        for(i=0;i<e*2;i++){
            if(k==G[i][1]&& !visit[G[i][2]]){
                insert(G[i][2]);
                visit[G[i][2]]=1;
                T[j][1]=k;
                T[j][2]=G[i][2];
                j++;
            }
        }
        printf("%d ",k);
        delete();
    }
    for(i=0;i<v-1;i++){
        printf("\n(%d,%d)",T[i][1],T[i][2]);
    }
}
