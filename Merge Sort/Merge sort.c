#include<stdio.h>
#include<time.h>
void merge(int a[],int lo,int mid,int hi);
void merge_sort(int a[],int lo,int hi);
void display(int a[],int n);
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
  merge_sort(a,1,n);
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
void merge(int a[],int lo,int mid,int hi)
{

  int i,j,n1,n2,k;
  n1=mid-lo+1;
  n2=hi-mid;
  int l[n1+1];
  int r[n2+1];

  for(i=1;i<=n1;i++)
  {
    l[i]=a[lo+i-1];
   }

    for(j=1;j<=n2;j++)
  {
    r[j]=a[mid+j];
   }

  l[n1+1]=9999;
  r[n2+1]=9999;

  i=1;
  j=1;
   for(k=lo;k<=hi;k++)
   {
    if(l[i]<=r[j])
    {
    a[k]=l[i];
     i=i+1;
    }
    else
    {
    a[k]=r[j];
     j=j+1;
    }
   }
}
void merge_sort(int a[],int lo,int hi)
{
  int mid;

  if(lo<hi)
  {
   mid=(lo+hi)/2;
   merge_sort(a,lo,mid);
   merge_sort(a,mid+1,hi);
   merge(a,lo,mid,hi);
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
