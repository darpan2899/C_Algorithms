#include<stdio.h>
#include<time.h>
int fact(int n)
{ 
 int f=1;
 if(n==1)
 {
  return 1;
 }
 else
 {
  f=n*fact(n-1);
 }
 return f;
}
void main()
{
 clock_t start,end;
  
 int i,n,f;
 float ans;
 printf("enter the number to find its factorial");
 scanf("%d",&n);
 start=clock(); 
 f=fact(n);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f \n",ans);
 printf("%d",f);
}
