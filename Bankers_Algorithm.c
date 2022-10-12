#include<stdio.h>

int main()

{
    //1.Number of resources and processes
    int n,m;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the number of resources : ");
    scanf("%d",&m);

    //2.Accepting allocated and maximum need of each process
    int i,j;
    int alloc[n][m],max[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)

        {
            printf("Resource allocated for process[%d][%d]: ",i+1,j+1);
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)

        {
            printf("Max resource need for  process[%d][%d]  : ",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
        printf("\n");
    }

    //3.Get the number of available resources
    int avail[m];
    for(i=0;i<m;i++)
    {
        printf("Number of Resource[%d] available :",i+1);
        scanf("%d",&avail[i]);
    }

    //4.Calculating need matrix
    int need[n][m];
    printf("The Need matrix is : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
           printf("%d\t",need[i][j]=max[i][j]-alloc[i][j]);
        }
        printf("\n");
    }

    //5.Initializing a flag array to check if a process is completed or not
    int completed[n];
    for(i=0;i<n;i++)
    {
        completed[i]=0;
    }

    //6.Checking if need>available and finding out the safe sequence
    int k,sequence[n],index=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(completed[i]==0)
            {
                int flag=0;
                for(k=0;k<m;k++)
                {
                    if(need[i][k]>avail[k])
                        flag=1;break;
                }

            if(flag==0)
            {
                sequence[index++]=i;
                for(k=0;k<m;k++)
                {
                    avail[k]+=alloc[i][k];
                    completed[i]=1;
                }
            }

            }
        }
    }
    int flag = 1;

	for( i=0;i<n;i++)
	{
	if(completed[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}

	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", sequence[i]);
	printf(" P%d", sequence[n - 1]);
}
}
