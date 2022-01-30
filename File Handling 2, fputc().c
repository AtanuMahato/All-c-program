#include<stdio.h>
int main()
{
  FILE *fp=NULL;
  char ch[20];
  fp=fopen("a2.txt","w");
  if(fp==NULL)
  {
    printf("File is Not Create");
  }
  else
  {
    printf("Enter a Sentence");
    gets(ch);
    fputs(ch,fp);
    printf("Data Inserted");
  }
  fclose(fp);
  return 0;
}
