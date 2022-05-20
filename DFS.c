#include<stdio.h>
void DFS(int , int);
int graph[20][20];
int visited[20];
int main()
{
  int total,i,j,start;
  printf("Enter total number of vertix in the graph:- ");
  scanf("%d",&total);
  printf("Enter the adjuction matrice of the graph\n");
  for(i=0;i<total;i++)
  {
	for(j=0;j<total;j++)
	{
	  scanf("%d",&graph[i][j]);
	}
  }
  for(i=0;i<total;i++)
  {
	visited[i] = 0;
  }
  printf("Enter the starting vertex:- ");
  scanf("%d",&start);
  printf("Traversal of the graph using BFS is :- ");
  DFS(start,total);
}
void DFS(int vertix,int n)
{
	int i;
	printf("%d",vertix);
	visited[vertix] = 1;
	for(i=0;i<n;i++)
	{
	   if(graph[vertix][i]==1&&!visited[i])
	   {
		  DFS(i,n);
	   }
	}
}
