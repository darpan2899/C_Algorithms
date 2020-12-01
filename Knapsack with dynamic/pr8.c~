#include<stdio.h>
#include<time.h>

void knapsack(int n,int W,int wt[],int vl[]);

void knapsackans(int n,int W,int wt[],int vl[],int kp[n+1] [W+1]);

void main()
{
 int i,n,W;
 float ans;
  clock_t start,end;
 printf("enter the no. of items");
 scanf("%d",&n);
 
  printf("enter the size of knapsack");
 scanf("%d",&W);
 
 int wt[n+1],vl[n+1];
 
 for(i=1;i<=n;i++)
 {
  printf("\nenter weight of item %d=",i);
  scanf("%d",&wt[i]);
  
  printf("\nenter value of item %d=",i);
  scanf("%d",&vl[i]);
 }
 start=clock();
knapsack(n,W,wt,vl);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("\ntime= %f \n",ans);
}

void knapsack(int n,int W,int wt[],int vl[])
{
 int w,i;
 int kp[n+1][W+1];
 
 for(w=0;w<=W;w++)
 {
 kp[0][w]=0;
 }
 
 for(i=1;i<=n;i++)
 {
  kp[i][0]=0;
  }
  
 for(i=1;i<=n;i++)
 {
   for(w=1;w<=W;w++)
   {
    if(wt[i]<=w)
    {
      if( (vl[i] + kp[i-1][w-wt[i]]) > (kp[i-1][w]) )
      {
        kp[i][w]=vl[i] + kp[i-1][w-wt[i]];
       }
       else
       {
         kp[i][w]=kp[i-1][w];
        }
       }
     else
      {
       kp[i][w]=kp[i-1][w];
      }
     }
   }
   
   knapsackans(n,W,wt,vl,kp);
}
void knapsackans(int n,int W,int wt[],int vl[],int kp[n+1] [W+1])
{
 int i=n,k=W,v=0;
 
 while( i>0 && k>0 )
 {
  if(kp[i][k]!=kp[i-1][k])
  {
   printf("\nitem=%d  value =%d",i,vl[i]);
  
   v=v+vl[i];
   k=k-wt[i];
   i=i-1;
  }
  else
  {
   i=i-1;
   }
  }
  
  printf("\n total profit= %d \n",v);
}
