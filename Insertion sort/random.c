#include<stdio.h>
void main()
{
 int i,j,a[1000];
 FILE *fp;
 fp=fopen("random.txt","w");
 for(i=0;i<1000;i++)
 {
  j=rand()%1000;
  fprintf(fp,"%d \t",j);
  
 }
 fclose(fp);
  fp=fopen("random.txt","r");
  for(i=0;i<1000;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
  fclose(fp);
  for(i=0;i<1000;i++)
  {
   printf("%d \t",a[i]);
  }
 
}

