#include<stdio.h>
int main()

{
int mark;

printf("enter the mark of the student ");

scanf("%d",&mark);

	if(mark<=100)
	{

	  if(mark>=90)
	  {

	  	printf("exelent");

	  }
	  else if(mark>=80 && mark<90)
	  {

	  	printf("good");

	  }
	  else if (mark>=60 && mark<80)
	  {

	  	printf("avarage");

	  }
	  else if(mark>=50 && mark<60)
	  {

	  	printf("satisfactory");

	  }
	  else
	  {

	  printf("not upto the mark ");

      }
      
	}
	else

		printf("enter the mark within 100");

	return 0;
}

