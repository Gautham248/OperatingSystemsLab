

//FCFS Disk Scheduling

#include<stdio.h>
#include<stdlib.h>
int main()
{
  //1. Accept the number of service request

  int n;
  printf("Enter the number of requests  : ");
  scanf("%d",&n);

  //2. Ask the user to enter the Sequence of requests and the head position

  int request_queue[n],initial,i;
  printf("Enter the request queue : \n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&request_queue[i]);
  }
  printf("Enter the initial head position :");
  scanf("%d",&initial);


  //3.Service the requests in the order in which they arrive
  //4.Calculate total head movement
  int thm=0;
  for(i=0;i<n;i++)
  {
      thm=thm+(abs(request_queue[i]-initial));
      initial=request_queue[i];
  }

  //5.Print total head movement
  printf("Total Head Movement = %d",thm);


}

