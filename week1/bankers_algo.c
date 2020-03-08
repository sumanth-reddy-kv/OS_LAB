#include<stdio.h>
#include<stdlib.h>


int isavailable(int r,int i,int need[][10],int avail[])
{
    int j,flag=1;
    for(j=0;j<r;j++)
    {
        if(need[i][j]>avail[j])
        {
            flag=0;
        }
    }
    return flag;
}
void safeseq(int p,int r,int pid[], int max[][10], int alloc[][10], int avail[], int need[][10],int seq[], int marked[],int index)
{
    int i,j;
    for(i=0;i<p;i++)
    {

        if(marked[i]==0 && isavailable(r,i,need,avail))
        {
            marked[i]=1;
            for(j=0;j<r;j++)
                avail[j]+=alloc[i][j];

            seq[index++]=pid[i];
            safeseq(p,r,pid,max,alloc,avail,need,seq,marked,index);

            seq[index--]=0;
            marked[i]=0;

            for(j=0;j<r;j++)
                avail[j]-=alloc[i][j];
        }
    }
    if(index==p)
    {
        for(i=0;i<p;i++)
        {
            printf("->P%d",seq[i]);
        }
        printf("\n");
    }
    return;
}
int main()
{
    int i,j,p,r,index=0;
    int pid[10],max[10][10],alloc[10][10],avail[10],need[10][10],seq[10];
    int marked[10]={};
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("Enter the number of resources per process: ");
    scanf("%d",&r);
    printf("Enter the Max resources of each process: ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

        pid[i]=i+1;
    }        
    printf("Enter the Allocated resources of each process: ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter the Available resources: ");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);

    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    safeseq(p,r,pid,max,alloc,avail,need,seq,marked,index); 
    return 0;                   
}