#include<stdio.h>
int main()
{
   FILE *file =NULL;
   char name[20];
   int roll;
   printf("Enter Name and Roll:-");
   scanf("%s%d",&name,&roll);
   file=fopen("atanu3.txt","w");
   if(file==NULL)
   {
     printf("File doesnot Create");
   }
   else
   {
     fprintf(file,"Name=%s\tRoll=%d",name,roll);
     fclose(file);
   }
   
}
