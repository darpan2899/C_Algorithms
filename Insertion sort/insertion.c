#include<stdio.h>
#include<time.h>
void ins_sort(int a[],int n)
{
  int i,j,key;
  float ans;
  clock_t start,end;
  start=clock();
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
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f",ans);
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
   j=rand()%5000;
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
 display(a,n);
 
 fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   
  fprintf(fp,"%d \t",a[i]);
 }
 fclose(fp);
 printf("\n");
 
}
  
