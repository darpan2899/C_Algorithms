#include<stdio.h>
#include<time.h>
void main()
{
 clock_t start,end;
  
 int fact=1,i,n;
 float ans;
 printf("enter the number to find its factorial");
 scanf("%d",&n);
 start=clock();
 for(i=1;i<=n;i++)
 {
  fact=fact*i;
 }
   end=clock();
   ans=((float)end-start)/CLOCKS_PER_SEC;
   printf("time= %f \n",ans);
   printf("factorial=%d \n",fact);
}
