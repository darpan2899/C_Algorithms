#include<stdio.h>
#include<time.h>
int binary_search(int a[],int lo,int hi,int item)
{
  int mid;
  
  
  if(lo<=hi)
  {
   mid=(lo+hi)/2;
    if(item==a[mid])
    {
     return mid;
    }
    else if(item>a[mid])
    {
     binary_search(a,mid+1,hi,item);
    }
    else if(item<a[mid])
    {
     binary_search(a,lo,mid-1,item);
    }
    else
    {
     return -1;
    }
  }
 
 
}
void ins_sort(int a[],int n)
{
  int i,j,key;
 for(j=1;j<n;j++)
 {
  key=a[j];
   i=j-1;
  while((i>=0)&&(a[i]>key))
  {
   a[i+1]=a[i];
   i=i-1;
  }
  a[i+1]=key;
 }
}
void display(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
}

void main()
{
 
 int i,n,item,j,pos;
 float ans;
 FILE *fp;
 clock_t start,end;
 printf("enter the size of array");
 scanf("%d",&n);
 int a[n];
 fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   j=rand()%n + 1;
  fprintf(fp,"%d \t",j);
 }
 fclose(fp);
 fp=fopen("random.txt","r");
  for(i=0;i<n;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
  fclose(fp);
 ins_sort(a,n);
 printf("enter the no.you want to search");
 scanf("%d",&item);

  start=clock();
 pos=binary_search(a,0,n-1,item);
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f \n",ans);

 if(pos==-1)
 {
  printf("number not found");
  
 }
 else
 {
  printf("number= %d at position= %d \n",item,pos);
 }
 //display(a,n);
 
 fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   
  fprintf(fp,"%d \t",a[i]);
 }
 fclose(fp);
 printf("\n");
 
}
  
