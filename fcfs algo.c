#include<stdio.h>
#include<stdlib.h>
void display(int[],int[],int);
void shortAT_value(int[],int);
int processID(int,int[],int,int[]);
void count_TAT(int[],int[],int[],int );
void count_WT(int[],int[],int[],int);
void count_RT(int[],int[],int[],int);
void display_chart(int,int[],int[],int[],int[],int[],int[]);
float count_AVG_TAT(int[],int);
float count_AVG_WT(int[],int);
int main()
{
	int process,i,at,bt;
	printf("Enter how many process you have:- ");
	scanf("%d",&process);
	int array1[process],array2[process];
	int CT_array[process],TAT_array[process],WT_array[process],RT_array[process];
	for(i=0;i<process;i++)
	{
	  printf("Enter arrival time of process%d:- ",i+1);
	  scanf("%d",&at);
	  printf("Enter burst time of process%d:- ",i+1);
	  scanf("%d",&bt);
	  array1[i] = at;
	  array2[i] = bt;
	}
	display(array1,array2,process);
	int demo_array[process];
	for(i=0;i<process;i++)
	{
	  demo_array[i] = array1[i];
	}
	int AT_value ;
	 shortAT_value(demo_array,process);
	 printf("\n\nGantt chart of this algorithm------------\n\n");
	 printf("\t");
	 int processed[process];
	  for(i=0;i<process;i++)
      {
	    processed[i] = 0;
      }
	for(i=0;i<process;i++)
	{
	  AT_value = demo_array[i];
	  int PID = processID(AT_value,array1,process,processed);
      printf("|  p%d |  ",PID+1);
	}
	printf("\n\t");
	int j;
	int CT = demo_array[0];
	int R_array[process];
	for(i=0;i<process;i++)
    {
	    processed[i] = 0;
    }
	for(j=0;j<process;j++)
	{
	int value = demo_array[j];
	  int ID = processID(value,array1,process,processed);
		while(CT<value)
		{
		  CT = CT+1;
		}
	    R_array[ID] = CT;
	    printf("%d",CT);
	   CT = CT + array2[ID];
	   CT_array[ID] = CT;
	  printf("     %d  ",CT);
	}
	count_TAT(array1,CT_array,TAT_array,process);
	count_WT(array2,TAT_array,WT_array,process);
    count_RT(R_array,RT_array,array1,process);
    printf("\n\n");
	display_chart(process,array1,array2,CT_array,TAT_array,WT_array,RT_array);
	float AVG_TAT = count_AVG_TAT(TAT_array,process);
	printf("\n\tAverage TAT = %.2f\n",AVG_TAT);
	float AVG_WT = count_AVG_WT(WT_array,process);
	printf("\n\tAvegrage WT = %.2f\n",AVG_WT);
	return 0;
}
void display(int array1[],int array2[],int p)
{
  int i;
  printf("\t-------------------------------------------------");
  printf("\n\t|  process ID\t|  Arrivel Time |  Burst Time   |\n");
  printf("\t-------------------------------------------------\n");
  for(i=0;i<p;i++)
  {
	 printf("\t|\tp%d\t|\t%d\t|\t %d\t|\n",i+1,array1[i],array2[i]);
  }
  printf("\t-------------------------------------------------\n");
}
void shortAT_value(int array[],int n)
{
   int i,j,temp,count=0;
  for(i=0;i<n-1;i++)
  {
    count=1;
    for(j=0;j<n-1-i;j++)
    {
      if(array[j]>array[j+1])
      {
        temp=array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
        count=0;
	  }
	}
	if(count==1)
	{
	 break;
	}
  }
}
int processID(int value,int array[],int p,int processed[])
{
   int i;
   for(i=0;i<p;i++)
   {
	 if(array[i]==value&&processed[i]== 0)
	 {
	   processed[i] = 1;
	   return i;
	 }
   }
}
void count_TAT(int AT[],int CT[],int TAT[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	 TAT[i] = CT[i] - AT[i];
   }
}
void count_WT(int BT[],int TAT[],int WT[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	 WT[i] = TAT[i] - BT[i];
   }
}
void count_RT(int FR[],int RT[],int AT[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	  RT[i] = FR[i] - AT[i];
   }
}
void display_chart(int p,int AT[],int BT[],int CT[],int TAT[],int WT[],int RT[])
{
   int i;
   printf("\t------------------------------------------------------------------------------------------------------------------------------");
   printf("\n\t|  process ID\t|  Arrival Time |  Burst Time   |  Complacent Time  |  Turn Around Time  |  Waiting Time  |  Response Time  |\n");
   printf("\t------------------------------------------------------------------------------------------------------------------------------\n");
   for(i=0;i<p;i++)
   {
	  printf("\t|\tp%d\t|\t%d\t|\t %d\t|\t %d\t    |\t\t%d\t |\t %d\t  |\t   %d\t    |\n",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i],RT[i]);
   }
   printf("\t------------------------------------------------------------------------------------------------------------------------------\n");
}
float count_AVG_TAT(int TAT[],int p)
{
   int i,count =0;
   float avg_TAT;
   for(i=0;i<p;i++)
   {
	  count = count + TAT[i];
   }
   avg_TAT = count /(float) p ;
   return avg_TAT;
}
float count_AVG_WT(int WT[],int p)
{
  int i,count = 0;
  float avg_WT;
  for(i=0;i<p;i++)
  {
	 count = count + WT[i];
  }
  avg_WT = count /(float) p;
  return avg_WT;
}














