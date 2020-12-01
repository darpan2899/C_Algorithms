#include<stdio.h>
#include<time.h>
void linear_search(int a[],int n,int item)
{
  int i;
  float ans;
  clock_t start,end;
  start=clock();
 for(i=0;i<n;i++)
 { 
  if(item==a[i])
  {
   printf("number= %d at position= %d \n",a[i],i);
   
  }
 }
 end=clock();
 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f\n",ans);
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
 
 int i,n,item,j;
 
 FILE *fp;
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
 printf("enter the no.you want to search");
 scanf("%d",&item);
 linear_search(a,n,item);
 //display(a,n);
 
 /*fp=fopen("random.txt","w");
 for(i=0;i<n;i++)
 {
   
  fprintf(fp,"%d \t",a[i]);
 }
 fclose(fp);
 printf("\n");*/
 
}
  
