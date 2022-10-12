
#include<stdio.h>
#include<stdlib.h>
int main()
{
  //1. Accept the number of service request

  int n;
  printf("Enter the number of requests  : ");
  scanf("%d",&n);

  //2. Ask the user to enter the
  //(1)Sequence of requests (2) head position (3)size of disk

  int request_queue[n],initial,i,size;
  printf("Enter the request queue : \n");
  for(i=0;i<n;i++)
  {
      scanf("%d",&request_queue[i]);
  }

  printf("Enter the initial head position :");
  scanf("%d",&initial);

  printf("Enter the size of disk : ");
  scanf("%d",&size);

  //3.Sort the request queue in Ascending order
  int j,temp;

  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {
          if(request_queue[i]>request_queue[j])
          {
              temp=request_queue[i];
              request_queue[i]=request_queue[j];
              request_queue[j]=temp;

          }
      }
  }

  //4.Finding the head position among the request queue
  int index;
  for(i=0;i<n;i++)
  {
      if(initial<request_queue[i])
      index=i;
      break;
  }


  int choice;
  printf("1 for high | 0 for low : ");
  scanf("%d",&choice);

  if(choice==1)
  {
  int thm=0;
  thm=((size-1)-initial)+(abs(request_queue[0]-(size-1)));
  printf("Total head movement= %d",thm);



  }
    else
    {
        int thm=0;
        thm=initial+request_queue[n-1];
        printf("Total head movement= %d",thm);

    }






}
