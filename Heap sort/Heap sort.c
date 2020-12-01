#include<stdio.h>
#include<time.h>

void swap(int *t1,int *t2)
{
 int t;
 t=*t1;
* t1=*t2;
 *t2=t;
}
int LEFT(int i)
{
  return (2*i);
 }
 int RIGHT(int i)
 {
  return ((2*i)+1);
  }
void max_heapify(int a[],int i,int hs)
{
 int l,r,largest;
 
 l=LEFT(i);
 r=RIGHT(i);
 
 if(l<=hs && a[l]>a[i])
 {
  largest = l;
 }
 else
 {
  largest = i;
 }
 
 if(r<=hs && a[r] > a[largest])
 {
  largest = r;
 }
 
 if(largest!=i)
 {
  swap(&a[i],&a[largest]);
  max_heapify(a,largest,hs);
 }
}

void build_max_heap(int a[],int n)
{
 int hs,i;
 hs=n;
 
 for(i=(n/2);i>=1;i--)
 {
  max_heapify(a,i,hs);
 }
}

void heap_sort(int a[],int n)
{
 int hs,i;
 hs=n;
 build_max_heap(a,n);
 for(i=n;i>=2;i--)
 {
  swap(&a[i],&a[1]);
  hs=hs-1;
 max_heapify(a,1,hs);
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
  heap_sort(a,n);
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
 

   
