#include<stdio.h>
int main()
{
  char sen[500];
  int i,count_vowel=0,count_consonant=0,count_space=0,l=0;
  printf("Enter a Sentence:-");
  gets(sen);
  while(sen[l]!='\0')
  {
    l++;
  }
   for(i=0;i<l;i++)
   {
      if(sen[i]==65||sen[i]==97||sen[i]==101||sen[i]==69||sen[i]==105||sen[i]==73||sen[i]==111||sen[i]==79||sen[i]==117||sen[i]==85)
      {
        count_vowel++;
	  }
	  else if(sen[i]==' ')
	  {
	    count_space++;
	  }
	  else
	  {
	    count_consonant++;
	  }
   }
   printf("Total Count of Vowel=%d\n",count_vowel);
   printf("Total Count of Consonant=%d\n",count_consonant);
   printf("Total Count of Space=%d\n",count_space);
}
