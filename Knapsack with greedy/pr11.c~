#include<stdio.h>
#include<time.h>

void knapsack(int n,int W,int wt[],int vl[],int pw[],int name[]);



void main()
{
 int i,j,n,W,min,temp,temp1,temp2,temp3;
 float ans;
  clock_t start,end;
 printf("enter the no. of items");
 scanf("%d",&n);
 
  printf("enter the size of knapsack");
 scanf("%d",&W);
 
 int name[n+1],wt[n+1],vl[n+1],pw[n+1];
 
 for(i=1;i<=n;i++)
 {
  name[i]=i;
  
  printf("\nenter weight of item %d=",i);
  scanf("%d",&wt[i]);
  
  printf("\nenter value of item %d=",i);
  scanf("%d",&vl[i]);

  pw[i]=(vl[i] / wt[i]);

  
 }

 for(i=1;i<=n;i++)
 {
  min=i;
 for(j=i+1;j<=n;j++)
  {
   if(pw[min]<pw[j])
  {
   temp=name[min];
    name[min]=name[j];
    name[j]=temp;
   
    temp1=pw[min];
    pw[min]=pw[j];
    pw[j]=temp1;

    temp2=wt[min];
    wt[min]=wt[j];
    wt[j]=temp2;

    temp3=vl[min];
    vl[min]=vl[j];
    vl[j]=temp3;
  }
  
 }
}



 start=clock();
knapsack(n,W,wt,vl,pw,name);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("\ntime= %f \n",ans);
}

void knapsack(int n,int W,int wt[],int vl[],int pw[],int name[])
{
 int weight=0,profit=0,i;
 float x[n+1];
 
 
 
 for(i=1;i<=n;i++)
 {
  x[i]=0;
  }
  
 for(i=1;i<=n;i++)
 {
  if(weight + wt[i] <= W)
  {
    x[i]=1;

    weight=weight+wt[i];
    profit=profit+vl[i];

   printf("\nitem=%d weight=%d value =%d",name[i],wt[i],vl[i]);

   printf("\ntotal weight=%d \ntotal profit=%d",weight,profit);
  } 
  else
  {
    x[i]=((W-weight)/(float)wt[i]);


    weight=W;
    profit = profit + (vl[i] * x[i]);

   
  
   printf("\nitem=%d weight=%d value =%d",name[i],wt[i],vl[i]);

   printf("\ntotal weight=%d \ntotal profit=%d",weight,profit);

   break;

  }


 }
   
  
}

