#include<stdio.h>
#include<stdlib.h>

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[],int rt[])
{
    int j,time=0,save=-1,contswitch=-1,minm=999,complete=0;
    int check=0,shortest,idletime=0;
    while(complete!=n)
    {
        for(j=0;j<n;j++)
        {
            if(at[j]<=time && rt[j]<minm && rt[j]>0)
            {
                shortest=j;
                minm=rt[j];
                check=1;
            }
        }
        if(check==0)
            {
                time++;
                idletime++;
                continue;
            }
        printf("Process Execution at time %d is:P%d\n",time,pid[shortest]);

        rt[shortest]--;
        minm=rt[shortest];

        if(shortest!=save)
        {
            contswitch++;
            save=shortest;
        }
        if(minm==0)
            minm=999;

        if(rt[shortest]==0)
        {
            complete++;
            check=0;
            compt[shortest]=time+1;
            tat[shortest]=compt[shortest]-at[shortest];
            wt[shortest]=tat[shortest]-bt[shortest];
        }
        time++;
    }
	printf("\n\nContext Switching:%d\n\n",contswitch);
    return idletime;
}
int main()
{
	int n,i,idle=0;
	int *PID,*at,*bt,*tat,*wt,*compt,*rt;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

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

    idle=finding(n,PID,at,bt,tat,wt,compt,rt);

	printf("|PID\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",PID[i],at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);

    return 0;
}