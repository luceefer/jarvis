#include<stdio.h>
#include<stdlib.h>
void knapsack(int M,float w[],float p[],int n);
int main()
{
int n,i,j,M;
float r[10],w[10],p[10],temp;
printf("Enter the capacity of the knapsack: ");
scanf("%d",&M);
printf("Enter the number of objects: ");
scanf("%d",&n);
printf("Enter the weights of the objects: ");
for(i=0;i<n;i++)
{
scanf("%f",&w[i]);
}
printf("Enter the profits of the objects: ");
for(i=0;i<n;i++)
{
scanf("%f",&p[i]);
}
for(i=0;i<n;i++)
{
r[i]=p[i]/w[i];
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(r[i]<r[j])
{
temp=r[i];
r[i]=r[j];
r[j]=temp;
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=w[i];
w[i]=w[j];
w[j]=temp;
}}}
knapsack(M,w,p,n);
}
void knapsack(int M,float w[],float p[],int n)
{
float x[20],tp=0;
int i,j,u;
u=M;
for(i=0;i<n;i++)
x[i]==0.0;
for(i=0;i<n;i++)
{
if(w[i]>u)
break;
else
{
x[i]=1;
tp=tp+p[i];
u=u-w[i];
}}
if(i<n)
x[i]=u/w[i];
tp=tp+(x[i]*p[i]);
for(i=0;i<n;i++)
{
printf("\nObject %d, fraction=%.2f, profit=%.2f",i+1,x[i],p[i]*x[i]);}
printf("\n\nMaximum Profit: %.2f\n",tp);
}
