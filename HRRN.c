#include<stdio.h>
void display(int[],int[],int);
void sort_array(int[],int);
int processID(int ,int[],int);
void set_defaultarray_value(int[],int);
int check_ready_queue(int,int[],float[],int,int[],int[]);
float count_RR(int,int);
void sort_RR_array(float[],int);
int search_higherRR_pid(float,float[],int);
void count_TAT(int[],int[],int[],int);
void count_WT(int[],int[],int[],int);
void count_RT(int[],int[],int[],int);
void display_chart(int,int[],int[],int[],int[],int[],int[]);
float count_AVG_TAT(int[],int);
float count_AVG_WT(int[],int);
int main()
{
   int process,i,j;
   printf("Enter how many process you have :- ");
   scanf("%d",&process);
   int AT_array[process],BT_array[process],demo_at[process],processed[process];
   for(i=0;i<process;i++)
   {
	  printf("Enter the arrival time of process(%d):- ",i+1);
	  scanf("%d",&AT_array[i]);
	  printf("Enter the burst time of process(%d):- ",i+1);
	  scanf("%d",&BT_array[i]);
   }
   display(AT_array,BT_array,process);
   printf("\n");
   printf("Gantt Chart:- \n\n");
   for(i=0;i<process;i++)
   {
	  demo_at[i] = AT_array[i];
   }
   sort_array(demo_at,process);
   set_defaultarray_value(processed,process);
   int CT,PID,count,k;
   int CT_array[process+1],RT_array[process],C_T[process];
   CT = demo_at[0];
   CT_array[0] = CT;
   PID = processID(demo_at[0],AT_array,process);
   printf("\t| p%d ",PID+1);
   processed[PID] = 1;
   RT_array[PID] = CT;
   CT = CT + BT_array[PID];
   CT_array[1] = CT;
   C_T[PID] = CT;
   float demo_array[process],demo2_array[process];
   k =2;
   for(j=1;j<process;j++)
   {
	   for(i=0;i<process;i++)
	   {
		 demo_array[i] = 0;
	   }
	   check_ready_queue(CT,AT_array,demo_array,process,processed,BT_array);
	   for(i=0;i<process;i++)
	   {
		 demo2_array[i] = demo_array[i];
	   }
	   sort_RR_array(demo2_array,process);
	   int id = search_higherRR_pid(demo2_array[process-1],demo_array,process);
	   processed[id] = 1;
	   RT_array[id] = CT;
	   CT = CT + BT_array[id];
	   C_T[id] = CT;
	   CT_array[k] = CT;
	   k++;
	   printf("| p%d ",id+1);
   }
   printf(" |\n\t");
   for(i=0;i<=process;i++)
   {
	 printf("%d    ",CT_array[i]);
   }
   printf("\n");
   int TAT[process],WT[process],RT[process];
   count_TAT(AT_array,C_T,TAT,process);
   count_WT(BT_array,TAT,WT,process);
   count_RT(AT_array,RT_array,RT,process);
   printf("\n");
   display_chart(process,AT_array,BT_array,C_T,TAT,WT,RT);
   float AVG_TAT = count_AVG_TAT(TAT,process);
   printf("\n\tAverage TAT = %.2f\n",AVG_TAT);
   float AVG_WT = count_AVG_WT(WT,process);
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
void sort_array(int array[],int n)
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
int processID(int value,int array[],int p)
{
	int i;
	for(i=0;i<p;i++)
	{
	   if(array[i] == value)
	   {
		  return i;
	   }
    }
}
void set_defaultarray_value(int array[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	  array[i] = 0;
   }
}
int check_ready_queue(int ct,int at_array[],float demo_array[],int p,int processed[],int bt_array[])
{
   int i,count,WT;
   count = 0;
   float value;
   for(i=0;i<p;i++)
   {
	  if( at_array[i]<=ct && processed[i] == 0 )
	  {
		 WT = ct - at_array[i];
		 value = count_RR( WT,bt_array[i]);
		 demo_array[i] = value;
		 count++;
	  }
   }
}
float count_RR(int wt,int bt)
{
  float R_R = (wt+bt)/(float)(bt);
  return R_R;
}
void sort_RR_array(float array[],int n)
{
  int i,j,count=0;
  float temp;
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
int search_higherRR_pid(float value,float array[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	  if(array[i]==value)
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
void count_RT(int AT[],int RT_array[],int RT[],int p)
{
   int i;
   for(i=0;i<p;i++)
   {
	  RT[i] = RT_array[i] - AT[i];
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









