#include<stdio.h>
int main()
{

int reference[]={1,2,3,4,2,1};
int N=6; //total number of references
int n=3; //no of frames
int i,j,found=0,occupied = 0,pf = 0;
int fifo[n];

for(i=0;i<n;i++)
    fifo[i] = -1;

for(i=0;i<N;i++)
{   found=0;
    for(j=0;j<n;j++)
    {
        if(fifo[j]==reference[i])
        {
            found=1;
            break;
        }
    }
    if(found==1)
        continue;
    pf++;
    if(occupied<n)
    {
        for(j=0;j<n;j++)
            if(fifo[j]==-1)
                break;
        fifo[j]=reference[i];
        occupied++;
    }
    else
    {
        for(j=1;j<n;j++)
        {
            fifo[j-1] = fifo[j];
        }
        fifo[n-1]=reference[i];
    }

    for(j=0;j<n;j++)
        printf("%d ",fifo[j]);

    printf("\n");
}

printf("\nTotal Number of Page faults are : %d",pf);

return 0;
}
