#include <stdio.h>
void main()
{
	int pid[20], brst[20],wt[20],tat[20],remtime[20],flag[20];
	int sttime=0, endtime=0, totburst=0, totwt=0, tottat=0, quantum, duration, n, i;
	float avgwt=0.0, avgtat=0.0;

	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter Quantum slice : ");
	scanf("%d",&quantum);
	for(i=1;i<=n;i++)
	{
		pid[i] = i;
		printf("Enter burst time for processs %d: ",i);
		scanf("%d",&brst[i]);
		remtime[i]=brst[i];
		flag[i]=0;
		wt[i]=0;
		tat[i]=0;
		totburst = totburst + brst[i];
	}
	i=1;//elements start from location 1
	printf("Pid\t\tBurst Time\t\tStart Time\t\tEnd Time\t\tRemaining Time\n");
	while(sttime<totburst)
	{
		if(flag[i]==0)
		{
			if(remtime[i]<=quantum)
			{
				duration =remtime[i];
				remtime[i]=0;
				flag[i]=1; //indicates process over
			}
			else
			{
				duration = quantum;
				remtime[i] = remtime[i] - quantum;
			}	

			endtime = sttime+duration;
			wt[i]=endtime-brst[i];
			tat[i]=wt[i]+brst[i];
			printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",pid[i],brst[i],sttime,endtime,remtime[i]);
			sttime=endtime;
		}
		i=(i+1)%(n+1);	
	}

	for(i=1;i<=n;i++)
	{
		totwt = totwt + wt[i];
		tottat = tottat + tat[i];
	}

	avgwt = (float)totwt/n;
	avgtat = (float)tottat/n;

	for(i=1;i<=n;i++)
	{
		printf("\nProcess %d",i);
		printf("\n\t Waiting time : %d",wt[i]);
		printf("\n\t Turnaround time : %d",tat[i]);
	}
	printf("\n\n\t Total waiting time : %d",totwt);
	printf("\n\t Total turnaround time : %d",tottat);
	printf("\n\n\t Average waiting time : %f",avgwt);
	printf("\n\t Average turnaround time : %f",avgtat);

}