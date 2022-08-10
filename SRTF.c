#include<stdio.h>
void display(int[],int[],int);
void sort_array(int[],int);
int processID(int,int[],int,int[]);
int processID_1(int,int[],int,int[]);
void count_TAT(int[],int[],int[],int);
void count_WT(int[],int[],int[],int);
void count_RT(int[],int[],int[],int);
void display_chart(int,int[],int[],int[],int[],int[],int[]);
float count_AVG_TAT(int[],int);
float count_AVG_WT(int[],int);
int main()
{
   int process,i;
   printf("Enter how many process you have:- ");
   scanf("%d",&process);
   int  AT_array[process],BT_array[process];
   for(i=0;i<process;i++)
   {
	 printf("Enter the arrival time of process(%d):- ",i+1);
	 scanf("%d",&AT_array[i]);
	 printf("Enter the burst time of process(%d):- ",i+1);
	 scanf("%d",&BT_array[i]);
   }
   	display(AT_array,BT_array,process);
   	printf("\n");
   	int total_BT = 0;
	for(i=0;i<process;i++)
	{
	  total_BT = total_BT + BT_array[i];
	}
   	
   	int demo_at[process],demo_bt[process],RT_array[process],CT_array[process],p[total_BT+1];
   	for(i=0;i<process;i++)
	{
	  demo_at[i] = AT_array[i];
    }
    for(i=0;i<process;i++)
    {
	  demo_bt[i] = BT_array[i];
	}
    sort_array(demo_at,process);
    int CT,PID,demo[process],processed[process],check[process],rt_check[process];
    int checked[process];
    for(i=0;i<process;i++)
    {
	   checked[i]=0;
	}
    for(i=0;i<process;i++)
    {
	   check[i] = 0;
	}
	for(i=0;i<process;i++)
	{
	   rt_check[i] = 0;
	}
	CT = demo_at[0];
	PID = processID(demo_at[0],AT_array,process,processed);
	int count = 0;
	for(i=0;i<process;i++)
	{
	  processed[i] = 0;
	}
	for(i=0;i<process;i++)
	{
	  if((demo_bt[PID] - 1)>demo_bt[i])
	  {
		   count =1;
		   demo_bt[PID] = demo_bt[PID] - 1;
		   break;
	  }
	}
	printf("\t|  p%d  | ",PID+1);
	checked[PID] = 1;
	RT_array[PID] = CT;
	rt_check[PID] = 1;
	p[0] = CT;
	if(count!=0)
	{
	  CT = CT+1;
	  
	}
	else
	{
	  CT = CT + demo_bt[PID];
	  demo_bt[PID] = 0;
	  check[PID] = 1;
	}
	CT_array[PID] = CT;
	p[1] = CT;
	int k = 2;
	while(CT!=total_BT){

	 for(i=0;i<process;i++)
     {
	   demo[i] = 0;
     }
     for(i=0;i<process;i++)
     {
	   if(AT_array[i]<=CT&&check[i]==0)
	   {
		  demo[i] = demo_bt[i];
	   }
     }
  int id,j;
  sort_array(demo,process);
  


	 for(i=0;i<process;i++)
     {
	  if(demo[i] != 0)
	  {
	    if(demo[i] == demo[i+1])
		{
		   id = processID_1(demo[i],demo_bt,process,checked);
		   checked[id] = 1;
		   break;
        }
        else
        {
		   id = processID(demo[i],demo_bt,process,processed);
		   checked[id] = 1;
		   break;
		}
	  }
     }

  
	 

  
  count =0;
	for(j=0;j<process;j++)
	{
	  if((demo_bt[id] - 1)>=demo_bt[j])
	  {
		   count =1;
		   demo_bt[id] = demo_bt[id] - 1;
		   break;
	  }
	}
	if(rt_check[id]==0)
	{
	   RT_array[id] = CT;
	   rt_check[id] = 1;
	}
	if(count!=0)
	{
	  CT = CT+1;
	}
	else
	{
	  CT = CT + demo_bt[id];
	  demo_bt[id] = 0;
	  check[id] = 1;
	}
	CT_array[id] = CT;
	p[k] = CT;
	k++;
	printf("  p%d  |",id+1);
 }
 printf("\n\t");
 for(i=0;i<=total_BT;i++)
 {
	printf("%d      ",p[i]);
 }
int TAT[process],WT[process],RT[process];
count_TAT(AT_array,CT_array,TAT,process);
count_WT(BT_array,TAT,WT,process);
count_RT(AT_array,RT_array,RT,process);
printf("\n");
display_chart(process,AT_array,BT_array,CT_array,TAT,WT,RT);
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
int processID(int data,int array[],int p,int processed[])
{
   int i;
   for(i=0;i<p;i++)
   {
	 if(array[i] == data)
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
int processID_1(int data,int array[],int p,int checked[])
{
   int i;
   for(i=0;i<p;i++)
   {
	  if(array[i] == data&&checked[i] == 1)
	  {
		 return i;
	  }
   }
}









