#include<stdio.h>
void convert_upper(char[],int);
int main()
{
   char line[200];
   int j;
   printf("Enter the line:- ");
   gets(line);
   while(line[j]!='\0')
   {
	 convert_upper(line,j);
	 j++;
   }
   puts(line);
}
void convert_upper(char str[],int i)
{
	switch(str[i])
	 {
		case 'a':
		{
		   str[i]='A';
		   break;
		}
		case 'b':
		{
		  str[i]='B';
		  break;
		}
		case 'c':
		{
		  str[i]='C';
		  break;
		}
		case 'd':
		{
		  str[i]='D';
		  break;
		}
		case 'e':
		{
		  str[i]='E';
		  break;
		}
		case 'f':
		{
		  str[i]='F';
		  break;
		}
		case 'h':
		{
		  str[i]='H';
		  break;
		}
		case 'i':
		{
		   str[i]='I';
		   break;
		}
		case 'j':
		{
		  str[i]='J';
		  break;
		}
		case 'k':
		{
		  str[i]='K';
		  break;
		}
		case 'l':
		{
		   str[i]='L';
		   break;
		}
		case 'm':
		{
		  str[i]='M';
		  break;
		}
		case 'n':
		{
		  str[i]='N';
		  break;
		}
		case 'o':
		{
		  str[i]='O';
		  break;
		}
		case 'p':
		{
		  str[i]='P';
		  break;
		}
		case 'q':
		{
		  str[i]='Q';
		  break;
		}
		case 'r':
		{
		  str[i]='R';
		  break;
		}
		case 's':
		{
		   str[i]='S';
		   break;
		}
		case 't':
		{
		   str[i]='T';
		   break;
		}
		case 'u':
		{
		  str[i]='U';
		  break;
		}
		case 'v':
		{
		  str[i]='V';
		  break;
		}
		case 'w':
		{
		  str[i]='W';
		  break;
		}
		case 'x':
		{
		  str[i]='X';
		  break;
		}
		case 'y':
		{
			str[i]='Y';
			break;
		}
		case 'z':
		{
		  str[i]='Z';
		  break;
		}
	 }
}
