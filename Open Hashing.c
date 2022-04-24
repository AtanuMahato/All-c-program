#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  int key;
  struct node* link;
};
void add(struct node[],int);
void display(struct node[],int);
void add_new_data(struct node[],int);
void search(struct node[],int);
void delete(struct node[],int);
int length(struct node*);
int main()
{
int size;
printf("Enter the size of the hash table:- ");
scanf("%d",&size);
struct node hash_table[size];
  int n;
  while(1)
  {
	printf("1:for add a data in hash table\n");
	printf("2:for display the data in the hash table\n");
	printf("3:for add a new data in hash table\n");
	printf("4:for search a data int the hash table\n");
	printf("5:for delete a data from the hash table\n");
	printf("6:for exit\n");
	scanf("%d",&n);
	switch(n)
	{
	  case 1:
	  {
		add(hash_table,size);
		break;
	  }
	  case 2:
	  {
		display(hash_table,size);
		break;
	  }
	  case 3:
	  {
		add_new_data(hash_table,size);
		break;
	  }
	  case 4:
	  {
		 search(hash_table,size);
		 break;
	  }
	  case 5:
	  {
		delete(hash_table,size);
		break;
	  }
	  case 6:
	  {
		exit(0);
	  }
	}
  }
}
void add(struct node array[],int N)
{
  int data,i,j=0,k=0;
  while(j<N)
  {
	 array[j%N].link = NULL;
	 j++;
  }
  while(k<N)
  {
	array[k%N].data = -1;
	k++;
  }
  printf("Enter the data:- \n");
  for(i=0;i<N;i++)
  {
	 scanf("%d",&data);
	 if(array[data%N].data==-1)
	  {
		array[data%N].data = data;
		array[data%N].key = data%N;
	  }
	  else
	  {
		struct node* newnode = NULL;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->link = NULL;
		if(array[data%N].link==NULL)
		array[data%N].link = newnode;
		else
		{
		  struct node* p = array[data%N].link;
		  while(p->link!=NULL)
		  {
			p = p->link;
		  }
		  p->link = newnode;
		}
	  }
  }
}
void display(struct node array[],int N)
{
   int i;
   printf("key\tvalue\n\n");
   for(i=0;i<N;i++)
   {
	  if(array[i].data==-1&&array[i].link==NULL)
	  {
		printf("%d\n\n",i);
	  }
	  else
	  {
	  
		 printf("%d\t%d",array[i].key,array[i].data==-1?0:array[i].data);
	     if(array[i].link==NULL)
	     printf("\n\n");
	     else
	     printf("\t");
	     struct node* p = array[i].link;
	     while(p!=NULL)
	     {
	    	printf("%d\t",p->data);
	    	p = p->link;
	     }
	     if(array[i].link!=NULL)
	     printf("\n\n");
	  }
   }
}
void add_new_data(struct node array[],int N)
{
  int new;
  printf("Enter the data:- ");
  scanf("%d",&new);
  if(array[new%N].data==-1)
  {
	array[new%N].data = new;
	array[new%N].key = new%N;
  }
  else
  {
	struct node* newnode = NULL,* p = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = new;
	newnode->link = NULL;
	if(array[new%N].link==NULL)
	array[new%N].link = newnode;
	else
	{
	   p = array[new%N].link;
	   while(p->link!=NULL)
	   {
	     p = p->link;
	   }
	    p->link = newnode;
    }
  }
}
void search(struct node array[],int N)
{
  int ele;
  printf("\nEnter the search data:- ");
  scanf("%d",&ele);
  if(array[ele%N].data==ele)
  {
	printf("\nData is found in %d number key\n",array[ele%N].key);
  }
  else
  {
	printf("\nData is not present in the hash table\n");
  }
}
void delete(struct node array[],int N)
{
  int ele,len;
  printf("Enter the data:");
  scanf("%d",&ele);
  struct node* p = array[ele%N].link,* r = NULL,* q =NULL;
  if(array[ele%N].data==ele)
  array[ele%N].data = -1;
  else
  {
	int i = 1;
	len = length(p);
	while(p->data!=ele)
	{
	   q = p;
	   p = p->link;
	   i++;
	}
	 r = p->link;
	if(i==1)
	{

	   array[ele%N].link = r;
	   free(p);
	}
	else if(i==len)
	{
	  q->link = NULL;
	  free(p);
	}
	else
	{
	  p->link = NULL;
	  q->link = r;
	  free(p);
	}
  }
}
int length(struct node* p)
{
  int i=0;
  while(p!=NULL)
  {
	i++;
	p = p->link;
  }
  return i;
}
