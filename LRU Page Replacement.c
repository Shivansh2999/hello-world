#include<stdio.h>
int main()
{
int reference[]={1, 2, 3, 4,2,1};
int n=3;
int counter[8]={0};
int frame[n];
int max=0;
int i,j,k,free=n;

for(i=0;i<n;i++)
frame[i]=-1;

int present = 0;
int pf=0;

for(i=0;i<6;i++)
{  present =0;
  for(j=0;j<8;j++)
  { for(k=0;k<n;k++)
     { if(frame[k] == j )
         counter[j] = counter[j]+1;
      }
   }

  counter[reference[i]]=0;

  for(j=0;j<n;j++)
  {
    if(frame[j]==reference[i])
     present=1; 
  }

  if(present)
    continue;

  if(free)
  {
   for(k=0;k<n;k++)
     if(frame[k] == -1)
      { frame[k] = reference[i];
        free= free-1;
        pf++;
        break;
      }
    continue;
   }
   else
   {
   	pf++;
   	for(k=0;k<7;k++)
   	{
   	  if(counter[max] < counter[k])
   	  {
   	    max = k;
          }
        }

        for(k=0;k<n;k++)
        {
        if(frame[k] == max)
         { counter[max] = 0;
           frame[k]=reference[i];
           
           break;
          }
         }
     }
}

printf("Total Page Faults = %d\n",pf);
  return 0;
}

  


