#include<stdio.h>


void printSets(int s[],int u[],int n){
    int i;
    for(i=0;i<n;i++){
        if(s[i])
            printf("%d",u[i]);
        if(i+1 != n && s[i])
            printf(", ");
    }
}
void viewSets(int n,int a[],int b[],int u[]){
    int i;
    printf("univeal Set = {");
    for(i=0;i<n;i++){
       printf("%d",u[i]);
       if(i+1 != n)
        printf(", ");
    }
    printf("}\n");
    printf("Set A = {");
    printSets(a,u,n);
    printf("}\n");
    printf("Set B = {");
    printSets(b,u,n);
    printf("}\n");
}
void unionSet(int n,int a[],int b[],int u[]){
   int i,c[10];
   for(i=0;i<n;i++){
      if(a[i]||b[i])
        c[i] = 1;
      else
        c[i] = 0;
   }
    printf("Set A U B = {");
    printSets(c,u,n);
    printf("}\n");
}
void interSection(int n,int a[],int b[],int u[]){
    int i,c[10];
    for(i=0;i<n;i++){
        if(a[i]&&b[i])
            c[i] = 1;
        else
            c[i] = 0;
    }
    printf("Set A n B = {");
    printSets(c,u,n);
    printf("}\n");
}

void difference(int n,int a[],int b[],int u[]){
    int ch;
    printf(" 1. A - B \n 2. B - A \n");
    scanf("%d",&ch);
    if(ch == 1){
        int i,c[10];
        for(i=0;i<n;i++){
            if((!(a[i]&&b[i])) && a[i])
                c[i] = 1;
            else
                c[i] = 0;
        }
        printf("Set A - B = {");
        printSets(c,u,n);
        printf("}\n");
    }else if(ch == 2){
        int i,c[10];
        for(i=0;i<n;i++){
            if((!(a[i]&&b[i])) && b[i])
                c[i] = 1;
            else
                c[i] = 0;
        }
        printf("Set B - A = {");
        printSets(c,u,n);
        printf("}\n");
    }else{
        printf("invalid input \n");
    }
}

int main(){
    int u[10],a[10],b[10],n,i;
    int cm;
    printf("enter the size of the universal set\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter %d th element of universal set\t",i+1);
        scanf("%d",&u[i]);
        printf("is %d in set A (1/0)\t",u[i]);
        scanf("%d",&cm);
        cm?(a[i] = 1):(a[i] = 0);
        printf("is %d in set B (1/0)\t",u[i]);
        scanf("%d",&cm);
        cm?(b[i] = 1):(b[i] = 0);
    }

	while(1)
	{
		printf("\n Set Opertaions \n ----------------\n  1.Vew Sets \n  2.Union\n  3.Inter section \n  4.difference \n  5.exit\n \n cmd--> ");
		scanf("%d",&cm);
		switch(cm)
		{
			case 1:
                viewSets(n,a,b,u);
                break;
            case 2:
                unionSet(n,a,b,u);
                break;
            case 3:
                interSection(n,a,b,u);
                break;
            case 4:
                difference(n,a,b,u);
                break;
        }
    }

}