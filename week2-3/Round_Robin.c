#include<stdio.h>
#include<stdlib.h>

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[],int rt[],int timequantum)
{
    int i,time=0,save=-1,contswitch=-1,complete=0,done,idletime=0;
    while(complete!=n)
    {
        done=0;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                done=1;
                if(save!=i)
                {
                    contswitch++;
                    save=i;
                }
                printf("Process Execution at time %d is:P%d\n",time,pid[save]);                
                
                if(rt[i]>timequantum)
                {
                    rt[i]-=timequantum;
                    time+=timequantum;
                }
                else
                {
                    time+=rt[i];
                    rt[i]=0;
                    compt[i]=time;
                    tat[i]=time-at[i];
                    wt[i]=tat[i]-bt[i];
                    complete++;
                }
            }
        }

        if(done==0)
        {
            time++;
            idletime++;
        }
    }
	printf("\n\nContext Switching:%d\n\n",contswitch);
    return idletime;
}
int main()
{
	int n,i,idle=0,timequantum;
	int *PID,*at,*bt,*tat,*wt,*compt,*rt;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

    printf("Enter the time quantum: ");
    scanf("%d",&timequantum);

	at=(int*)malloc(sizeof(int)*n);
	bt=(int*)malloc(sizeof(int)*n);
	tat=(int*)malloc(sizeof(int)*n);
	wt=(int*)malloc(sizeof(int)*n);
	compt=(int*)malloc(sizeof(int)*n);
    PID=(int*)malloc(sizeof(int)*n);
    rt=(int*)malloc(sizeof(int)*n);

	printf("Enter the Arrival time and burst time of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
		PID[i]=i+1;
	}

    idle=finding(n,PID,at,bt,tat,wt,compt,rt,timequantum);

	printf("|PID\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",PID[i],at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);

    return 0;
}