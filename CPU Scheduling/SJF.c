#include<stdio.h>

int main()
{
    printf("Enter the number of processes: ");
    int temp,n,i,j,bt[10],wt[10],tat[10];
    float avwt=0,avtat=0;
    scanf("%d",&n);
    printf("Enter the burst time of each process : \n");
    for(i=0;i<n;i++)
    {
        printf("Process[%d] :",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
        }
    }
    printf("\nProcess\t\tBT\t\tWT\t\tTAT\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avtat+=tat[i];
        avwt+=wt[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    avwt/=n;
    avtat/=n;
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f",avtat);



}
