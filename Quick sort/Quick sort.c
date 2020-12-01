#include<stdio.h>
#include<time.h>
void swap(int *t1,int *t2)
{
 int t;
 t=*t1;
* t1=*t2;
 *t2=t;
}

int partition(int a[],int l,int r)
{
  int pivot,lo,hi; 
  pivot = a[l];
  lo=l+1;
  hi=r;
  while(lo<=hi)
  {
     while(a[hi]>pivot)
     {
      hi=hi-1;
     }
    while(lo<=hi && a[lo]<=pivot)
    {
    lo=lo+1;
    }

   if(lo<=hi)
   {
    swap(&a[lo],&a[hi]);
    lo=lo+1;
    hi=hi-1;
   }
  }
 swap(&a[l],&a[hi]);
 return hi;
}

void quick_sort(int a[],int l,int r)
{
  int q;
 if(l<r)
 {
  q=partition(a,l,r);
  quick_sort(a,l,q-1);
  quick_sort(a,q+1,r);
 }
}
void display(int a[],int n)
{
  int i;
  for(i=1;i<=n;i++)
 {
   printf("%d\t",a[i]);
 }
}
void main()
{
 int i,n,item,j;
 float ans;
 FILE *fp;
 clock_t start,end;
 printf("enter the size of array");
 scanf("%d",&n);
 int a[n];
 fp=fopen("random.txt","w");
 for(i=1;i<=n;i++)
 {
   j=rand()%n + 1;
  fprintf(fp,"%d \t",j);
 }
 fclose(fp);
 fp=fopen("random.txt","r");
  for(i=1;i<=n;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
  fclose(fp);
 /* for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }*/

  start=clock();
  quick_sort(a,1,n);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f \n",ans);


 display(a,n);

/* fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {

  fprintf(fp,"%d \t",a[i]);
 }
 fclose(fp);
 printf("\n");*/

}
 

   
