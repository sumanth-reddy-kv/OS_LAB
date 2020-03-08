#include<stdio.h
#include<stdlib.h>

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[],int rt[],int temppri[])
{
    int i,time=0,save=-1,contswitch=-1,complete=0,done,priority,idletime=0,mainprio;
    while(complete!=n)
    {
        done=0;
        priority=0;
        for(i=0;i<n;i++)
        {
            if(temppri[i]>priority)
            {
                if(at[i]<time && rt[i]>0)
                {
                    priority=temppri[i];
                    mainprio=i;
                    done=1;
                }
            }
        }
        if(done==0)
            {
                time++;
                idletime++;
                continue;
            }

        rt[mainprio]--;
        
        if(mainprio!=save)
        {
            contswitch++;
            save=mainprio;
        }
        printf("Process Execution at time %d is:P%d\n",time,pid[save]);
        
        if(rt[mainprio]==0)
        {
            complete++;
            done=0;
            compt[mainprio]=time+1;
            tat[mainprio]=compt[mainprio]-at[mainprio];
            wt[mainprio]=tat[mainprio]-bt[mainprio];
        }
        time++;
    }
	printf("\n\nContext Switching:%d\n\n",contswitch);
    return idletime;
}
int main()
{
	int n,i,idle=0;
	int *PID,*at,*bt,*pri,*tat,*wt,*compt,*rt,*temppri;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

	at=(int*)malloc(sizeof(int)*n);
	bt=(int*)malloc(sizeof(int)*n);
	pri=(int*)malloc(sizeof(int)*n);
	tat=(int*)malloc(sizeof(int)*n);
	wt=(int*)malloc(sizeof(int)*n);
	compt=(int*)malloc(sizeof(int)*n);
    PID=(int*)malloc(sizeof(int)*n);
    rt=(int*)malloc(sizeof(int)*n);
    temppri=(int*)malloc(sizeof(int)*n);

	printf("Enter the Arrival time,burst time and priority of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&at[i],&bt[i],&pri[i]);
        rt[i]=bt[i];
        temppri[i]=pri[i];
		PID[i]=i+1;
	}

    idle=finding(n,PID,at,bt,tat,wt,compt,rt,temppri);

	printf("|PID\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",PID[i],at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);

    return 0;
}