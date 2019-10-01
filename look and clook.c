#include<stdio.h>
#include<math.h>

void look(int n,int noq, int qu[10], int st)
{
    int s=0;
    int i=0,j,t;
    for(i=0;i<noq-1;i++)
        for(j=0;j<noq-i-1;j++)
            if(qu[j] > qu[j+1])
            {
                t=qu[j];
                qu[j]=qu[j+1];
                qu[j+1]=t;
            }

    if( qu[noq-1] < st)  //all requests are left side
        s = st - qu[0];
    else
    {
        s = (st - qu[0]) + (qu[noq-1] - qu[0]) ;
    }

   printf("\n Total look seek time (goes to end 0 first) : %d",s);
}
void clook(int n,int noq, int qu[10], int st)
{
    int s=0;
    int i=0,j,t;
    for(i=0;i<noq-1;i++)
        for(j=0;j<noq-i-1;j++)
            if(qu[j] > qu[j+1])
            {
                t=qu[j];
                qu[j]=qu[j+1];
                qu[j+1]=t;
            }

    if( qu[noq-1] < st)  // all requests are left side
        s = st - qu[0];
    else
    {   for(j=0;j<noq;j++)
        {
            if(qu[j] > st)
                break;
        }
        s = (st - qu[0]) + ( qu[noq-1] - qu[j] );
    }

   printf("\n Total clook seek time (goes to end 0 first) : %d",s);
}
int main()
{
 int n,st,noq;
 n=200;
 noq=10;
 int qu[10] = {5,24,17,78,81,23,89,104,72,134};
 st= 50;
 look(n,noq,qu,st);
 clook(n,noq,qu,st);
 return 0;
}
