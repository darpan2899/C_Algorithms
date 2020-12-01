#include<stdio.h>
#include<time.h>


void matrix_chain_order(int p[],int no);

void P_O_P(int no,int s[no] [no],int i,int j);

void main()
{
 int i,n;
 float ans;
  clock_t start,end;
 printf("enter the no. of matrices");
 scanf("%d",&n);
 
 
 
 int p[n+1];
 
 for(i=0;i<=n;i++)
 {
 
  
  printf("\nenter value of p%d=",i);
  scanf("%d",&p[i]);
 }
 start=clock();
 matrix_chain_order(p,n+1);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("\ntime= %f \n",ans);
}

void matrix_chain_order(int p[],int no)
{
 int n,i,j,l,k,q;
 n=no-1;
 int m[n+1][n+1],s[n+1][n+1];
 
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
    m[i][j]=0;
    s[i][j]=0;
   }
 }
 
 for(i=1;i<=n;i++)
 {
  m[i][i]=0;
 }
 
 for(l=2;l<=n;l++)
 {
   for(i=1;i<=(n-l+1);i++)
   {
     j=i+l-1;
     m[i][j]=9999999;
     
     for(k=i;k<=(j-1);k++)
     {
       q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j] );
       
       if(q < m[i][j])
       {
        m[i][j]=q;
        s[i][j]=k;
       } 
     }
   }
 }
 
 printf("m=");
 for(i=1;i<=n;i++)
 {
   printf("\n");
   printf("|");
   for(j=1;j<=n;j++)
   {
    printf(" %d ",m[i][j]);
   }
   printf("\t|");
 }
 printf("\n");
 printf("\n");
 
  printf("s=");
  for(i=1;i<=n;i++)
  {
   printf("\n");
    printf("|");
   for(j=1;j<=n;j++)
   {
    printf("%d ",s[i][j]);
   }
    printf("|");
 }
 printf("\n");
 
 i=1;
 j=n;
 P_O_P(n,s,i,j);
}

void P_O_P(int n,int s[n+1] [n+1],int i,int j)
{ 
 int x1,x2;
 if(i==j)
 {
  printf("A%d",i);
 }
 
 else
 {
  printf("(");
  x1=s[i][j];
  P_O_P(n,s,i,x1);
  x2=(s[i][j]+1);
  P_O_P(n,s,x2,j);
  printf(")");
 }
}
