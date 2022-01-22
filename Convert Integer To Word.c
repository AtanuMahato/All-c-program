#include<stdio.h>
int main()
{
  char num[50],l=0;
  printf("Enter Number:-");
  gets(num);
   while(num[l]!='\0')
   {
     switch(num[l]-48)
     {
      case 1:
       {
        printf("One ");
        break;
	   }
	  case 2:
	   {
	    printf("Two ");
	    break;
	   }
	  case 3:
	   {
	    printf("Three ");
	    break;
	   }
	  case 4:
	   {
	    printf("Four ");
	    break;
		}
	  case 5:
	  {
	   printf("Five ");
	   break;
	   }
	   case 6:
	   {
	    printf("Six ");
	    break;
		}
		case 7:
		{
		 printf("Seven ");
		 break;
		}
		 case 8:
		{
		  printf("Eight ");
		  break;
		}
		  case 9:
		{
		   printf("Nine ");
		   break;
		}
		default :
		{
		 printf("Zero ");
		}
	 }
     l++;
   }
   return 0;
}
