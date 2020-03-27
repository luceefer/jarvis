#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int G[MAX][MAX],spanning[MAX][MAX],n;
int prims();
int main()
{
int i,j,total;
printf("Enter number of vertex: ");
scanf("%d",&n);
printf("Enter cost adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
total=prims();
if(total>=9999)
{
    printf("\nMST does not exist...");
    exit(0);
}
printf("Minimum Spanning Tree Matrix: ");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("%d ",spanning[i][j]);
}
printf("\n\nMinimum Spanning Tree Total Cost: %d\n",total);
}
int prims()
{
int cost[MAX][MAX];
int u,v,min,distance[MAX],from[MAX];
int visited[MAX],no_of_edges,i,min_cost,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(G[i][j]==0)
cost[i][j]=9999;
else
cost[i][j]=G[i][j];
spanning[i][j]=0;
}}
distance[0]=0;
visited[0]=1;
for(i=1;i<n;i++)
{
distance[i]=cost[0][i];
from[i]=0;
visited[i]=0;
}
min_cost=0;
no_of_edges=n-1;
while(no_of_edges>0)
{
min=9999;
for(i=1;i<n;i++)
{
if(visited[i]==0&&distance[i]<min)
{
v=i;
min=distance[i];
}}
u=from[v];
spanning[u][v]=distance[v];
spanning[u][v]=distance[v];
no_of_edges--;
visited[v]=1;
for(i=1;i<n;i++)
{
if(visited[i]==0&&cost[i][v]<distance[i])
{
distance[i]=cost[i][v];
from[i]=v;
}}
min_cost=min_cost+cost[u][v];
}

return (min_cost);
}
