#include<stdio.h>
void display(int[],int[],int);
void sorte_array(int[],int);
int processID(int,int[],int,int []);
void count_TAT(int[],int[],int[],int);
void count_WT(int[],int[],int[],int);
void count_RT(int[],int[],int[],int);
void display_chart(int,int[],int[],int[],int[],int[],int[]);
float count_AVG_TAT(int[],int);
float count_AVG_WT(int[],int);
int main()
{
  int process,i,j;
  printf("\nEnter how many process you have:- ");
  scanf("%d",&process);
  int AT_array[process],BT_array[process];
  for(i=0;i<process;i++)
  {
	 printf("Enter arrivel time of process(%d):- ",i+1);
	 scanf("%d",&AT_array[i]);
	 printf("Enter Burst time of process(%d):- ",i+1);
	 scanf("%d",&BT_array[i]);
  }
  display(AT_array,BT_array,process);
  int sorted_AT[process];
  for(i=0;i<process;i++)
  {
	 sorted_AT[i] = AT_array[i];
  }
  sorte_array(sorted_AT,process);
  int CT,PID;
  int demo[process],check[process];
  int processed[process],bt_check[process];
  for(i=0;i<process;i++)
  {
	processed[i]=0;
  }
  for(i=0;i<process;i++)
  {
	demo[i] = 0;
  }
  for(i=0;i<process;i++)
  {
	 check[i] = 0;
  }
  CT = sorted_AT[0];
  for(i=0;i<process;i++)
  {
	if(AT_array[i]==CT)
	{
	   demo[i] = BT_array[i];
	}
  }
  sorte_array(demo,process);
  for(i=0;i<process;i++)
  {
	if(demo[i]!=0)
	{
	  PID = processID(demo[i],BT_array,process,processed);
	  break;
	}
  }
  check[PID] = 1;
  processed[PID] = 1;
  printf("\n\n\t|  p%d  |  ",PID+1);
  int RT[process],CT_array[process],p[process+1];
  RT[PID] = CT;
  p[0] = CT;
  CT = CT + BT_array[PID];
  p[1] = CT;
  CT_array[PID] = CT;
  int k = 2;
  for(j=1;j<process;j++)
  {
	 for(i=0;i<process;i++)
     {
	   demo[i] = 0;
     }
  for(i=0;i<process;i++)
  {
	 if(AT_array[i]<=CT&&check[i]==0&&processed[i]==0)
	 {
		demo[i] = BT_array[i];
	 }
  }
  int id;
  sorte_array(demo,process);
  for(i=0;i<process;i++)
  {
	  if(demo[i] != 0)
	  {
		id = processID(demo[i],BT_array,process,processed);
		check[id] = 1;
		processed[id] = 1;
		RT[id] = CT;
		CT = CT+demo[i];
		CT_array[id] = CT;
		p[k] = CT;
		k++;
		break;
	  }
  }
  printf("|  p%d  |  ",id+1);
 }
 printf("\n\t");
 for(i=0;i<process;i++)
 {
	
	  printf("%d      %d  ",p[i],p[i+1]);
	
 }
 int TAT[process],WT[process],RT_array[process];
 count_TAT(AT_array,CT_array,TAT,process);
 count_WT(BT_array,TAT,WT,process);
 count_RT(AT_array,RT,RT_array,process);
 printf("\n\n");
 display_chart(process,AT_array,BT_array,CT_array,TAT,WT,RT_array);
 float AVG_TAT = count_AVG_TAT(TAT,process);
 printf("\n\tAverage TAT = %.2f\n",AVG_TAT);
 float AVG_WT = count_AVG_WT(WT,process);
 printf("\n\tAvegrage WT = %.2f\n",AVG_WT);
  return 0;
}
void display(int AT[],int BT[],int p)
{
	  int i;
	  printf("\t-------------------------------------------------");
	  printf("\n\t|  process ID\t|  Arrivel Time |  Burst Time   |\n");
	  printf("\t-------------------------------------------------\n");
	  for(i=0;i<p;i++)
	  {
		 printf("\t|\tp%d\t|\t%d\t|\t %d\t|\n",i+1,AT[i],BT[i]);
	  }
	  printf("\t-------------------------------------------------\n");
}
void sorte_array(int array[],int n)
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
   int i ;
   for(i=0;i<p;i++)
   {
	  if(array[i]==value&&processed[i]==0)
	  {
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
void count_RT(int AT[],int RT[],int RT_array[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	  RT_array[i] = RT[i] - AT[i];
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




