#include<stdio.h>
#include<stdlib.h>

void arrange(int n,int at[],int bt[],int PID[])
{
	int i,j,small,swap;
	for(i=0;i<n;i++)
	{
		small=i;
		for(j=i;j<n;j++)
		{
			if(at[small]>at[j])
				small=j;
            else if(at[small]==at[j])
                if(bt[small]>bt[j])
                    small=j;
		}
		
		swap=at[i];
		at[i]=at[small];
		at[small]=swap;
		swap=bt[i];
		bt[i]=bt[small];
		bt[small]=swap;
		swap=PID[i];
		PID[i]=PID[small];
		PID[small]=swap;
	}
}

int finding(int n,int pid[],int at[],int bt[],int tat[],int wt[],int compt[])
{
	int i,j;
    int temp,low,save;
    compt[0]=at[0]+bt[0];
    tat[0]=compt[0]-at[0];
    wt[0]=tat[0]-bt[0];

    for(i=0;i<n;i++)
    {
        temp=compt[i-1];
        low=bt[i];
        save=i;

        for(j=i;j<n;j++)
        	if(temp>=at[j] && low>=bt[j])
        	{
            	low=bt[j];
            	save=j;
        	}
        
    }
}
int main()
{
	int n,i,idle=0;
	int *PID,*at,*bt,*tat,*wt,*compt,*x;

	printf("Enter the number of processes: ");
	scanf("%d",&n);

	at=(int*)malloc(sizeof(int)*n);
	bt=(int*)malloc(sizeof(int)*n);
	tat=(int*)malloc(sizeof(int)*n);
	wt=(int*)malloc(sizeof(int)*n);
	compt=(int*)malloc(sizeof(int)*n);
    PID=(int*)malloc(sizeof(int)*n);
    x=(int*)malloc(sizeof(int)*(n+1));

	printf("Enter the Arrival time and burst time of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&at[i],&bt[i]);
		PID[i]=i+1;
	}
	arrange(n,at,bt,PID);
    idle=finding(n,PID,at,bt,tat,wt,compt);

	printf("|PID\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",PID[i],at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);

}