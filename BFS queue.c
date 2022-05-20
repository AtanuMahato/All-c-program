#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int front = -1;
int rear = -1;
int graph[10][10];
int visited[10];
void enqueue(int);
int dequeue();
int isempty();
int isfull();
void BFS(int,int);
int main()
{
   int total,i,j,start;
   printf("Enter total number of vertix of the graph:- ");
   scanf("%d",&total);
   printf("Enter the adjuction vertices of the graph\n");
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
   BFS(start,total);
   return 0;
}
void enqueue(int n)
{
   if(isfull())
   {
	  printf("Queue is full");
   }
   else
   {
	  if(front == -1)
	  {
		front = 0;
	  }
	  rear++;
	  queue[rear] = n;
   }
}
int dequeue()
{
   int data;
   if(isempty())
   {
	 printf("Queue is empty");
   }
   else
   {
	 data = queue[front];
	 front++;
   }
   return data;
}
int isfull()
{
  if(rear == max-1)
  {
	return 1;
  }
  return 0;
}
int isempty()
{
  if(front == -1)
  {
	return 1;
  }
  return 0;
}
void BFS(int a,int n)
{
  int j,deq_data;
  printf("%d\t",a);
  visited[a] = 1;
  enqueue(a);
  while(!isempty())
  {
	deq_data = dequeue();
	for(j=0;j<n;j++)
	{
	  if(graph[deq_data][j] ==1&&visited[j]==0)
	  {
		printf("%d\t",j);
		visited[j] = 1;
		enqueue(j);
	  }
	}
  }
}
