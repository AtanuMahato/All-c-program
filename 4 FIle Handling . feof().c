#include<stdio.h>
int main()
{
   FILE *file=NULL;
   char ch;
   file=fopen("a.txt","r");
   if(file==NULL)
   {
      printf("File Doesnot Create");
   }
   else
   {
     while(!feof(file))
     {
        ch=getc(file);
        printf("%c",ch);
	 }
   }
   fclose(file);
   return 0;
   getch();
}
