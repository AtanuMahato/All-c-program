#include<stdio.h>
// #include<conio.h>
#include<string.h>
int main()
{
  FILE *fp=NULL;
  char ch[]="a";
  int count =strlen(ch);
  int i;
  fp=fopen("a.txt","w");
  if(fp==NULL)
  {
    printf("File is Not Created");
  }
  else
  {
    for(i=0;i<count;i++)
    {
      fputc(ch[i],fp);
	}
	printf("Data Inserted");
	fclose(fp);
  }
  getch();
}
