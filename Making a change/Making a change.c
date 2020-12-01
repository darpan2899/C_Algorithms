#include<stdio.h>
#include<time.h>

void makingchange(int n,int N,int d[]);

void makingchangeans(int n,int N,int d[],int c[n+1] [N+1]);

void main()
{
 int i,n,N;
 float ans;
  clock_t start,end;
 printf("enter the no. of coins");
 scanf("%d",&n);
 
  printf("enter the size of change");
 scanf("%d",&N);
 
 int d[n+1];
 
 for(i=1;i<=n;i++)
 {
  printf("\nenter value of coin %d=",i);
  scanf("%d",&d[i]);
  
  
 }
 start=clock();
 makingchange(n,N,d);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("\ntime= %f \n",ans);
}

void makingchange(int n,int N,int d[])
{
 int i,j;
 int c[n+1][N+1];
 
 
 
 for(i=1;i<=n;i++)
 {
  c[i][0]=0;
  }
  
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=N;j++)
   {
    if(i==1&&j<d[i])
     {
      c[i][j]=999999;
      }
      else if(i==1)
      {
       c[i][j]=(1+ c[1][j-d[i]]);
      }
      else if(j<d[i])
      {
        c[i][j]=c[i-1][j];
      }
      else if(c[i-1][j]<(1+ c[i][j-d[i]]))
      {
        c[i][j]=c[i-1][j];
      }
      else
      {
        c[i][j]=(1+ c[i][j-d[i]]);
      }
    }
   }
   
   makingchangeans(n,N,d,c);
}
void makingchangeans(int n,int N,int d[],int c[n+1] [N+1])
{
 int i=n,j=N,v=0;
 
 while( i>0 && j>0 )
 {
  if(c[i][j]!=c[i-1][j])
  {
   printf("\ncoin=%d",d[i]);
  
   v++;
 
   j=j-d[i];
  }
  else
  {
   i=i-1;
   }
  }
  
  printf("\n total coins= %d \n",v);
}
