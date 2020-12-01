#include<stdio.h>
#include<time.h>
void sel_sort(int a[],int n)
{
  int i,j,min,temp;
  float ans;
  clock_t start,end;
  start=clock();
 for(i=0;i<n;i++)
 {
  min=i;
 for(j=i+1;j<n;j++)
  {
   if(a[min]>a[j])
  {
    temp=a[min];
    a[min]=a[j];
    a[j]=temp;
  }
  
 }
}
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f",ans);
 printf("\n");
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
 
 int i,n,key,j;
 
 FILE *fp;
 printf("enter the size of array");
 scanf("%d",&n);
 int a[n];
 fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   j=rand()%n;
  fprintf(fp,"%d \t",j);
 }
 fclose(fp);
 fp=fopen("random.txt","r");
  for(i=0;i<n;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
  fclose(fp);
 sel_sort(a,n);
 display(a,n);
 
 fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   
  fprintf(fp,"%d \t",a[i]);
 }
 fclose(fp);
 printf("\n");
 
}
  
