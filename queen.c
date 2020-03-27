#include<stdio.h>
#include<stdlib.h>
int board[100],count;
void queen(int row,int n)
{
int column;
for(column=1;column<=n;column++)
{
if(place(row,column))
{
board[row]=column;
if(row==n)
{
int i,j;
printf("\nSolution %d:\n",++count);
for(i=1;i<=n;++i)
printf("\t%d",i);
for(i=1;i<=n;++i)
{
printf("\n%d",i);
for(j=1;j<=n;++j)
{
if(board[i]==j)
printf("\tQ");
else
printf("\t-");
}}}
else
queen(row+1,n);
}}}
int place(int row,int column)
{
int i;
for(i=1;i<=row-1;i++)
{
if(board[i]==column)
return 0;
else
{
if(abs(board[i]-column)==abs(i-row))
return 0;
}}
return 1;
}
int main()
{
int n;
printf("Enter the number of queens: ");
scanf("%d",&n);
if(n==2||n==3)
{
    printf("There is no possible solution...");
}
queen(1,n);
}
