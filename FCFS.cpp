#include<stdio.h>

int pid[20], BT[20], WT[20], TAT[20], n;

//WT = ager process er TAT( WT + BT) for FCFS
void calculate_waiting_time()
{
    WT[0]=0;
    for(int i=1; i<n; i++)
    {
        WT[i] = WT[i-1] + BT[i-1];
    }
}

//TurnArroundTime = waiting_time + BT
void calculate_TAT_time()
{
    for(int i=0; i<n; i++)
    {
        TAT[i] = WT[i] + BT[i];
    }
}

double average_WT()
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum= sum + WT[i];

    return (double)sum/n;
}

double average_TAT()
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum+= TAT[i];
    return (double)sum/n;
}

int main()
{
    printf("Enter the number of process: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        pid[i]=i;
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &BT[i]);
    }

    calculate_waiting_time();
    calculate_TAT_time();

    printf("\n\t Process \tBurst Time \tWaiting Time \tTurnaround Time\n");

    for(int i=0; i<n; i++)
    {
        printf("\n\t p%d \t\t %d \t\t %d \t\t %d", pid[i], BT[i], WT[i], TAT[i]);
    }

    double AWT = average_WT();
    double ATAT = average_TAT();

    printf("\n\nAverage Waiting Time: %lf\n", AWT);
    printf("\nAverage Turnarround Time: %lf\n", ATAT);


}

/*
Enter the number of process: 3
Enter the burst time of process 0: 24
Enter the burst time of process 1: 3
Enter the burst time of process 2: 3

         Process        Burst Time      Waiting Time    Turnaround Time

         p0              24              0               24
         p1              3               24              27
         p2              3               27              30

Average Waiting Time: 17.000000

Average Turnarround Time: 27.000000
*/
