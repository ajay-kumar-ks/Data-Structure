#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];
int rankArr[MAX];

void makeSet(int n){
    int i;
    for(i=0;i<n;i++){
        parent[i] = i;
        rankArr[i] = 1;
    }
}

int findSet(int x){
    if(parent[x] != x){
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y){
    int rootX = findSet(x);
    int rootY = findSet(y);

    if(rootX == rootY) return;

    if(rankArr[rootX] < rankArr[rootY])
       parent[rootX] = rootY;
    else if(rankArr[rootX] > rankArr[rootY])
       parent[rootY] = rootX;
    else{
        parent[rootY] = rootX;
        rankArr[rootX]++;
    }
}

int main(){
    int n = 5;
    makeSet(n);

    unionSets(0,2);
    unionSets(4,2);
    unionSets(3,1);

    if(findSet(4) == findSet(0))
      printf("0 and 4 are in the same set\n");
    else
      printf("0 and 4 are in different sets\n");

    if(findSet(1) == findSet(0))
      printf("1 and 0 are in the same set\n");
    else
      printf("1 and 0 are in different sets\n");

    return 0;
}