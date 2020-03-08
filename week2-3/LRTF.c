#include<stdio.h>
#include<stdlib.h>

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[],int rt[])
{
    int j, contswitch=-1,time=0,save=-1,maxm=0,complete=0;
    int check=0,largest,idletime=0;
    while(complete!=n)
    {
        maxm=0;
        for(j=0;j<n;j++)
        {
            if(at[j]<=time && rt[j]>maxm && rt[j]>0)
            {
                largest=j;
                maxm=rt[j];
                check=1;
            }
        }
        if(check==0)
            {
                time++;
                idletime++;
                continue;
            }

        rt[largest]--;
        maxm=rt[largest];

        if(largest!=save)
        {
            contswitch++;
            save=largest;
        }

        printf("Process Execution at time %d is:P%d\n",time,pid[largest]);

        if(rt[largest]==0)
        {
            complete++;
            check=0;
            compt[largest]=time+1;
            tat[largest]=compt[largest]-at[largest];
            wt[largest]=tat[largest]-bt[largest];
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