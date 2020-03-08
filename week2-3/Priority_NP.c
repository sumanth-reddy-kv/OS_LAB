#include<stdio.h>
#include<stdlib.h>

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[],int priority[],int marked[])
{
    int i,time=0,save=-1,complete=0,done,idletime=0,prio;
    while(complete!=n)
    {
        prio=0;
        done=0;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && marked[i]!=1)
            {
                if(prio<priority[i])
                {
                    done=1;
                    prio=priority[i];
                    save=i;
                }
            }                   
        }
        if(done==0)
        {
            time++;
            idletime++;
            continue;
        }    
        time+=bt[save];
        marked[save]=1;
        compt[save]=time;
        tat[save]=time-at[save];
        wt[save]=tat[save]-bt[save];
        complete++;
    }

	printf("\n\nContext Switching:%d\n\n",n-1);
    return idletime;
}
int main()
{
	int n,i,idle=0;
	int *PID,*at,*bt,*tat,*wt,*compt,*priority,*marked;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

	at=(int*)malloc(sizeof(int)*n);
	bt=(int*)malloc(sizeof(int)*n);
	tat=(int*)malloc(sizeof(int)*n);
	wt=(int*)malloc(sizeof(int)*n);
	compt=(int*)malloc(sizeof(int)*n);
    PID=(int*)malloc(sizeof(int)*n);
    priority=(int*)malloc(sizeof(int)*n);
    marked=(int*)malloc(sizeof(int)*n);

	printf("Enter the Arrival time, burst time and priority of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&at[i],&bt[i],&priority[i]);
		PID[i]=i+1;
	}

    idle=finding(n,PID,at,bt,tat,wt,compt,priority,marked);

	printf("|PID\t|Priority\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",PID[i],priority[i],at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);

    return 0;
}