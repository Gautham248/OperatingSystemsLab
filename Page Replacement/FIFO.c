#include<stdio.h>
int main()
{

    printf("Enter the length of the reference string :");
    int n;
    scanf("%d",&n);

    printf("Enter the reference string : ");
    int i,j,k,rs[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    int f;
    printf("Enter the number of frames : ");
    scanf("%d",&f);


    int m[f];
    for(i=0;i<f;i++)
    {
        m[i]=-1;
    }

    int pagefault=0,count=0;
    for(i=0;i<n;i++)
    {
        //page hit
        for(k=0;k<f;k++)
        {
            if(m[k]==rs[i])
                break;
        }
        //page miss and insertion of new page
        if(k==f)
        {
            m[count++]=rs[i];
            pagefault++;
        }
        for(j=0;j<f;j++)
        {
            printf("%d\t",m[j]);
        }
        if(k==f)
            printf("\tPF No. :%d",pagefault);
        printf("\n");
        if(count==f)
            count=0;
    }
    printf("Number of page faults using FIFO are :%d ",pagefault);



}
