#include<stdio.h>
#include<time.h>

void merge(int a[],int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q;
	int l[n1],e[n2];
	for(i=1;i<=n1;i++)
	{
		l[i]=a[p+i-1];	
	}
	for(j=1;j<=n2;j++)
	{
		e[j]=a[q+j];
	}
	l[n1+1]=9999;
	e[n2+1]=9999;
	i=1;
	j=1;
	
	for(k=p;k<=r;k++)
	{
		if(l[i]<=e[j])
		{
			a[k]=l[i];
			i=i+1;
		}
		else
		{
			a[k]=e[j];
			j=j+1;
		}
	}
}
void mergsort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergsort(a,p,q);
		mergsort(a,q+1,r);
		merge(a,p,q,r);	
	}
		
	
}
void display(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
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
 fp=fopen("random2.txt","w");
 for(i=1;i<=n;i++)
 {
   j=rand()%n + 1;
  fprintf(fp,"%d \t",j);
 }
 fclose(fp);
 fp=fopen("random2.txt","r");
  for(i=1;i<=n;i++)
  {
   fscanf(fp,"%d",&a[i]);
  }
  fclose(fp);	
  int p,r;
  p=1;
  r=n;
  start=clock();
  mergsort(a,p,r);
  end=clock();

 ans=((float)end-start)/CLOCKS_PER_SEC;
 printf("time= %f \n",ans);
 display(a,n);
  
}
