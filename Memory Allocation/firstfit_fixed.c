#include<stdio.h>

int main()
{
    int n,m,i,j,fix=0;
    int block[10],process[10],blockno[10],interfrag[10],markedblock[10]={},unresolved[10]={};

    printf("Enter the no of blocks: ");
    scanf("%d",&n);
    printf("Enter the no of processes: ");
    scanf("%d",&m);

    printf("Enter the block sizes: ");
    for(i=0;i<n;i++)
        scanf("%d",&block[i]);

    printf("ENter the process size values: ");
    for(i=0;i<m;i++)
        scanf("%d",&process[i]);

    for(i=0;i<m;i++)
    {
        fix=0;
        for(j=0;j<n;j++)
        {
            if(process[i]<block[j] && markedblock[j]==0)
            {
                blockno[i]=j+1;
                fix=1;
                break;
            }
        }

        if(fix==0)
        {
            printf("process %d isn't placed\n",i+1);
            unresolved[i]=1;
        }
        else
        {
            interfrag[i]=block[j]-process[i];
            markedblock[j]=1;
        }
    }

    printf("pno\t|size\t|bno\t|interfrag\n");
    for(i=0;i<m;i++)
    {
        if(unresolved[i]==0)
            printf("%d\t|%d\t|%d\t|%d\n",i+1,process[i],blockno[i],interfrag[i]);
    }

    return 0;
}