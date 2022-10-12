
#include<stdio.h>
#include<stdlib.h>
int main()
{


  int n;
  printf("Enter the number of requests  : ");
  scanf("%d",&n);



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

    for(i=0;i<n;i++)
    {
        printf("%d\t",request_queue[i]);
    }


  int choice;

 int index;

  for(i=0;i<n;i++)
  {
      if(initial<request_queue[i])
      {
      index=i;
      break;

      }
  }

  printf("\nINDEX : %d\n",index);
  int y;
  y=index-1;
  printf("1 for high | 0 for low : ");
  scanf("%d",&choice);
  int thm=0;
  if(choice==1)
  {

  int x;
  x=size-1;
  thm=x+(x-initial);
  thm+=request_queue[y];
  printf("Total head movement= %d",thm);
  }
    else
    {

        thm=(size-1)+initial+(size-request_queue[index]-1);
        printf("Total head movement= %d",thm);
    }






}
