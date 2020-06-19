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
int comptvalues(int n,int at[],int bt[],int compt[])
{
	int i,idle=0;
	compt[0]=at[0]+bt[0];

	for(i=1;i<n;i++)
	{
		if(at[i]<=compt[i-1])
			compt[i]=compt[i-1]+bt[i];
		else
		{
			idle=idle+at[i]-compt[i-1];
			compt[i]=at[i]+bt[i];
		}
	}
	return idle;
}
void tat_wt_values(int n,int compt[],int at[],int bt[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=compt[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}
void ganttchart(int n,int PID[],int bt[],int tat[],int compt[])
{
    int i, j;
    													// print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) 
		printf("--");
        printf(" ");
    }
    printf("\n|");

		    											// printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i] - 1; j++) printf(" ");
        printf("P%d", PID[i]);
        for(j=0; j<bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    													// printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    													// printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("  ");
        if(compt[i] > 9) printf("\b"); 									// backspace : remove 1 space
        printf("%d", compt[i]);

    }
    printf("\n");

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
	idle=comptvalues(n,at,bt,compt);
	tat_wt_values(n,compt,at,bt,wt,tat);

	printf("|PID\t|Arrival time\t|Burst time\t|completion\t|turn around\t|wait time\t|");
	for(i=0;i<n;i++)
		printf("\n|P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",(PID[i]),at[i],bt[i],compt[i],tat[i],wt[i]);
	printf("\n\nIdle time:%d\n\n",idle);
	printf("\tGantt Chart\n");
        ganttchart(n,PID,bt,tat,compt);

	printf("\nContext Switching: %d(Non Preemptive)\n",n-1);

}

