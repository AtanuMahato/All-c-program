#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node* left;
  int data;
  struct node* right;
};
struct node* print_tree(struct node*);
struct node* create()
{
  struct node* new_node;
  int n;
  new_node =(struct node*)malloc(sizeof(struct node));
  scanf("%d",&n);
  if(n==-1)
  {
	 return NULL;
  }
  new_node->data = n;
  printf("Enter the left child node of %d:- ",n);
  new_node->left = create();
  printf("Enter the right child node of %d:- ",n);
  new_node->right = create();
  return new_node;
}
int main()
{
  struct node* root;
  printf("Enter the root node of the tree:- \n");
  printf("(-1 for no child node)\n");
  root = create();
  printf("\tnode\tleft child node\tright child node\n");
  print_tree(root);
  return 0;
}

struct node* print_tree(struct node* temp)
{
  struct node* p = temp->left;
  struct node* q = temp->right;
   if(p == NULL && q == NULL)
   {
	 printf("\t %d\n",temp->data);
	 return NULL;
   }
  if(p == NULL)
  {
	printf("\t %d\t\t\t\t%d\n",temp->data,q->data);
	print_tree(q);
	return NULL;
  }
  if(q == NULL)
  {
	printf("\t %d\t\t%d\n",temp->data,p->data);
	print_tree(p);
	return NULL;
  }
  
  printf("\t %d\t\t%d\t\t%d\n",temp->data,p->data,q->data);
  
     print_tree(p);
     print_tree(q);
     return NULL;
}
